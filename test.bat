@echo off
set PATH=D:\deCours\coursework\QT\Tools\CMake_64\bin;D:\deCours\coursework\QT\Tools\mingw1310_64\bin;D:\deCours\coursework\QT\6.9.0\mingw_64\bin;%PATH%
set CMAKE_PREFIX_PATH=D:\deCours\coursework\QT\6.9.0\mingw_64

echo Checking Google Test...
if not exist googletest (
    echo Google Test not found. Please run download_gtest.bat first
    pause
    exit /b 1
)

echo Building tests...
if not exist build_test mkdir build_test

cd build_test
if not exist Makefile cmake -G "MinGW Makefiles" ..
cmake --build .

echo Copying Qt dependencies for tests...
if not exist Qt6Core.dll copy "D:\deCours\coursework\QT\6.9.0\mingw_64\bin\Qt6Core.dll" . 2>nul
if not exist Qt6Gui.dll copy "D:\deCours\coursework\QT\6.9.0\mingw_64\bin\Qt6Gui.dll" . 2>nul
if not exist Qt6Widgets.dll copy "D:\deCours\coursework\QT\6.9.0\mingw_64\bin\Qt6Widgets.dll" . 2>nul
if not exist platforms mkdir platforms
if not exist platforms\qwindows.dll copy "D:\deCours\coursework\QT\6.9.0\mingw_64\plugins\platforms\qwindows.dll" platforms\ 2>nul

echo Tests built successfully!
cd ..
a_test.bat