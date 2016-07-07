/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./src/lecda.y" /* yacc.c:339  */

#include "lecda.h"



#line 72 "./src/lecda.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMERO_ENTERO = 256,
    FIN_DE_FICHERO = 257,
    TOKEN_INVALIDO = 258,
    IDENTIFICADOR = 259,
    COMENTARIO = 260,
    CODIGO_RUTINA = 261,
    PR_CODI = 500,
    PR_CODIAC = 501,
    PR_RUTINA = 502,
    PR_ESCRIBE = 503,
    PR_GENERA = 504,
    PR_MADE = 505,
    PR_MADS = 506,
    PR_MAG = 507,
    PR_SWITCH = 508,
    PR_IF = 509,
    PR_CONCATENA = 510,
    VD_ENTERO = 1000,
    VD_FUNCION_RE = 1001,
    VD_CADENA = 1002,
    VD_CODI = 1003,
    VD_CODIAC = 1004,
    VD_MADE = 1005,
    VD_MADS = 1006,
    VD_MAG = 1007,
    VD_RUTINA = 1008
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 8 "./src/lecda.y" /* yacc.c:355  */

  JKES entero;  //Valor entero de la variable (Codi unico o simple)
  JKES (*funcionRE)();  //Funcion que retorna numero entero
	JKB *cadena; //Puntero a cadena (Rutina)
  PVACIO codi;
  PVACIO codiac;
  PVACIO made;
  PVACIO mads;
  PVACIO mag;
  PVACIO rutina;

#line 150 "./src/lecda.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 165 "./src/lecda.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1010

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    30,
       2,    34,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    36,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     3,     4,     5,     6,
       7,     8,     2,     2,     2,     2,     2,     2,     2,     2,
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
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      20,    21,    22,    23,    24,    25,    26,    27,    28,     1,
       2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    68,    71,    72,    73,    74,    78,    79,
      80,    81,    84,    93,   103,   108,   118,   128,   156,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   179,   180,
     181,   182,   183,   184,   185,   187,   188,   190,   211,   227,
     251,   285,   299,   318,   335,   352,   364,   365,   370,   378,
     414,   456,   464,   474,   489,   501,   514,   518,   522
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMERO_ENTERO", "FIN_DE_FICHERO",
  "TOKEN_INVALIDO", "IDENTIFICADOR", "COMENTARIO", "CODIGO_RUTINA",
  "PR_CODI", "PR_CODIAC", "PR_RUTINA", "PR_ESCRIBE", "PR_GENERA",
  "PR_MADE", "PR_MADS", "PR_MAG", "PR_SWITCH", "PR_IF", "PR_CONCATENA",
  "VD_ENTERO", "VD_FUNCION_RE", "VD_CADENA", "VD_CODI", "VD_CODIAC",
  "VD_MADE", "VD_MADS", "VD_MAG", "VD_RUTINA", "'\\n'", "';'", "'('",
  "')'", "':'", "'='", "'@'", "'}'", "'{'", "','", "$accept", "input",
  "line", "sentencia", "declaracionPura", "idAsignado", "tipoDeVar",
  "numeroEntero", "asignacionPura", "modoGen", "asignaMag", "filasMag",
  "valoresM", "procedimientoSimple", "tipoArchivo", "errorLexico", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,  1009,  1010,   256,   257,   258,   259,   260,   261,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
    1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,    10,
      59,    40,    41,    58,    61,    64,   125,   123,    44
};
# endif

#define YYPACT_NINF -53

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-53)))

