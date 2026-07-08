# 自动同步脚本 - 监控文件变化并自动提交到GitHub
# 改进版：使用PowerShell实现，更好的Windows兼容性

param(
    [string]$WatchDir = "D:\Zclaude",
    [int]$CheckInterval = 5,
    [int]$DebounceSeconds = 3
)

# 设置控制台编码为UTF-8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
$OutputEncoding = [System.Text.Encoding]::UTF8

$LogFile = Join-Path $WatchDir ".sync-log.txt"
$LockFile = Join-Path $WatchDir ".sync-lock"

# 日志函数
function Write-Log {
    param([string]$Message, [string]$Level = "INFO")
    $timestamp = Get-Date -Format "yyyy/MM/dd HH:mm:ss"
    $logEntry = "[$timestamp] $Message"
    Write-Host $logEntry
    Add-Content -Path $LogFile -Value $logEntry -Encoding UTF8
}

# 检查Git是否可用
function Test-GitAvailable {
    try {
        $null = git --version 2>&1
        return $true
    } catch {
        return $false
    }
}

# 清理函数
function Cleanup {
    if (Test-Path $LockFile) {
        Remove-Item $LockFile -Force -ErrorAction SilentlyContinue
    }
    Write-Log "监控已停止" "INFO"
    exit 0
}

# 注册退出清理
Register-EngineEvent -SourceIdentifier PowerShell.Exiting -Action { Cleanup } | Out-Null

# 主程序开始
Write-Log "========================================"
Write-Log "自动同步脚本启动"
Write-Log "========================================"
Write-Log "监控目录: $WatchDir"
Write-Log "检查间隔: ${CheckInterval}秒"
Write-Log "防抖延迟: ${DebounceSeconds}秒"
Write-Log "按 Ctrl+C 停止监控"
Write-Log "----------------------------------------"

# 检查Git
if (-not (Test-GitAvailable)) {
    Write-Log "错误：找不到git命令，请确保Git已安装并添加到PATH" "ERROR"
    Write-Log "下载Git: https://git-scm.com/download/win" "ERROR"
    exit 1
}

# 检查并清理过期的锁文件
if (Test-Path $LockFile) {
    $lockInfo = Get-Item $LockFile
    $lockAge = (Get-Date) - $lockInfo.LastWriteTime
    if ($lockAge.TotalMinutes -gt 10) {
        Write-Log "锁文件过期（$([int]$lockAge.TotalMinutes)分钟），清理中..." "WARN"
        Remove-Item $LockFile -Force
    } else {
        Write-Log "监控脚本已在运行中（锁文件存在，创建于$($lockInfo.LastWriteTime)）" "ERROR"
        Write-Log "如需强制运行，请删除: $LockFile" "ERROR"
        exit 1
    }
}

# 创建锁文件
$PID | Out-File -FilePath $LockFile -Encoding ASCII
Write-Log "锁文件已创建: $LockFile (PID: $PID)"

# 初始化
$lastHash = ""
$lastChangeTime = $null
$pendingSync = $false

# 排除的文件模式
$excludePatterns = @(
    "\.git\\.*",
    "\.sync-.*",
    "\.ps1$",
    "\.log$",
    "\.lock$"
)

function Get-DirectoryHash {
    param([string]$Path)

    $files = Get-ChildItem -Path $Path -Recurse -File -ErrorAction SilentlyContinue |
        Where-Object {
            $relativePath = $_.FullName.Substring($Path.Length + 1)
            $excluded = $false
            foreach ($pattern in $excludePatterns) {
                if ($relativePath -match $pattern) {
                    $excluded = $true
                    break
                }
            }
            -not $excluded
        } |
        Sort-Object FullName

    $hashInput = ($files | ForEach-Object {
        "$($_.LastWriteTime.Ticks)|$($_.FullName)|$($_.Length)"
    }) -join "`n"

    $hasher = [System.Security.Cryptography.MD5]::Create()
    $hashBytes = $hasher.ComputeHash([System.Text.Encoding]::UTF8.GetBytes($hashInput))
    return [BitConverter]::ToString($hashBytes).Replace("-", "").ToLower()
}

function Sync-ToGitHub {
    $timestamp = Get-Date -Format "yyyy/MM/dd HH:mm:ss"

    try {
        Set-Location $WatchDir

        # 检查网络连接
        $remoteTest = git ls-remote origin 2>&1
        if ($LASTEXITCODE -ne 0) {
            Write-Log "网络连接失败，跳过本次同步" "ERROR"
            return
        }

        # 添加所有更改
        git add -A 2>&1 | Out-Null

        # 检查是否有更改
        $status = git status --porcelain
        if ([string]::IsNullOrEmpty($status)) {
            Write-Log "无实际变化，跳过" "INFO"
            return
        }

        # 计算更改的文件数
        $fileCount = ($status -split "`n" | Where-Object { $_ -ne "" }).Count
        $commitMsg = "auto-sync: $timestamp ($fileCount 个文件)"

        # 提交
        $commitResult = git commit -m $commitMsg 2>&1
        if ($LASTEXITCODE -ne 0) {
            Write-Log "提交失败: $commitResult" "ERROR"
            return
        }

        # 推送（最多重试3次）
        $maxRetries = 3
        for ($attempt = 1; $attempt -le $maxRetries; $attempt++) {
            $pushResult = git push origin main 2>&1
            if ($LASTEXITCODE -eq 0) {
                Write-Log "同步成功 ($fileCount 个文件)" "SUCCESS"
                return
            } else {
                if ($attempt -lt $maxRetries) {
                    Write-Log "推送失败，5秒后重试 ($attempt/$maxRetries)..." "WARN"
                    Start-Sleep -Seconds 5
                } else {
                    Write-Log "推送失败（已重试$maxRetries 次）: $pushResult" "ERROR"
                }
            }
        }
    } catch {
        Write-Log "同步过程出错: $($_.Exception.Message)" "ERROR"
    }
}

# 主循环
Write-Log "开始监控文件变化..."

try {
    while ($true) {
        try {
            $currentHash = Get-DirectoryHash -Path $WatchDir

            if ($currentHash -ne $lastHash -and $null -ne $lastHash) {
                # 检测到变化
                if (-not $pendingSync) {
                    Write-Log "检测到文件变化，等待写入完成..." "INFO"
                    $lastChangeTime = Get-Date
                    $pendingSync = $true
                }
            }

            # 检查是否应该执行同步（防抖）
            if ($pendingSync -and $null -ne $lastChangeTime) {
                $timeSinceChange = ((Get-Date) - $lastChangeTime).TotalSeconds
                if ($timeSinceChange -ge $DebounceSeconds) {
                    Write-Log "开始同步..." "INFO"
                    Sync-ToGitHub
                    $pendingSync = $false
                    $lastChangeTime = $null
                }
            }

            $lastHash = $currentHash
        } catch {
            Write-Log "监控循环出错: $($_.Exception.Message)" "ERROR"
        }

        Start-Sleep -Seconds $CheckInterval
    }
} finally {
    Cleanup
}
