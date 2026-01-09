@echo off
chcp 65001 >nul
title 🚀 ACM 训练日结助手
color 0A

echo ========================================================
echo        🚀 ACM 训练日结助手 (Auto Commit Tool)
echo ========================================================

:: --- 1. 清理垃圾 ---
echo.
echo [1/3] 正在清理 .exe 文件...
del /s /q *.exe >nul 2>&1
echo ✅ 清理完毕。

:: --- 2. 准备提交 ---
echo.
echo [2/3] 正在扫描变动...
git status -s

:: 自动添加脚本本身
git add daily_commit.bat >nul 2>&1

:: --- 关键修复：防止断行的短提示 ---
echo.
set /p msg="请输入备注 (如: AC 1001): "

:: 如果没输入，给个默认值
if "%msg%"=="" set msg=Daily Update

git add .
git commit -m "%msg%"

:: --- 3. 推送网络 ---
echo.
echo [3/3] 正在推送到 GitHub...
git push

if %errorlevel% neq 0 (
    color 0C
    echo.
    echo ❌ 推送失败！可能是网络问题。
    echo 💡 提示：如果开了梯子，请配置 Git 代理。
) else (
    echo.
    echo 🎉 大功告成！
)

echo.
pause