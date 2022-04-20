%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "y.tab.h"
#include "lib\pila.c"
#include "lib\funciones.c"
int yystopparser=0;
FILE  *yyin;
extern int yylineno;
char str_aux[50];
char str_aux2[50];
int __buscar;
int __repe;
int tipoDatoID;
char conector[10];
char compara[10];
int cuerpoCont=0;
int auxDato;
int posEnTabla;
int isNegado=0;
int cuentaSent;
int tipoDatoIzq;
int tipoDatoDer;
int tipoDatoID;
int yyerror();
int yyparse();
int yylex();
%}
%union {
int intval;
float val;
char *str_val;
}

%token <str_val>VARIABLE 
%token <int>CONST_INT
%token <float>CONST_REAL
%token <str_val>CONST_STRING


%token IF WHILE DECVAR ENDDEC INTEGER REAL WRITE ELSE OP_ASIG ENDWHILE ENDIF
%token OP_SUMA OP_MULT OP_MAY OP_MAY_IGU OP_MEN OP_MEN_IGU OP_IGUAL
%token OP_DIF PARENTESIS_A PARENTESIS_C OP_RESTA OP_DIV
%token PUNTO_COMA COMA OP_AND OP_NOT OP_OR READ STRING 
%token CORCHETE_A CORCHETE_C OP_DIV
%left OP_RESTA OP_SUMA
%%
iniciopro: DECVAR declaracion ENDDEC {auxOp=0;cantidadInlist=0;} programa   {
                                                            grabarTabla();
                                                            printf("\n---INTERMEDIA---(ARBOL RECORRIDO EN POSTORDEN)\n");
                                                            postOrden(&programaPtr,intermedia);
                                                            tree_print_dot(&programaPtr,graph);
                                                            generaAssembler(&programaPtr);
                                                           }

          | escrituraSinVar 



programa: sentencia 	                  {
                                          if(programaPtr!=NULL)
                                          {    
                                            printf("paso1");
                                              sprintf(str_aux, "CUERPO%d",cuerpoCont++);
							                            programaPtr = crearNodo(str_aux, sentenciaPtr, NULL);
                                             
						                             	} else   
                                          {
							                                 programaPtr = sentenciaPtr;
			                                   }
                                         }
	      | programa sentencia          
                                          {
                                                if(programaPtr!=NULL)
                                          {     
                           
                                          sprintf(str_aux, "CUERPO%d",cuerpoCont++);
							                            programaPtr = crearNodo(str_aux, programaPtr, sentenciaPtr);
							                            } 
                                          else 
                                          {    
                                             printf("paso2");
                                            sprintf(str_aux, "CUERPO%d",cuerpoCont++);
							                                   programaPtr = crearNodo(str_aux, sentenciaPtr,NULL);
			                                    }
                                          }

                                          

sentencia: asignacion PUNTO_COMA		{ sentenciaPtr = asigPtr;
                                          printf("\nREGLA 3: <sentencia>--><asignacion> PUNTO_COMA\n");}
          | ciclo                   {sentenciaPtr = cicloPtr;printf("\nREGLA 4: <sentencia>--><ciclo>\n");}
          | decisiones              {sentenciaPtr = decisionesPtr;printf("\nREGLA 5: <sentencia>--><decisiones>\n");}
          | escritura PUNTO_COMA           {sentenciaPtr = escrituraPtr;printf("\nREGLA 6: <sentencia>--><escritura> PUNTO_COMA\n");}
          | lectura PUNTO_COMA             {sentenciaPtr = lecturaPtr;printf("\nREGLA 7: <sentencia>--><lectura> PUNTO_COMA\n");}
               
               
declaracion: listadeclara                  {printf("\nREGLA 8: <declaracion>--><listadeclara> PUNTO_COMA\n");}      
            | declaracion listadeclara            {printf("\nREGLA 9: <declaracion>--> <declaracion> <listadeclara> PUNTO_COMA\n");}  

