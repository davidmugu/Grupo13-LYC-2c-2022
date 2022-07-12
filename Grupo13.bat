@echo off

flex Lexico.l
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c -o Grupo13.exe

.\Grupo13.exe Prueba.txt

cls
echo Generando el numbers.obj
tasm numbers.asm
pause
cls
echo Generando el Final.obj
tasm Final.asm
pause
cls
echo Linkeando..
tlink /3 Final.obj numbers.obj /v /s /m
pause
cls
echo Ejecutando el exe
echo --------------------------------------
Final.exe
echo.
echo --------------------------------------
pause
del Final.obj
del Final.map
del Final.exe
del numbers.obj
cls