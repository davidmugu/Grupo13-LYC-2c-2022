#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 0
#define ERROR -1
#define PILA_LLENA 1
#define PILA_VACIA 2

typedef struct sNodo
{
    struct sNodo* sig;
    char datos[200];
}nodo;

typedef nodo* Pila;

void crearPila(Pila* p);
int apilar(Pila* p,char* d);
int desapilar(Pila* p,char* d);
int pilaLlena(Pila* p);
int pilaVacia(Pila* p);
int topePila(Pila* p, char* d);
void vaciarPila(Pila* p);

void crearPila(Pila* p) {
    *p = NULL;
}

int apilar(Pila* p,char* d) {
    nodo* nuevoNodo=(nodo*)malloc(sizeof(nodo));
    if(!nuevoNodo)
        return PILA_LLENA;

    strcpy(nuevoNodo->datos,d);
    nuevoNodo->sig = *p;
    *p = nuevoNodo;

    return OK;
}

int desapilar(Pila* p,char* d) {
    nodo* nodoAEliminar;
    if(!*p)
        return PILA_VACIA;

    nodoAEliminar = (nodo*)malloc(sizeof(nodo));
    nodoAEliminar = *p;
    strcpy(d,nodoAEliminar->datos);
    *p = nodoAEliminar->sig;
    free(nodoAEliminar);
    return OK;
}

int pilaLlena(Pila* p) {
    void* nodo = malloc(sizeof(nodo));
    free(nodo);

    return nodo == NULL;
}

int pilaVacia(Pila* p) {
    return *p == NULL;
}

int topePila(Pila* p ,char* d) {
    if(!*p)
        return PILA_VACIA;
    strcpy(d,*p->datos);
    return OK;
}

void vaciarPila(Pila* p) {
    nodo* nodo;
    while(*p) {
        nodo = *p;
        *p = nodo->sig;
        free(nodo);
    }
}