#define YYTABLE_NINF -35

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -53,    41,   -53,   -53,   -53,    10,    13,    16,    -8,    20,
      21,    22,    -2,     0,    17,    15,    29,   -53,   -53,   -53,
      24,    61,   -53,    31,   -53,    39,    33,    40,   -53,    19,
      59,    60,    62,    89,    91,    92,    63,     2,    67,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
       3,    -1,     9,     9,   -21,     9,     9,     9,    65,    66,
      69,   -53,    70,    71,    72,   -17,   -53,    74,     5,   -53,
      31,   102,   -53,    75,   -53,    76,    79,    52,    78,    80,
      81,    77,    82,    83,   -53,    87,    94,    86,     9,    90,
      31,     4,   -53,   -53,   -53,   -53,   -53,   -53,    88,   -53,
     -53,    93,    95,    98,   101,    73,    96,   -53,    97,   -53,
       6,   -53,    99,   105,   103,   104,   106,     7,   107,   109,
     -53,   -53,   108,   110,   111,   113,   -53,   -53,   100,   -53,
     -53,   117,   -53,   -53,   -53,   114,   115,   116,   -53,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     6,    58,    28,    29,    30,     0,    31,
      32,    33,     0,     0,     0,     0,     0,     4,     3,     5,
       0,     0,     9,     0,    10,     7,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    18,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     8,     0,     0,    53,
       0,     0,    35,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,    52,    12,    13,    54,    57,    56,     0,    15,
      16,     0,     0,     0,     0,     0,     0,    38,     0,    45,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    55,     0,     0,     0,     0,    46,    47,     0,    41,
      39,     0,    42,    43,    44,     0,     0,     0,    17,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,   -53,   -53,    45,   -53,   -52,   -53,   -53,
     -53,   -53,   -50,   -53,   -53,   125
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    48,    21,    73,    22,   128,
      23,    50,    51,    24,    98,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    75,    69,    78,    79,    80,    49,    69,    69,    69,
      62,    76,    72,    87,     4,    63,    26,    77,    88,    27,
      91,    64,    28,    29,   126,   127,    30,    31,    32,    33,
      65,    34,    70,   111,    49,   120,   108,    71,    90,    67,
     110,     2,    71,    71,    71,     3,     4,    54,    35,    36,
       5,     6,     7,     8,    38,     9,    10,    11,    96,   -34,
     -34,   -34,   -34,    37,    52,    12,    13,    14,    15,    16,
      17,    53,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      55,    56,    58,    57,    59,    60,    66,    81,    82,    84,
      61,    83,    85,    86,    89,    92,   117,    93,    94,    95,
      99,   102,   100,   101,   105,   107,   103,   104,   106,   109,
     112,   115,    97,   114,   113,   116,    25,   119,   118,   121,
     122,     0,   135,   123,   124,     0,   125,   129,   130,   132,
     133,   131,   134,   136,   137,   139,     0,   138
};

