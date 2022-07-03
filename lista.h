#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR_3 -1
#define DUPLICADO 1

typedef struct sNodoLista
{
    char nombre[50];
    char tipoDato[50];
    char valor[50];
    int  longitud;
    struct sNodoLista* sig;
}nodoLista;

typedef nodoLista* Lista;

void crearLista(Lista *l);
int insertarEnOrden(Lista *l, char* nombre, char* tipoDato, char* valor, int longitud);
int insertarEntero(Lista *l, char* lex);
int insertarReal(Lista *l, char* lex);
int insertarString(Lista *l, char* nombre);
int insertarVariable(Lista *l, char* nombre, char* tipoDato); 
int eliminarTabla(Lista *l);
char* eliminarCaracter(char* lex);

void crearLista(Lista *l) {
    *l = NULL;
}

int insertarEnOrden(Lista *l, char* nombre, char* tipoDato, char* valor, int longitud) {
    int res = -1;
    nodoLista* nuevoNodo = (nodoLista*)malloc(sizeof(nodoLista));
    
    if(!nuevoNodo)
        return ERROR_3;

    while(*l && ((res = (strcmp((*l)->nombre, nombre))) < 0))
        l = &(*l)->sig;

    if(res == 0)
        return DUPLICADO;
    strcpy(nuevoNodo->nombre, nombre);
    strcpy(nuevoNodo->tipoDato, tipoDato);
    strcpy(nuevoNodo->valor, valor);
    
    nuevoNodo->longitud = longitud;
    nuevoNodo->sig = *l;
    *l = nuevoNodo;

    return OK;
}

int insertarEntero(Lista *l, char* lex) {
    int res = -1;
    char nombre[100];

    strcpy(nombre, "_");
    strcat(nombre, lex); 

    res = insertarEnOrden(l, nombre, "CONST_INT", lex, 0);

    if(res == DUPLICADO){
        printf("La constante numerica %s ya se ingreso en la tabla de simbolos\n",lex);
        return DUPLICADO;
    }
    printf("La constante numerica %s se inserto en la tabla de simbolos\n",lex);
    return OK;
}

int insertarReal(Lista *l, char* lex) {
    int res = -1;
    char nombre[100];

    strcpy(nombre, "_");
    strcat(nombre, lex); 

    res = insertarEnOrden(l, nombre, "CONST_REAL", lex, 0);

    if(res == DUPLICADO){
        printf("La constante real %s ya se ingreso en la tabla de simbolos\n",lex);
        return DUPLICADO;
    }
    return OK;
}

int insertarString(Lista *l, char* lex) {
    int res = -1;
    char nombre[100];

    char* nuevoNombre = eliminarCaracter(lex);

    strcpy(nombre, "_");
    strcat(nombre, nuevoNombre);

    res = insertarEnOrden(l, nombre, "CONST_STRING", nuevoNombre, strlen(nuevoNombre));

    if(res == DUPLICADO) {
        printf("La constante string %s ya se ingreso en la tabla de simbolos\n",lex);
        return DUPLICADO;
    }
    return OK;
}

char* eliminarCaracter(char* lex) {
    char* cad = lex;
    char* cadIni = cad;
    while(*lex) {
        if(*lex != '"') {
            (*cad) = (*lex);
            cad++;
        }
        lex++;
    }
    *cad = '\0';
    return cadIni;
}

int insertarVariable(Lista *l, char* lex, char* tipoDato) {
    int res = -1;

    res = insertarEnOrden(l, lex, tipoDato, " ", 0);
    if(res == DUPLICADO){
        printf("La variable %s ya se ingreso en la tabla de simbolos\n",lex);
        return DUPLICADO;
    }
    return OK;
}

int eliminarTabla(Lista *l) {
    FILE *Tabla = fopen("ts.txt", "wt");
    
    if(!Tabla) {
        printf("No se pudo abrir el archivo ts.txt \n");
        return ERROR_3;
    }

    printf("\n                           TABLA DE SIMBOLOS                              \n");

    printf("+------------------------------------------------------------------------------------+\n");
    printf("|%-25s|%-16s|%-30s|%-10s|\n", "NOMBRE", "TIPO DE DATO", "VALOR", "LONGITUD");
    printf("+------------------------------------------------------------------------------------+\n");

    fprintf(Tabla,"\n                           TABLA DE SIMBOLOS                           \n");
    fprintf(Tabla, "+------------------------------------------------------------------------------------+\n");
    fprintf(Tabla, "|%-25s|%-16s|%-30s|%-10s|\n", "NOMBRE", "TIPO DE DATO", "VALOR", "LONGITUD");
    fprintf(Tabla, "+------------------------------------------------------------------------------------+\n");

    while(*l)
    {
        printf("|%-25s|%-16s|%-30s|%-10d|\n", (*l)->nombre, (*l)->tipoDato, (*l)->valor, (*l)->longitud);
        fprintf(Tabla, "|%-25s|%-16s|%-30s|%-10d|\n", (*l)->nombre, (*l)->tipoDato, (*l)->valor, (*l)->longitud);
        l = &(*l)->sig;
    }

    printf("+------------------------------------------------------------------------------------+\n");
    fprintf(Tabla, "+------------------------------------------------------------------------------------+\n");
    fclose(Tabla);

    return OK;
}