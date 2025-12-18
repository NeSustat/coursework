@echo off
cd build_test
if exist tests.exe (
    tests.exe
) else (
    echo tests.exe not found! Run test.bat first.
    pause
)
cd ..