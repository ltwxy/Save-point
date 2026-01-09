@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

echo ========================================================
echo      🚀 ACM 训练日结助手 (Auto Commit Tool)
echo ========================================================
echo.

:: 1. 检查状态，列出所有变动的文件
git status -s
echo.
echo --------------------------------------------------------
echo 正在扫描变动文件...
echo.

:: 2. 循环处理每一个变动的文件
:: 这里的逻辑是：只提取文件名，不提交删除的文件
for /f "tokens=2 delims= " %%f in ('git status -s') do (
    echo [处理中] %%f
    
    :: 3. 询问备注
    set /p "msg=请输入 %%f 的备注 (直接回车跳过此文件): "
    
    :: 4. 如果用户输入了备注，就单独提交这个文件
    if defined msg (
        git add %%f
        git commit -m "%%f - !msg!"
        echo ✅ 已提交: %%f
    ) else (
        echo ⏭️ 已跳过: %%f
    )
    
    echo --------------------------------------------------------
    :: 清空变量，防止影响下一次循环
    set "msg="
)

:: 5. 最后统一推送
echo.
echo 正在推送到 GitHub...
git push

echo.
echo 🎉 今日任务已归档！绿格子 +1
pause