static const yytype_int8 yycheck[] =
{
      50,    53,     3,    55,    56,    57,     3,     3,     3,     3,
       8,    32,     3,    30,     5,    13,     6,    38,    35,     6,
      70,    19,     6,    31,    17,    18,     6,     6,     6,    31,
      28,    31,    33,    29,     3,    29,    88,    38,    33,    36,
      90,     0,    38,    38,    38,     4,     5,    28,    31,    34,
       9,    10,    11,    12,    30,    14,    15,    16,     6,    20,
      21,    22,    23,    34,    31,    24,    25,    26,    27,    28,
      29,    31,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      31,    31,     3,    31,     3,     3,    29,    32,    32,    29,
      37,    32,    31,    31,    30,     3,    33,    32,    32,    30,
      32,    34,    32,    32,    27,    29,    34,    34,    24,    29,
      32,    23,    77,    28,    31,    24,     1,    30,    32,    30,
      25,    -1,    32,    30,    30,    -1,    30,    30,    29,    29,
      29,    33,    29,    26,    30,    29,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,     0,     4,     5,     9,    10,    11,    12,    14,
      15,    16,    24,    25,    26,    27,    28,    29,    41,    42,
      43,    45,    47,    49,    52,    54,     6,     6,     6,    31,
       6,     6,     6,    31,    31,    31,    34,    34,    30,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    44,     3,
      50,    51,    31,    31,    28,    31,    31,    31,     3,     3,
       3,    37,     8,    13,    19,    28,    29,    36,    51,     3,
      33,    38,     3,    46,    54,    46,    32,    38,    46,    46,
      46,    32,    32,    32,    29,    31,    31,    30,    35,    30,
      33,    51,     3,    32,    32,    30,     6,    44,    53,    32,
      32,    32,    34,    34,    34,    27,    24,    29,    46,    29,
      51,    29,    32,    31,    28,    23,    24,    33,    32,    30,
      29,    30,    25,    30,    30,    30,    17,    18,    48,    30,
      29,    33,    29,    29,    29,    32,    26,    30,    32,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    41,    41,    42,    42,
      42,    42,    43,    43,    43,    43,    43,    43,    43,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    45,    45,
      45,    45,    45,    45,    45,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    48,    48,    49,    50,
      50,    51,    51,    51,    52,    52,    53,    53,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     3,     1,
       1,     1,     5,     5,     2,     5,     5,    10,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     7,
      10,     7,     8,     8,     8,     5,     1,     1,     3,     4,
       5,     1,     3,     2,     5,     7,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 72 "./src/lecda.y" /* yacc.c:1646  */
    {  }
#line 1401 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 6:
#line 73 "./src/lecda.y" /* yacc.c:1646  */
    {printf("Fin del análisis.\n"); YYACCEPT;}
#line 1407 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 8:
#line 78 "./src/lecda.y" /* yacc.c:1646  */
    { (yyval.entero) = DECLARACION_PURA;        }
#line 1413 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 9:
#line 79 "./src/lecda.y" /* yacc.c:1646  */
    { (yyval.entero) = ASIGNACION_PURA;         }
#line 1419 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 10:
#line 80 "./src/lecda.y" /* yacc.c:1646  */
    { (yyval.entero) = PROCEDIMIENTO_SIMPLE;    }
#line 1425 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 12:
#line 85 "./src/lecda.y" /* yacc.c:1646  */
    { 
                    VL_CODI *vrTmp = malloc(sizeof (VL_CODI));
                    vrTmp->valorMax = (yyvsp[-1].entero) ;
                    agregaId( (yyvsp[-3].cadena),  TPID_CODI, VALOR_SIN_INICIALIZAR);
                    //Inicializa el valor
                    tabla_Ids->valor.codi = vrTmp;      
                    //printf("Se ha declarado un Codi: %s\n", $2 );
                  }
#line 1438 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 13:
#line 94 "./src/lecda.y" /* yacc.c:1646  */
    {
                    VL_CODIAC *vrTmp = malloc(sizeof (VL_CODIAC));
                    vrTmp->dim= (yyvsp[-1].entero);
                    vrTmp->rutinaI = calloc( (yyvsp[-1].entero) , sizeof (JK_ID*) );
                    agregaId( (yyvsp[-3].cadena),  TPID_CODIAC, VALOR_SIN_INICIALIZAR);
                    //Inicializa parcialmente el valor
                    tabla_Ids->valor.codiac = vrTmp; 
                    printf("Se ha declarado un Codiac: %s\n", (yyvsp[-3].cadena) );          
                  }
#line 1452 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 14:
#line 104 "./src/lecda.y" /* yacc.c:1646  */
    {
                    agregaId( (yyvsp[0].cadena),  TPID_RUTINA, VALOR_SIN_INICIALIZAR);
                    //printf("Se ha declarado una Rutina: %s\n", $2 );
                  }
#line 1461 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 15:
#line 109 "./src/lecda.y" /* yacc.c:1646  */
    { 
                    VL_MADE *vrTmp = malloc(sizeof (VL_MADE));
                    vrTmp->dim= (yyvsp[-1].entero);
                    vrTmp->codiI = calloc( (yyvsp[-1].entero) , sizeof (JK_ID*) );
                    agregaId( (yyvsp[-3].cadena),  TPID_MADE, VALOR_SIN_INICIALIZAR);
                    //Inicializa parcialmente el valor
                    tabla_Ids->valor.made = vrTmp; 
                    //printf("Se ha declarado una made: %s\n", $2 );
                  }
#line 1475 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 16:
#line 119 "./src/lecda.y" /* yacc.c:1646  */
    { 
                    VL_MADS *vrTmp = malloc(sizeof (VL_MADS));
                    vrTmp->dim= (yyvsp[-1].entero);
                    vrTmp->codiacI = calloc( (yyvsp[-1].entero) , sizeof (JK_ID*) );
                    agregaId( (yyvsp[-3].cadena),  TPID_MADS, VALOR_SIN_INICIALIZAR);
                    //Inicializa parcialmente el valor
                    tabla_Ids->valor.mads = vrTmp; 
                    //printf("Se ha declarado una mads: %s\n", $2 );
                  }
#line 1489 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 17:
#line 130 "./src/lecda.y" /* yacc.c:1646  */
    {
                    JKES i;
                    VL_MAG *vrTmp = malloc(sizeof (VL_MAG));
                    VL_MADE *madeTmp = ((JK_ID *) (yyvsp[-3].made))->valor.made;
                    VL_MADS *madsTmp = ((JK_ID *) (yyvsp[-1].mads))->valor.mads;
                    vrTmp->dim= (yyvsp[-6].entero);
                    vrTmp->nIn= madeTmp->dim;
                    vrTmp->nOut= madsTmp->dim;
                    vrTmp->codiI = calloc( vrTmp->nIn , sizeof (JK_ID*) );
                    for(i=0;i < vrTmp->nIn; i++)
                    {
                      *(vrTmp->codiI + i) = *(madeTmp->codiI + i);
                    }
                    
                    vrTmp->codiacI = calloc( vrTmp->nOut , sizeof (JK_ID*) );
                    for(i=0;i < vrTmp->nOut; i++)
                    {
                      *(vrTmp->codiacI + i) = *(madsTmp->codiacI + i);
                    }
                    vrTmp->elementos = calloc((vrTmp->nIn + vrTmp->nOut)* (yyvsp[-6].entero) , sizeof(JKB));
                    agregaId( (yyvsp[-8].cadena),  TPID_MAG, VALOR_SIN_INICIALIZAR);
                    //Inicializa parcialmente el valor
                    tabla_Ids->valor.made = vrTmp; 
                    //printf("Se ha declarado una mag: %s\n", $2 );
                  }
#line 1519 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 18:
#line 157 "./src/lecda.y" /* yacc.c:1646  */
    {
                    //Error-001
                    varDeAsig = (yyvsp[0].entero);
                    AVISO_LINEA_ERROR;
                    printf("\tEl nombre \"%s\" para la nueva variable ya se ha asignado."
                    , varDeAsig->id);
                    YYABORT;
                  }
#line 1532 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 19:
#line 168 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) =  (yyvsp[0].entero);  }
#line 1538 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 20:
#line 169 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) =  (yyvsp[0].funcionRE);  }
#line 1544 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 21:
#line 170 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) =  (yyvsp[0].cadena);  }
#line 1550 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 22:
#line 171 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) =  (yyvsp[0].codi);  }
#line 1556 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 23:
#line 172 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) =  (yyvsp[0].codiac);  }
#line 1562 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 24:
#line 173 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) =  (yyvsp[0].made);  }
#line 1568 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 25:
#line 174 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) =  (yyvsp[0].mads);  }
#line 1574 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 26:
#line 175 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) =  (yyvsp[0].mag);  }
#line 1580 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 27:
#line 176 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) =  (yyvsp[0].rutina);  }
#line 1586 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 28:
#line 179 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) = TPDV_CODI;}
#line 1592 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 29:
#line 180 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) = TPDV_CODIAC;}
#line 1598 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 30:
#line 181 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) = TPDV_RUTINA;}
#line 1604 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 31:
#line 182 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) = TPDV_MADE;}
#line 1610 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 32:
#line 183 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) = TPDV_MADS;}
#line 1616 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 33:
#line 184 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) = TPDV_MAG;}
#line 1622 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 37:
#line 191 "./src/lecda.y" /* yacc.c:1646  */
    {
                  //printf("Rutina original(%i):\n%s\n", (JKE) $3,$3 );
                  JKB* rutinaVolatil= 0;//Se usa para borrar la rutina remanente
                  varDeAsig = (yyvsp[-3].rutina);
                  if( varDeAsig->tipo & 0x80 != 0)
                  {
                    rutinaVolatil = varDeAsig->valor.rutina;
                  } else
                  {
                    FLAG_VARIABLE_INICIALIZADA ;
                  }
                  varDeAsig->valor.rutina = modificaTabs((JKB*)(yyvsp[-1].cadena),0);
                  free((yyvsp[-1].cadena));
                  
                  //printf("Rutina asignada(%i):\n%s\n", (JKE) varDeAsig->valor.rutina, varDeAsig->valor.rutina);
                  if(rutinaVolatil!=0 && rutinaVolatil != varDeAsig->valor.rutina )
                    free(rutinaVolatil);  
                }
#line 1645 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 38:
#line 212 "./src/lecda.y" /* yacc.c:1646  */
    {
                  JKB* rutinaVolatil= 0;//Se usa para borrar la rutina remanente
                  varDeAsig = (yyvsp[-4].rutina);
                  if( varDeAsig->tipo & 0x80 != 0)
                  {
                    rutinaVolatil = varDeAsig->valor.rutina;
                  }else
                  {
                    FLAG_VARIABLE_INICIALIZADA ;
                  }
                  varDeAsig->valor.rutina = ((JK_ID *) (yyvsp[-2].rutina))->valor.rutina;
                  //printf("Rutina asignada:\n%s\n",varDeAsig->valor);
                  if(rutinaVolatil!=0 && rutinaVolatil != varDeAsig->valor.rutina )
                    free(rutinaVolatil); 
                }
#line 1665 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 39:
#line 228 "./src/lecda.y" /* yacc.c:1646  */
    {
                  JKB* rutinaVolatil= 0;//Se usa para borrar la rutina remanente
                  varDeAsig = (yyvsp[-6].rutina);
                  if( varDeAsig->tipo & 0x80 != 0)
                  {
                    rutinaVolatil = varDeAsig->valor.rutina;
                  }else
                  {
                    FLAG_VARIABLE_INICIALIZADA ;
                  }
                  if((yyvsp[-2].entero)  < 0)
                  {
                    AVISO_LINEA_ERROR;
                    printf("\n\tSe debe dar un número positivo de tabulaciones\n");
                    YYABORT;
                  }
                  varDeAsig->valor.rutina = modificaTabs( ((JK_ID *) (yyvsp[-4].rutina))->valor.rutina, (yyvsp[-2].entero));
                  //printf("Rutina asignada:\n%s\n",varDeAsig->valor);
                  if(rutinaVolatil!=0 && rutinaVolatil != varDeAsig->valor.rutina )
                    free(rutinaVolatil); 
                }
#line 1691 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 40:
#line 252 "./src/lecda.y" /* yacc.c:1646  */
    { 
                  varDeAsig = (yyvsp[-9].rutina);
                  JKB* rutinaVolatil= 0;
                  
                  if( varDeAsig->tipo & 0x80 != 0)
                  {
                    rutinaVolatil = varDeAsig->valor.rutina;
                  }else
                  {
                    FLAG_VARIABLE_INICIALIZADA ;
                  }
                  if(analizaMag((yyvsp[-5].mag),ANALISIS_GENERAL) != 0)
                  {
                    //Error-007
                    AVISO_LINEA_ERROR;
                    printf("\n\tError en la definicion de la mag;\n");
                    YYABORT;
                  }
                  //espaciosTab=3;

                  varDeAsig->valor.rutina = generaCodigo((yyvsp[-5].mag), (yyvsp[-3].entero));
                  if( varDeAsig->valor.rutina == 0)
                  {
                    //Error-007
                    AVISO_LINEA_ERROR;
                    printf("\nError en generacion de codigo;\n");
                    YYABORT;
                  }
                  //printf("Se genero la rutina %s:\n",varDeAsig->id);
                  //Se libera al final por si hay autoreferencia
                  if(rutinaVolatil!=0 && rutinaVolatil != varDeAsig->valor.rutina )
                    free(rutinaVolatil);
                }
#line 1729 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 41:
#line 285 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero)=1;
                  varDeAsig = (yyvsp[-6].rutina);
                  JKB* rutinaVolatil= 0;
                  if( varDeAsig->tipo & 0x80 != 0)
                  {
                    rutinaVolatil = varDeAsig->valor.rutina;
                  }else
                  {
                    FLAG_VARIABLE_INICIALIZADA ;
                  }
                  varDeAsig->valor.rutina = concatenaCadenas( (((JK_ID*)(yyvsp[-2].codiac))->valor.codiac )  );
                  if(rutinaVolatil!=0 && rutinaVolatil != varDeAsig->valor.rutina )
                    free(rutinaVolatil);
                }