listadeclara : {_cantIds=0;} listvar OP_ASIG tdato      {agregarTipoDeDatoVarAtabla(auxDato);printf("\nREGLA 10: <listadeclara>--><listvar> OP_ASIG <tdato>\n");}

listvar : listvar PUNTO_COMA VARIABLE              {_cantIds++;colocarEnTablaSimb($<str_val>3,0,yylineno,0);printf("\nREGLA 11: <listvar>--><listvar> PUNTO_COMA VARIABLE \n");}
        | VARIABLE                         {_cantIds++;colocarEnTablaSimb($<str_val>1,0,yylineno,0);printf("\nREGLA 12: <listvar>-->VARIABLE \n");}

tdato: INTEGER                {auxDato = Integer ;printf("\nREGLA 13: <tdato>-->INTEGER\n");}
      | REAL                 {auxDato = REAL ;printf("\nREGLA 14: <tdato>-->REAL\n");}
      | STRING                {auxDato = String ;printf("\nREGLA 15: <tdato>-->STRING\n");}

escrituraSinVar: escrituraSinVarSente {printf("\nREGLA 16: <escrituraSinVar>--><escrituraSinVarSente>\n");}
                 | escrituraSinVar escrituraSinVarSente  {printf("\nREGLA 17: <escrituraSinVar>--><escrituraSinVar> <escrituraSinVarSente>\n");}

escrituraSinVarSente: WRITE CONST_STRING PUNTO_COMA {printf("\nREGLA 18: <escrituraSinVarSente>-->WRITE CONST_STRING PUNTO_COMA\n");}

decisiones : IF PARENTESIS_A condicion conectLog condicion subrutIf4 PARENTESIS_C LLAV_A subrutIf programa LLAV_C subrutIf3  ELSE LLAV_A programa LLAV_C {  generaIntermediaIfConElse();
                                                                                                                                  printf("\nREGLA 19: <decisiones>-->IF PARENTESIS_A <condicion> <conectLog> <condicion> PARENTESIS_C LLAV_A <programa> LLAV_C ELSE LLAV_A <programa> LLAV_C\n");}
            
            
            | IF PARENTESIS_A subrutIf2 OP_NOT condicion subrutIf PARENTESIS_C LLAV_A programa LLAV_C subrutIf3  ELSE LLAV_A programa LLAV_C {  generaIntermediaIfConElse();
                                                                                                                                    printf("\nREGLA 20: <decisiones>-->IF PARENTESIS_A OP_NOT <condicion> PARENTESIS_C LLAV_A <programa> LLAV_C ELSE LLAV_A <programa> LLAV_C\n");}
            | IF PARENTESIS_A condicion subrutIf PARENTESIS_C  LLAV_A programa LLAV_C subrutIf3  ELSE LLAV_A programa LLAV_C { 
                                                                                                                              generaIntermediaIfConElse();
                                                                                                                              printf("\nREGLA 21: <decisiones>-->IF PARENTESIS_A <condicion> PARENTESIS_C LLAV_A <programa> LLAV_C ELSE LLAV_A <programa> LLAV_C\n");}                                                                                                                   
                                                                                           
            | IF PARENTESIS_A condicion conectLog condicion subrutIf4 PARENTESIS_C LLAV_A subrutIf programa  LLAV_C  { generaIntermediaIf();   
                                                                                                        printf("\nREGLA 22: <decisiones>-->IF PARENTESIS_A <condicion> <conectLog> <condicion> PARENTESIS_C LLAV_A <programa> LLAV_C\n");}
            
            | IF PARENTESIS_A subrutIf2 OP_NOT condicion subrutIf PARENTESIS_C LLAV_A  programa LLAV_C  {generaIntermediaIf();  
                                                                                          printf("\nREGLA 23: <decisiones>-->IF PARENTESIS_A OP_NOT <condicion> PARENTESIS_C LLAV_A <programa> LLAV_C\n");}
            | IF PARENTESIS_A condicion subrutIf PARENTESIS_C LLAV_A programa LLAV_C  {    generaIntermediaIf();             
                                                                            printf("\nREGLA 24: <decisiones>-->IF PARENTESIS_A <condicion> PARENTESIS_C LLAV_A <programa> LLAV_C\n");}
                                                                                     
