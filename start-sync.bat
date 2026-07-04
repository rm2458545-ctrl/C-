@echo off
chcp 65001 >nul
echo ========================================
echo   自动同步脚本启动器
echo ========================================
echo.
echo 正在启动文件监控同步...
echo 按 Ctrl+C 可以停止监控
echo.
cd /d D:\Zclaude

:: 检查Git Bash是否可用
where bash >nul 2>&1
if %errorlevel% neq 0 (
    echo 错误：找不到bash命令
    echo 请确保Git已安装并添加到PATH
    echo.
    echo 下载Git: https://git-scm.com/download/win
    pause
    exit /b 1
)

:: 清理可能残留的锁文件
if exist .sync-lock (
    echo 清理残留的锁文件...
    del /f .sync-lock 2>nul
)

:: 启动监控脚本
bash auto-sync.sh

if %errorlevel% neq 0 (
    echo.
    echo 脚本异常退出，错误代码: %errorlevel%
    pause
)
