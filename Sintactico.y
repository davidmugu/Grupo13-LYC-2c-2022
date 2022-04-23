%{
#include "lista.h"
#include "pila.h"
#include "y.tab.h"

FILE *yyin;

tList symbolTable;
tStack stackDataTypeDecVar;
tStack invertStackDataType;
tStack stackVar;

extern int yylex();
extern void yyerror();
extern char* yytext;
extern int yylineno;

%}

%union{
    char* strVal;
}

%token DIM
%token WHILE
%token ENDWHILE
%token IF
%token ELSE
%token ENDIF
%token INT         
%token REAL       
%token STRING      
%token GET        
%token DISPLAY    
%token AS  
%token CORCHETE_A 
%token CORCHETE_C   
%token COMA      
%token PUNTO_COMA 
%token PARENTESIS_A    
%token PARENTESIS_C     
%token OP_MENOR      
%token OP_MAYOR       
%token OP_MEN_IGU
%token OP_MAY_IGU 
%token OP_NOT       
%token OP_AND      
%token OP_OR    
%token OP_COMP    
%token EQU_MAX
%token EQU_MIN
%token <strVal>CONST_INT
%token <strVal>CONST_REAL
%token <strVal>VARIABLE    
%token <strVal>CONST_STRING 
%token COMENTARIO_A
%token COMENTARIO_C
%token COMENTARIO
%token FOR
%token NEXT
%token TO
%token .

%left  OP_RESTA OP_SUMA
%right OP_MULT OP_DIV
%right MENOS_UNARIO
%right OP_ASIG   

%%

programa:   prog             
        ;

prog: sentencia                 {;}
  ;

sentencia: sentencia grammar PUNTO_COMA  {;}
        | grammar PUNTO_COMA             {;}
        ;

grammar:   dec_var                    {printf("Regla - fin de Sentencia de declaracion de variable\n\n");}
       |   asig                       {printf("Regla - fin de Sentencia de asignacion \n\n");}
       |   display                    {printf("Regla - fin de Sentencia de Display \n\n");}
       |   get                        {printf("Regla - fin de Sentencia de Get \n\n");}
       |   if                         {printf("Regla - fin de Sentencia de IF \n\n");}
       |   while                      {printf("Regla - fin de Sentencia de While \n\n");}
       |   for                        {printf("Regla - fin de Sentencia de Tema especial - For \n\n");}
       ;

asig:   VARIABLE OP_ASIG expr             {printf("Regla - Sentencia de asignacion por expresion \n");}
    |   VARIABLE OP_ASIG CONST_STRING_R     {printf("Regla - Sentencia de asignacion por constante string \n");}
    ;

CONST_STRING_R: CONST_STRING {
	    insertString(&symbolTable, $1);
	};

NUMERO: CONST_INT{
        insertNumber(&symbolTable,$1);
      }    
      | CONST_REAL {
        insertFloat(&symbolTable,$1);
      };

expr: expr OP_SUMA termino         {printf("Regla - Sentencia de suma \n");}
	| expr OP_RESTA termino          {printf("Regla - Sentencia de resta \n");} 
	| termino                       {;}
    ;

termino: termino OP_MULT factor   {printf("Regla - Sentencia de multiplicacion\n");}
	   | termino OP_DIV factor    {printf("Regla - Sentencia de division\n");}
     | '-' termino %prec MENOS_UNARIO
	   | factor                     {;}
       ;

                    
factor: PARENTESIS_A expr PARENTESIS_C    {;}
      | NUMERO                    {;}
	    | VARIABLE                  {;}
      ;

display: DISPLAY CONST_STRING_R   {printf("Regla - Sentencia de display con constante string\n");}
       | DISPLAY expr             {printf("Regla - Sentencia de display con expresion\n");}
       ;

get: GET VARIABLE {printf("Regla - Sentencia de Get con variable\n");}
   ;

while: WHILE  cond_completa {printf("Regla - Sentencia de while con condicion\n");}
       while_exp
       ENDWHILE
    ;

while_exp: sentencia {;}
            ;

for: FOR VARIABLE OP_ASIG expr TO expr CORCHETE_A CONST_INT CORCHETE_C {printf("Regla - Sentencia de FOR con valor en corchete\n");}
     sentencia
     NEXT VARIABLE
    | FOR VARIABLE OP_ASIG expr TO expr {printf("Regla - Sentencia de FOR sin valor en corchete\n");}
      sentencia
      NEXT VARIABLE
    ;

if: IF cond_completa      
    sentencia             {;}
    ENDIF                 {;}
    | IF cond_completa    
      sentencia           
      ELSE                
      sentencia           
      ENDIF               
    | IF cond_completa    {printf("Regla - if y else sin sentencia\n");}
      ELSE                {;}
      ENDIF               {;}
    | IF cond_completa    {printf("Regla - if sin sentencia\n");}
      ENDIF               {printf("Regla - fin de if sin sentencia\n");}
    ;

