flex Lexico.l
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c -o Primero.exe