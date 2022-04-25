
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PAL_RESERVADA = 258,
     WHILE = 259,
     ENDWHILE = 260,
     IF = 261,
     ELSE = 262,
     ENDIF = 263,
     TIPO_DATO = 264,
     INT = 265,
     REAL = 266,
     STRING = 267,
     WRITE = 268,
     READ = 269,
     BETWEEN = 270,
     TAKE = 271,
     DECVAR = 272,
     ENDDEC = 273,
     CORCHETE_A = 274,
     CORCHETE_C = 275,
     LLAVE_A = 276,
     LLAVE_C = 277,
     COMA = 278,
     PUNTO_COMA = 279,
     PARENTESIS_A = 280,
     PARENTESIS_C = 281,
     OP_MENOR = 282,
     OP_MAYOR = 283,
     OP_MEN_IGU = 284,
     OP_MAY_IGU = 285,
     OP_NOT = 286,
     OP_AND = 287,
     OP_OR = 288,
     OP_COMP = 289,
     OP_IGUAL = 290,
     CONST_INT = 291,
     CONST_REAL = 292,
     VARIABLE = 293,
     CONST_STRING = 294,
     COMENTARIO_A = 295,
     COMENTARIO_C = 296,
     COMENTARIO = 297,
     OP_SUMA = 299,
     OP_RESTA = 300,
     OP_DIV = 301,
     OP_MULT = 302,
     MENOS_UNARIO = 303,
     OP_ASIG = 304
   };
#endif
/* Tokens.  */
#define PAL_RESERVADA 258
#define WHILE 259
#define ENDWHILE 260
#define IF 261
#define ELSE 262
#define ENDIF 263
#define TIPO_DATO 264
#define INT 265
#define REAL 266
#define STRING 267
#define WRITE 268
#define READ 269
#define BETWEEN 270
#define TAKE 271
#define DECVAR 272
#define ENDDEC 273
#define CORCHETE_A 274
#define CORCHETE_C 275
#define LLAVE_A 276
#define LLAVE_C 277
#define COMA 278
#define PUNTO_COMA 279
#define PARENTESIS_A 280
#define PARENTESIS_C 281
#define OP_MENOR 282
#define OP_MAYOR 283
#define OP_MEN_IGU 284
#define OP_MAY_IGU 285
#define OP_NOT 286
#define OP_AND 287
#define OP_OR 288
#define OP_COMP 289
#define OP_IGUAL 290
#define CONST_INT 291
#define CONST_REAL 292
#define VARIABLE 293
#define CONST_STRING 294
#define COMENTARIO_A 295
#define COMENTARIO_C 296
#define COMENTARIO 297
#define OP_SUMA 299
#define OP_RESTA 300
#define OP_DIV 301
#define OP_MULT 302
#define MENOS_UNARIO 303
#define OP_ASIG 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 19 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"

    char* strVal;



/* Line 1676 of yacc.c  */
#line 154 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


