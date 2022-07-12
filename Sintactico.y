%{
#include "lista.h"
#include "pila.h"
#include "tercetos.h"
#include "y.tab.h"
#include "gci.h"
#include "assem.h"
#include "constantes.h"

FILE *yyin;

Lista tablaSimbolos;
Pila pilaVariables;//Pila pilaVariables;
Pila pilaTiposDatos;//Pila pilaTiposDatos;

/* VARIABLES PARA GCI */

int numeracion_terceto;
char aux[1000];
int aux_indice;

int programa_ind, prog_ind, sentencia_ind, grammar_ind, dec_var_ind, declaraciones_ind, lista_var_ind, tipo_dato_ind, asig_ind, between_ind, take_ind,
lista_cte_ind, write_ind, read_ind, while_ind, if_ind, expresion_ind, termino_ind, factor_ind, cond_simple_ind, condicion_ind, operador_algebraico_ind, auxiliar_ind;


/**/
Pila pila_termino, pila_expresion;
int contador_t, contador_e, recuperar_puntero, es_nuevo_token;
t_lista_tercetos lista_tercetos;
Pila pila_condicion, pila_cantidad_desapilar;
char *operador_comparacion;

/*-------------------*/

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

        
programa:             prog                                  {generar_assembler("Final.asm", &lista_tercetos, &tablaSimbolos);programa_ind = prog_ind; printf("Regla - Programa \n");}   //          
        ;
prog:                 sentencia                             {prog_ind = sentencia_ind; printf("Regla - Prog\n");} //
    ;

sentencia:            sentencia grammar PUNTO_COMA          {sentencia_ind = crear_terceto(transformar_indice(sentencia_ind),transformar_indice(grammar_ind),SIGNO_VACIO,&numeracion_terceto, &lista_tercetos); printf("Regla - Sentencia Recursiva\n");}
         |            grammar PUNTO_COMA                    {sentencia_ind = grammar_ind; printf("Regla - Sentencia Corte\n");}
         ;

grammar:              dec_var                               {grammar_ind = dec_var_ind; printf("Regla - Sentencia de DEC_VAR\n");}
       |              asig                                  {grammar_ind = asig_ind; printf("Regla - Sentencia de ASIG\n");}
       |              if                                    {grammar_ind = if_ind; printf("Regla - Sentencia de IF\n");}
       |              while                                 {grammar_ind = while_ind; printf("Regla - Sentencia de WHILE\n");}
       |              between                               {grammar_ind = between_ind; printf("Regla - Sentencia de BETWEEN\n");}
       |              take                                  {grammar_ind = take_ind; printf("Regla - Sentencia de TAKE\n");}
       |              write                                 {grammar_ind = write_ind; printf("Regla - Sentencia de WRITE\n");}
       |              read                                  {grammar_ind = read_ind; printf("Regla - Sentencia de READ\n");}
       ;

dec_var:              DECVAR declaraciones ENDDEC           {printf("Regla - Sentencia de Declaracion de Variables\n");} 
       ;

declaraciones:        lista_var DOS_PUNTOS tipo_dato                      {printf("Regla - Declaraciones corte\n");}
             |        lista_var DOS_PUNTOS tipo_dato declaraciones        {printf("Regla - Declaraciones iteracion\n");}
             ;

lista_var:           lista_var COMA VARIABLE                {printf("Regla - lista variables iteracion\n");apilar(&pilaVariables,$3);}   
         |           VARIABLE                               {printf("Regla - lista de variables corte\n");apilar(&pilaVariables, $1);}                                                  
         ;
tipo_dato:            INT                                   {printf("Regla - tipo de dato INT\n");while(!pilaVacia(&pilaVariables)) {
                                                             char variable[100];
                                                             desapilar(&pilaVariables, variable);
                                                             insertarVariable(&tablaSimbolos, variable, "INT");
                                                             }}
         |            REAL                                  {printf("Regla - tipo de dato REAL\n");while(!pilaVacia(&pilaVariables)) {
                                                             char variable[100];
                                                             desapilar(&pilaVariables, variable);
                                                             insertarVariable(&tablaSimbolos, variable, "REAL");
                                                             }}
         |            STRING                                {printf("Regla - tipo de dato STRING\n");while(!pilaVacia(&pilaVariables)) {
                                                             char variable[100];
                                                             desapilar(&pilaVariables, variable);
                                                             insertarVariable(&tablaSimbolos, variable, "STRING");
                                                             }}                                                      
         ;

asig:                 VARIABLE OP_ASIG expresion            {asig_ind = crear_terceto(SIGNO_IGUAL,$1,transformar_indice(expresion_ind),&numeracion_terceto, &lista_tercetos);printf("Regla - Sentencia de Asignacion por Expresion\n");} 
    |                 VARIABLE OP_ASIG CONST_STRING         {asig_ind = crear_terceto(SIGNO_IGUAL, $1, $3, &numeracion_terceto, &lista_tercetos); printf("Regla - Sentencia de Asignacion por String\n");insertarString(&tablaSimbolos, $3);} 
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

write:                WRITE VARIABLE                        {write_ind = crear_terceto(FUNCION_WRITE, $2, SIGNO_VACIO, &numeracion_terceto, &lista_tercetos); printf("Regla - Sentencia de Write: VARIABLE\n");}   
     |                WRITE CONST_STRING                    {write_ind = crear_terceto(FUNCION_WRITE, $2, SIGNO_VACIO, &numeracion_terceto, &lista_tercetos); printf("Regla - Sentencia de Write: CONST_STRING"); insertarString(&tablaSimbolos, $2);}
     |                WRITE CONST_INT                      {write_ind = crear_terceto(FUNCION_WRITE, $2, SIGNO_VACIO, &numeracion_terceto, &lista_tercetos); printf("Regla - Sentencia de Write: CONST_INT\n"); insertarEntero(&tablaSimbolos, $2);}
     ; 

read:                 READ VARIABLE                         { read_ind = crear_terceto(FUNCION_READ,$2,SIGNO_VACIO, &numeracion_terceto, &lista_tercetos);printf("Regla - Sentencia de Read: VARIABLE\n");}              
    ;

while:                WHILE {

char num_terceto_pun;
crear_terceto(crear_etiqueta(numeracion_terceto), SIGNO_VACIO, SIGNO_VACIO, &numeracion_terceto, &lista_tercetos);
num_terceto_pun = numeracion_terceto+0;
apilar(&pila_condicion, &num_terceto_pun);

}
condicion LLAVE_A sentencia LLAVE_C ENDWHILE          {
    
    char aux, cant_desapilar, i;
    desapilar(&pila_condicion, &cant_desapilar);
    for(i = 0; i < cant_desapilar; i++)
    {
        desapilar(&pila_condicion, &aux);
        cambiar_elemento(&lista_tercetos, aux, transformar_indice(numeracion_terceto + 2), SEGUNDO_ELEMENTO);
    }
    
    desapilar(&pila_condicion, &aux);
	crear_terceto(BI, transformar_indice(aux), SIGNO_VACIO, &numeracion_terceto, &lista_tercetos);
	crear_terceto(crear_etiqueta(numeracion_terceto), SIGNO_VACIO, SIGNO_VACIO, &numeracion_terceto, &lista_tercetos);
	while_ind = numeracion_terceto;

    printf("Regla - Sentencia de While\n");}
     ;

if:  IF condicion LLAVE_A sentencia LLAVE_C ENDIF {
    
	int i;
    char cantidad_desapilar, auxiliar;
	desapilar(&pila_cantidad_desapilar, &cantidad_desapilar);
	for(i = 0; i < cantidad_desapilar; i++)
	{
		desapilar(&pila_condicion, &auxiliar);
		cambiar_elemento(&lista_tercetos, auxiliar, transformar_indice(numeracion_terceto + 1), SEGUNDO_ELEMENTO);	
	}
	crear_terceto(crear_etiqueta(numeracion_terceto), SIGNO_VACIO, SIGNO_VACIO, &numeracion_terceto, &lista_tercetos);
	if_ind = numeracion_terceto;

    printf("Regla - Sentencia de if sin else\n");}
  |                   IF condicion LLAVE_A sentencia LLAVE_C ELSE LLAVE_A sentencia LLAVE_C ENDIF                       {printf("Regla - Sentencia de if con else\n");}
  |                   IF condicion LLAVE_A sentencia LLAVE_C ELSE condicion LLAVE_A sentencia LLAVE_C ENDIF             {printf("Regla - Sentencia de if con else (mas condicion)\n");}
  ;            

expresion:            expresion OP_SUMA termino           {expresion_ind = crear_terceto(SIGNO_SUMAR, transformar_indice(expresion_ind), transformar_indice(termino_ind), &numeracion_terceto, &lista_tercetos); printf("Regla - Sentencia de suma\n");}
	       |            expresion OP_RESTA termino          {expresion_ind = crear_terceto(SIGNO_RESTAR, transformar_indice(expresion_ind), transformar_indice(termino_ind), &numeracion_terceto, &lista_tercetos); printf("Regla - Sentencia de resta\n");} 
	       |            termino                             {expresion_ind = termino_ind;printf("Regla - Expresion <- Termino\n");}
         ;

termino:              termino OP_MULT factor              {termino_ind = crear_terceto(SIGNO_MULT, transformar_indice(termino_ind), transformar_indice(factor_ind), &numeracion_terceto, &lista_tercetos); printf("Regla - Sentencia de multiplicacion\n");}
	     |              termino OP_DIV factor               {termino_ind = crear_terceto(SIGNO_DIVISION, transformar_indice(termino_ind), transformar_indice(factor_ind), &numeracion_terceto, &lista_tercetos) ;printf("Regla - Sentencia de division\n");}
	     |              factor                              {termino_ind = factor_ind;printf("Regla - Termino <- Factor\n");}
       ;

                    
factor:               PARENTESIS_A expresion PARENTESIS_C   {factor_ind = expresion_ind; printf("Regla - Factor\n");}
      |               CONST_INT                             {factor_ind = crear_terceto($1,SIGNO_VACIO,SIGNO_VACIO,&numeracion_terceto,&lista_tercetos);printf("Regla - Constante Entera\n");insertarEntero(&tablaSimbolos, $1);}
      |               CONST_REAL                            {factor_ind = crear_terceto($1,SIGNO_VACIO,SIGNO_VACIO,&numeracion_terceto,&lista_tercetos);printf("Regla - Constante Real\n");insertarReal(&tablaSimbolos, $1);}
	  |               VARIABLE                              {factor_ind = crear_terceto($1,SIGNO_VACIO,SIGNO_VACIO,&numeracion_terceto,&lista_tercetos);printf("Regla - Variable\n");}
      ;

condicion:            PARENTESIS_A cond_simple PARENTESIS_C                           {condicion_ind = cond_simple_ind; printf("Regla - Condicion");}
         |            PARENTESIS_A cond_simple OP_AND cond_simple PARENTESIS_C        {printf("Regla - Comparacion AND\n");}
         |            PARENTESIS_A cond_simple OP_OR cond_simple PARENTESIS_C         {printf("Regla Comparacion OR\n");}
         ;

cond_simple:          expresion {auxiliar_ind = expresion_ind;} OP_COMP expresion           {crear_terceto(CMP, transformar_indice(auxiliar_ind), transformar_indice(expresion_ind), &numeracion_terceto, &lista_tercetos);expresion_ind=crear_terceto(obtener_branch(OP_COMP_), SIGNO_VACIO, SIGNO_VACIO, &numeracion_terceto, &lista_tercetos); printf("Comparacion Igual\n");}
           |          expresion {auxiliar_ind = expresion_ind;} OP_MAY_IGU expresion        {crear_terceto(CMP, transformar_indice(auxiliar_ind), transformar_indice(expresion_ind), &numeracion_terceto, &lista_tercetos);expresion_ind=crear_terceto(obtener_branch(OP_MAY_IGU_), SIGNO_VACIO, SIGNO_VACIO, &numeracion_terceto, &lista_tercetos); printf("Comparacion Igual\n");printf("Comparacion Mayor-Igual\n");}
           |          expresion {auxiliar_ind = expresion_ind;} OP_MEN_IGU expresion        {crear_terceto(CMP, transformar_indice(auxiliar_ind), transformar_indice(expresion_ind), &numeracion_terceto, &lista_tercetos);expresion_ind=crear_terceto(obtener_branch(OP_MEN_IGU_), SIGNO_VACIO, SIGNO_VACIO, &numeracion_terceto, &lista_tercetos); printf("Comparacion Igual\n");printf("Comparacion Menor-Igual\n");}
           |          expresion {auxiliar_ind = expresion_ind;} OP_MAYOR expresion          {crear_terceto(CMP, transformar_indice(auxiliar_ind), transformar_indice(expresion_ind), &numeracion_terceto, &lista_tercetos);expresion_ind=crear_terceto(obtener_branch(OP_MAYOR_), SIGNO_VACIO, SIGNO_VACIO, &numeracion_terceto, &lista_tercetos); printf("Comparacion Igual\n");printf("Comparacion Mayor\n");}
           |          expresion {auxiliar_ind = expresion_ind;} OP_MENOR expresion          {crear_terceto(CMP, transformar_indice(auxiliar_ind), transformar_indice(expresion_ind), &numeracion_terceto, &lista_tercetos);expresion_ind=crear_terceto(obtener_branch(OP_MENOR_), SIGNO_VACIO, SIGNO_VACIO, &numeracion_terceto, &lista_tercetos); printf("Comparacion Igual\n");printf("Comparacion Menor\n");}
           |          expresion {auxiliar_ind = expresion_ind;} OP_NOT expresion            {crear_terceto(CMP, transformar_indice(auxiliar_ind), transformar_indice(expresion_ind), &numeracion_terceto, &lista_tercetos);expresion_ind=crear_terceto(obtener_branch(OP_NOT_), SIGNO_VACIO, SIGNO_VACIO, &numeracion_terceto, &lista_tercetos); printf("Comparacion Igual\n");printf("Comparacion Distinto\n");}
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

    iniciar_gci(&lista_tercetos, &pila_condicion, &pila_cantidad_desapilar, &pila_termino, &pila_expresion, &contador_t, &contador_e, &es_nuevo_token, &recuperar_puntero, &numeracion_terceto);


    yyparse();

    finalizar_gci(&lista_tercetos, &pila_condicion, &pila_cantidad_desapilar, &pila_termino, &pila_expresion, "intermedio.txt");

    printf("\n\nSe procede a eliminar la Tabla de Simbolos\n");
    eliminarTabla(&tablaSimbolos);
    printf("La Tabla de Simbolos se elimino correctamente\n");
    
    printf("\n Compilacion exitosa \n");
    fclose(yyin);
    return 0;
}