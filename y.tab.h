
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
     WHILE = 258,
     ENDWHILE = 259,
     IF = 260,
     ELSE = 261,
     ENDIF = 262,
     WRITE = 263,
     READ = 264,
     BETWEEN = 265,
     TAKE = 266,
     DECVAR = 267,
     ENDDEC = 268,
     INT = 269,
     REAL = 270,
     STRING = 271,
     CORCHETE_A = 272,
     CORCHETE_C = 273,
     LLAVE_A = 274,
     LLAVE_C = 275,
     PARENTESIS_A = 276,
     PARENTESIS_C = 277,
     COMA = 278,
     PUNTO_COMA = 279,
     DOS_PUNTOS = 280,
     OP_MENOR = 281,
     OP_MAYOR = 282,
     OP_MEN_IGU = 283,
     OP_MAY_IGU = 284,
     OP_NOT = 285,
     OP_AND = 286,
     OP_OR = 287,
     OP_COMP = 288,
     OP_IGUAL = 289,
     CONST_INT = 290,
     CONST_REAL = 291,
     CONST_STRING = 292,
     VARIABLE = 293,
     COMENTARIO_A = 294,
     COMENTARIO_C = 295,
     COMENTARIO = 296,
     OP_SUMA = 298,
     OP_RESTA = 299,
     OP_DIV = 300,
     OP_MULT = 301,
     OP_ASIG = 302
   };
#endif
/* Tokens.  */
#define WHILE 258
#define ENDWHILE 259
#define IF 260
#define ELSE 261
#define ENDIF 262
#define WRITE 263
#define READ 264
#define BETWEEN 265
#define TAKE 266
#define DECVAR 267
#define ENDDEC 268
#define INT 269
#define REAL 270
#define STRING 271
#define CORCHETE_A 272
#define CORCHETE_C 273
#define LLAVE_A 274
#define LLAVE_C 275
#define PARENTESIS_A 276
#define PARENTESIS_C 277
#define COMA 278
#define PUNTO_COMA 279
#define DOS_PUNTOS 280
#define OP_MENOR 281
#define OP_MAYOR 282
#define OP_MEN_IGU 283
#define OP_MAY_IGU 284
#define OP_NOT 285
#define OP_AND 286
#define OP_OR 287
#define OP_COMP 288
#define OP_IGUAL 289
#define CONST_INT 290
#define CONST_REAL 291
#define CONST_STRING 292
#define VARIABLE 293
#define COMENTARIO_A 294
#define COMENTARIO_C 295
#define COMENTARIO 296
#define OP_SUMA 298
#define OP_RESTA 299
#define OP_DIV 300
#define OP_MULT 301
#define OP_ASIG 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 39 "Sintactico.y"

    char* strVal;



/* Line 1676 of yacc.c  */
#line 150 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


