#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "constantes.h"

void iniciar_gci(t_lista_tercetos*, Pila*, Pila*, Pila*, Pila*, int*, int*, int*, int*, int*);
void finalizar_gci(t_lista_tercetos*, Pila*, Pila*, Pila*, Pila*, const char*);
char* transformar_indice(int);
char* obtener_branch(const char*);
void invertir_branch(t_lista_tercetos*, int);
char* crear_etiqueta(int);
int crear_terceto(const char*, const char*, const char*, int*, t_lista_tercetos*);

char* obtener_branch_invertido(const char*);

void iniciar_gci(t_lista_tercetos *pl, Pila *pcondiciones, Pila *pcantidad_salto, Pila *pterminos, Pila *pexpresiones, int *pcontador_t, int *pcontador_e, int *pes_nuevo_token, int *precuperar_puntero, int *pnumeracion)
{

	crear_lista_tercetos(pl);
	crearPila(pcondiciones);
	crearPila(pcantidad_salto);
	crearPila(pterminos);
	crearPila(pexpresiones);
	*pcontador_t = 0;
	*pcontador_e = 0;
	*pes_nuevo_token = 0;
	*precuperar_puntero = 0;
	*pnumeracion = -1;
}

void finalizar_gci(t_lista_tercetos *pl, Pila *pcondiciones, Pila *pcantidad_salto, Pila *pterminos, Pila *pexpresiones, const char *path)
{
	guardar_lista_en_archivo_terceto(pl, path);
	vaciar_lista_tercetos(pl);
	vaciarPila(pcondiciones);
	vaciarPila(pcantidad_salto);
	vaciarPila(pterminos);
	vaciarPila(pexpresiones);
}

char* transformar_indice(int indice)
{
	char cadena_numero[100], *resultado;
	itoa(indice, cadena_numero, 10);
	resultado = (char*) malloc(sizeof(cadena_numero) + TERCETO_CANTIDAD_CORCHETES + 1);
	if(resultado == NULL)
	{
		puts("Problemas de memoria");
		return NULL;
	}
	strcpy(resultado, "[");
	strcat(strcat(resultado, cadena_numero), "]");
	return resultado;
}


// Para un operador de comparación devuelve la instrucción de assembler necesaria
char* obtener_branch(const char *op)
{
	if(strcmp(op, OPERADOR_LE) == 0)
	{
		return BGE;
	}

	if(strcmp(op, OPERADOR_LEQ) == 0)
	{
		return BGT;
	}

	if(strcmp(op, OPERADOR_GE) == 0)
	{
		return BLE;
	}

	if(strcmp(op, OPERADOR_GEQ) == 0)
	{
		return BLT;
	}

	if(strcmp(op, OPERADOR_NE) == 0)
	{
		return BEQ;
	}

	if(strcmp(op, OPERADOR_IGUAL) == 0)
	{
		return BNE;
	}

	return NULL;
}


// Para una branch esppecifico devuelve el branch opuesto
char* obtener_branch_invertido(const char *op)
{
	if(strcmp(op, BGE) == 0)
	{
		return BLT;
	}

	if(strcmp(op, BGT) == 0)
	{
		return BLE;
	}

	if(strcmp(op, BLE) == 0)
	{
		return BGT;
	}

	if(strcmp(op, BLT) == 0)
	{
		return BGE;
	}

	if(strcmp(op, BEQ) == 0)
	{
		return BNE;
	}

	if(strcmp(op, BNE) == 0)
	{
		return BEQ;
	}

	return NULL;
}	

void invertir_branch(t_lista_tercetos *pl, int indice)
{
	
	cambiar_elemento(pl, indice, obtener_branch_invertido(buscar_elemento(pl, indice, PRIMER_ELEMENTO)), 1);
}

char* crear_etiqueta(int nro_terceto_prev)
{
	char *res;
	res = (char*) malloc(strlen(ETIQUETA) * sizeof(char) + CANTIDAD_DIGITOS_NUMERO);
	if(res == NULL)
	{
		return NULL;
	}
	sprintf(res,"%s%d", ETIQUETA, nro_terceto_prev + 1);
	return res;
}


int crear_terceto(const char *p1, const char *p2, const char *p3, int *pnumero, t_lista_tercetos *pl)
{
	t_dato_lista_tercetos *pd;
	int resultado = -60;
	
	pd = (t_dato_lista_tercetos*) malloc(sizeof(t_dato_lista_tercetos));
	if(pd == NULL)
	{
		puts("Problemas de memoria");
		exit(ERROR);
	}
	
	// Primero aumento la numeración
	(*pnumero)++;

	if((pd->s1 = strdup(p1)) == NULL)
	{
		puts("Problemas de memoria");
		exit(ERROR);
	}

	if((pd->s2 = strdup(p2)) == NULL)
	{
		puts("Problemas de memoria");
		exit(ERROR);
	}

	if((pd->s3 = strdup(p3)) == NULL)
	{
		puts("Problemas de memoria");
		exit(ERROR);
	}

	pd->nro = *pnumero;
	
	
	// Una vez armado el dato insertamos
	resultado = insertar_ordenado_tercetos(pl, pd, comparacion_tercetos);
	if(resultado == LISTA_DUPLICADO)
	{
		free(pd);
	}
	else if(resultado == LISTA_LLENA)
	{
		puts("Probelmas de memoria");
		exit(ERROR);
	}
	
	return *pnumero;
}