subrutIf: /* vacio */ { 
                       if(programaPtr!=NULL)
                       {
                         ponerEnPila(&pilaPrograma,&programaPtr,sizeof(programaPtr));
                         programaPtr=NULL;
                       }
                       else
                       {
                       if(sentenciaPtr!=NULL)
                           ponerEnPila(&pilaPrograma,&sentenciaPtr,sizeof(sentenciaPtr));
                       }
                       ponerEnPila(&pilaCondicion,&condicionPtr,sizeof(condicionPtr));
                       isNegado=0;
                      }

subrutIf3: /* vacio */ { 
                        if(programaPtr!=NULL)
                        {
                         ponerEnPila(&pilaPrograma,&programaPtr,sizeof(programaPtr));
                         programaPtr=NULL;
                        }
                        else
                        {
                        if(sentenciaPtr!=NULL)
                           ponerEnPila(&pilaPrograma,&sentenciaPtr,sizeof(sentenciaPtr));
                        }
                       }
subrutIf2:/* vacio */ {isNegado=1;}

subrutIf4:/* vacio */ { 
                        if(!strcmp(conector,"OP_OR"))
                            cuerpo = crearHoja("CONDMOR",SinTipo);
                        else
                            cuerpo = crearHoja("CONDMAND",SinTipo);
                        cuerpo = crearNodo("CUERPO",cuerpo,condicionPtrIzq);
                        condicionPtr = crearNodo(conector,cuerpo,condicionPtr);
                        //condicionPtr = crearNodo(conector,condicionPtrIzq,condicionPtr);
                      }

conectLog: OP_AND  {condicionPtrIzq = condicionPtr; strcpy(conector,"OP_AND"); printf("\nREGLA 25: <conectLog>-->OP_AND\n");} 
           |OP_OR  {condicionPtrIzq = condicionPtr; strcpy(conector,"OP_OR"); printf("\nREGLA 26: <conectLog>-->OP_OR\n");}
                  

ciclo : WHILE PARENTESIS_A condicion conectLog  condicion subrutIf4 subrutIf PARENTESIS_C LLAV_A programa LLAV_C {      generaIntermediaWhile();
                                                                                                printf("\nREGLA 27: <ciclo>-->WHILE PARENTESIS_A <condicion> OP_AND <condicion> PARENTESIS_C LLAV_A <programa> LLAV_C\n");}
        | WHILE PARENTESIS_A OP_NOT subrutIf2 condicion subrutIf PARENTESIS_C LLAV_A programa LLAV_C {generaIntermediaWhile();
                                                                                         printf("\nREGLA 28: <ciclo>-->WHILE PARENTESIS_A OP_NOT <condicion> PARENTESIS_C LLAV_A <programa> LLAV_C\n");}
        | WHILE PARENTESIS_A condicion PARENTESIS_C subrutIf LLAV_A programa LLAV_C {   generaIntermediaWhile(); 
                                                                              printf("\nREGLA 29: <ciclo>-->WHILE PARENTESIS_A <condicion> PARENTESIS_C LLAV_A <programa> LLAV_C\n");}

escritura : WRITE VARIABLE           {posEnTabla=chequearVarEnTabla($<str_val>2,yylineno);
                                    esVariableNumerica(posEnTabla,yylineno);
                                    escrituraPtr=crearNodo("WRITE",crearHoja($<str_val>2,tablaSimb[posEnTabla].tipoDeDato),NULL);
                                          printf("\nREGLA 30: <escritura>-->WRITE VARIABLE \n");}
          | WRITE CONST_STRING  { sprintf(str_aux, "_%s",$<str_val>2);
                                escrituraPtr=crearNodo("WRITE",crearHoja(str_aux,CteString),NULL);
                                    printf("\nREGLA 31: <escritura>-->WRITE CONST_STRING\n");}

