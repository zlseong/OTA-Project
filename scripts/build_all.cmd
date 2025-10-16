
@echo off
setlocal
set BUILD_DIR=%~dp0..\\build
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"
pushd "%BUILD_DIR%"
cmake -S .. -B .
cmake --build . --config Release
popd
echo Done.