#line 1748 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 42:
#line 300 "./src/lecda.y" /* yacc.c:1646  */
    {
                  VL_CODIAC *vrTmp;
                  varDeAsig = (yyvsp[-7].codiac);
                  vrTmp=varDeAsig->valor.codiac;
                  if((yyvsp[-5].entero) < vrTmp->dim)
                  *(vrTmp->rutinaI + (yyvsp[-5].entero)) = (JK_ID*) (yyvsp[-2].rutina);
                  else
                  {
                    //Error-002
                    AVISO_LINEA_ERROR;
                    printf("\tEl valor de índice %i excede la dimensión de \"%s\" que es %i"
                    , (yyvsp[-5].entero), varDeAsig->id,vrTmp->dim);
                    YYABORT;
                  }
                  //printf("Se asigno una accion a un codiac\n");
                }
#line 1769 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 43:
#line 319 "./src/lecda.y" /* yacc.c:1646  */
    {
                  VL_MADE *vrTmp;
                  varDeAsig = (yyvsp[-7].made);
                  vrTmp=varDeAsig->valor.made;
                  if((yyvsp[-5].entero) < vrTmp->dim)
                   *(vrTmp->codiI + (yyvsp[-5].entero)) = (JK_ID*) (yyvsp[-2].codi);
                  else
                  {
                    //Error-003
                    AVISO_LINEA_ERROR;
                    printf("\tEl valor de índice %i excede la dimensión de \"%s\" que es %i"
                    , (yyvsp[-5].entero), varDeAsig->id,vrTmp->dim);
                    YYABORT;
                  }
                  //printf("Made correcta\n");
                }
