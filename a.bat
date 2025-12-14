@echo off

if exist *.png rm *.png

cd build
wordcloud
cd ..