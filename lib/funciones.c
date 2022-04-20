#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

char msg[100];
char aux_str[50];

char cteFloat[50];
int auxEntero = 0;
int esCondMultOR = 0;
int esCondMultAND = 0;
int esCondWhile = 0;
int etiqFalseIf = 0;
int etiqFinIf = 0;
int etiqTrueIf = 0;
int contEtiqWhile = 0;
int auxReal = 0;
int fueConDMultOR = 0;
int fueConDMultAND = 0;
int condMultInlistif = 0;
int condMultInlistOr = 0;
int noActivar = 0;

char etiqTrue[50];
char etiqFalse[50];
char etiqWhile[50];
char aux_str2[50];

void colocarEnTablaSimb(char *ptr, int esCte, int linea, int tDatoCte)
{
	int i = 0, dupli = 0;
	if (esCte)
		sprintf(aux_str, "_%s", ptr);
	while (i < cuentaRegs && !dupli)
	{
		if (!strcmp(tablaSimb[i].lexema, esCte ? aux_str : ptr))
			dupli = 1;
		i++;
	}
	if (!dupli)
	{
		tablaSimb[cuentaRegs].longitud = strlen(ptr);
		if (esCte)
		{
			strcpy(tablaSimb[cuentaRegs].valor, ptr);
			strcpy(tablaSimb[cuentaRegs].lexema, aux_str);
			tablaSimb[cuentaRegs].tipoDeDato = tDatoCte;
		}
		else
			strcpy(tablaSimb[cuentaRegs].lexema, ptr);

		cuentaRegs++;
	}
	else
	{
		if (!esCte)
		{
			sprintf(msg, "'%s' ya se encuentra declarada previamente.", ptr);
			mensajeDeError(ErrorSintactico, msg, linea);
		}
	}
}
void cambiarValor(char *auxValor)
{
	strcpy(tablaSimb[cuentaRegs - 1].valor, auxValor);
}
void replace(char *orig, char rep, char busc)
{
	char *aux = orig;
	if (!*orig)
	{
		*orig = 'v';
		*(orig + 1) = 'a';
	}
	else
	{
		//remplazo espacios por guiones
		while (*orig)
		{
			if (*orig == busc || *orig == ':')
				*orig = rep;
			orig++;
		}
		//borro guiones
		while (*aux)
		{
			*aux = *(aux + 1);
			aux++;
		}
		*(aux - 2) = '\0';
	}
}

int chequearVarEnTabla(char *lexema, int linea)
{
	int pos = 0;
	pos = buscarEnTabla(lexema);
	//Si no existe en la tabla, error
	if (pos == -1)
	{
		sprintf(msg, "La variable '%s' debe ser declarada previamente en la seccion de declaracion de variables", lexema);
		mensajeDeError(ErrorSintactico, msg, linea);
	}
	//Si existe en la tabla, dejo que la compilacion siga
	return pos;
}

int buscarEnTabla(char *nombre)
{
	int i = 0, pos = -1;
	while (i < cuentaRegs)
	{
		if (!strcmp(tablaSimb[i].lexema, nombre))
		{
			pos = i;
		}
		i++;
	}
	return pos;
}

void mensajeDeError(enum tipoError error, const char *info, int linea)
{
	switch (error)
	{
	case ErrorLexico:
		printf("ERROR Lexico en la linea %d. Descripcion: %s\n", linea, info);
		break;

	case ErrorSintactico:
		printf("ERROR Sintactico en la linea %d. Descripcion: %s.\n", linea, info);
		break;
	}
	system("Pause");
	exit(1);
}

void agregarTiposDatosCte(int tDato)
{
	tablaSimb[cuentaRegs - 1].tipoDeDato = tDato;
}

void agregarTipoDeDatoVarAtabla(int tDato)
{
	int i = 0, actual = 0;
	while (actual < _cantIds)
	{
		tablaSimb[cuentaRegs - actual - 1].tipoDeDato = tDato;
		actual++;
	}
}

