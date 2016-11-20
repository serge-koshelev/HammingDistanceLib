@echo off

set BOOST_ROOT=c:/Apps/3rdparty/boost_1_59_0
set BOOST_LIBRARYDIR=c:/Apps/3rdparty/boost_1_59_0/lib64-msvc-14.0

pushd %~dp0
set TOP_LEVEL_DIR=%CD%
popd

if NOT %TOP_LEVEL_DIR% == %CD% goto l1

echo -------------------------------------------------
echo Do not run the script inside the source directory
echo Please use bootstrap.vbs script
echo -------------------------------------------------
goto exit

:l1

c:\Apps\3rdparty\cmake-3.6.2\bin\cmake.exe -Wno-dev -G"Visual Studio 14 Win64" %TOP_LEVEL_DIR% -DCMAKE_INSTALL_PREFIX=%CD%

:exit
pause
