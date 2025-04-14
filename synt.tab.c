
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
#line 1 "synt.y"
#include<stdio.h>
#include "synt.tab.h"  
#include <string.h>
extern int num_de_lignes;
extern int col;
extern char *yytext; 
char tabl_inter [100][20];
char tabl_inter2 [100][20];
int cpt= 0;
int cpt2= 0;
char sauvtype [20];
char sauv [20];
double sauvval; 
int indicetab; 



/* Line 189 of yacc.c  */
#line 91 "synt.tab.c"

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
     MainPrgm = 258,
     idf = 259,
     pnt_virgul = 260,
     var = 261,
     BeginPg = 262,
     accolade_ouvr = 263,
     accolade_ferm = 264,
     EndPg = 265,
     let = 266,
     deux_pnts = 267,
     constante = 268,
     egal = 269,
     virgul = 270,
     reel = 271,
     entier = 272,
     entier_pos = 273,
     corechet_ouvr = 274,
     corechet_ferm = 275,
     entier_neg = 276,
     reel_pos = 277,
     reel_neg = 278,
     affect = 279,
     chaine = 280,
     if_cond = 281,
     then = 282,
     parenthese_ferm = 283,
     parenthese_ouvr = 284,
     lire = 285,
     output = 286,
     add = 287,
     soustract = 288,
     division = 289,
     multipl = 290,
     inf = 291,
     sup = 292,
     inf_ou_egal = 293,
     sup_ou_egal = 294,
     neg = 295,
     and = 296,
     or = 297,
     diff = 298,
     boucle_for = 299,
     from = 300,
     to = 301,
     step = 302,
     boucle_do = 303,
     boucle_while = 304,
     else_cond = 305,
     identiq = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 17 "synt.y"

int entier;
char* str;
float reel;



