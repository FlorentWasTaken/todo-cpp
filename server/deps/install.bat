@echo off
setlocal enabledelayedexpansion

set RED=^[[0;31m
set GREEN=^[[0;32m
set DEFAULT=^[[0m

where conan >nul 2>&1
if %errorlevel% neq 0 (
    echo !RED!Conan isn't installed.!DEFAULT!
    exit /b 1
)

conan install . --build=missing

if !errorlevel! equ 0 (
    echo !GREEN!Successfully installed dependencies in the current directory.!DEFAULT!
) else (
    echo !RED!Error while installing dependencies.!DEFAULT!
)

endlocal