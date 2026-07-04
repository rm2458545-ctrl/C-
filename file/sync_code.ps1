# Code文件夹自动同步脚本
# 用法: .\sync_code.ps1

Set-Location "D:\Zclaude"

$logFile = "D:\Zclaude\sync_log.txt"

function Write-Log {
    param($message)
    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    "$timestamp - $message" | Tee-Object -FilePath $logFile -Append -Encoding UTF8
}

Write-Log "开始同步Code文件夹..."

try {
    # 添加Code文件夹的所有更改
    git add Code/

    # 检查是否有更改需要提交
    $status = git status --porcelain Code/
    if ([string]::IsNullOrWhiteSpace($status)) {
        Write-Log "没有新的更改需要同步"
        exit 0
    }

    # 提交更改
    $datetime = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    git commit -m "sync: Code文件夹更新 $datetime"

    # 推送到GitHub
    $pushResult = git push origin main 2>&1
    if ($LASTEXITCODE -eq 0) {
        Write-Log "同步成功！"
        Write-Log "已推送更改到GitHub"
    } else {
        Write-Log "同步失败: $pushResult"
        exit 1
    }
} catch {
    Write-Log "发生错误: $_"
    exit 1
}

Write-Log "同步完成"