%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "y.tab.h"

#define MAX_CHARACTERS 30
#define MAX_FLOAT_32 2147483647
#define MAX_INT_16 65536

FILE *yyin;
FILE *ptTxt;

void displayError(char* msg);
int yyerror(void);


%}

%option noyywrap
%option yylineno

COMENTARIO_A        "-/"
COMENTARIO_C        "/-"
COMENTARIO          {COMENTARIO_A}(.)*{COMENTARIO_C}
OP_AND              "&&"|"AND"
OP_OR               "||"|"OR"
OP_NOT              "!"
ESPACIO_EN_BLANCO   [ \t\r\v\f]
SALTO_LINEA         [\n]
NUMERO              [0-9]
LETRA               [a-zA-Z]
VARIABLE            {LETRA}({LETRA}|{NUMERO}|"_")*
COMA                ","
PUNTO_COMA          ";"
COMILLA             ["]
CONST_REAL          {NUMERO}+"."{NUMERO}+|{NUMERO}+"."|"."{NUMERO}+
CONST_INT           {NUMERO}+
CONST_STRING        {COMILLA}.(.)+.{COMILLA}
INT                 "INT"|"int"|"INTEGER"|"integer"
REAL                "REAL"|"real"|"FLOAT"|"float"
STRING              "STRING"|"string"
WHILE               "while"|"WHILE"
ENDWHILE            "endwhile"|"ENDWHILE"
IF                  "IF"|"if"
ELSE                "else"|"ELSE"
ENDIF               "endif"|"ENDIF"
WRITE               "WRITE"|"write"
READ                "READ"|"read"
BETWEEN             "BETWEEN"|"between"
TAKE                "TAKE"|"take"
DECVAR              "DECVAR"|"decvar"
ENDDEC              "ENDDEC"|"enddec"
CORCHETE_A          "["
CORCHETE_C          "]"
PARENTESIS_A        "("
PARENTESIS_C        ")"
OP_ASIG             ":="
OP_SUMA             "+"
OP_RESTA            "-"
OP_MENOR            "<"
OP_MAYOR            ">"
OP_COMP             "=="
OP_MULT             "*"
OP_DIV              "/"
OP_MEN_IGU          {OP_MENOR}{OP_ASIG}
OP_MAY_IGU          {OP_MAYOR}{OP_ASIG}

%%

{COMENTARIO_A}            {;}
{COMENTARIO_C}            {;}
{COMENTARIO}              {;}
{OP_AND}                  {return OP_AND;}      
{OP_OR}                   {return OP_OR;}     
{OP_NOT}                  {return OP_NOT;}
{ESPACIO_EN_BLANCO}       {;} 
{SALTO_LINEA}             {;} 
{VARIABLE}                {
                            yylval.strVal = strdup(yytext);
                            return VARIABLE;
                          }
{COMA}                    {return COMA;}      
{PUNTO_COMA}              {return PUNTO_COMA;}
{CONST_REAL}                 {  
                                float value = atof(strdup(yytext));
                                if ( value > MAX_FLOAT_32 ) 
                                {
                                    displayError("Numero real supera los 32 bits");
                                } 
                                else 
                                {
                                     yylval.strVal = strdup(yytext);
                                     return CONST_REAL;
                                }
                            }
{CONST_INT}                 {   
                                int value = atoi(strdup(yytext));
                                // printf("Valor entero: %d, Valor de MAX_INT_16: %d", value, MAX_INT_16);
                                if( value > MAX_INT_16 ) {
                                    displayError("Entero supera los 16 bits");
                                } else {
                                     yylval.strVal = strdup(yytext);
                                     return CONST_INT;
                                }
                            }
{CONST_STRING}            {
                            if(strlen(yytext) > 30)
                            {
                                    displayError("Constante String supera el maximo de caracteres permitido");
                            } 
                            else 
                                {
                                    yylval.strVal = strdup(yytext);
                                    return CONST_STRING;
                                }

                          }
{INT}                     {return INT;} 
{REAL}                    {return REAL;}      
{STRING}                  {return STRING;}
{WHILE}                   {return WHILE;}             
{ENDWHILE}                {return ENDWHILE;}  
{IF}                      {return IF;}        
{ELSE}                    {return ELSE;}      
{ENDIF}                   {return ENDIF;} 
{WRITE}                   {return WRITE;}
{READ}                    {return READ;} 
{CORCHETE_A}              {return CORCHETE_A;}  
{CORCHETE_C}              {return CORCHETE_C;}  
{PARENTESIS_A}            {return PARENTESIS_A;}    
{PARENTESIS_C}            {return PARENTESIS_C;}     
{OP_ASIG}                 {return OP_ASIG;}   
{OP_SUMA}                 {return OP_SUMA;}    
{OP_RESTA}                {return OP_RESTA;}
{OP_MENOR}                {return OP_MENOR;}      
{OP_MAYOR}                {return OP_MAYOR;}
{OP_COMP}                 {return OP_COMP;}    
{OP_MULT}                 {return OP_MULT;}   
{OP_DIV}                  {return OP_DIV;}         
{OP_MEN_IGU}              {return OP_MEN_IGU;}  
{OP_MAY_IGU}              {return OP_MAY_IGU;}          
.                          {displayError("Error en Lexico - Token no valido");} 

%%

int main(int argc,char *argv[])
{ 
  crearPila(&pilaExpresion);
  crearPila(&pilaOperadoresCond);
  crearPila(&pilaTermino);
  crearPila(&pilaFactor);
  crearPila(&pilaPrograma);
  crearPila(&pilaCondicion);

  cuentaRegs=0;
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	  printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
    return 1;
  }
  if((tab = fopen("ts.txt", "wt")) == NULL)
      {
        printf("\nNo se puedo crear el archivo tabla_de_simbolos.bin\n");
      return 1;
      }
  yyparse();
  vaciarPila(&pilaExpresion);
  vaciarPila(&pilaOperadoresCond);
  vaciarPila(&pilaTermino);
  vaciarPila(&pilaFactor);
  vaciarPila(&pilaPrograma);
  vaciarPila(&pilaCondicion);
  fclose(yyin);
  return 0;
}
void displayError(char* msg)
{
    printf("%s - linea del archivo analizado: %d\n", msg, yylineno); 
    system("Pause");
    exit(1);
}

int yyerror(void){

	printf("Error en analizador sintactico en la linea del archivo analizado: %d\n", yylineno);
	system("Pause");
	exit(1);
}