lectura : READ VARIABLE              {posEnTabla=chequearVarEnTabla($<str_val>2,yylineno);
                                    lecturaPtr= crearNodo("READ",crearHoja($<str_val>2,tablaSimb[posEnTabla].tipoDeDato),NULL);
                                    printf("\nREGLA 32: <lectura>-->READ VARIABLE \n");}

condicion : opera oplog opera  {
                                 sacarDePila(&pilaOperadoresCond,&operDerPtr,sizeof(operDerPtr));
                                 sacarDePila(&pilaOperadoresCond,&operIzqPtr,sizeof(operDerPtr));
                                 if(isNegado)
                                    invertirCondicion(compara);
                                  tipoDatoIzq=verificarTipoDato(&operIzqPtr,yylineno);
                                  tipoDatoDer=verificarTipoDato(&operDerPtr,yylineno);
                                 errorDeCompatibilidadOperadores(tipoDatoIzq,tipoDatoDer,yylineno,"Los operadores de la condicion no son compatibles");
                                 condicionPtr=crearNodo(compara,operIzqPtr,operDerPtr);
                                 printf("\nREGLA 33:<condicion>--><opera> <oplog> <opera>\n");
                               }
            | funcionlist      { 
                                 condicionPtr = inlistBuscarPtr;
                                 printf("\nREGLA 34:<condicion>--><funcionList>\n");
                               }

opera: expresion        {sacarDePila(&pilaExpresion,&exprPtr,sizeof(exprPtr));
                          //auxCond =crearHoja($<str_val>1,CteInt);
                              ponerEnPila(&pilaOperadoresCond,&exprPtr,sizeof(exprPtr));}
      

oplog: OP_MAY_IGU          {strcpy(compara,"BLT");
                              printf("\nREGLA 35: <opera>-->OP_MAY_IGU\n");}
    | OP_MEN_IGU           {strcpy(compara,"BGT");
                              printf("\nREGLA 36: <opera>-->OP_MENEIGU\n");}
    | OP_IGUAL             {strcpy(compara,"BNE");
                              printf("\nREGLA 37: <opera>-->OP_IGUAL\n");}
    | OP_MAY               {strcpy(compara,"BLE");
                              printf("\nREGLA 38: <opera>-->OP_MAY\n");}
    | OP_MEN               {strcpy(compara,"BGE");
                              printf("\nREGLA 39: <opera>-->OP_MEN\n");}
    | OP_DIF               {strcpy(compara,"BEQ");
                              printf("\nREGLA 40: <opera>-->OP_DIF\n");}
    ;

list: list PUNTO_COMA var      {   
                         tipoDatoIzq=verificarTipoDato(&inlistExprePtr,yylineno);
                         errorDeCompatibilidadOperadores(tipoDatoIzq,tipoDatoID,yylineno,"tipo de datos de los campos del inlist no compatibles con la variable a buscar");
                           auxInlist1=crearNodo("BNE",crearHoja(inlistAux2,tipoDatoID),inlistExprePtr);
                           auxInlist2=crearNodo("OP_ASIG",crearHoja(inlistAux,Integer),crearHoja("_1",CteInt));
                           auxInlist1=crearNodo("IF",auxInlist1,auxInlist2);
                           inlistBuscarPtr=crearNodo("BUSCAR",inlistBuscarPtr,auxInlist1);
                            printf("\nREGLA 42: <list>--><list> PUNTO_COMA <var>\n");
                        }
      | var             {      
                            tipoDatoIzq=verificarTipoDato(&inlistExprePtr,yylineno);
                            errorDeCompatibilidadOperadores(tipoDatoIzq,tipoDatoID,yylineno,"tipo de datos de los campos del inlist no compatibles con la variable a buscar");
                           auxInlist1=crearNodo("BNE",crearHoja(inlistAux2,tipoDatoID),inlistExprePtr);
                           auxInlist2=crearNodo("OP_ASIG",crearHoja(inlistAux,Integer),crearHoja("_1",CteInt));
                           auxInlist1=crearNodo("IF",auxInlist1,auxInlist2);
                           inlistBuscarPtr=crearNodo("BUSCAR",inlistPtr,auxInlist1);
                           printf("\nREGLA 43: <list>--><var>\n");
                        }

