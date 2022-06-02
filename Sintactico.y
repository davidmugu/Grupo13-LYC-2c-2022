%{
#include "lista.h"
#include "pila.h"
#include "y.tab.h"

FILE *yyin;

Lista tablaSimbolos;
Pila pilaVariables;
Pila pilaTiposDatos;

extern int yylex();
extern void yyerror();
extern char* yytext;
extern int yylineno;

%}

%union{
    char* strVal;
}

%token  WHILE
%token  ENDWHILE
%token  IF
%token  ELSE
%token  ENDIF
%token  WRITE
%token	READ
%token	BETWEEN
%token	TAKE
%token	DECVAR
%token	ENDDEC
%token  INT         
%token  REAL       
%token  STRING
%token  CORCHETE_A 
%token  CORCHETE_C
%token  LLAVE_A
%token  LLAVE_C
%token  PARENTESIS_A    
%token  PARENTESIS_C   
%token  COMA      
%token  PUNTO_COMA 
%token  DOS_PUNTOS
%token  OP_MENOR      
%token  OP_MAYOR       
%token  OP_MEN_IGU
%token  OP_MAY_IGU 
%token  OP_NOT       
%token  OP_AND      
%token  OP_OR    
%token  OP_COMP
%token  OP_IGUAL
%token  <strVal>CONST_INT
%token  <strVal>CONST_REAL
%token  <strVal>CONST_STRING 
%token  <strVal>VARIABLE    
%token  COMENTARIO_A
%token  COMENTARIO_C
%token  COMENTARIO
%token  .

%left  OP_RESTA OP_SUMA
%right OP_MULT OP_DIV
%right OP_ASIG   

%%

programa:             prog                                  {printf("Regla - Programa \n");}             
        ;

prog:                 sentencia                             {printf("Regla - Prog\n");}
    ;

sentencia:            sentencia grammar PUNTO_COMA          {printf("Regla - Sentencia Recursiva\n");}
         |            grammar PUNTO_COMA                    {printf("Regla - Sentencia Corte\n");}
         ;

grammar:              dec_var                               {printf("Regla - Sentencia de DEC_VAR\n");}
       |              asig                                  {printf("Regla - Sentencia de ASIG\n");}
       |              if                                    {printf("Regla - Sentencia de IF\n");}
       |              while                                 {printf("Regla - Sentencia de WHILE\n");}
       |              between                               {printf("Regla - Sentencia de BETWEEN\n");}
       |              take                                  {printf("Regla - Sentencia de TAKE\n");}
       |              write                                 {printf("Regla - Sentencia de WRITE\n");}
       |              read                                  {printf("Regla - Sentencia de READ\n");}
       ;

dec_var:              DECVAR declaraciones ENDDEC           {printf("Regla - Sentencia de Declaracion de Variables\n");} 
       ;

declaraciones:        lista_var DOS_PUNTOS tipo_dato                      {;}
             |        lista_var DOS_PUNTOS tipo_dato declaraciones        {;}
             ;

lista_var:           lista_var COMA VARIABLE                {apilar(&pilaVariables, $3);}    
         |           VARIABLE                               {apilar(&pilaVariables, $1);}                                                  
         ;
tipo_dato:            INT                                   {while(!pilaVacia(&pilaVariables)) {
                                                             char variable[100];
                                                             desapilar(&pilaVariables, variable);
                                                             insertarVariable(&tablaSimbolos, variable, "INT");
                                                             }}
         |            REAL                                  {while(!pilaVacia(&pilaVariables)) {
                                                             char variable[100];
                                                             desapilar(&pilaVariables, variable);
                                                             insertarVariable(&tablaSimbolos, variable, "REAL");
                                                             }}
         |            STRING                                {while(!pilaVacia(&pilaVariables)) {
                                                             char variable[100];
                                                             desapilar(&pilaVariables, variable);
                                                             insertarVariable(&tablaSimbolos, variable, "STRING");
                                                             }}                                                      
         ;

asig:                 VARIABLE OP_ASIG expresion            {printf("Regla - Sentencia de Asignacion por Expresion\n");} 
    |                 VARIABLE OP_ASIG CONST_STRING         {printf("Regla - Sentencia de Asignacion por String\n");insertarString(&tablaSimbolos, $3);} 
    ;

between:              BETWEEN PARENTESIS_A VARIABLE COMA CORCHETE_A expresion PUNTO_COMA expresion CORCHETE_C PARENTESIS_C        {printf("Regla - Sentencia de Between\n");}  
       ;

take:                 TAKE PARENTESIS_A operador_algebraico PUNTO_COMA CONST_INT PUNTO_COMA CORCHETE_A lista_cte CORCHETE_C PARENTESIS_C        {printf("Regla - Sentencia de Take con Lista de Constantes\n");insertarEntero(&tablaSimbolos, $5);} 
    |                 TAKE PARENTESIS_A operador_algebraico PUNTO_COMA CONST_INT PUNTO_COMA CORCHETE_A CORCHETE_C PARENTESIS_C                  {printf("Regla - Sentencia de Take sin Lista de Constantes\n");insertarEntero(&tablaSimbolos, $5);}   
    ;

