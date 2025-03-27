@echo off
setlocal enabledelayedexpansion

:: 生成随机测试数据
set n=10
set m=2

:: 生成测试数据并写入 input.txt
(
    echo %n% %m%
    for /L %%i in (1, 1, %n%) do (
        set line=
        for /L %%j in (1, 1, %m%) do (
            set /A "num=!random! %% 1000000 + 1"
            set line=!line! !num!
        )
        echo !line!
    )
) > input.txt

:: 编译并运行 A.cpp
g++ CSP_23_1.cpp -o wrong.exe
if %errorlevel% neq 0 (
    echo Failed to compile CSP_23_1.cpp
    exit /b 1
)
wrong.exe < input.txt > output_wrong.txt

:: 编译并运行 B.cpp
g++ CSP_23_1_correct.cpp -o correct.exe
if %errorlevel% neq 0 (
    echo Failed to compile CSP_23_1_correct.cpp
    exit /b 1
)
correct.exe < input.txt > output_correct.txt

:: 比较输出文件
fc output_wrong.txt output_correct.txt > nul
if %errorlevel% neq 0 (
    echo Outputs differ
) else (
    echo Outputs are identical
)

endlocal