@echo off
chcp 65001 >nul
cd /d "D:\Zclaude"
git add .
if "%~1"=="" (
    git commit -m "update: %date% %time%"
) else (
    git commit -m "%~1"
)
git push
pause