lista_cte:            CONST_INT                                   {printf("Regla - CTE INT\n");insertarEntero(&tablaSimbolos, $1);}
         |            CONST_REAL                                  {printf("Regla - CTE REAL\n");insertarReal(&tablaSimbolos, $1);}
         |            lista_cte PUNTO_COMA CONST_INT              {printf("Regla - Lista CTE INT\n");insertarEntero(&tablaSimbolos, $3);}
         |            lista_cte PUNTO_COMA CONST_REAL             {printf("Regla - Lista CTE REAL");insertarReal(&tablaSimbolos, $3);}
         ;            

write:                WRITE VARIABLE                        {printf("Regla - Sentencia de Write: VARIABLE\n");}   
     |                WRITE CONST_STRING                    {printf("Regla - Sentencia de Write: CONST_STRING"); insertarString(&tablaSimbolos, $2);}
     |                WRITE CONST_INT                      {printf("Regla - Sentencia de Write: CONST_INT\n"); insertarEntero(&tablaSimbolos, $2);}
     ; 

read:                 READ VARIABLE                         {printf("Regla - Sentencia de Read: VARIABLE\n");}              
    ;

while:                WHILE condicion LLAVE_A sentencia LLAVE_C ENDWHILE          {printf("Regla - Sentencia de While\n");}
     ;

if:                   IF condicion LLAVE_A sentencia LLAVE_C ENDIF                                                      {printf("Regla - Sentencia de if sin else\n");}
  |                   IF condicion LLAVE_A sentencia LLAVE_C ELSE LLAVE_A sentencia LLAVE_C ENDIF                       {printf("Regla - Sentencia de if con else\n");}
  |                   IF condicion LLAVE_A sentencia LLAVE_C ELSE condicion LLAVE_A sentencia LLAVE_C ENDIF             {printf("Regla - Sentencia de if con else (mas condicion)\n");}
  ;            

expresion:            expresion OP_SUMA termino           {printf("Regla - Sentencia de suma\n");}
	       |            expresion OP_RESTA termino          {printf("Regla - Sentencia de resta\n");} 
	       |            termino                             {printf("Regla - Expresion <- Termino\n");}
         ;

termino:              termino OP_MULT factor              {printf("Regla - Sentencia de multiplicacion\n");}
	     |              termino OP_DIV factor               {printf("Regla - Sentencia de division\n");}
	     |              factor                              {printf("Regla - Termino <- Factor\n");}
       ;

                    
factor:               PARENTESIS_A expresion PARENTESIS_C   {printf("Regla - Factor\n");}
      |               CONST_INT                             {printf("Regla - Constante Entera\n");insertarEntero(&tablaSimbolos, $1);}
      |               CONST_REAL                            {printf("Regla - Constante Real\n");insertarReal(&tablaSimbolos, $1);}
	  |               VARIABLE                              {printf("Regla - Variable\n");}
      ;

cond_simple:          expresion OP_COMP expresion           {printf("Comparacion Igual\n");}
           |          expresion OP_MAY_IGU expresion        {printf("Comparacion Mayor-Igual\n");}
           |          expresion OP_MEN_IGU expresion        {printf("Comparacion Menor-Igual\n");}
           |          expresion OP_MAYOR expresion          {printf("Comparacion Mayor\n");}
           |          expresion OP_MENOR expresion          {printf("Comparacion Menor\n");}
           |          expresion OP_NOT expresion            {printf("Comparacion Distinto\n");}
           ;

condicion:            PARENTESIS_A cond_simple PARENTESIS_C                           {printf("Regla - Condicion");}
         |            PARENTESIS_A cond_simple OP_AND cond_simple PARENTESIS_C        {printf("Regla - Comparacion AND\n");}
         |            PARENTESIS_A cond_simple OP_OR cond_simple PARENTESIS_C         {printf("Regla Comparacion OR\n");}
         ;

operador_algebraico:  OP_SUMA                               {printf("Operador Suma\n");}
                   |  OP_RESTA                              {printf("Operador Resta\n");}
                   |  OP_DIV                                {printf("Operador Division\n");}
                   |  OP_MULT                               {printf("Operador Multiplicacion\n");}
                   ;
 
%%


int main(int argc, char* argv[])
{
    if((yyin = fopen(argv[1],"rt")) == NULL)
    {
        printf("\n No se puede abrir el archivo %s \n", argv[1]);
    }

    printf("\n Compilando... \n\n");

    printf("Se procede a crear la Tabla de Simbolos\n");
    crearLista(&tablaSimbolos);
    printf("La Tabla de Simbolos se creo correctamente\n");
    printf("Se procede a crear la Pila de Variables\n");
    crearPila(&pilaVariables);
    printf("La Pila de Variables se creo correctamente\n");
    printf("Se procede a crear la Pila de Tipos de Datos\n");
    crearPila(&pilaTiposDatos);
    printf("La Pila de Tipos de Datos se creo correctamente\n\n");

    yyparse();

    printf("\n\nSe procede a eliminar la Tabla de Simbolos\n");
    eliminarTabla(&tablaSimbolos);
    printf("La Tabla de Simbolos se elimino correctamente\n");
    
    printf("\n Compilacion exitosa \n");
    fclose(yyin);
    return 0;
}