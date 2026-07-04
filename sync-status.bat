@echo off
chcp 65001 >nul
echo ========================================
echo   同步状态检查
echo ========================================
echo.

cd /d D:\Zclaude

:: 检查锁文件
if exist .sync-lock (
    echo [状态] 自动同步: 运行中 ✓
    echo [PID] $(type .sync-lock)
) else (
    echo [状态] 自动同步: 未运行 ✗
)

:: 检查Git状态
echo.
echo [Git状态]
git status --short

:: 检查远程连接
echo.
echo [远程仓库]
git remote -v

:: 检查最后提交
echo.
echo [最后提交]
git log --oneline -3

:: 检查同步日志
if exist .sync-log.txt (
    echo.
    echo [最近日志]
    powershell -Command "Get-Content .sync-log.txt -Tail 5"
)

echo.
pause
