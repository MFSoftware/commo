@echo off

set project=commo
set builder="Visual Studio 15 2017"
set configuration=Debug
set arch=Win32

title %project% build script

if exist bin/%project%.dll call:clearDir
call:makeBuild
echo.
pause
goto:eof

:makeBuild
echo Trying to build with %builder%
echo.
cmake -S ./ -G %builder% -B bin
cd bin
echo.
echo Building..
cmake --build . --target %project% --config %configuration%
echo.

echo Cleaning temp dirs
rmdir %arch% /s /q
rmdir "commo.dir" /s /q
rmdir CMakeFiles /s /q
del *.vcxproj
del *.filters
del *.sln
del cmake_install.cmake
del CMakeCache.txt
echo.

echo Ready binares
cd %configuration%
xcopy . ..
cd ..
rmdir %configuration% /s /q
goto:eof

:clearDir
echo Clearing dir..
cd bin
del %project%.dll
del %project%.pdb
del %project%.ilk
echo.
cd ..
goto:eof