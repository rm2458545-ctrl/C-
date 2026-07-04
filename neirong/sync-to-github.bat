@echo off
chcp 65001 >nul
cd /d D:\Zclaude

echo [%date% %time%] 开始同步...

:: 添加所有更改（包括文件移动、删除）
git add -A

:: 检查是否有更改
git diff --cached --quiet
if %errorlevel% equ 0 (
    echo [%date% %time%] 没有更改需要同步
    exit /b 0
)

:: 提交更改
git commit -m "sync: 自动同步 %date% %time%"

:: 推送到 GitHub
git push origin main

if %errorlevel% equ 0 (
    echo [%date% %time%] 同步成功！
) else (
    echo [%date% %time%] 同步失败，请检查网络连接
)

pause
