@echo off
chcp 1251 > log
del log

set MAIN=modle
set EXE=myprogram
set CHARSET="-finput-charset=utf-8 -fexec-charset=windows-1251"



g++ "%CHARSET%" %MAIN%.cpp -o %EXE%

%EXE%