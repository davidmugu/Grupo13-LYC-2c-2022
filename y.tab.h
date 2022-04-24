
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
     INT = 263,
     REAL = 264,
     STRING = 265,
     WRITE = 266,
     READ = 267,
     BETWEEN = 268,
     TAKE = 269,
     DECVAR = 270,
     ENDDEC = 271,
     CORCHETE_A = 272,
     CORCHETE_C = 273,
     COMA = 274,
     PUNTO_COMA = 275,
     PARENTESIS_A = 276,
     PARENTESIS_C = 277,
     OP_MENOR = 278,
     OP_MAYOR = 279,
     OP_MEN_IGU = 280,
     OP_MAY_IGU = 281,
     OP_NOT = 282,
     OP_AND = 283,
     OP_OR = 284,
     OP_COMP = 285,
     CONST_INT = 286,
     CONST_REAL = 287,
     VARIABLE = 288,
     CONST_STRING = 289,
     COMENTARIO_A = 290,
     COMENTARIO_C = 291,
     COMENTARIO = 292,
     OP_SUMA = 294,
     OP_RESTA = 295,
     OP_DIV = 296,
     OP_MULT = 297,
     MENOS_UNARIO = 298,
     OP_ASIG = 299
   };
#endif
/* Tokens.  */
#define WHILE 258
#define ENDWHILE 259
#define IF 260
#define ELSE 261
#define ENDIF 262
#define INT 263
#define REAL 264
#define STRING 265
#define WRITE 266
#define READ 267
#define BETWEEN 268
#define TAKE 269
#define DECVAR 270
#define ENDDEC 271
#define CORCHETE_A 272
#define CORCHETE_C 273
#define COMA 274
#define PUNTO_COMA 275
#define PARENTESIS_A 276
#define PARENTESIS_C 277
#define OP_MENOR 278
#define OP_MAYOR 279
#define OP_MEN_IGU 280
#define OP_MAY_IGU 281
#define OP_NOT 282
#define OP_AND 283
#define OP_OR 284
#define OP_COMP 285
#define CONST_INT 286
#define CONST_REAL 287
#define VARIABLE 288
#define CONST_STRING 289
#define COMENTARIO_A 290
#define COMENTARIO_C 291
#define COMENTARIO 292
#define OP_SUMA 294
#define OP_RESTA 295
#define OP_DIV 296
#define OP_MULT 297
#define MENOS_UNARIO 298
#define OP_ASIG 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 20 "Sintactico.y"

    char* strVal;



/* Line 1676 of yacc.c  */
#line 144 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