#line 1790 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 44:
#line 336 "./src/lecda.y" /* yacc.c:1646  */
    {
                  VL_MADS *vrTmp;
                  varDeAsig = (yyvsp[-7].mads);
                  vrTmp=varDeAsig->valor.mads;
                  if((yyvsp[-5].entero) < vrTmp->dim)
                   *(vrTmp->codiacI + (yyvsp[-5].entero)) = (JK_ID*) (yyvsp[-2].codiac);
                  else
                  {
                    //Error-004
                    AVISO_LINEA_ERROR;
                    printf("\tEl valor de índice %i excede la dimensión de \"%s\" que es %i"
                    , (yyvsp[-5].entero), varDeAsig->id,vrTmp->dim);
                    YYABORT;
                  } 
                  //printf("Mads correcta\n");
                }
#line 1811 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 45:
#line 353 "./src/lecda.y" /* yacc.c:1646  */
    {
                  JKES numero = 0;
                  VL_MAG *vrTmp = varDeAsig->valor.mag;
                  JKB *matriz = vrTmp->elementos;
                  printf("Mag correcta con %i filas.\n\n", (yyvsp[-3].entero) );
                  //for(numero= 0; numero < 12;numero++)
                  //printf("Elemento %i de la mag %s es : %i \n",numero,
                  // varDeAsig->id,  *(matriz+numero) );
                }
