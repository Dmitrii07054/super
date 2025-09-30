@echo off
chcp 1251 > nul
echo Компиляция всех cpp файлов...

set CHARSET="-finput-charset=utf-8 -fexec-charset=windows-1251"

g++ *.cpp -o myprogram.exe
if %errorlevel% == 0 (
    echo Запуск программы...
    echo.
    myprogram.exe
) else (
    echo Ошибка компиляции!
)
pause