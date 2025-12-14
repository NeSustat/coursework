@echo off
set PATH=D:\deCours\coursework\QT\Tools\CMake_64\bin;D:\deCours\coursework\QT\Tools\mingw1310_64\bin;D:\deCours\coursework\QT\6.9.0\mingw_64\bin;%PATH%
set CMAKE_PREFIX_PATH=D:\deCours\coursework\QT\6.9.0\mingw_64

echo Building project...
if exist build rmdir /s /q build
mkdir build
if exist *.png rm *.png
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .

echo Copying Qt dependencies...
copy "D:\deCours\coursework\QT\6.9.0\mingw_64\bin\Qt6Core.dll" .
copy "D:\deCours\coursework\QT\6.9.0\mingw_64\bin\Qt6Gui.dll" .
mkdir platforms
copy "D:\deCours\coursework\QT\6.9.0\mingw_64\plugins\platforms\qwindows.dll" platforms\

echo Done! 
wordcloud.exe
cd ..