%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "gocompiler.c"
    
    int yylex(void);
    void yyerror (const char *s);
    void checkdivision();
    int check = 0;
%}

%union{
    char * value;
}


%token PACKAGE ID SEMICOLON VAR LPAR RPAR COMMA INT FLOAT32 BOOL STRING FUNC LBRACE RBRACE ASSIGN ELSE IF FOR RETURN PRINT STRLIT BLANKID PARSEINT CMDARGS LSQ RSQ INTLIT REALLIT OR AND
%token LT GT EQ NE LE GE PLUS MINUS STAR DIV MOD NOT

%left COMMA


%%
Program: PACKAGE ID SEMICOLON {printf("1º rule\n");}
        ;

Declarations: 
            | VarDeclaration SEMICOLON Declarations
            | FuncDeclaration SEMICOLON Declarations
            ;

VarDeclaration: VAR VarSpec
              | VAR LPAR VarSpec SEMICOLON RPAR
              ;

VarSpec: ID AuxVarSpec Type
        |
        ;


AuxVarSpec: COMMA ID AuxVarSpec
          |
          ;


Type: INT 
    | FLOAT32
    | BOOL
    |STRING
    ;

FuncDeclaration:  FUNC ID LPAR Parameters RPAR Type FuncBody
               |  FUNC ID LPAR RPAR Type FuncBody
               |  FUNC ID LPAR Parameters RPAR FuncBody  
               |  FUNC ID LPAR RPAR FuncBody
               ;


Parameters: ID Type AuxParameters
          |
          ;

AuxParameters: COMMA ID Type AuxParameters
             |
             ;

FuncBody: LBRACE VarsAndStatements RBRACE
        ;


VarsAndStatements: VarsAndStatements VarDeclaration SEMICOLON
                 | VarsAndStatements Statement SEMICOLON
                 | VarsAndStatements SEMICOLON
                 |
                 ;

Statement: ID ASSIGN Expr
         | LBRACE AuxStatement RBRACE
         | IF Expr LBRACE AuxStatement RBRACE
         | IF Expr LBRACE {Statement SEMICOLON} RBRACE ELSE LBRACE AuxStatement RBRACE
         | FOR Expr LBRACE AuxStatement RBRACE
         | FOR LBRACE AuxStatement RBRACE 
         | RETURN
         | RETURN Expr
         | FuncInvocation
         | ParseArgs
         | PRINT LPAR Expr RPAR
         | PRINT LPAR STRLIT RPAR
         ;


AuxStatement: Statement SEMICOLON AuxStatement
            |
            ;

ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR
         ;

FuncInvocation: ID LPAR AuxFuncInvocation RPAR
              ;


AuxFuncInvocation: Expr
                 | COMMA Expr
                 ;


Expr: Expr OR Expr
    | Expr AND Expr
    | Expr LT Expr
    | Expr GT Expr
    | Expr EQ Expr
    | Expr NE Expr
    | Expr LE Expr
    | Expr GE Expr
    | Expr PLUS Expr
    | Expr MINUS Expr
    | Expr STAR Expr
    | Expr DIV Expr
    | Expr MOD Expr
    | NOT Expr
    | MINUS Expr
    | PLUS Expr
    | Expr MOD Expr
    | INTLIT
    | REALLIT
    | ID
    | FuncInvocation
    | LPAR Expr RPAR
    ;



%%

