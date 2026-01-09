@echo off
chcp 65001 >nul
title GitHub 文件删除助手
color 0A

:START
git pull
cls
echo ========================================================
echo           GitHub 文件/文件夹 删除助手
echo ========================================================
echo.
echo 请选择删除模式：
echo.
echo [1] 双杀模式 (彻底删除)
echo     - 同时删除 GitHub 仓库 和 本地电脑 里的文件。
echo     - 慎用！文件会直接消失。
echo.
echo [2] 隐身模式 (只删 GitHub，保留本地)
echo     - 删除 GitHub 仓库里的文件，但保留你电脑里的文件。
echo     - 适合移除不小心上传的配置文件、密钥或临时文件。
echo.
echo [3] 退出
echo.
echo ========================================================
set /p choice="请输入数字 [1-3] 并按回车: "

if "%choice%"=="1" goto DELETE_ALL
if "%choice%"=="2" goto DELETE_REMOTE
if "%choice%"=="3" exit
goto START

:DELETE_ALL
echo.
echo --------------------------------------------------------
echo 正在进入：双杀模式 (GitHub + 本地)
echo --------------------------------------------------------
goto COMMON_INPUT

:DELETE_REMOTE
echo.
echo --------------------------------------------------------
echo 正在进入：隐身模式 (只删 GitHub)
echo --------------------------------------------------------
goto COMMON_INPUT

:COMMON_INPUT
echo 注意：如果是文件夹，脚本会自动递归删除。
echo 请输入要删除的文件名或文件夹名 (包含后缀，如 config.js 或 .idea)：
echo.
set /p target="文件名/路径: "

if "%target%"=="" goto START

echo.
echo 正在执行 Git 命令...
echo.

:: 根据选择执行不同的删除命令
if "%choice%"=="1" (
    git rm -r "%target%"
) else (
    git rm -r --cached "%target%"
)

:: 检查上一条命令是否成功，如果不成功（比如文件不存在）则报错
if %errorlevel% neq 0 (
    echo.
    echo [错误] 找不到文件或 Git 命令执行失败，请检查文件名是否正确。
    pause
    goto START
)

echo.
echo [提交更改]
set /p msg="请输入 Commit 备注 (直接回车默认填 'Delete files'): "
if "%msg%"=="" set msg=Delete files

git commit -m "%msg%"

echo.
echo [正在推送到 GitHub...]
git push

if %errorlevel% equ 0 (
    echo.
    echo ======================================
    echo           操作成功！
    echo ======================================
) else (
    echo.
    echo [错误] 推送失败，请检查网络或 Git 配置。
)

pause
goto START