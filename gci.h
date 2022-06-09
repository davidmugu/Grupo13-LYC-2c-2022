#ifndef GCI_H
#define GCI_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tercetos.h"


void iniciar_gci(t_lista_tercetos*, Pila*, Pila*, Pila*, Pila*, int*, int*, int*, int*, int*);
void finalizar_gci(t_lista_tercetos*, Pila*, Pila*, Pila*, Pila*, const char*);
char* transformar_indice(int);
char* obtener_branch(const char*);
void invertir_branch(t_lista_tercetos*, int);
char* crear_etiqueta(int);
int crear_terceto(const char*, const char*, const char*, int*, t_lista_tercetos*);

#endif