var: expresion           {
                           sacarDePila(&pilaExpresion,&inlistExprePtr,sizeof(exprPtr));
                       
                           printf("\nREGLA 44: <list>--><expresion>\n");
                         }

asignacion: VARIABLE  OP_ASIG {strcpy(str_aux2,$<str_val>1);} expresion	    
                                                        {     
                                                          posEnTabla=chequearVarEnTabla($<str_val>1,yylineno); 
                                                          sacarDePila(&pilaExpresion,&exprPtr,sizeof(exprPtr));
                                                          asigPtr = crearNodo("OP_ASIG",crearHoja(str_aux2,tablaSimb[posEnTabla].tipoDeDato),exprPtr);
                                                          verificarTipoDato(&asigPtr,yylineno);
                                                          printf("\nREGLA 45: <asignacion>-->VARIABLE  OP_ASIG <expresion>\n");
                                                         }
            | VARIABLE  OP_ASIG {strcpy(str_aux2,$<str_val>1);} CONST_STRING       
                                                         {         
                                                          posEnTabla=chequearVarEnTabla($<str_val>1,yylineno);
                                                          asigPtr = crearNodo("OP_ASIG",crearHoja($<str_val>1,tablaSimb[posEnTabla].tipoDeDato),crearHoja($<str_val>4,CteString)) ;
                                                          verificarTipoDato(&asigPtr,yylineno);
                                                          printf("\nREGLA 46: <asignacion>-->VARIABLE  OP_ASIG CONST_STRING\n");}	
expresion: termino                                       {
                                                          sacarDePila(&pilaTermino,&terminoPtr,sizeof(terminoPtr));
                                                          ponerEnPila(&pilaExpresion,&terminoPtr,sizeof(terminoPtr)); 
                                                          printf("\nREGLA 47: <expresion>--><termino>\n");}
		   | expresion OP_SUMA termino               {        
                                                          auxOp++;
                                                          sacarDePila(&pilaTermino,&terminoPtr,sizeof(terminoPtr));
                                                          sacarDePila(&pilaExpresion,&exprPtr,sizeof(exprPtr));
                                                          exprPtr = crearNodo("OP_SUMA",exprPtr,terminoPtr);
                                                          ponerEnPila(&pilaExpresion,&exprPtr,sizeof(exprPtr));    
                                                          printf("\nREGLA 48: <expresion>--><expresion> OP_SUMA <termino>\n");}
		   | expresion OP_RESTA termino              {        
                                                          auxOp++;
                                                          sacarDePila(&pilaTermino,&terminoPtr,sizeof(terminoPtr));
                                                          sacarDePila(&pilaExpresion,&exprPtr,sizeof(exprPtr));
                                                          exprPtr = crearNodo("OP_RESTA",exprPtr,terminoPtr);
                                                          ponerEnPila(&pilaExpresion,&exprPtr,sizeof(exprPtr));       
                                                          printf("\nREGLA 49: <expresion>--><expresion> OP_RESTA <termino>\n");
                                                         }
               | OP_RESTA expresion %prec MENOS_UNARIO 
                                                         { 
                                                          auxOp++;
                                                          sacarDePila(&pilaExpresion,&exprPtr,sizeof(exprPtr));
                                                          exprPtr=crearNodo("OP_RESTA",exprPtr,NULL);
                                                          ponerEnPila(&pilaExpresion,&exprPtr,sizeof(exprPtr));
                                                          printf("\nREGLA 50: <expresion>-->OP_RESTA <expresion>\n");
                                                         }
		   

