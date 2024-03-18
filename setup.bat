@echo off
setlocal enabledelayedexpansion

set RED=^[[0;31m
set GREEN=^[[0;32m
set DEFAULT=^[[0m

where cmake >nul 2>&1
if %errorlevel% neq 0 (
    echo !RED!Cmake isn't installed.!DEFAULT!
    exit /b 1
)

cd deps
./install.bat
cd ..
cmake .

if !errorlevel! equ 0 (
    echo !GREEN!Successfully set up project.!DEFAULT!
) else (
    echo !RED!Error while setting up project.!DEFAULT!
)

endlocal