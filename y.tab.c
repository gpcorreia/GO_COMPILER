/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gocompiler.y"

    #include "gocompiler.h"
    #include "gocompiler.c"
    int yylex(void);
    void yyerror (const char *s);
    void checkdivision();
    void showList(Tree * head,int point2print);
    extern char * yytext;
    extern int hide;
    int check = 0;
    int needsBlock = 0;
    Tree * my_tree = NULL;
    int yydebug = 0;
    int syntatic_errors = 0;

#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PACKAGE = 258,
    SEMICOLON = 259,
    VAR = 260,
    LPAR = 261,
    RPAR = 262,
    COMMA = 263,
    INT = 264,
    FLOAT32 = 265,
    BOOL = 266,
    STRING = 267,
    FUNC = 268,
    LBRACE = 269,
    RBRACE = 270,
    ASSIGN = 271,
    ELSE = 272,
    IF = 273,
    FOR = 274,
    RETURN = 275,
    PRINT = 276,
    BLANKID = 277,
    PARSEINT = 278,
    CMDARGS = 279,
    LSQ = 280,
    RSQ = 281,
    OR = 282,
    AND = 283,
    LT = 284,
    GT = 285,
    EQ = 286,
    NE = 287,
    LE = 288,
    GE = 289,
    PLUS = 290,
    MINUS = 291,
    STAR = 292,
    DIV = 293,
    MOD = 294,
    NOT = 295,
    STRLIT = 296,
    RESERVED = 297,
    INTLIT = 298,
    ID = 299,
    REALLIT = 300,
    UNARY = 301
  };
#endif
/* Tokens.  */
#define PACKAGE 258
#define SEMICOLON 259
#define VAR 260
#define LPAR 261
#define RPAR 262
#define COMMA 263
#define INT 264
#define FLOAT32 265
#define BOOL 266
#define STRING 267
#define FUNC 268
#define LBRACE 269
#define RBRACE 270
#define ASSIGN 271
#define ELSE 272
#define IF 273
#define FOR 274
#define RETURN 275
#define PRINT 276
#define BLANKID 277
#define PARSEINT 278
#define CMDARGS 279
#define LSQ 280
#define RSQ 281
#define OR 282
#define AND 283
#define LT 284
#define GT 285
#define EQ 286
#define NE 287
#define LE 288
#define GE 289
#define PLUS 290
#define MINUS 291
#define STAR 292
#define DIV 293
#define MOD 294
#define NOT 295
#define STRLIT 296
#define RESERVED 297
#define INTLIT 298
#define ID 299
#define REALLIT 300
#define UNARY 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "gocompiler.y"

	char * string;
	struct tree * node;

