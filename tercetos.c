#include "../include/lista_tercetos.h"

void crear_lista_tercetos(t_lista_tercetos *pl)
{
    *pl=NULL;
}

void vaciar_lista_tercetos(t_lista_tercetos *pl)
{
    t_nodo_lista_tercetos *pnodo;
    while(*pl)
    {
        pnodo=*pl;
        *pl=pnodo->psig;
        free(pnodo);
    }
}

int insertar_ordenado_tercetos(t_lista_tercetos *pl, const t_dato_lista_tercetos *pd,t_cmp_tercetos cmp)
{
    t_nodo_lista_tercetos *pnodo;
    while(*pl && cmp(pd,&(*pl)->dato)>0)
        pl=&(*pl)->psig;
    if(*pl && cmp(pd,&(*pl)->dato)==0)
        return LISTA_DUPLICADO;
    pnodo=(t_nodo_lista_tercetos*)malloc(sizeof(t_nodo_lista_tercetos));
    if(!pnodo)
        return LISTA_LLENA;
    pnodo->dato=*pd;
    pnodo->psig=*pl;
    *pl=pnodo;
    return TODO_BIEN;
}

int comparacion_tercetos(const t_dato_lista_tercetos *pd1, const t_dato_lista_tercetos *pd2)
{
    return pd1->nro - pd2->nro;
}

void guardar_lista_en_archivo_terceto(t_lista_tercetos *pl, const char *path)
{
	t_dato_lista_tercetos *pd;
	FILE *pf = fopen(path, TEXTO_ESCRITURA);
	if(pf == NULL)
	{
		printf("No se pudo abrir el archivo %s\n", path);
		return;
	}

    while(*pl)
    {
        pd =  &(*pl)->dato;
		fprintf(pf,"[%d] (%s, %s, %s)\n", pd->nro, pd->s1, pd->s2, pd->s3);
        pl = &(*pl)->psig;
    }
	fclose(pf);
}

char* buscar_elemento(const t_lista_tercetos *pl, int nro_terceto, int nro_elemento)
{
	while(*pl)
    {
        if( (*pl)->dato.nro - nro_terceto == 0)
		{
			if(nro_elemento == PRIMER_ELEMENTO)
			{
				return (*pl)->dato.s1;
			}
			else if(nro_elemento == SEGUNDO_ELEMENTO)
			{
				return (*pl)->dato.s2;
			}
			else
			{
				return (*pl)->dato.s3;
			}
		}
        pl=&(*pl)->psig;
    }
	return NULL;
}

void cambiar_elemento(const t_lista_tercetos *pl, int nro_terceto, const char *s ,int nro_elemento )
{
	
	while(*pl)
    {
        if((*pl)->dato.nro - nro_terceto == 0)
		{
			if(nro_elemento == PRIMER_ELEMENTO)
			{
				free((*pl)->dato.s1);
				if(((*pl)->dato.s1 = strdup(s)) == NULL)
				{
					puts("Problemas de memoria");
					exit(ERROR);
				}
				return;
			}
			else if(nro_elemento == SEGUNDO_ELEMENTO)
			{
				free((*pl)->dato.s2);
				if(((*pl)->dato.s2 = strdup(s)) == NULL)
				{
					puts("Problemas de memoria");
					exit(ERROR);
				}
				return;
			}
			else
			{
				free((*pl)->dato.s3);
				if(((*pl)->dato.s3 = strdup(s)) == NULL)
				{
					puts("Problemas de memoria");
					exit(ERROR);
				}
				return;
			}
			
		}
        pl=&(*pl)->psig;
    }
}


char* obtener_branch_invertido(const char*);

void iniciar_gci(t_lista_tercetos *pl, t_pila *pcondiciones, t_pila *pcantidad_salto, t_pila *pterminos, t_pila *pexpresiones, int *pcontador_t, int *pcontador_e, int *pes_nuevo_token, int *precuperar_puntero, int *pnumeracion)
{

	crear_lista_tercetos(pl);
	crear_pila(pcondiciones);
	crear_pila(pcantidad_salto);
	crear_pila(pterminos);
	crear_pila(pexpresiones);
	*pcontador_t = 0;
	*pcontador_e = 0;
	*pes_nuevo_token = 0;
	*precuperar_puntero = 0;
	*pnumeracion = -1;
}

void finalizar_gci(t_lista_tercetos *pl, t_pila *pcondiciones, t_pila *pcantidad_salto, t_pila *pterminos, t_pila *pexpresiones, const char *path)
{
	guardar_lista_en_archivo_terceto(pl, path);
	vaciar_lista_tercetos(pl);
	vaciar_pila(pcondiciones);
	vaciar_pila(pcantidad_salto);
	vaciar_pila(pterminos);
	vaciar_pila(pexpresiones);
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