cond_completa: PARENTESIS_A cond_completa PARENTESIS_C                      {;}
             | PARENTESIS_A cond_completa OP_OR cond_completa PARENTESIS_C {printf("Regla - Sentencia de condicion OR multiple\n");}
             | PARENTESIS_A cond_completa OP_AND cond_completa PARENTESIS_C {printf("Regla - Sentencia de condicion AND multiple\n");}
             | PARENTESIS_A cond_completa OP_OR cond PARENTESIS_C {printf("Regla - Sentencia de condicion OR multiple\n");}
             | PARENTESIS_A cond_completa OP_AND cond PARENTESIS_C {printf("Regla - Sentencia de condicion AND multiple\n");}
             | OP_NOT cond_completa                       {printf("Regla - Sentencia de condicion negada\n");}
             | PARENTESIS_A cond OP_OR cond_completa PARENTESIS_C {printf("Regla - Sentencia de condicion OR multiple\n");}
             | PARENTESIS_A cond OP_AND cond_completa PARENTESIS_C {printf("Regla - Sentencia de condicion AND multiple\n");}
             | PARENTESIS_A cond OP_AND cond PARENTESIS_C {printf("Regla - Sentencia de condicion AND multiple\n");}
             | PARENTESIS_A cond OP_OR cond PARENTESIS_C  {printf("Regla - Sentencia de condicion OR multiple\n");} 
             | PARENTESIS_A cond PARENTESIS_C {printf("Regla - Sentencia de condicion simple\n");}
             | PARENTESIS_A equmin PARENTESIS_C {printf("Regla - Sentencia de condicion equmin\n");}
             | PARENTESIS_A equmax PARENTESIS_C {printf("Regla - Sentencia de condicion equmax\n");}
             ;

equmax: EQU_MAX PARENTESIS_A cond_equ PARENTESIS_C	{printf("Regla - Sentencia de EQUMAX\n");}
        ;

equmin: EQU_MIN PARENTESIS_A cond_equ PARENTESIS_C {printf("Regla - Sentencia de EQUMIN\n");}
        ;
cond_equ: expr PUNTO_COMA CORCHETE_A lista CORCHETE_C {printf("Regla - Sentencia de Expresion y Listado de variables o constantes en EQUMIN/EQUMAX\n");}
        ;
lista: expr_list 							{;}
      | lista COMA expr_list  				{;}
	    ;

expr_list: CONST_INT      {;}
        |  CONST_REAL     {;}
        |  CONST_STRING   {;}
        |  VARIABLE       {;}
        ;

cond: expr OP_COMP expr  {;}
    | expr OP_MAY_IGU expr {;}
    | expr OP_MEN_IGU expr {;}
    | expr OP_MENOR expr {;}
    | expr OP_MAYOR expr {;}
    | expr OP_AND expr {;}
    | expr OP_OR expr {;}
    | expr OP_NOT termino {;}
    | OP_NOT VARIABLE {;}
    ;

dec_var: DIM CORCHETE_A seg_asig CORCHETE_C {
                                        char dataType[100];
                                        char variable[100];
										printf("Regla - Sentencia de declaracion de variable\n");
                                        while(!emptyStack(&stackDataTypeDecVar)){
                                          popStack(&stackDataTypeDecVar,dataType);
                                          pushStack(&invertStackDataType,dataType);
                                        }
                                        while(!emptyStack(&invertStackDataType) && !emptyStack(&stackVar)){
                                            popStack(&invertStackDataType,dataType);
                                            popStack(&stackVar,variable);
                                            insertVariable(&symbolTable,variable,dataType);
                                        }

};


seg_asig:  VARIABLE COMA seg_asig COMA tipo                 {
                                                              printf("Regla - sentencia declaracion de variable\n");
                                                              pushStack(&stackVar,$1);
                                                            }
          |  VARIABLE CORCHETE_C AS CORCHETE_A tipo         {
                                                              printf("Regla - sentencia de declaracion de tipo\n");
                                                              pushStack(&stackVar,$1);
                                                            }
          ;
			 
 
tipo: 	INT 	    {pushStack(&stackDataTypeDecVar,"INTEGER");}
      | REAL      {pushStack(&stackDataTypeDecVar,"FLOAT");}	
      | STRING  	{pushStack(&stackDataTypeDecVar,"STRING");}
      ;

%%


int main(int argc, char* argv[])
{
    if((yyin = fopen(argv[1],"rt")) == NULL)
    {
        printf("\n No se puede abrir el archivo %s \n", argv[1]);
    }

    printf("\n Compilando... \n\n");

    createList(&symbolTable);
    createStack(&stackVar);
    createStack(&stackDataTypeDecVar);
    createStack(&invertStackDataType);
    yyparse();

    deleteTable(&symbolTable);
    
    printf("\n Compilacion exitosa \n");
    fclose(yyin);
    return 0;
}