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
{OP_OR}                     {fprintf(ptTxt,"OP_OR %s\n",yytext);}
{OP_AND}                    {fprintf(ptTxt,"OP_AND %s\n",yytext);}
{OP_NOT}                    {fprintf(ptTxt,"OP_NOT %s\n",yytext);}
{ESPACIO_EN_BLANCO}         {;}
{SALTO_LINEA}               {fprintf(ptTxt,"\n",yytext);}
{TIPO_DATO}                 {fprintf(ptTxt,"TIPO_DATO %s\n",yytext);}
{PAL_RESERVADA}             {fprintf(ptTxt,"PAL_RESERVADA %s\n",yytext);}
{VARIABLE}                  {
                            //  yylval.strVal = strdup(yytext);
                                fprintf(ptTxt,"VARIABLE %s\n",yytext);
                            }
{COMA}                      {fprintf(ptTxt,"COMA %s\n",yytext);}
{PUNTO_COMA}                {fprintf(ptTxt,"PUNTO_COMA %s\n",yytext);}
{CONST_REAL}                {
                                float value = atof(strdup(yytext));
                                if ( value > MAX_FLOAT_32 ) {
                                    fprintf(ptTxt,"Numero real supera los 32 bits: %s\n",yytext);
                                    displayError("Numero real supera los 32 bits");
                                } else {
                                //  yylval.strVal = strdup(yytext);
                                    fprintf(ptTxt,"CONST_REAL %s\n",yytext);
                                }
                            }
{CONST_INT}                 {
                                int value = atoi(strdup(yytext));
                                if( value > MAX_INT_16 ) {
                                    fprintf(ptTxt,"Entero supera los 16 bits: %s\n",yytext);
                                    displayError("Entero supera los 16 bits");
                                } else {
                                //    yylval.strVal = strdup(yytext);
                                    fprintf(ptTxt,"CONST_INT %s\n",yytext);
                                }
                            }
{CONST_STRING}              {
                                if(strlen(yytext) > MAX_CHARACTERS) {
                                    fprintf(ptTxt,"Constante String supera el maximo de caracteres permitido: %s\n",yytext);
                                    displayError("Constante String supera el maximo de caracteres permitido");
                                } else {
                                //    yylval.strVal = strdup(yytext);
                                    fprintf(ptTxt,"CONST_STRING %s\n",yytext);
                                }
                            }
{INT}                       {fprintf(ptTxt,"INT %s\n",yytext);}
{REAL}                      {fprintf(ptTxt,"REAL %s\n",yytext);}
{STRING}                    {fprintf(ptTxt,"STRING %s\n",yytext);}
{WHILE}                     {fprintf(ptTxt,"WHILE %s\n",yytext);}
{ENDWHILE}                  {fprintf(ptTxt,"ENDWHILE %s\n",yytext);}
{IF}                        {fprintf(ptTxt,"IF %s\n",yytext);}
{ELSE}                      {fprintf(ptTxt,"ELSE %s\n",yytext);}
{ENDIF}                     {fprintf(ptTxt,"ENDIF %s\n",yytext);}
{WRITE}                     {fprintf(ptTxt,"WRITE %s\n",yytext);}
{READ}                      {fprintf(ptTxt,"READ %s\n",yytext);}
{BETWEEN}                   {fprintf(ptTxt,"BETWEEN %s\n",yytext);}
{TAKE}                      {fprintf(ptTxt,"TAKE %s\n",yytext);}
{DECVAR}                    {fprintf(ptTxt,"DECVAR %s\n",yytext);}
{ENDDEC}                    {fprintf(ptTxt,"ENDDEC %s\n",yytext);}
{CORCHETE_A}                {fprintf(ptTxt,"CORCHETE_A %s\n",yytext);}
{CORCHETE_C}                {fprintf(ptTxt,"CORCHETE_C %s\n",yytext);}
{PARENTESIS_A}              {fprintf(ptTxt,"PARENTESIS_A %s\n",yytext);}
{PARENTESIS_C}              {fprintf(ptTxt,"PARENTESIS_C %s\n",yytext);}
{LLAVE_A}                   {fprintf(ptTxt,"LLAVE_A %s\n",yytext);}
{LLAVE_C}                   {fprintf(ptTxt,"LLAVE_C %s\n",yytext);}
{OP_ASIG}                   {fprintf(ptTxt,"OP_ASIG %s\n",yytext);}
{OP_IGUAL}                  {fprintf(ptTxt,"OP_IGUAL %s\n",yytext);}
{OP_SUMA}                   {fprintf(ptTxt,"OP_SUMA %s\n",yytext);}
{OP_RESTA}                  {fprintf(ptTxt,"OP_RESTA %s\n",yytext);}
{OP_MENOR}                  {fprintf(ptTxt,"OP_MENOR %s\n",yytext);}
{OP_MAYOR}                  {fprintf(ptTxt,"OP_MAYOR %s\n",yytext);}
{OP_COMP}                   {fprintf(ptTxt,"OP_COMP %s\n",yytext);}
{OP_MULT}                   {fprintf(ptTxt,"OP_MULT %s\n",yytext);}
{OP_DIV}                    {fprintf(ptTxt,"OP_DIV %s\n",yytext);}
{OP_MEN_IGU}                {fprintf(ptTxt,"OP_MEN_IGU %s\n",yytext);}
{OP_MAY_IGU}                {fprintf(ptTxt,"OP_MAY_IGU %s\n",yytext);}
.                           {
                                fprintf(ptTxt,"Error en Lexico - Token no valido %s\n",yytext);
                                displayError("Error en Lexico - Token no valido");
                            }        

%%

int main(int argc,char *argv[]) {
    if ((yyin = fopen(argv[1], "rt")) == NULL) {
        printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
    } else {
        ptTxt = fopen("Salida.txt", "wt");
        yylex();
    }
    fclose(yyin);
    fclose(ptTxt);
}

void displayError(char* msg) {
    printf("%s - linea del archivo analizado: %d\n", msg, yylineno); 
    system("Pause");
    exit(1);
}

int yyerror(void) {
	printf("Error en analizador sintactico en la linea del archivo analizado: %d\n", yylineno);
	system("Pause");
	exit(1);
}