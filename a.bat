@echo off

if exist *.png rm *.png
if exist *.jpg rm *.jpg

cd build
wordcloud
cd ..