void grabarTabla()
{
	int i;
	fprintf(tab, "%-30s|%-30s|%-30s|%s\n", "NOMBRE", "TIPO", "VALOR", "LONGITUD");
	fprintf(tab, "---------------------------------------------------------------------------------------------------------------------------------------------\n");

	for (i = 0; i < cuentaRegs; i++)
	{
		fprintf(tab, "%-30s", tablaSimb[i].lexema);
		switch (tablaSimb[i].tipoDeDato)
		{
		case Float:
			fprintf(tab, "|%-30s|%-30s|%d", "FLOAT", "--", tablaSimb[i].longitud);
			break;
		case Integer:
			fprintf(tab, "|%-30s|%-30s|%d", "INTEGER", "--", tablaSimb[i].longitud);
			break;
		case String:
			fprintf(tab, "|%-30s|%-30s|%d", "STRING", "--", tablaSimb[i].longitud);
			break;
		case CteFloat:
			fprintf(tab, "|%-30s|%-30s|%d", "CTE_FLOAT", tablaSimb[i].valor, tablaSimb[i].longitud);
			break;
		case CteInt:

			fprintf(tab, "|%-30s|%-30s|%d", "CTE_INT", tablaSimb[i].valor, tablaSimb[i].longitud);
			break;
		case CteString:
			fprintf(tab, "|%-30s|%-30s|%d", "CTE_STRING", tablaSimb[i].valor, tablaSimb[i].longitud);
			break;
		}
		fprintf(tab, "\n");
	}
	fclose(tab);
}

void invertirCondicion(char *condicion)
{
	if (strcmp(condicion, "BEQ") == 0)
	{
		strcpy(condicion, "BNE");
	}
	else if (strcmp(condicion, "BNE") == 0)
	{
		strcpy(condicion, "BEQ");
	}
	else if (strcmp(condicion, "BGT") == 0)
	{
		strcpy(condicion, "BLT");
	}
	else if (strcmp(condicion, "BLT") == 0)
	{
		strcpy(condicion, "BGT");
	}
	else if (strcmp(condicion, "BGE") == 0)
	{
		strcpy(condicion, "BLE");
	}
	else if (strcmp(condicion, "BLE") == 0)
	{
		strcpy(condicion, "BGE");
	}
}

int verifRangoString(char *ptr, int linea)
{
	if ((strlen(ptr) - 2) > LIMITE) //-2 para que no cuente las comillas
	{
		sprintf(msg, "la cadena (%s) supera el rango permitido", ptr);
		mensajeDeError(ErrorLexico, msg, linea);
	}
	return 0;
}

void esVariableNumerica(int posDeTabla, int linea)
{
	int tDato = tablaSimb[posDeTabla].tipoDeDato;
	if (tDato != Integer && tDato != Float)
	{
		sprintf(msg, "Solo se muestran variables numericas:la variable (%s) no es una variable numerica", tablaSimb[posDeTabla].lexema);
		mensajeDeError(ErrorSintactico, msg, linea);
	}
}


int verifRangoID(char *ptr, int linea)
{
	if ((strlen(ptr)) > LIMITE)
	{
		sprintf(msg, "La variable: %s supera el rango permitido", ptr);
		mensajeDeError(ErrorLexico, msg, linea);
	}
	return 0;
}
int verifRangoCTE_ENT(char *ptr, int linea)
{
	if (strlen(ptr) > LIMITEENT || atoi(ptr) > 32767) //no hay numeros negativos en el lexico
	{
		sprintf(msg, "La constante: %s supera el rango permitido", ptr);
		mensajeDeError(ErrorLexico, msg, linea);
	}
	return 0;
}

int verifRangoCTE_REAL(char *ptr, int linea)
{
	if (atof(ptr) > 3.40282347e+38F || atof(ptr) < 3.40282347e-38F)
	{
		sprintf(msg, "la constante real: %s supera el rango permitido", ptr);
		mensajeDeError(ErrorLexico, msg, linea);
	}
	return 0;
}
void errorCaracter(char *ptr, int linea)
{
	sprintf(msg, "Caracter: %s invalido", ptr);
	mensajeDeError(ErrorLexico, msg, linea);
}

void modificarCteFloat(char *cteFlo)
{
	char *aux;
	sprintf(cteFloat, "%scteF", cteFlo);
	if (aux = strstr(cteFloat, "."))
	{
		*aux = '_';
		strcpy(cteFlo, cteFloat);
	}
}


int verificarCompatible(int tipo, int tipoAux)
{

	if (tipo == tipoAux)
		return TRUE;
	if (tipo == CteInt && tipoAux == Integer || tipoAux == CteInt && tipo == Integer)
		return TRUE;
	if (tipo == CteFloat && tipoAux == Float || tipoAux == CteFloat && tipo == Float)
		return TRUE;
	if (tipo == CteString && tipoAux == String || tipoAux == CteString && tipo == String)
		return TRUE;
	return FALSE;
}


