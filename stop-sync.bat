@echo off
echo 正在停止文件监控...
taskkill /F /IM bash.exe /FI "WINDOWTITLE eq auto-sync*" 2>nul
del /f D:\Zclaude\.sync-lock 2>nul
echo 监控已停止
pause
