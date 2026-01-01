@echo off
REM Compile and run the flags test program

echo Building libftprintf library...
cd ..\ft_printf
make
if errorlevel 1 (
    echo Error building library!
    pause
    exit /b 1
)

echo.
echo Compiling test_printf_flags.c...
cd ..\tests
gcc -Wall -Wextra -Werror -I ../ft_printf/include -I ../ft_printf/libft test_printf_flags.c -L ../ft_printf -lftprintf -o test_printf_flags.exe

if errorlevel 1 (
    echo Error compiling test program!
    pause
    exit /b 1
)

echo.
echo Running test program...
echo.
test_printf_flags.exe

pause