#line 235 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   308

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    49,    49,    52,    53,    54,    57,    58,    61,    62,
      66,    67,    71,    72,    73,    74,    77,    78,    79,    80,
      84,    87,    88,    91,    95,    96,    97,    98,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   117,   118,   121,   122,   125,   126,   129,   130,   133,
     134,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   162
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PACKAGE", "SEMICOLON", "VAR", "LPAR",
  "RPAR", "COMMA", "INT", "FLOAT32", "BOOL", "STRING", "FUNC", "LBRACE",
  "RBRACE", "ASSIGN", "ELSE", "IF", "FOR", "RETURN", "PRINT", "BLANKID",
  "PARSEINT", "CMDARGS", "LSQ", "RSQ", "OR", "AND", "LT", "GT", "EQ", "NE",
  "LE", "GE", "PLUS", "MINUS", "STAR", "DIV", "MOD", "NOT", "STRLIT",
  "RESERVED", "INTLIT", "ID", "REALLIT", "UNARY", "$accept", "Program",
  "Declarations", "VarDeclaration", "VarSpec", "AuxVarSpec", "Type",
  "FuncDeclaration", "Parameters", "AuxParameters", "FuncBody",
  "VarsAndStatements", "Statement", "AuxStatement", "ParseArgs",
  "FuncInvocation", "CallParams", "AuxCallParams", "Expr", "Id", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -30,    25,   -72,    12,   -72,     0,     9,   -30,   -72,
      24,    26,   -30,   -72,    47,    51,     0,     0,    60,   -30,
      99,    14,   -72,   -72,    70,    47,   -72,   -72,   -72,   -72,
     -72,   138,    74,    99,   -72,   -72,   -72,    69,   -72,   138,
      76,   124,   -72,    69,   -72,   -30,   -72,   -72,   -72,    48,
     -72,    35,   120,    35,    84,    87,    90,   -72,   -72,    23,
     -72,    99,    92,    83,     2,    35,    35,    35,   -72,   -72,
     -72,   205,    95,    48,   231,   258,   126,   -72,   -72,    16,
      81,    35,    76,    48,   -72,   123,   147,   -72,   -72,   -72,
      48,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    91,    48,   133,   165,   134,   144,
     179,    89,   258,   -72,   -72,   -72,   -72,   112,   192,   217,
     263,   263,   263,   263,   263,   263,    98,    98,   -72,   -72,
     -72,   -72,   116,   -72,   -72,   -72,   -72,    35,   -72,   110,
     136,   -72,   179,   151,   145,   -72,     3,    48,   181,   164,
     175,   -72,    35,   -72,   245,   184,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    73,     0,     1,     5,     9,     0,     2,
       0,     0,     9,     6,    11,     0,     5,     5,     0,     0,
       0,     0,     3,     4,     0,    11,    12,    13,    14,    15,
       8,     0,     0,     0,     7,    10,    27,     0,    19,     0,
      22,     0,    17,     0,    18,     0,    20,    40,    26,     0,
      23,     0,     0,    34,     0,     0,     0,    37,    36,     0,
      16,     0,     0,     0,     0,     0,     0,     0,    67,    68,
      70,     0,    69,     0,     0,    35,     0,    24,    25,     0,
       0,     0,    22,     0,    29,     0,     0,    66,    65,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    28,    21,    41,    71,    72,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    33,     0,    39,    38,    46,    45,     0,    47,     0,
      30,    32,    50,     0,     0,    49,     0,     0,     0,     0,
       0,    44,     0,    31,     0,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,    19,   216,   193,   278,    -7,   -72,   -72,   222,
      56,   -72,   264,   -71,   -72,   -40,   -72,   166,    21,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    10,    13,    20,    30,    11,    32,    46,
      38,    41,    62,    63,    57,    70,   109,   138,    71,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       4,    58,   104,    85,   148,     7,    14,    15,    64,    58,
       1,    14,   114,     8,     3,    12,     6,   108,    25,   117,
      33,    31,    64,   -48,    37,     5,    40,   149,    16,    79,
      17,    80,    43,    58,   132,    22,    23,    65,    66,    81,
      59,    64,    67,    58,    61,    68,     3,    69,    59,    47,
      58,    65,    66,     3,    82,    19,    67,    21,     3,    68,
       3,    69,    49,   -42,    24,    58,    51,    52,    53,    54,
      65,    66,    59,    74,    75,    67,   150,    34,    68,     3,
      69,    39,    59,    36,    45,    86,    87,    88,    89,    59,
      76,    77,     3,    42,    78,    44,    83,   107,    84,    60,
     110,    79,   112,   111,    59,   139,   131,    58,    26,    27,
      28,    29,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    47,    64,   140,    48,     7,
     115,   141,    64,   143,    73,   101,   102,   103,    49,    50,
     133,   135,    51,    52,    53,    54,    59,    26,    27,    28,
      29,   136,    36,   144,   116,    65,    66,   146,   142,   147,
      67,    65,    66,    68,     3,    69,    67,   106,     3,    68,
       3,    69,   134,   154,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   137,   151,   152,
     153,   156,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    18,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    90,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   105,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    55,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   155,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    99,   100,
     101,   102,   103,    35,   113,    56,     0,     0,   145
};

