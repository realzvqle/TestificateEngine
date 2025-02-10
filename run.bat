@echo off


xmake
robocopy glsl build\windows\x64\release\glsl /s
xmake run