#line 1825 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 46:
#line 364 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero)= MODO_GEN_SWITCH;}
#line 1831 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 47:
#line 365 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero)= MODO_GEN_IF;}
#line 1837 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 48:
#line 371 "./src/lecda.y" /* yacc.c:1646  */
    {
            varDeAsig = (yyvsp[-2].mag);
            //filaNumerica = malloc(sizeof(VV_SEC_NUM));
            
          }
#line 1847 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 49:
#line 379 "./src/lecda.y" /* yacc.c:1646  */
    {
            VV_SEC_NUM *numIn = (yyvsp[-3].codi);
            VV_SEC_NUM *numOut = (yyvsp[-1].codi);
            VL_MAG *vrTmp = varDeAsig->valor.mag;
            JKB *matriz = vrTmp->elementos;
            JKES i ;
            //printf("\n Entradas: %i \tSalidas: %i \n\n", numIn->dim, numOut->dim);
            //Verifica magnitudes
            if(numIn->dim == vrTmp->nIn && numOut->dim == vrTmp->nOut)
            {
              for(i=0;i<numIn->dim;i++)
              {
                *(matriz+ i ) = numIn->nums[i];
                 //printf(" %i,",numIn->nums[i]);
              }
              for(i=0;i< numOut->dim ;i++)
              {
                *(matriz+ i + numIn->dim ) = numOut->nums[i];
                //printf(" %i,",numOut->nums[i]);
              }
              (yyval.entero)=1;
            } else 
            {
              //Error en la separacion de filas de entrada, o cantidad de
              // elementos, se puede identificar bien los errores.
              
              //Error-005
              AVISO_LINEA_ERROR;
              printf("\tNo se puede asignar la matriz a la Mag.\n");
              printf("\tError en la especificación de la secuencia.\n");
              printf("\tVerifique los separadores o la cantidad de elementos.\n");
              YYABORT;
              
            }
          }
