@echo off
set PATH=C:\vscode\coursework\QT\Tools\CMake_64\bin;C:\vscode\coursework\QT\Tools\mingw1310_64\bin;C:\vscode\coursework\QT\6.9.0\mingw_64\bin;%PATH%
set CMAKE_PREFIX_PATH=C:\vscode\coursework\QT\6.9.0\mingw_64

echo Building project...
if not exist build mkdir build
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
cd ..
echo Done! Run: build\wordcloud.exe