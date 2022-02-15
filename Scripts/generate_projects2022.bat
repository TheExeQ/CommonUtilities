@echo off

pushd ..\
call Premake\premake5.exe vs2022
popd
pause