#line 1887 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 50:
#line 415 "./src/lecda.y" /* yacc.c:1646  */
    {
          VV_SEC_NUM *numIn = (yyvsp[-3].codi);
          VV_SEC_NUM *numOut = (yyvsp[-1].codi);
          VL_MAG *vrTmp = varDeAsig->valor.mag;
          JKB *matriz = vrTmp->elementos;
          JKES i ;
          //printf("\n Entradas: %i \tSalidas: %i \n\n", numIn->dim, numOut->dim);
          if(numIn->dim == vrTmp->nIn && numOut->dim == vrTmp->nOut
              && (yyvsp[-4].entero)< vrTmp->dim)
          {
            //printf("\t");
            for(i=0;i<numIn->dim;i++)
            {
              *(matriz+ i + (yyvsp[-4].entero) *(vrTmp->nIn+vrTmp->nOut)) = numIn->nums[i];
              //printf(" %i,",numIn->nums[i]);
            }
            //printf("\t : ");
            for(i=0;i< numOut->dim ;i++)
            {
              *(matriz+ i + numIn->dim + (yyvsp[-4].entero) *(vrTmp->nIn+vrTmp->nOut)) 
              = numOut->nums[i];
              //printf(" %i,",numOut->nums[i]);
            }
            //printf("\n");
            (yyval.entero)+=1;
            //Libera la memoria
            free(numIn);
            free(numOut);
          } else 
          {
            //Error en la separacion de filas de entrada, o cantidad de
            // elementos, se puede identificar bien los errores.
            //Error-005
            AVISO_LINEA_ERROR;
            printf("\tNo se puede asignar la matriz a la Mag.\n");
            printf("\tError en la especificación de la secuencia.\n");
            printf("\tVerifique los separadores o la cantidad de elementos.\n");
            YYABORT;
          }
        }
#line 1932 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 51:
#line 457 "./src/lecda.y" /* yacc.c:1646  */
    {
            filaNumerica = malloc(sizeof(VV_SEC_NUM));
            filaNumerica->nums[0] = (JKB) (yyvsp[0].entero);
            filaNumerica->dim = 1;
            (yyval.codi)=filaNumerica;
            //printf(" inicia #%i \t",$1);
          }
