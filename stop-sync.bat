@echo off
chcp 65001 >nul
echo 正在停止文件监控...

:: 查找并终止bash进程（通过锁文件）
if exist D:\Zclaude\.sync-lock (
    echo 找到锁文件，正在清理...
    del /f D:\Zclaude\.sync-lock 2>nul
)

:: 终止可能运行的bash进程
tasklist /FI "IMAGENAME eq bash.exe" 2>nul | find /I "bash.exe" >nul
if %errorlevel% equ 0 (
    echo 终止bash进程...
    taskkill /F /IM bash.exe >nul 2>&1
)

echo.
echo 监控已停止
echo.
pause