/* Line 214 of yacc.c  */
#line 186 "synt.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 198 "synt.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    15,    16,    23,    27,    36,    40,    42,
      51,    60,    62,    64,    66,    68,    72,    74,    76,    78,
      80,    81,    85,    89,    92,    95,    98,   101,   104,   109,
     113,   117,   121,   125,   129,   133,   136,   138,   140,   142,
     144,   146,   148,   155,   156,   160,   166,   168,   170,   174,
     178,   188,   193,   194,   198,   202,   205,   209,   213,   215,
     217,   219,   221,   223,   225,   227,   237
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,     3,     4,     5,     6,    54,     7,     8,
      61,     9,    10,     5,    -1,    -1,    11,    58,    12,    59,
       5,    54,    -1,    56,     5,    54,    -1,    13,    55,    12,
      59,    14,    57,     5,    54,    -1,     4,    15,    55,    -1,
       4,    -1,    11,    58,    12,    19,    16,     5,    18,    20,
      -1,    11,    58,    12,    19,    17,     5,    18,    20,    -1,
      18,    -1,    21,    -1,    22,    -1,    23,    -1,     4,    15,
      58,    -1,     4,    -1,    16,    -1,    17,    -1,     4,    -1,
      -1,    60,    63,    61,    -1,    60,    62,    61,    -1,    66,
      61,    -1,    68,    61,    -1,    70,    61,    -1,    74,    61,
      -1,    75,    61,    -1,    19,    18,    20,    63,    -1,    24,
      64,     5,    -1,    29,    64,    28,    -1,    64,    32,    64,
      -1,    64,    33,    64,    -1,    64,    35,    64,    -1,    64,
      34,    64,    -1,    40,    64,    -1,     4,    -1,    65,    -1,
      18,    -1,    21,    -1,    22,    -1,    23,    -1,    30,    29,
       4,    67,    28,     5,    -1,    -1,    15,     4,    67,    -1,
      31,    29,    69,    28,     5,    -1,    25,    -1,     4,    -1,
      25,    15,    69,    -1,     4,    15,    69,    -1,    26,    29,
      72,    28,    27,     8,    61,     9,    71,    -1,    50,     8,
      61,     9,    -1,    -1,    72,    41,    72,    -1,    72,    42,
      72,    -1,    40,    72,    -1,    29,    72,    28,    -1,    64,
      73,    64,    -1,    64,    -1,    36,    -1,    37,    -1,    38,
      -1,    39,    -1,    51,    -1,    43,    -1,    48,     8,    61,
       9,    49,    29,    72,    28,     5,    -1,    44,     4,    45,
      18,    46,    18,    47,    18,     8,    61,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    44,    44,    51,    52,    53,    54,    56,    57,    60,
      71,    83,    90,    97,   104,   113,   113,   115,   124,   135,
     137,   137,   142,   150,   150,   150,   150,   150,   152,   154,
     165,   166,   167,   169,   170,   173,   174,   179,   184,   184,
     184,   184,   187,   191,   191,   195,   197,   197,   200,   201,
     205,   207,   207,   210,   211,   212,   213,   214,   215,   218,
     218,   218,   218,   218,   218,   220,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MainPrgm", "idf", "pnt_virgul", "var",
  "BeginPg", "accolade_ouvr", "accolade_ferm", "EndPg", "let", "deux_pnts",
  "constante", "egal", "virgul", "reel", "entier", "entier_pos",
  "corechet_ouvr", "corechet_ferm", "entier_neg", "reel_pos", "reel_neg",
  "affect", "chaine", "if_cond", "then", "parenthese_ferm",
  "parenthese_ouvr", "lire", "output", "add", "soustract", "division",
  "multipl", "inf", "sup", "inf_ou_egal", "sup_ou_egal", "neg", "and",
  "or", "diff", "boucle_for", "from", "to", "step", "boucle_do",
  "boucle_while", "else_cond", "identiq", "$accept", "DEBUT",
  "DECLARATION_LIST", "VARIABLEConst", "DECLARATION_Tableau", "VALEUR",
  "VARIABLE", "TYPE1", "IDFS", "INSTRUCTIONS", "AFFECTATION_TAB",
  "AFFECTATION_NOR", "EXPRESSION_ADD", "VALEUR2", "INPUT", "REPETITION",
  "OUTPUT", "DANS_OUTPUT", "CONDITION", "SINON", "EXPRESSION_COND",
  "OPERATEUR_COND", "LOOP_DO", "LOOP_FOR", 0
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
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    57,    58,    58,    59,    59,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      65,    65,    66,    67,    67,    68,    69,    69,    69,    69,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    74,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,     0,     6,     3,     8,     3,     1,     8,
       8,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       0,     3,     3,     2,     2,     2,     2,     2,     4,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     6,     0,     3,     5,     1,     1,     3,     3,
       9,     4,     0,     3,     3,     2,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     9,    11
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       0,    16,     0,     8,     0,     0,     3,     0,     0,     0,
       0,    20,     5,    15,    17,    18,     0,     0,     7,     0,
      19,     0,     0,     0,     0,     0,     0,     0,    20,    20,
      20,    20,    20,     0,     0,     3,     0,     0,     0,     0,
       0,    20,     0,     0,    20,    20,     0,    23,    24,    25,
      26,    27,     0,     0,     4,    11,    12,    13,    14,     0,
      36,    38,    39,    40,    41,     0,     0,    58,    37,     0,
      43,    47,    46,     0,     0,     0,     0,     0,     0,     0,
      22,    21,     0,     0,     0,     3,    58,     0,    35,    55,
       0,     0,     0,     0,    59,    60,    61,    62,    64,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    29,     2,     9,    10,     6,    30,
      56,    31,    32,    34,    33,    57,     0,    53,    54,    43,
       0,    49,    48,    45,     0,     0,    28,    20,    44,    42,
       0,     0,     0,     0,     0,    52,     0,     0,     0,    50,
      20,    65,    20,     0,     0,    66,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    14,    10,    69,    12,    27,    36,    37,
      54,    55,    77,    78,    38,   115,    39,    83,    40,   159,
      79,   110,    41,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
      16,    19,    33,    45,   -70,    32,    43,    38,    49,    50,
      71,    68,    89,    88,    96,    72,    43,    38,    51,    49,
      -5,    21,   -70,   -70,   -70,   -70,    62,   115,   -70,   109,
     -70,   101,   102,   103,   129,   126,    -4,   127,    21,    21,
      21,    21,    21,   130,   132,    43,    84,     6,   134,     5,
      94,    21,   122,    37,    21,    21,   131,   -70,   -70,   -70,
     -70,   -70,   124,   125,   -70,   -70,   -70,   -70,   -70,   139,
     -70,   -70,   -70,   -70,   -70,     6,     6,    78,   -70,   -20,
     133,   135,   136,   117,   128,   138,   137,    37,    37,    40,
     -70,   -70,   144,   140,   141,    43,    53,   -10,    78,   -70,
      37,    37,    37,    37,   -70,   -70,   -70,   -70,   -70,   -70,
      37,   142,     6,     6,   148,   143,     5,     5,   149,   107,
     106,   146,    65,    93,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,    60,    60,   -70,   -70,    93,   150,   -70,   118,   133,
     151,   -70,   -70,   -70,   145,   147,   -70,    21,   -70,   -70,
     119,     6,   153,   154,    -2,   114,   157,   162,   160,   -70,
      21,   -70,    21,   164,   165,   -70,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -11,   156,   -70,   -70,   161,   159,   -70,   -38,
     -70,    56,   -39,   -70,   -70,    41,   -70,     2,   -70,   -70,
     -69,   -70,   -70,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      57,    58,    59,    60,    61,    22,    97,    99,   111,    81,
      70,    24,    25,    85,    89,    52,    90,    91,   130,     1,
      53,   112,   113,     3,    71,    30,   157,    72,    73,    74,
      82,   112,   113,     4,    64,    75,    96,    98,     6,   112,
     113,    70,    11,   137,   138,   124,    76,    31,   122,   123,
       5,    32,    33,    13,     7,    71,     8,    15,    72,    73,
      74,   131,   132,   133,   134,    34,    87,    24,    25,    35,
      26,   135,   100,   101,   102,   103,    16,    88,    43,    44,
      21,   129,   154,    17,   128,   100,   101,   102,   103,   104,
     105,   106,   107,   129,   102,   103,   108,   100,   101,   102,
     103,    18,    65,    19,   109,    66,    67,    68,    20,   152,
     100,   101,   102,   103,   104,   105,   106,   107,   141,   142,
      45,   108,   163,    46,   164,   100,   101,   102,   103,   109,
      47,    48,    49,    50,    51,    62,    56,    63,    80,    84,
      86,    92,    93,    94,    95,   118,   119,   120,   114,   125,
     116,   117,   139,   144,   143,   145,   149,   121,   147,   112,
     126,   127,   155,   150,   158,   160,   153,   161,   162,   136,
      53,   140,   156,   165,   166,    28,   151,   146,    23,    29,
     148
};

