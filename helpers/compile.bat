@echo off

SET APP_NAME=program

cd .\build

cmake.exe -S .. -B . -G "MinGW Makefiles" -DAPP_NAME=%APP_NAME%

mingw32-make.exe