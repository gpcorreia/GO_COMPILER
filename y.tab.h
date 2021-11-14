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
    ID = 259,
    SEMICOLON = 260,
    VAR = 261,
    LPAR = 262,
    RPAR = 263,
    COMMA = 264,
    INT = 265,
    FLOAT32 = 266,
    BOOL = 267,
    STRING = 268,
    FUNC = 269,
    LBRACE = 270,
    RBRACE = 271,
    ASSIGN = 272,
    ELSE = 273,
    IF = 274,
    FOR = 275,
    RETURN = 276,
    PRINT = 277,
    STRLIT = 278,
    BLANKID = 279,
    PARSEINT = 280,
    CMDARGS = 281,
    LSQ = 282,
    RSQ = 283,
    INTLIT = 284,
    REALLIT = 285,
    OR = 286,
    AND = 287,
    LT = 288,
    GT = 289,
    EQ = 290,
    NE = 291,
    LE = 292,
    GE = 293,
    PLUS = 294,
    MINUS = 295,
    STAR = 296,
    DIV = 297,
    MOD = 298,
    NOT = 299
  };
#endif
/* Tokens.  */
#define PACKAGE 258
#define ID 259
#define SEMICOLON 260
#define VAR 261
#define LPAR 262
#define RPAR 263
#define COMMA 264
#define INT 265
#define FLOAT32 266
#define BOOL 267
#define STRING 268
#define FUNC 269
#define LBRACE 270
#define RBRACE 271
#define ASSIGN 272
#define ELSE 273
#define IF 274
#define FOR 275
#define RETURN 276
#define PRINT 277
#define STRLIT 278
#define BLANKID 279
#define PARSEINT 280
#define CMDARGS 281
#define LSQ 282
#define RSQ 283
#define INTLIT 284
#define REALLIT 285
#define OR 286
#define AND 287
#define LT 288
#define GT 289
#define EQ 290
#define NE 291
#define LE 292
#define GE 293
#define PLUS 294
#define MINUS 295
#define STAR 296
#define DIV 297
#define MOD 298
#define NOT 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "gocompiler.y"

    char * value;

#line 149 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