static const yytype_int16 yycheck[] =
{
       1,    41,    73,     1,     1,     5,     7,     8,     6,    49,
       3,    12,    83,    13,    44,     6,     4,     1,    19,    90,
      21,     7,     6,     7,    31,     0,    33,    24,     4,     6,
       4,     8,    39,    73,   105,    16,    17,    35,    36,    16,
      41,     6,    40,    83,    45,    43,    44,    45,    49,     1,
      90,    35,    36,    44,    61,     8,    40,     6,    44,    43,
      44,    45,    14,    15,     4,   105,    18,    19,    20,    21,
      35,    36,    73,    52,    53,    40,   147,     7,    43,    44,
      45,     7,    83,    14,     8,    64,    65,    66,    67,    90,
       6,     4,    44,    37,     4,    39,     4,    76,    15,    43,
      79,     6,    81,    22,   105,    16,    15,   147,     9,    10,
      11,    12,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     1,     6,    15,     4,     5,
       7,    15,     6,    23,    14,    37,    38,    39,    14,    15,
       7,     7,    18,    19,    20,    21,   147,     9,    10,    11,
      12,     7,    14,    17,     7,    35,    36,     6,   137,    14,
      40,    35,    36,    43,    44,    45,    40,    41,    44,    43,
      44,    45,     7,   152,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     8,     7,    25,
      15,     7,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    12,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    14,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    14,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    41,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    35,    36,
      37,    38,    39,    25,    82,    41,    -1,    -1,   142
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    48,    44,    66,     0,     4,     5,    13,    49,
      50,    54,     6,    51,    66,    66,     4,     4,    51,     8,
      52,     6,    49,    49,     4,    66,     9,    10,    11,    12,
      53,     7,    55,    66,     7,    52,    14,    53,    57,     7,
      53,    58,    57,    53,    57,     8,    56,     1,     4,    14,
      15,    18,    19,    20,    21,    50,    59,    61,    62,    66,
      57,    66,    59,    60,     6,    35,    36,    40,    43,    45,
      62,    65,    66,    14,    65,    65,     6,     4,     4,     6,
       8,    16,    53,     4,    15,     1,    65,    65,    65,    65,
      14,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    60,    14,    41,    65,     1,    63,
      65,    22,    65,    56,    60,     7,     7,    60,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    15,    60,     7,     7,     7,     7,     8,    64,    16,
      15,    15,    65,    23,    17,    64,     6,    14,     1,    24,
      60,     7,    25,    15,    65,    26,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    54,    54,    54,    54,
      55,    56,    56,    57,    58,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     0,     2,     5,     3,     0,
       3,     0,     1,     1,     1,     1,     7,     6,     6,     5,
       3,     4,     0,     3,     3,     3,     2,     0,     3,     3,
       5,     9,     5,     4,     1,     2,     1,     1,     4,     4,
       1,     3,     0,    11,     8,     4,     4,     2,     0,     3,
       0,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     1,     1,     1,
       1,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2:
#line 49 "gocompiler.y"
                                           { my_tree = add1child(createNode("Program",NULL),(yyvsp[0].node));}
#line 1542 "y.tab.c"
    break;

  case 3:
#line 52 "gocompiler.y"
                                                       {(yyval.node) = addbro((yyvsp[-2].node),(yyvsp[0].node));}
#line 1548 "y.tab.c"
    break;

  case 4:
#line 53 "gocompiler.y"
                                                        { (yyval.node) = addbro((yyvsp[-2].node),(yyvsp[0].node));}
#line 1554 "y.tab.c"
    break;

  case 5:
#line 54 "gocompiler.y"
                 {(yyval.node) = NULL;}
#line 1560 "y.tab.c"
    break;

  case 6:
#line 57 "gocompiler.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 1566 "y.tab.c"
    break;

  case 7:
#line 58 "gocompiler.y"
                                                {(yyval.node) = (yyvsp[-2].node);}
#line 1572 "y.tab.c"
    break;

  case 8:
#line 61 "gocompiler.y"
                            {(yyval.node) = createListId((yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1578 "y.tab.c"
    break;

  case 9:
#line 62 "gocompiler.y"
          { (yyval.node) = NULL;}
#line 1584 "y.tab.c"
    break;

  case 10:
#line 66 "gocompiler.y"
                                { (yyval.node) = addbro((yyvsp[-1].node),(yyvsp[0].node));}
#line 1590 "y.tab.c"
    break;

  case 11:
#line 67 "gocompiler.y"
            {(yyval.node) = NULL;}
#line 1596 "y.tab.c"
    break;

  case 12:
#line 71 "gocompiler.y"
            { (yyval.node) = createNode("Int",NULL);}
#line 1602 "y.tab.c"
    break;

  case 13:
#line 72 "gocompiler.y"
              {(yyval.node) = createNode("Float32",NULL);}
#line 1608 "y.tab.c"
    break;

  case 14:
#line 73 "gocompiler.y"
           {(yyval.node) = createNode("Bool",NULL);}
#line 1614 "y.tab.c"
    break;

  case 15:
#line 74 "gocompiler.y"
             {(yyval.node) = createNode("String",NULL);}
#line 1620 "y.tab.c"
    break;

  case 16:
#line 77 "gocompiler.y"
                                                              {(yyval.node) = createFuncDecl((yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1626 "y.tab.c"
    break;

  case 17:
#line 78 "gocompiler.y"
                                                     {(yyval.node) = createFuncDecl((yyvsp[-4].node),NULL,(yyvsp[-1].node),(yyvsp[0].node));}
#line 1632 "y.tab.c"
    break;

  case 18:
#line 79 "gocompiler.y"
                                                        {(yyval.node) = createFuncDecl((yyvsp[-4].node),(yyvsp[-2].node),NULL,(yyvsp[0].node));}
#line 1638 "y.tab.c"
    break;

  case 19:
#line 80 "gocompiler.y"
                                              { (yyval.node) = createFuncDecl((yyvsp[-3].node),NULL,NULL,(yyvsp[0].node));}
#line 1644 "y.tab.c"
    break;

  case 20:
#line 84 "gocompiler.y"
                                    {(yyval.node) = addbro(addchild(createNode("ParamDecl",NULL),(yyvsp[-1].node),(yyvsp[-2].node)),(yyvsp[0].node));}
#line 1650 "y.tab.c"
    break;

  case 21:
#line 87 "gocompiler.y"
                                           { (yyval.node) = addbro(addchild(createNode("ParamDecl",NULL),(yyvsp[-1].node),(yyvsp[-2].node)),(yyvsp[0].node));}
#line 1656 "y.tab.c"
    break;

  case 22:
#line 88 "gocompiler.y"
                {(yyval.node) = NULL;}
#line 1662 "y.tab.c"
    break;

  case 23:
#line 91 "gocompiler.y"
                                          { (yyval.node) = add1child(createNode("FuncBody",NULL),(yyvsp[-1].node));}
#line 1668 "y.tab.c"
    break;

  case 24:
#line 95 "gocompiler.y"
                                                              {(yyval.node) = addbro((yyvsp[-2].node),(yyvsp[-1].node));}
#line 1674 "y.tab.c"
    break;

  case 25:
#line 96 "gocompiler.y"
                                                         { (yyval.node) = addbro((yyvsp[-2].node),(yyvsp[-1].node));  }
#line 1680 "y.tab.c"
    break;

  case 26:
#line 97 "gocompiler.y"
                                               {(yyval.node) = (yyvsp[-1].node);}
#line 1686 "y.tab.c"
    break;

  case 27:
#line 98 "gocompiler.y"
                   {(yyval.node) = NULL;}
#line 1692 "y.tab.c"
    break;

  case 28:
#line 101 "gocompiler.y"
                            {(yyval.node) = addchild(createNode("Assign",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1698 "y.tab.c"
    break;

  case 29:
#line 102 "gocompiler.y"
                                      { if((yyvsp[-1].node) != NULL && (yyvsp[-1].node)->next != NULL) (yyval.node) = add1child(createNode("Block",NULL),(yyvsp[-1].node)); else (yyval.node) = (yyvsp[-1].node);}
#line 1704 "y.tab.c"
    break;

  case 30:
#line 103 "gocompiler.y"
                                              {(yyval.node) = cicleIf((yyvsp[-3].node),(yyvsp[-1].node),NULL);}
#line 1710 "y.tab.c"
    break;

  case 31:
#line 104 "gocompiler.y"
                                                                              { (yyval.node) = cicleIf((yyvsp[-7].node),(yyvsp[-5].node),(yyvsp[-1].node));}
#line 1716 "y.tab.c"
    break;

  case 32:
#line 105 "gocompiler.y"
                                               { (yyval.node) = cicleFor((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1722 "y.tab.c"
    break;

  case 33:
#line 106 "gocompiler.y"
                                          { (yyval.node) = cicleFor(NULL,(yyvsp[-1].node));}
#line 1728 "y.tab.c"
    break;

  case 34:
#line 107 "gocompiler.y"
                    {(yyval.node) = createNode("Return",NULL);}
#line 1734 "y.tab.c"
    break;

  case 35:
#line 108 "gocompiler.y"
                       { (yyval.node) = add1child(createNode("Return",NULL),(yyvsp[0].node));}
#line 1740 "y.tab.c"
    break;

  case 36:
#line 109 "gocompiler.y"
                          {(yyval.node) = add1child(createNode("Call",NULL),(yyvsp[0].node));}
#line 1746 "y.tab.c"
    break;

  case 37:
#line 110 "gocompiler.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1752 "y.tab.c"
    break;

  case 38:
#line 111 "gocompiler.y"
                                { (yyval.node) = add1child(createNode("Print",NULL),(yyvsp[-1].node));}
#line 1758 "y.tab.c"
    break;

  case 39:
#line 112 "gocompiler.y"
                                  { (yyval.node) = add1child(createNode("Print",NULL),createNode("StrLit",(yyvsp[-1].string)));}
#line 1764 "y.tab.c"
    break;

  case 40:
#line 113 "gocompiler.y"
                 { (yyval.node) = NULL; syntatic_errors = 1;}
#line 1770 "y.tab.c"
    break;

  case 41:
#line 117 "gocompiler.y"
                                               {(yyval.node) = addbro((yyvsp[-2].node),(yyvsp[0].node));}
#line 1776 "y.tab.c"
    break;

  case 42:
#line 118 "gocompiler.y"
              {(yyval.node) = NULL;}
#line 1782 "y.tab.c"
    break;

  case 43:
#line 121 "gocompiler.y"
                                                                           { (yyval.node) = addchild(createNode("ParseArgs",NULL),(yyvsp[-10].node),(yyvsp[-2].node));}
#line 1788 "y.tab.c"
    break;

  case 44:
#line 122 "gocompiler.y"
                                                             {(yyval.node) = NULL; syntatic_errors = 1;}
#line 1794 "y.tab.c"
    break;

  case 45:
#line 125 "gocompiler.y"
                                        { (yyval.node) = addbro((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1800 "y.tab.c"
    break;

  case 46:
#line 126 "gocompiler.y"
                                   {(yyval.node) = NULL; syntatic_errors = 1;}
#line 1806 "y.tab.c"
    break;

  case 47:
#line 129 "gocompiler.y"
                               {(yyval.node) = addbro((yyvsp[-1].node),(yyvsp[0].node));}
#line 1812 "y.tab.c"
    break;

  case 48:
#line 130 "gocompiler.y"
            {(yyval.node) = NULL;}
#line 1818 "y.tab.c"
    break;

  case 49:
#line 133 "gocompiler.y"
                                        { (yyval.node) = addbro((yyvsp[-1].node),(yyvsp[0].node));}
#line 1824 "y.tab.c"
    break;

  case 50:
#line 134 "gocompiler.y"
               {(yyval.node) = NULL;}
#line 1830 "y.tab.c"
    break;

  case 51:
#line 138 "gocompiler.y"
                   { (yyval.node) = addchild(createNode("Or",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1836 "y.tab.c"
    break;

  case 52:
#line 139 "gocompiler.y"
                    { (yyval.node) = addchild(createNode("And",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1842 "y.tab.c"
    break;

  case 53:
#line 140 "gocompiler.y"
                   { (yyval.node) = addchild(createNode("Lt",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1848 "y.tab.c"
    break;

  case 54:
#line 141 "gocompiler.y"
                   { (yyval.node) = addchild(createNode("Gt",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1854 "y.tab.c"
    break;

  case 55:
#line 142 "gocompiler.y"
                   { (yyval.node) = addchild(createNode("Eq",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1860 "y.tab.c"
    break;

  case 56:
#line 143 "gocompiler.y"
                   { (yyval.node) = addchild(createNode("Ne",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1866 "y.tab.c"
    break;

  case 57:
#line 144 "gocompiler.y"
                   { (yyval.node) = addchild(createNode("Le",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1872 "y.tab.c"
    break;

  case 58:
#line 145 "gocompiler.y"
                   { (yyval.node) = addchild(createNode("Ge",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1878 "y.tab.c"
    break;

  case 59:
#line 146 "gocompiler.y"
                     { (yyval.node) = addchild(createNode("Add",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1884 "y.tab.c"
    break;

  case 60:
#line 147 "gocompiler.y"
                      { (yyval.node) = addchild(createNode("Sub",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1890 "y.tab.c"
    break;

  case 61:
#line 148 "gocompiler.y"
                     { (yyval.node) = addchild(createNode("Mul",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1896 "y.tab.c"
    break;

  case 62:
#line 149 "gocompiler.y"
                    { (yyval.node) = addchild(createNode("Div",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1902 "y.tab.c"
    break;

  case 63:
#line 150 "gocompiler.y"
                    { (yyval.node) = addchild(createNode("Mod",NULL),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1908 "y.tab.c"
    break;

  case 64:
#line 151 "gocompiler.y"
                          { (yyval.node) = addchild(createNode("Not",NULL),(yyvsp[0].node),NULL);}
#line 1914 "y.tab.c"
    break;

  case 65:
#line 152 "gocompiler.y"
                             { (yyval.node) = addchild(createNode("Minus",NULL),(yyvsp[0].node),NULL);}
#line 1920 "y.tab.c"
    break;

  case 66:
#line 153 "gocompiler.y"
                            { (yyval.node) = addchild(createNode("Plus",NULL),(yyvsp[0].node),NULL);}
#line 1926 "y.tab.c"
    break;

  case 67:
#line 154 "gocompiler.y"
             { (yyval.node) = createNode("IntLit",(yyvsp[0].string));}
#line 1932 "y.tab.c"
    break;

  case 68:
#line 155 "gocompiler.y"
              { (yyval.node) = createNode("RealLit",(yyvsp[0].string));}
#line 1938 "y.tab.c"
    break;

  case 69:
#line 156 "gocompiler.y"
         { (yyval.node) = (yyvsp[0].node);}
#line 1944 "y.tab.c"
    break;

  case 70:
#line 157 "gocompiler.y"
                     { (yyval.node) = add1child(createNode("Call",NULL),(yyvsp[0].node));}
#line 1950 "y.tab.c"
    break;

  case 71:
#line 158 "gocompiler.y"
                      { (yyval.node) = NULL; syntatic_errors = 1;}
#line 1956 "y.tab.c"
    break;

  case 72:
#line 159 "gocompiler.y"
                     { (yyval.node) = (yyvsp[-1].node);}
#line 1962 "y.tab.c"
    break;

  case 73:
#line 162 "gocompiler.y"
        { (yyval.node) = createNode("Id",(yyvsp[0].string));}
#line 1968 "y.tab.c"
    break;


#line 1972 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 167 "gocompiler.y"




int main(int argc, char *argv[])
{   
    if(argc > 1){
        if (strcmp(argv[1], "-l") == 0) {
            hide = 0;
			yylex();
        }
        if (strcmp(argv[1], "-t") == 0) {
            hide = 1;
			yyparse();

            if(!syntatic_errors){
                 showList(my_tree,0);
            }
        }
    }
    else{
        hide = 1;
        yyparse();
    }

    return 0;
}
