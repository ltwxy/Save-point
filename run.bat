@echo off
chcp 65001 >nul
title 🚀 正在映射虚拟工作区...

:: 1. 定义你要映射的盘符 (推荐用 W 代表 Work)
set "VIRTUAL_DISK=W:"

:: 2. 删除可能已经存在的旧映射 (防止冲突)
subst %VIRTUAL_DISK% /d >nul 2>&1

:: 3. 施展魔法：把当前所在的文件夹 (%~dp0) 映射为 W: 盘
subst %VIRTUAL_DISK% "%~dp0"

if %errorlevel% neq 0 (
    echo ❌ 映射失败！请检查 W: 盘符是否被占用。
    pause
    exit
)

:: 4. 通过 W: 盘打开 VS Code
echo ✅ 映射成功！正在通过纯英文路径启动 VS Code...
code %VIRTUAL_DISK%\

:: 5. 退出脚本 (黑框会自动消失)
exit