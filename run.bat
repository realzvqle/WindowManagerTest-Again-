@echo off

xmake
copy raylib.dll "build/windows/x64/release/"
copy lua54.dll "build/windows/x64/release/"
if exist build/windows/x64/release/resources rd build/windows/x64/release/resources /s /q
md build/windows/x64/release/resources
robocopy resources/ build/windows/x64/release/resources/ /s
xmake run 