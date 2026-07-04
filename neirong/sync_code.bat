@echo off
chcp 65001 >nul
cd /d "D:\Zclaude"

echo [%date% %time%] 开始同步Code文件夹...

:: 添加Code文件夹的所有更改
git add Code/

:: 检查是否有更改需要提交
git diff --cached --quiet Code/
if %errorlevel% equ 0 (
    echo [%date% %time%] 没有新的更改需要同步
    goto :end
)

:: 提交更改，使用当前时间作为提交信息
for /f "tokens=2 delims==" %%I in ('wmic os get localdatetime /value') do set datetime=%%I
set datetime=%datetime:~0,4%-%datetime:~4,2%-%datetime:~6,2% %datetime:~8,2%:%datetime:~10,2%:%datetime:~12,2%
git commit -m "sync: Code文件夹更新 %datetime%"

:: 推送到GitHub
git push origin main
if %errorlevel% equ 0 (
    echo [%date% %time%] 同步成功！
) else (
    echo [%date% %time%] 同步失败，请检查网络连接
)

:end
echo.
pause