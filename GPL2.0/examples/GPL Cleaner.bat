@echo off

del /q /f ..\GPLib\dlls\*.pdb
del /q /f ..\GPLib\dlls\*.exe

CLS

ECHO Cleaning project
ECHO.
CHOICE /C:AB /D A /T 1 > NUL
rd remove /s /q
cls
ECHO Cleaning project .
ECHO.
CHOICE /C:AB /D A /T 1 > NUL
md remove
cls
ECHO Cleaning project . .
ECHO.
CHOICE /C:AB /D A /T 1 > NUL
attrib remove +H
cls
ECHO Cleaning project . . .
ECHO.
CHOICE /C:AB /D A /T 1 > NUL

ECHO.
ECHO.

pause



