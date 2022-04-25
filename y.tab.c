
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"

#include "lista.h"
#include "pila.h"
#include "y.tab.h"

FILE *yyin;

Lista tablaSimbolos;
Pila pilaVariables;
Pila pilaTiposDatos;

extern int yylex();
extern void yyerror();
extern char* yytext;
extern int yylineno;



/* Line 189 of yacc.c  */
#line 92 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 19 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"

    char* strVal;



/* Line 214 of yacc.c  */
#line 230 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 242 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    50,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    14,    16,    18,    20,
      22,    24,    26,    28,    32,    36,    40,    42,    44,    46,
      50,    54,    56,    60,    64,    67,    69,    73,    75,    77,
      78,    84,    86,    87,    93,   100,   101,   102,   109,   110,
     115,   119,   125,   131,   137,   143,   146,   152,   158,   164,
     170,   174,   178,   182,   186,   190,   194,   198,   202,   206,
     209,   220,   231,   233,   235,   237,   239,   241,   245,   247,
     249,   252,   254
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    54,    -1,    54,    55,    24,
      -1,    55,    24,    -1,    56,    -1,    65,    -1,    62,    -1,
      72,    -1,    73,    -1,    77,    -1,    78,    -1,    38,    49,
      59,    -1,    38,    49,    57,    -1,    38,    49,    58,    -1,
      39,    -1,    36,    -1,    37,    -1,    59,    44,    60,    -1,
      59,    45,    60,    -1,    60,    -1,    60,    47,    61,    -1,
      60,    46,    61,    -1,    50,    60,    -1,    61,    -1,    25,
      59,    26,    -1,    58,    -1,    38,    -1,    -1,     4,    70,
      63,    64,     5,    -1,    54,    -1,    -1,     6,    70,    54,
      66,     8,    -1,     6,    70,    54,     7,    54,     8,    -1,
      -1,    -1,     6,    70,    67,     7,    68,     8,    -1,    -1,
       6,    70,    69,     8,    -1,    25,    70,    26,    -1,    25,
      70,    33,    70,    26,    -1,    25,    70,    32,    70,    26,
      -1,    25,    70,    33,    71,    26,    -1,    25,    70,    32,
      71,    26,    -1,    31,    70,    -1,    25,    71,    33,    70,
      26,    -1,    25,    71,    32,    70,    26,    -1,    25,    71,
      32,    71,    26,    -1,    25,    71,    33,    71,    26,    -1,
      25,    71,    26,    -1,    59,    34,    59,    -1,    59,    30,
      59,    -1,    59,    29,    59,    -1,    59,    27,    59,    -1,
      59,    28,    59,    -1,    59,    32,    59,    -1,    59,    33,
      59,    -1,    59,    31,    60,    -1,    31,    38,    -1,    15,
      25,    38,    23,    19,    59,    24,    59,    20,    26,    -1,
      16,    25,    74,    24,    36,    24,    19,    75,    20,    26,
      -1,    44,    -1,    45,    -1,    47,    -1,    47,    -1,    76,
      -1,    75,    23,    76,    -1,    36,    -1,    37,    -1,    13,
      38,    -1,    76,    -1,    14,    38,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    72,    72,    75,    78,    79,    83,    84,    85,    86,
      87,    88,    89,    92,    93,    94,    97,   101,   104,   108,
     109,   110,   113,   114,   115,   116,   120,   121,   122,   125,
     125,   130,   134,   133,   136,   141,   142,   141,   144,   144,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     183,   185,   187,   188,   189,   190,   194,   195,   198,   199,
     212,   212,   213
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PAL_RESERVADA", "WHILE", "ENDWHILE",
  "IF", "ELSE", "ENDIF", "TIPO_DATO", "INT", "REAL", "STRING", "WRITE",
  "READ", "BETWEEN", "TAKE", "DECVAR", "ENDDEC", "CORCHETE_A",
  "CORCHETE_C", "LLAVE_A", "LLAVE_C", "COMA", "PUNTO_COMA", "PARENTESIS_A",
  "PARENTESIS_C", "OP_MENOR", "OP_MAYOR", "OP_MEN_IGU", "OP_MAY_IGU",
  "OP_NOT", "OP_AND", "OP_OR", "OP_COMP", "OP_IGUAL", "CONST_INT",
  "CONST_REAL", "VARIABLE", "CONST_STRING", "COMENTARIO_A", "COMENTARIO_C",
  "COMENTARIO", ".", "OP_SUMA", "OP_RESTA", "OP_DIV", "OP_MULT",
  "MENOS_UNARIO", "OP_ASIG", "'-'", "$accept", "programa", "prog",
  "sentencia", "grammar", "asig", "CONST_STRING_R", "NUMERO", "expr",
  "termino", "factor", "while", "$@1", "while_exp", "if", "$@2", "$@3",
  "$@4", "$@5", "cond_completa", "cond", "between", "take", "operador",
  "lista_cte", "expr_cte", "write", "read", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      45
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    57,    58,    58,    59,
      59,    59,    60,    60,    60,    60,    61,    61,    61,    63,
      62,    64,    66,    65,    65,    67,    68,    65,    69,    65,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    73,    74,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     1,     1,     1,     3,
       3,     1,     3,     3,     2,     1,     3,     1,     1,     0,
       5,     1,     0,     5,     6,     0,     0,     6,     0,     4,
       3,     5,     5,     5,     5,     2,     5,     5,     5,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
      10,    10,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    68,    69,     0,
       0,     2,     3,     0,     6,     8,     7,     9,    10,    71,
      11,    12,     0,     0,    29,    35,    70,    72,     0,     0,
       0,     1,     0,     5,     0,     0,    17,    18,    28,     0,
      27,     0,    21,    25,     0,     0,    45,     0,    32,     0,
       0,     0,    62,    63,    64,     0,     0,    16,    14,    27,
      13,     4,     0,    59,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
      50,     0,     0,    31,     0,     0,     0,    36,    39,     0,
       0,     0,    26,    54,    55,    53,    52,    58,    56,    57,
      51,    19,    20,    23,    22,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    33,     0,     0,     0,    42,
      44,    41,    43,    47,    48,    46,    49,    34,    37,     0,
       0,     0,     0,     0,     0,    66,     0,     0,     0,    60,
      61,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    58,    40,    41,    42,
      43,    15,    47,    84,    16,    86,    49,   116,    50,    44,
      45,    17,    18,    55,   134,    19,    20,    21
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -129
static const yytype_int16 yypact[] =
{
      94,   -22,   -22,    -3,    19,   -11,    55,  -129,  -129,    37,
     117,  -129,    94,    35,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,    68,   -22,  -129,    11,  -129,  -129,    56,    34,
      -5,  -129,    91,  -129,    68,   -20,  -129,  -129,  -129,    76,
    -129,   115,   -34,  -129,    95,   124,  -129,    94,    59,   113,
     121,   102,  -129,  -129,  -129,   131,    76,  -129,  -129,   134,
       8,  -129,   107,  -129,  -129,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    86,    86,  -129,    68,    68,
    -129,    68,    68,    94,   158,    94,   159,  -129,  -129,   147,
     132,    38,  -129,     8,     8,     8,     8,   -34,     8,     8,
       8,   -34,   -34,  -129,  -129,   143,   144,   145,   146,   148,
     149,   150,   151,  -129,    54,  -129,   165,    76,   154,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,    32,
     160,    76,   -15,    10,    96,  -129,   155,   156,   -15,  -129,
    -129,  -129
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,   -24,   -12,  -129,  -129,   153,   -28,   -23,
      78,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,     6,
      83,  -129,  -129,  -129,  -129,  -128,  -129,  -129
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -39
static const yytype_int16 yytable[] =
{
      32,    48,    60,    22,   135,    22,    62,    24,    25,    23,
     141,    23,    75,    76,    28,     1,    64,     2,    63,   -38,
      56,     7,     8,    83,     3,     4,     5,     6,    91,    46,
     136,    36,    37,    38,    57,    26,    32,    93,    94,    95,
      96,    46,    98,    99,   100,    39,    97,     7,     8,     9,
     101,   102,    73,    74,    73,    74,   131,    27,     1,    33,
       2,   114,   127,     1,    92,     2,    85,     3,     4,     5,
       6,    32,     3,     4,     5,     6,    73,    74,    52,    53,
      29,    54,    73,    74,   105,   107,    30,   109,   111,   129,
       7,     8,     9,    34,    51,     7,     8,     9,     1,    35,
       2,    56,    32,   133,    36,    37,    38,     3,     4,     5,
       6,    56,    36,    37,    38,    61,   137,    31,    39,   138,
      87,    77,    36,    37,    38,    89,    39,    78,    79,    88,
       7,     8,     9,    92,    65,    66,    67,    68,    69,    70,
      71,    72,    65,    66,    67,    68,    69,    70,    71,    72,
      80,    73,    74,   103,   104,    90,    81,    82,   -15,    73,
      74,   106,   108,   113,   110,   112,   117,   115,   118,   119,
     120,   121,   122,   128,   123,   124,   125,   126,   130,   132,
       0,   139,   140,    59
};

static const yytype_int16 yycheck[] =
{
      12,    25,    30,    25,   132,    25,    34,     1,     2,    31,
     138,    31,    46,    47,    25,     4,    39,     6,    38,     8,
      25,    36,    37,    47,    13,    14,    15,    16,    56,    23,
      20,    36,    37,    38,    39,    38,    48,    65,    66,    67,
      68,    35,    70,    71,    72,    50,    69,    36,    37,    38,
      73,    74,    44,    45,    44,    45,    24,    38,     4,    24,
       6,    85,     8,     4,    26,     6,     7,    13,    14,    15,
      16,    83,    13,    14,    15,    16,    44,    45,    44,    45,
      25,    47,    44,    45,    78,    79,    49,    81,    82,   117,
      36,    37,    38,    25,    38,    36,    37,    38,     4,    31,
       6,    25,   114,   131,    36,    37,    38,    13,    14,    15,
      16,    25,    36,    37,    38,    24,    20,     0,    50,    23,
       7,    26,    36,    37,    38,    23,    50,    32,    33,     8,
      36,    37,    38,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    27,    28,    29,    30,    31,    32,    33,    34,
      26,    44,    45,    75,    76,    24,    32,    33,    24,    44,
      45,    78,    79,     5,    81,    82,    19,     8,    36,    26,
      26,    26,    26,     8,    26,    26,    26,    26,    24,    19,
      -1,    26,    26,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     6,    13,    14,    15,    16,    36,    37,    38,
      52,    53,    54,    55,    56,    62,    65,    72,    73,    76,
      77,    78,    25,    31,    70,    70,    38,    38,    25,    25,
      49,     0,    55,    24,    25,    31,    36,    37,    38,    50,
      58,    59,    60,    61,    70,    71,    70,    63,    54,    67,
      69,    38,    44,    45,    47,    74,    25,    39,    57,    58,
      59,    24,    59,    38,    60,    27,    28,    29,    30,    31,
      32,    33,    34,    44,    45,    46,    47,    26,    32,    33,
      26,    32,    33,    54,    64,     7,    66,     7,     8,    23,
      24,    59,    26,    59,    59,    59,    59,    60,    59,    59,
      59,    60,    60,    61,    61,    70,    71,    70,    71,    70,
      71,    70,    71,     5,    54,     8,    68,    19,    36,    26,
      26,    26,    26,    26,    26,    26,    26,     8,     8,    59,
      24,    24,    19,    59,    75,    76,    20,    20,    23,    26,
      26,    76
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 75 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 78 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 79 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 83 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - fin de Sentencia de asignacion \n\n");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 84 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - fin de Sentencia de IF \n\n");}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 85 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - fin de Sentencia de While \n\n");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 86 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - fin de Sentencia de Between \n\n");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 87 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - fin de Sentencia de Take \n\n");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 88 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - fin de Sentencia de Write \n\n");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 89 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - fin de Sentencia de Read \n\n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 92 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de asignacion por expresion \n");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 93 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de asignacion por constante string \n");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 94 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de asignacion por constante entera \n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 97 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {
	    insertarString(&tablaSimbolos, (yyvsp[(1) - (1)].strVal));
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 101 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {
        insertarEntero(&tablaSimbolos,(yyvsp[(1) - (1)].strVal));
      }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 104 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {
        insertarReal(&tablaSimbolos,(yyvsp[(1) - (1)].strVal));
      }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 108 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de suma \n");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 109 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de resta \n");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 110 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 113 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de multiplicacion\n");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 114 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de division\n");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 116 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 120 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 121 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 122 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 125 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de while con condicion\n");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 130 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 134 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 135 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 141 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - if y else sin sentencia\n");}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 142 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 143 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 144 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - if sin sentencia\n");}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 145 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - fin de if sin sentencia\n");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 148 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 149 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de condicion OR multiple\n");}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 150 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de condicion AND multiple\n");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 151 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de condicion OR multiple\n");}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 152 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de condicion AND multiple\n");}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 153 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de condicion negada\n");}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 154 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de condicion OR multiple\n");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 155 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de condicion AND multiple\n");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 156 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de condicion AND multiple\n");}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 157 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de condicion OR multiple\n");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 158 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de condicion simple\n");}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 172 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 173 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 174 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 175 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 176 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 177 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 178 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 179 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 180 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 183 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de Between\n");}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 185 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {printf("Regla - Sentencia de Take\n");}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 187 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 188 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 189 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 190 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 194 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 195 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 198 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 199 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 212 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 213 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"
    {;}
    break;



/* Line 1455 of yacc.c  */
#line 2043 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 220 "C:\\Users\\santi\\Documents\\Proyectos\\TP-LyC\\Grupo13-LYC-2c-2022\\Sintactico.y"



int main(int argc, char* argv[])
{
    if((yyin = fopen(argv[1],"rt")) == NULL)
    {
        printf("\n No se puede abrir el archivo %s \n", argv[1]);
    }

    printf("\n Compilando... \n\n");

    printf("Se procede a crear la Tabla de Simbolos\n");
    crearLista(&tablaSimbolos);
    printf("La Tabla de Simbolos se creo correctamente\n");
    printf("Se procede a crear la Pila de Variables\n");
    crearPila(&pilaVariables);
    printf("La Pila de Variables se creo correctamente\n");
    printf("Se procede a crear la Pila de Tipos de Datos\n");
    crearPila(&pilaTiposDatos);
    printf("La Pila de Tipos de Datos se creo correctamente\n");

    yyparse();

    printf("Se procede a eliminar la Tabla de Simbolos\n");
    eliminarTabla(&tablaSimbolos);
    printf("La Tabla de Simbolos se elimino correctamente\n");
    
    printf("\n Compilacion exitosa \n");
    fclose(yyin);
    return 0;
}
