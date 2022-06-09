#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

/* CONSTATNES DE ARCHIVOS */
#define PATH_ARCHIVO_TS "./ts.txt"
#define PATH_ARCHIVO_CODIGO_INTERMEDIO "./intermedio.txt"
#define PATH_ARCHIVO_ASSEMBLER "./Final.asm"
#define TEXTO_ESCRITURA "wt"
#define TEXTO_LECTURA "rt"
#define TEXTO_APPEND "at"
#define TEXTO_LECTURA_ESCRITURA "r+"

/* CONSTANTES DE RETORNOS GENERALES */
#define TODO_BIEN 0
#define ERROR 1

/* CONSTANTES DE LISTA */
#define LISTA_LLENA -1
#define LISTA_VACIA -2
#define LISTA_DUPLICADO -3
#define LISTA_NO_EXISTE_ELEMENTO -4

#define PRIMER_ELEMENTO 1
#define SEGUNDO_ELEMENTO 2
#define TERCER_ELEMENTO 1

/* CONSTANTES DE PILA */
#define PILA_LLENA -1
#define PILA_VACIA -2

/* CONSTANTES DE LEXICO */
#define LEXICO_CANTIDAD_COMILLAS 2
#define LEXICO_CANTIDAD_GUIONES_BAJOS 1
#define LEXICO_MAXIMA_CANTIDAD_CARACTERES_STRING 30
#define LEXICO_MAXIMA_CANTIDAD_CARACTERES_REAL 41
#define LEXICO_MAXIMO_VALOR_REAL 3.4e38
#define LEXICO_MAXIMA_CANTIDAD_CARACTERES_ENTERO 5
#define LEXICO_MAXIMO_VALOR_ENTERO 32768

#define LEXICO_TIPO_STRING "String"
#define LEXICO_TIPO_FLOAT "Float"
#define LEXICO_TIPO_INTEGER "Integer"

#define ASCII_0 48
#define ASCII_9 57

#define ASCII_A 65
#define ASCII_Z 90

#define ASCII_a 97
#define ASCII_z 122

/* CONSTANTES DE SEMANTICA */
#define SEMANTICA_MAXIMA_LONGITUD_LISTA_DECLARACION 100

/* CONSTANTES DE TERCETOS */
#define TERCETO_CANTIDAD_CORCHETES 2
#define CANTIDAD_SALTOS_CONTAR 4

#define SIGNO_SUMAR "+"
#define SIGNO_RESTAR "-"
#define SIGNO_DIVISION "/"
#define SIGNO_MULT "*"

#define SIGNO_IGUAL ":="
#define SIGNO_VACIO " "

#define VARIABLE_CANT "@cant"
#define INI_VARIABLE_CANT "0"
#define AUMENTO_VARIABLE_CANT "1"
#define VARIABLE_AUX "@aux"

#define ENTRADA "GET"
#define SALIDA "PUT"
#define ETIQUETA "_ET_"

#define OPERADOR_LE "<"
#define OPERADOR_LEQ "<="
#define OPERADOR_GE	">"
#define OPERADOR_GEQ ">="
#define OPERADOR_NE	"<>"
#define OPERADOR_IGUAL "=="

#define CMP "CMP"

#define BI "BI"
#define BLT "BLT"
#define BLE "BLE"
#define BGT "BGT"
#define BGE "BGE"
#define BEQ "BEQ"
#define BNE "BNE"

#define CANTIDAD_DIGITOS_NUMERO 5

/* CONSTANTES DE ASSEMBLER */

// Cantidad de bits para representación
#define PRECISION_STRING "db"
#define PRECISION_INTEGER "dd"
#define PRECISION_FLOAT "dd"
#define PRECISION_VARIABLE "dd"

// Aritmética
#define CMD_SUMAR "FADD"
#define CMD_RESTAR "FSUB"
#define CMD_DIVIDIR "FDIV"
#define CMD_MULTIPLICAR "FMUL"

// Operaciones con pila
#define CMD_PUSH "FLD"
#define CMD_POP "FSTP"
#define CMD_LIBERAR "FFREE"

#define CMD_XCH "FXCH"

// Operaciones input/output
#define CMD_OUT_FLOAT "DisplayFloat"
#define CMD_OUT_STRING "DisplayString"
#define CMD_NUEVA_LINEA "newline 1"
#define CMD_IN_FLOAT "GetFloat"

// Comparaciones
#define CMD_CMP "FCOM"
#define CMD_STSW "FSTSW AX"
#define CMD_SAHF "SAHF"

#define CMD_BI "JMP"
#define CMD_BLT "JNAE"
#define CMD_BLE "JBE"
#define CMD_BGT "JNBE"
#define CMD_BGE "JNB"
#define CMD_BEQ "JE"
#define CMD_BNE "JNE"

#define CANTIDAD_CORCHETES 2
#define CANTIDAD_DOS_PUNTOS 1

/* CONSTANTES GENERALES */
#define CANTIDAD_ITOA 1000

#endif // CONSTANTES_H_INCLUDED