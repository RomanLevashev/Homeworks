@echo off
chcp 1251

setlocal enabledelayedexpansion

set PROJECTS_DIR="C:\Homeworks2"
set CONFIGURATION=Release
set PLATFORM=x64

for /r %PROJECTS_DIR% %%f in (*.sln) do (
    if exist "!PROJECT_DIR!main.c" (
    set SOLUTION_DIR=%%~dpf
    set PROJECT_NAME=%%~nf
    echo ������ �������: %%f
    msbuild "%%f" /p:Configuration=%CONFIGURATION% /p:Platform=%PLATFORM% /nologo /verbosity:minimal /p:TreatWarningsAsErrors=false
    
    if %errorlevel% neq 0 (
        echo ������ ������ �������: %%f
        exit /b %errorlevel%
    )
    set EXE_PATH=!SOLUTION_DIR!%PLATFORM%\%CONFIGURATION%\!PROJECT_NAME!.exe

    if exist "!EXE_PATH!" (
        echo ������ ������ ��� �������: %%f

        "!EXE_PATH!" --test

        if %errorlevel% neq 0 (
                echo ������ ��� ���������� ������ ��� �������: %%f
                exit /b %errorlevel%
            ) else (
                echo ����� ������� �������� ��� �������: %%f
                @echo.
            )
    ) else (
        echo ������: ���������� ���� ��� ������ �� ������ �: !EXE_PATH!
    )
    )
)

echo ��� ������� ������� �������.
pause
endlocal
