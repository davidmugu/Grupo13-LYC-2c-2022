#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 0
#define ERROR_2_ -1
#define PILA_LLENA_2 1
#define PILA_VACIA_2 2

typedef struct sNodoPila
{
    struct sNodoPila* sig;
    char datos[200];
}nodoPila;

typedef nodoPila* Pila;

void crearPila(Pila* p);
int apilar(Pila* p,char* d);
int desapilar(Pila* p,char* d);
int pilaLlena(Pila* p);
int pilaVacia(Pila* p);
void vaciarPila(Pila* p);

void crearPila(Pila* p) {
    *p = NULL;
}

int apilar(Pila* p,char* d) {
    nodoPila* nuevoNodo=(nodoPila*)malloc(sizeof(nodoPila));
    if(!nuevoNodo)
        return PILA_LLENA_2;

    strcpy(nuevoNodo->datos,d);
    nuevoNodo->sig = *p;
    *p = nuevoNodo;

    return OK;
}

int desapilar(Pila* p,char* d) {
    nodoPila* nodoAEliminar;
    if(!*p)
        return PILA_VACIA_2;

    nodoAEliminar = (nodoPila*)malloc(sizeof(nodoPila));
    nodoAEliminar = *p;
    strcpy(d,nodoAEliminar->datos);
    *p = nodoAEliminar->sig;
    free(nodoAEliminar);
    return OK;
}


int pilaLlena(Pila* p) {
    void* nodoPila = malloc(sizeof(nodoPila));
    free(nodoPila);

    return nodoPila == NULL;
}

int pilaVacia(Pila* p) {
    return *p == NULL;
}

void vaciarPila(Pila* p) {
    nodoPila* nodo;
    while(*p) {
        nodo = *p;
        *p = nodo->sig;
        free(nodo);
    }
}