cd "D:\Software\GnuWin32\bin\"
.\flex.exe "C:\Users\santi\Documents\Proyectos\TP-LyC\Grupo13-LYC-2c-2022\Lexico.l"
.\bison.exe -dyv "C:\Users\santi\Documents\Proyectos\TP-LyC\Grupo13-LYC-2c-2022\Sintactico.y"
Move-Item .\lex.yy.c "C:\Users\santi\Documents\Proyectos\TP-LyC\Grupo13-LYC-2c-2022" -Force
Move-Item .\y.tab.c "C:\Users\santi\Documents\Proyectos\TP-LyC\Grupo13-LYC-2c-2022" -Force
Move-Item .\y.tab.h "C:\Users\santi\Documents\Proyectos\TP-LyC\Grupo13-LYC-2c-2022" -Force
cd "D:\Software\MinGW\bin\"
.\gcc.exe "C:\Users\santi\Documents\Proyectos\TP-LyC\Grupo13-LYC-2c-2022\lex.yy.c" "C:\Users\santi\Documents\Proyectos\TP-LyC\Grupo13-LYC-2c-2022\y.tab.c" -o Primero.exe -Force
Move-Item "D:\Software\MinGW\bin\Primero.exe" "C:\Users\santi\Documents\Proyectos\TP-LyC\Grupo13-LYC-2c-2022\" -Force