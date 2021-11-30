/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 19 "gocompiler.y"

	char * string;
	struct tree * node;

#line 154 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
