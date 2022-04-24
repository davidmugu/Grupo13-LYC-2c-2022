%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 30
#define MAX_FLOAT_32 2147483647.0
#define MAX_INT_16 65535

FILE *yyin;
FILE *ptTxt;
int yylval;

void displayError(char* msg);
int yyerror(void);
%}

%option noyywrap
%option yylineno

COMENTARIO_A                "-/"
COMENTARIO_C                "/-"
COMENTARIO                  {COMENTARIO_A}(.)*{COMENTARIO_C}
ESPACIO_EN_BLANCO           [ \s\t\r\v\f]
SALTO_LINEA                 [\n]
NUMERO                      [0-9]
LETRA                       [a-zA-Z]
COMA                        ","
PUNTO_COMA                  ";"
COMILLA                     ["]
CONST_REAL                  {NUMERO}+"."{NUMERO}+|{NUMERO}+"."|"."{NUMERO}+
CONST_INT                   {NUMERO}+
CONST_STRING                {COMILLA}.(.)+.{COMILLA}
TIPO_DATO                   {INT}|{REAL}|{STRING}
PAL_RESERVADA               {WHILE}|{ENDWHILE}|{IF}|{ELSE}|{ENDIF}|{WRITE}|{READ}|{BETWEEN}|{TAKE}|{ENDDEC}|{DECVAR}
INT                         "INT"|"int"|"INTEGER"|"integer"
REAL                        "REAL"|"real"|"FLOAT"|"float"
STRING                      "STRING"|"string"
WHILE                       "while"|"WHILE"
ENDWHILE                    "endwhile"|"ENDWHILE"
IF                          "IF"|"if"
ELSE                        "else"|"ELSE"
ENDIF                       "endif"|"ENDIF"
WRITE                       "WRITE"|"write"
READ                        "READ"|"read"
BETWEEN                     "BETWEEN"|"between"
TAKE                        "TAKE"|"take"
DECVAR                      "DECVAR"|"decvar"
ENDDEC                      "ENDDEC"|"enddec"
VARIABLE                    {LETRA}({LETRA}|{NUMERO}|"_")*|{LETRA}
CORCHETE_A                  "["
CORCHETE_C                  "]"
PARENTESIS_A                "("
PARENTESIS_C                ")"
LLAVE_A                     "{"
LLAVE_C                     "}"
OP_AND                      "&&"|"AND"
OP_OR                       "||"|"OR"
OP_NOT                      "!"|"NOT"
OP_ASIG                     ":="
OP_IGUAL                    "="
OP_SUMA                     "+"
OP_RESTA                    "-"
OP_MENOR                    "<"
OP_MAYOR                    ">"
OP_COMP                     "=="
OP_MULT                     "*"
OP_DIV                      "/"
OP_MEN_IGU                  {OP_MENOR}{OP_IGUAL}
OP_MAY_IGU                  {OP_MAYOR}{OP_IGUAL}

%%

{COMENTARIO_A}              {;}
{COMENTARIO_C}              {;}
{COMENTARIO}                {;}
{OP_OR}                     {return OP_OR;}
{OP_AND}                    {return OP_AND;}
{OP_NOT}                    {return OP_NOT;}
{ESPACIO_EN_BLANCO}         {;}
{SALTO_LINEA}               {;}
{TIPO_DATO}                 {return TIPO_DATO;}
{PAL_RESERVADA}             {return PAL_RESERVADA;}
{VARIABLE}                  {
                            //  yylval.strVal = strdup(yytext);
                                {return VARIABLE;}
                            }
{COMA}                      {return COMA;}
{PUNTO_COMA}                {return PUNTO_COMA;}
{CONST_REAL}                {
                                float value = atof(strdup(yytext));
                                if ( value > MAX_FLOAT_32 ) {
                                    displayError("Numero real supera los 32 bits");
                                } else {
                                //  yylval.strVal = strdup(yytext);
                                    {return CONST_REAL;}
                                }
                            }
{CONST_INT}                 {
                                int value = atoi(strdup(yytext));
                                if( value > MAX_INT_16 ) {
                                    displayError("Entero supera los 16 bits");
                                } else {
                                //    yylval.strVal = strdup(yytext);
                                    {return CONST_INT;}
                                }
                            }
{CONST_STRING}              {
                                if(strlen(yytext) > MAX_CHARACTERS) {
                                    displayError("Constante String supera el maximo de caracteres permitido");
                                } else {
                                //    yylval.strVal = strdup(yytext);
                                    {return CONST_STRING;}
                                }
                            }
{INT}                       {return INT;}
{REAL}                      {return REAL;}
{STRING}                    {return STRING;}
{WHILE}                     {return WHILE;}
{ENDWHILE}                  {return ENDWHILE;}
{IF}                        {return IF;}
{ELSE}                      {return ELSE;}
{ENDIF}                     {return ENDIF;}
{WRITE}                     {return WRITE;}
{READ}                      {return READ;}
{BETWEEN}                   {return BETWEEN;}
{TAKE}                      {return TAKE;}
{DECVAR}                    {return DECVAR;}
{ENDDEC}                    {return ENDDEC;}
{CORCHETE_A}                {return CORCHETE_A;}
{CORCHETE_C}                {return CORCHETE_C;}
{PARENTESIS_A}              {return PARENTESIS_A;}
{PARENTESIS_C}              {return PARENTESIS_C;}
{LLAVE_A}                   {return LLAVE_A;}
{LLAVE_C}                   {return LLAVE_C;}
{OP_ASIG}                   {return OP_ASIG;}
{OP_IGUAL}                  {return OP_IGUAL;}
{OP_SUMA}                   {return OP_SUMA;}
{OP_RESTA}                  {return OP_RESTA;}
{OP_MENOR}                  {return OP_MENOR;}
{OP_MAYOR}                  {return OP_MAYOR;}
{OP_COMP}                   {return OP_COMP;}
{OP_MULT}                   {return OP_MULT;}
{OP_DIV}                    {return OP_DIV;}
{OP_MEN_IGU}                {return OP_MEN_IGU;}
{OP_MAY_IGU}                {return OP_MAY_IGU;}
.                           {displayError("Error en Lexico - Token no valido");}        

%%

void displayError(char* msg) {
    printf("%s - linea del archivo analizado: %d\n", msg, yylineno); 
}

int yyerror(void) {
	printf("Error en analizador sintactico en la linea del archivo analizado: %d\n", yylineno);
}