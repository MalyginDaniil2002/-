@echo off

if "%~1"=="" (
    echo "Ввод выполнен не до конца!"
    exit /b
)
if "%~2"=="" (
    echo "Ввод выполнен не до конца!"
    exit /b
)

for /f "delims=0123456789" %%a in ("%~1") do (
    echo Был выполнен ввод нечислового типа данных
    exit /b
)
for /f "delims=0123456789" %%a in ("%~2") do (
    echo Был выполнен ввод нечислового типа данных
    exit /b
)

if %~1 lss 0 (
    echo Ввод размера массива выполнен неверно!
    exit /b
)

if not %~2==0 if not %~2==1 (
    echo Ввод варианта обращения выполнен неверно!
    exit /b
)

if not exist "memory_overcommit_win.exe" (
    gcc memory_overcommit_win.c -o memory_overcommit_win.exe
)

memory_overcommit_win.exe %1 %2
