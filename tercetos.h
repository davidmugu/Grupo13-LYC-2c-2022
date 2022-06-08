#ifndef LISTA_TERCETOS_H_INCLUDED
#define LISTA_TERCETOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct
{
	char *s1;
	char *s2;
	char *s3;
	int nro;
}t_dato_lista_tercetos;

typedef struct s_nodo_lista_tercetos
{
    t_dato_lista_tercetos dato;
    struct s_nodo_lista_tercetos *psig;
}t_nodo_lista_tercetos;

typedef t_nodo_lista_tercetos* t_lista_tercetos;
typedef int(*t_cmp_tercetos)(const t_dato_lista_tercetos*, const t_dato_lista_tercetos*);


int comparacion_tercetos(const t_dato_lista_tercetos*, const t_dato_lista_tercetos*);

void crear_lista_tercetos(t_lista_tercetos*);
void vaciar_lista_tercetos(t_lista_tercetos*);
int insertar_ordenado_tercetos(t_lista_tercetos*, const t_dato_lista_tercetos*, t_cmp_tercetos);
void guardar_lista_en_archivo_terceto(t_lista_tercetos*, const char*);

char* buscar_elemento(const t_lista_tercetos*, int, int);
void cambiar_elemento(const t_lista_tercetos*, int, const char*, int);

void iniciar_gci(t_lista_tercetos*, t_pila*, t_pila*, t_pila*, t_pila*, int*, int*, int*, int*, int*);
void finalizar_gci(t_lista_tercetos*, t_pila*, t_pila*, t_pila*, t_pila*, const char*);
char* transformar_indice(int);
char* obtener_branch(const char*);
void invertir_branch(t_lista_tercetos*, int);
char* crear_etiqueta(int);
int crear_terceto(const char*, const char*, const char*, int*, t_lista_tercetos*);


#endif // LISTA_TERCETOS_H_INCLUDED