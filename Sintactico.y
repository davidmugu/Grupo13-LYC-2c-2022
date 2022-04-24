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

%token WHILE
%token ENDWHILE
%token IF
%token ELSE
%token ENDIF
%token INT         
%token REAL       
%token STRING
%token	WRITE
%token	READ
%token	BETWEEN
%token	TAKE
%token	DECVAR
%token	ENDDEC
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
%token <strVal>CONST_INT
%token <strVal>CONST_REAL
%token <strVal>VARIABLE    
%token <strVal>CONST_STRING 
%token COMENTARIO_A
%token COMENTARIO_C
%token COMENTARIO
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

grammar:   /*dec_var                    {printf("Regla - fin de Sentencia de declaracion de variable\n\n");}
       | */  asig                       {printf("Regla - fin de Sentencia de asignacion \n\n");}
       |   if                         {printf("Regla - fin de Sentencia de IF \n\n");}
       |   while                      {printf("Regla - fin de Sentencia de While \n\n");}
       |  between                     {printf("Regla - fin de Sentencia de Between \n\n");}
       |  take                     {printf("Regla - fin de Sentencia de Take \n\n");}
       |  write                     {printf("Regla - fin de Sentencia de Write \n\n");}
       |  read                     {printf("Regla - fin de Sentencia de Read \n\n");}
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

while: WHILE  cond_completa {printf("Regla - Sentencia de while con condicion\n");}
       while_exp
       ENDWHILE
    ;

while_exp: sentencia {;}
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

between : BETWEEN PARENTESIS_A VARIABLE COMA CORCHETE_A expr  PUNTO_COMA expr  CORCHETE_C PARENTESIS_C {printf("Regla - Sentencia de Between\n");}

take : TAKE PARENTESIS_A operador PUNTO_COMA CONST_INT PUNTO_COMA CORCHETE_A lista_cte CORCHETE_C PARENTESIS_C {printf("Regla - Sentencia de Take\n");}

operador: OP_SUMA {;}
		  |OP_RESTA {;}
		  |OP_MULT {;}
		  |OP_MULT {;}
		  
		  
lista_cte: expr_cte 							{;}
      | lista_cte COMA expr_cte  				{;}
	    ;

expr_cte: CONST_INT      {;}
        |  CONST_REAL     {;}

/*seg_asig:  VARIABLE COMA seg_asig COMA tipo                 {
                                                              printf("Regla - sentencia declaracion de variable\n");
                                                              pushStack(&stackVar,$1);
                                                            }
          |  VARIABLE CORCHETE_C AS CORCHETE_A tipo         {
                                                              printf("Regla - sentencia de declaracion de tipo\n");
                                                              pushStack(&stackVar,$1);
                                                            }
          ;
	*/		 
 
write : WRITE VARIABLE | expr_cte {;}
read :  READ  VARIABLE {;}

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