#line 1944 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 52:
#line 465 "./src/lecda.y" /* yacc.c:1646  */
    {
            if(filaNumerica->dim < MAX_SEC_NUMS )
            {
              filaNumerica->nums[filaNumerica->dim] = (yyvsp[0].entero);
              filaNumerica->dim += 1;
              //$$=filaNumerica;
            }
            //printf("#%i \t",$3);
         }
#line 1958 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 53:
#line 475 "./src/lecda.y" /* yacc.c:1646  */
    {
          //Error-006
          //No se porque no se actualiza a la linea de error la variable que 
          //cuenta las lineas, por eso incremento en 1 para que el mensaje
          //sea correcto.
          lineaLectura++; 
          AVISO_LINEA_ERROR;
          printf("\tNo se puede asignar la matriz a la Mag.\n");
          printf("\tEs posible que haga falta especificar una coma.\n");
          printf("\tCorrija la secuencia (fila) de la Mag.\n");
          YYABORT;
        }
#line 1975 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 54:
#line 489 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) = 1;
          FILE *fichero;
          JKB nombre [MAX_L_TOKEN+20];//deja 19 caracteres por si la extension es larga
          
          varDeAsig = (yyvsp[-2].rutina);
          printf("Nombre de archivo: %s\n", varDeAsig->id);
          
          sprintf(nombre, "%s.c",varDeAsig->id);
          fichero = fopen (nombre, "w");//Escribe el nombre del archivo
          fprintf(fichero,"%s\n", varDeAsig->valor.cadena);
          fclose(fichero);
        }
#line 1992 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 55:
#line 501 "./src/lecda.y" /* yacc.c:1646  */
    {(yyval.entero) = 1;
          FILE *fichero;
          JKB nombre [MAX_L_TOKEN+MAX_L_TOKEN];//deja 19 caracteres por si la extension es larga
          
          varDeAsig = (yyvsp[-4].rutina);
          printf("Nombre de archivo: %s\n", varDeAsig->id);
          
          sprintf(nombre, "%s.%s",varDeAsig->id,(yyvsp[-2].cadena));
          fichero = fopen (nombre, "w");//Escribe el nombre del archivo
          fprintf(fichero,"%s\n", varDeAsig->valor.cadena);
          fclose(fichero);
        }
#line 2009 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 56:
#line 514 "./src/lecda.y" /* yacc.c:1646  */
    {
          varDeAsig = (yyvsp[0].entero);
          (yyval.cadena) = varDeAsig->id;
        }
#line 2018 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 57:
#line 518 "./src/lecda.y" /* yacc.c:1646  */
    {
          (yyval.cadena) = (yyvsp[0].cadena);
        }
#line 2026 "./src/lecda.c" /* yacc.c:1646  */
    break;

  case 58:
#line 523 "./src/lecda.y" /* yacc.c:1646  */
    { printf("Token no valido en la linea %i\n:", lineaLectura+1);
              printf("\t%s\n", msjError); YYABORT;}
#line 2033 "./src/lecda.c" /* yacc.c:1646  */
    break;


#line 2037 "./src/lecda.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 527 "./src/lecda.y" /* yacc.c:1906  */




/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
/*%%%%%%%%%%%%%%%%%%%%%%%      Código adicional   %%%%%%%%%%%%%%%%%%%%%%%%*/


/* Función para el informe de errores*/
/* Llamada por yyparse ante un error */
int yyerror (char *s)  {
  printf ("%s\n", s);
}

/* Uso del parser*/
int main( int argc,char **argv)
{
  ++argv, --argc; /* se salta el nombre del programa */
  if(argc > 0 ){
    printf("Se utiliza un archivo\n");
    yyin= fopen(argv[0],"r");
    //yyout= fopen ("./resultado.txt", "w"); //Guarda el resultado en un archivo
  }
  else {
    printf("Versión terminal \n");
    yyin= stdin;
  }
  jkError = yyparse ();
  if(jkError!=0)
  {
    printf("\n **** Fin del procesamiento debido a algun error: %i.\n%s\n",jkError,msjError);
  }
  printf( "\nLineas procesadas : %d\n\n",
  lineaLectura );
  return 0;
}