static const yytype_uint8 yycheck[] =
{
      38,    39,    40,    41,    42,    16,    75,    76,    28,     4,
       4,    16,    17,    51,    53,    19,    54,    55,    28,     3,
      24,    41,    42,     4,    18,     4,    28,    21,    22,    23,
      25,    41,    42,     0,    45,    29,    75,    76,     6,    41,
      42,     4,     4,   112,   113,     5,    40,    26,    87,    88,
       5,    30,    31,     4,    11,    18,    13,     7,    21,    22,
      23,   100,   101,   102,   103,    44,    29,    16,    17,    48,
      19,   110,    32,    33,    34,    35,     5,    40,    16,    17,
       8,    28,   151,    15,    95,    32,    33,    34,    35,    36,
      37,    38,    39,    28,    34,    35,    43,    32,    33,    34,
      35,    12,    18,    15,    51,    21,    22,    23,    12,   147,
      32,    33,    34,    35,    36,    37,    38,    39,   116,   117,
       5,    43,   160,    14,   162,    32,    33,    34,    35,    51,
      29,    29,    29,     4,     8,     5,     9,     5,     4,    45,
      18,    10,    18,    18,     5,    28,    18,     9,    15,     5,
      15,    15,     4,    46,     5,    49,     5,    20,     8,    41,
      20,    20,     9,    18,    50,     8,    47,     5,     8,    27,
      24,    28,    18,     9,     9,    19,    29,   121,    17,    20,
     139
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,     4,     0,     5,     6,    11,    13,    54,
      56,     4,    58,     4,    55,     7,     5,    15,    12,    15,
      12,     8,    54,    58,    16,    17,    19,    59,    55,    59,
       4,    26,    30,    31,    44,    48,    60,    61,    66,    68,
      70,    74,    75,    16,    17,     5,    14,    29,    29,    29,
       4,     8,    19,    24,    62,    63,     9,    61,    61,    61,
      61,    61,     5,     5,    54,    18,    21,    22,    23,    57,
       4,    18,    21,    22,    23,    29,    40,    64,    65,    72,
       4,     4,    25,    69,    45,    61,    18,    29,    40,    64,
      61,    61,    10,    18,    18,     5,    64,    72,    64,    72,
      32,    33,    34,    35,    36,    37,    38,    39,    43,    51,
      73,    28,    41,    42,    15,    67,    15,    15,    28,    18,
       9,    20,    64,    64,     5,     5,    20,    20,    54,    28,
      28,    64,    64,    64,    64,    64,    27,    72,    72,     4,
      28,    69,    69,     5,    46,    49,    63,     8,    67,     5,
      18,    29,    61,    47,    72,     9,    18,    28,    50,    71,
       8,     5,     8,    61,    61,     9,     9
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
        case 2:

/* Line 1455 of yacc.c  */
#line 49 "synt.y"
    {printf("correcte syntaxiquement"); YYACCEPT ;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 56 "synt.y"
    {  strcpy(tabl_inter2[cpt2], (yyvsp[(1) - (3)].str)); cpt2 ++; strcpy(tabl_inter[cpt], (yyvsp[(1) - (3)].str)); cpt ++; insererConstante((yyvsp[(1) - (3)].str)); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 57 "synt.y"
    {  strcpy(tabl_inter2[cpt2], (yyvsp[(1) - (1)].str)); cpt2 ++; strcpy(tabl_inter[cpt], (yyvsp[(1) - (1)].str)); cpt ++;insererConstante((yyvsp[(1) - (1)].str)); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 61 "synt.y"
    { int i ;
        for (i = 0 ; i<cpt; i ++ ){
          if (rechercheType(tabl_inter[i],0)==0){
             insererType(tabl_inter[i],(yyvsp[(5) - (8)].str) , 0);
          insererTailleTableau(tabl_inter[i], (yyvsp[(7) - (8)].entier));
          }else{
            printf("erreur semantique double declaration de : %s a la ligne %d",tabl_inter[i],num_de_lignes);
          }
        }
        cpt =0 ; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 72 "synt.y"
    { int i ;
        for (i = 0 ; i<cpt; i ++ ){
          if (rechercheType(tabl_inter[i],0)==0){
            insererType(tabl_inter[i],(yyvsp[(5) - (8)].str) , 0);
          insererTailleTableau(tabl_inter[i], (yyvsp[(7) - (8)].entier));
          }else{
            printf("erreur semantique double declaration de : %s a la ligne %d",tabl_inter[i],num_de_lignes);
          }
        }
        cpt =0 ; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 83 "synt.y"
    {
  sauvval= (yyvsp[(1) - (1)].entier); int i ;
        for (i = 0 ; i<cpt2; i ++ ){
          
          insererVal(tabl_inter2[i],sauvval , 0);
          
        }
        cpt2 =0 ; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 90 "synt.y"
    {
  sauvval= (yyvsp[(1) - (1)].entier); int i ;
        for (i = 0 ; i<cpt2; i ++ ){
         
          insererVal(tabl_inter2[i],sauvval , 0);
         
        }
        cpt2 =0 ; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 97 "synt.y"
    {
  sauvval= (yyvsp[(1) - (1)].reel); int i ;
        for (i = 0 ; i<cpt2; i ++ ){
          
          insererVal(tabl_inter2[i],sauvval , 0);
          
        }
        cpt2 =0 ; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 104 "synt.y"
    {
  sauvval= (yyvsp[(1) - (1)].reel); int i ;
        for (i = 0 ; i<cpt2; i ++ ){
          
          insererVal(tabl_inter2[i],sauvval , 0);
        
        }
        cpt2 =0 ; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 113 "synt.y"
    { strcpy(tabl_inter[cpt], (yyvsp[(1) - (3)].str)); cpt ++; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 113 "synt.y"
    { strcpy(tabl_inter[cpt], (yyvsp[(1) - (1)].str)); cpt ++;  ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 115 "synt.y"
    {printf("TYPE1 start (reel): cpt=%d\n", cpt); strcpy(sauvtype , (yyvsp[(1) - (1)].str)) ; int i ;
        for (i = 0 ; i<cpt; i ++ ){
          if (rechercheType(tabl_inter[i],0)==0){
          insererType(tabl_inter[i],sauvtype , 0);
          }else{
            printf("erreur semantique double declaration de : %s a la ligne %d",tabl_inter[i],num_de_lignes);
          }
        }
         cpt=0;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 124 "synt.y"
    {strcpy(sauvtype , (yyvsp[(1) - (1)].str)) ; int i ;
        for (i = 0 ; i<cpt; i ++ ){
          if (rechercheType(tabl_inter[i],0)==0){
          insererType(tabl_inter[i],sauvtype , 0);
          }else{
            printf("erreur semantique double declaration de : %s a la ligne %d",tabl_inter[i],num_de_lignes);
          }
        }
        cpt=0; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 135 "synt.y"
    {strcpy(sauv , (yyvsp[(1) - (1)].str)); (yyval.str) = (yyvsp[(1) - (1)].str) ;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 137 "synt.y"
    {  if (rechercheType((yyvsp[(1) - (3)].str),0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",(yyvsp[(1) - (3)].str),num_de_lignes);
} 

;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 142 "synt.y"
    { 

  if (rechercheType((yyvsp[(1) - (3)].str),0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",(yyvsp[(1) - (3)].str),num_de_lignes);
  if ( recherchertailleTableau ((yyvsp[(1) - (3)].str))< indicetab){
    printf("depasement de taille du tableau de %s",(yyvsp[(1) - (3)].str));
  }
} ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 152 "synt.y"
    {indicetab= (yyvsp[(2) - (4)].entier) ; (yyval.reel)= (yyvsp[(4) - (4)].reel) ; ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 154 "synt.y"
    {
   if (strcmp(recherchertype(sauv), checkNumberType((yyvsp[(2) - (3)].reel))) != 0   ) { 
     printf (" erreur semantique non compatibilite de type a la ligne %d %s \n", num_de_lignes , checkNumberType((yyvsp[(2) - (3)].reel))) ;}
   if (estConstante(sauv) == 1) {
    printf("erreur semantique modification de valeur de constante %s à la ligne %d\n", sauv, num_de_lignes);
   }else{
     insererVal (sauv, (yyvsp[(2) - (3)].reel) , 0) ;
   }
    (yyval.reel) = (yyvsp[(2) - (3)].reel) ;;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 165 "synt.y"
    { (yyval.reel) = (yyvsp[(2) - (3)].reel) ;;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 166 "synt.y"
    { (yyval.reel) = (yyvsp[(1) - (3)].reel) + (yyvsp[(3) - (3)].reel) ; ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 167 "synt.y"
    { 
(yyval.reel) = (yyvsp[(1) - (3)].reel) - (yyvsp[(3) - (3)].reel) ; ;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 169 "synt.y"
    { (yyval.reel) = (yyvsp[(1) - (3)].reel) * (yyvsp[(3) - (3)].reel) ;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 170 "synt.y"
    {
   if ((yyvsp[(3) - (3)].reel) == 0) {printf("erreur semantique division par zero a la ligne %d \n", num_de_lignes);}
 (yyval.reel) = (yyvsp[(1) - (3)].reel) / (yyvsp[(3) - (3)].reel) ;;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 173 "synt.y"
    { (yyval.reel) = -(yyvsp[(2) - (2)].reel) ;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 174 "synt.y"
    { 
  (yyval.reel) = rechercherval((yyvsp[(1) - (1)].str));
  if (rechercheType((yyvsp[(1) - (1)].str),0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",(yyvsp[(1) - (1)].str),num_de_lignes);
  
} ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 179 "synt.y"
    {  (yyval.reel) = (yyvsp[(1) - (1)].reel) ; ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 184 "synt.y"
    { (yyval.reel) = (yyvsp[(1) - (1)].entier) ;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 184 "synt.y"
    { (yyval.reel) = (yyvsp[(1) - (1)].entier) ;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 184 "synt.y"
    { (yyval.reel) = (yyvsp[(1) - (1)].reel) ;;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 184 "synt.y"
    { (yyval.reel) = (yyvsp[(1) - (1)].reel) ;;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 187 "synt.y"
    { if (rechercheType((yyvsp[(3) - (6)].str),0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",(yyvsp[(3) - (6)].str),num_de_lignes);
} ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 191 "synt.y"
    { if (rechercheType((yyvsp[(2) - (3)].str),0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",(yyvsp[(2) - (3)].str),num_de_lignes);
} ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 197 "synt.y"
    { if (rechercheType((yyvsp[(1) - (1)].str),0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",(yyvsp[(1) - (1)].str),num_de_lignes);
} ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 201 "synt.y"
    { if (rechercheType((yyvsp[(1) - (3)].str),0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",(yyvsp[(1) - (3)].str),num_de_lignes);
} ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 223 "synt.y"
    { if (rechercheType((yyvsp[(2) - (11)].str),0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",(yyvsp[(2) - (11)].str),num_de_lignes);
} ;}
    break;



/* Line 1455 of yacc.c  */
#line 1877 "synt.tab.c"
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
#line 229 "synt.y"

int main() {
    
    yyparse();
    afficher();
}
yywrap()
{return 1;}
int yyerror(char *msg)
{  
    printf(" Erreur syntaxique a la ligne %d la colonne %d lentite %s " , num_de_lignes , col,  yytext);}
    