termino:  factor                                         {
                                                          sacarDePila(&pilaFactor,&factorPtr,sizeof(factorPtr));
                                                          ponerEnPila(&pilaTermino,&factorPtr,sizeof(factorPtr)); 
                                                          printf("\nREGLA 51: <termino>--><factor>\n");}
		 | termino OP_MULT factor	               {            
                                                          auxOp++;
                                                          sacarDePila(&pilaTermino,&terminoPtr,sizeof(terminoPtr));
                                                          sacarDePila(&pilaFactor,&factorPtr,sizeof(factorPtr));
                                                          terminoPtr=crearNodo("OP_MULT",terminoPtr,factorPtr);
                                                          ponerEnPila(&pilaTermino,&terminoPtr,sizeof(terminoPtr)); 
                                                          printf("\nREGLA 52: <termino>--><termino> OP_MULT <factor>\n");}
		 | termino OP_DIV factor            	   {            
                                                          auxOp++;
                                                          sacarDePila(&pilaTermino,&terminoPtr,sizeof(terminoPtr));
                                                          sacarDePila(&pilaFactor,&factorPtr,sizeof(factorPtr));
                                                          terminoPtr=crearNodo("OP_DIV",terminoPtr,factorPtr); 
                                                          ponerEnPila(&pilaTermino,&terminoPtr,sizeof(terminoPtr));
                                                          printf("\nREGLA 53: <termino>--><termino> OP_DIV <factor>\n");
                                                         }
factor : CONST_INT                                       {
                                                          sprintf(str_aux, "_%d",yylval.intval);
                                                          factorPtr = crearHoja(str_aux ,CteInt) ;
                                                          ponerEnPila(&pilaFactor,&factorPtr,sizeof(factorPtr));
                                                          printf("\nREGLA 54: <factor>-->CONST_INT\n");
                                                         }
		| VARIABLE                                          {         
                                                          posEnTabla=chequearVarEnTabla(yylval.str_val,yylineno);
                                                        
                                                          factorPtr = crearHoja(yylval.str_val,tablaSimb[posEnTabla].tipoDeDato);
                                                          ponerEnPila(&pilaFactor,&factorPtr,sizeof(factorPtr));
                                                          printf("\nREGLA 55: <factor>-->VARIABLE \n");
                                                         }
            | CONST_REAL                                 {
                                                          //sprintf(str_aux, "_%.5f",yylval.val);
                                                          sprintf(str_aux,"_%s",cteFlo);
                                                          factorPtr = crearHoja(str_aux,CteFloat) ;
                                                          ponerEnPila(&pilaFactor,&factorPtr,sizeof(factorPtr));
                                                          printf("\nREGLA 56: <factor>-->CONST_REAL\n");}
		| PARENTESIS_A   expresion  PARENTESIS_C                   {        
                                                          sacarDePila(&pilaExpresion,&exprPtr,sizeof(exprPtr));
                                                          ponerEnPila(&pilaFactor,&exprPtr,sizeof(exprPtr));             
                                                          printf("\nREGLA 57: <factor>-->PARENTESIS_A <expresion> PARENTESIS_C\n");}
            | PARENTESIS_A  expresion OP_DIV expresion PARENTESIS_C       {
                                                            auxOp++;
                                                          sacarDePila(&pilaExpresion,&exprPtr,sizeof(exprPtr));
                                                          sacarDePila(&pilaExpresion,&auxExprePtr,sizeof(exprPtr));
                                                          factorPtr=crearNodo("OP_DIV",auxExprePtr,exprPtr);
                                                          ponerEnPila(&pilaFactor,&factorPtr,sizeof(factorPtr));
                                                          printf("\nREGLA 59: <factor>-->PARENTESIS_A <expresion> OP_DIV <expresion> PARENTESIS_C\n");
                                                         }
                                          		
%%

