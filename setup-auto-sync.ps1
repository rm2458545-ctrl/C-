# 设置定时同步任务 - 每天同步一次
# 以管理员身份运行此脚本

$taskName = "GitHubAutoSync"
$scriptPath = "D:\Zclaude\sync-to-github.bat"

# 删除已存在的任务（如果有）
Unregister-ScheduledTask -TaskName $taskName -Confirm:$false -ErrorAction SilentlyContinue

# 创建任务触发器 - 每天凌晨 2 点
$trigger = New-ScheduledTaskTrigger -Daily -At "02:00"

# 创建任务操作
$action = New-ScheduledTaskAction -Execute "cmd.exe" -Argument "/c `"$scriptPath`""

# 创建任务设置
$settings = New-ScheduledTaskSettingsSet -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries -StartWhenAvailable

# 注册任务
Register-ScheduledTask -TaskName $taskName -Trigger $trigger -Action $action -Settings $settings -Description "自动同步文件到 GitHub"

Write-Host "✅ 定时同步任务已设置！" -ForegroundColor Green
Write-Host "📁 任务名称: $taskName" -ForegroundColor Cyan
Write-Host "⏱️  同步频率: 每天凌晨 2 点" -ForegroundColor Cyan
Write-Host "📍 同步路径: D:\Zclaude" -ForegroundColor Cyan
Write-Host ""
Write-Host "管理任务:" -ForegroundColor Yellow
Write-Host "  - 查看: Get-ScheduledTask -TaskName '$taskName'" -ForegroundColor White
Write-Host "  - 删除: Unregister-ScheduledTask -TaskName '$taskName'" -ForegroundColor White
Write-Host "  - 手动运行: Start-ScheduledTask -TaskName '$taskName'" -ForegroundColor White
