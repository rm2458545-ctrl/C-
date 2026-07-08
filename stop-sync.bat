@echo off
chcp 65001 >nul
echo ========================================
echo   停止自动同步
echo ========================================
echo.
echo 正在停止文件监控...
cd /d D:\Zclaude

:: 查找并终止PowerShell进程（通过锁文件）
if exist .sync-lock (
    echo 找到锁文件，正在清理...
    set /p PID=<.sync-lock
    del /f .sync-lock 2>nul

    :: 终止对应的PowerShell进程
    tasklist /FI "IMAGENAME eq powershell.exe" 2>nul | find /I "powershell.exe" >nul
    if %errorlevel% equ 0 (
        echo 终止PowerShell进程 (PID: %PID%)...
        taskkill /F /PID %PID% >nul 2>&1
    )
) else (
    echo 未找到运行中的同步脚本
)

:: 清理可能残留的锁文件
if exist .sync-lock (
    del /f .sync-lock 2>nul
)

echo.
echo 监控已停止
echo.
pause
