%{

    #include "gocompiler.h"
    #include "gocompiler.c"
    int yylex(void);
    void yyerror (const char *s);
    void checkdivision();
    extern char * yytext;
    int check = 0;
%}


%union {
    char * type;
	char * string;
	struct node * node;
}


%token ERROR PACKAGE SEMICOLON VAR LPAR RPAR COMMA INT FLOAT32 BOOL STRING FUNC LBRACE RBRACE ASSIGN ELSE IF FOR RETURN PRINT BLANKID PARSEINT CMDARGS LSQ RSQ OR AND
%token LT GT EQ NE LE GE PLUS MINUS STAR DIV MOD NOT
%token <string> RESERVED STRLIT INTLIT ID REALLIT


%left COMMA
%right ASSIGN
%left OR
%left AND 
%left GE LE LT GT EQ NE
%left PLUS MINUS
%left STAR DIV MOD
%right UNARY
%left LPAR RPAR LSQ RSQ LBRACE RBRACE


%%

Program: PACKAGE Id SEMICOLON Declarations {addNode("Program",""); showList();}
        ;

Declarations:   {$$ = NULL;}
               | VarDeclaration SEMICOLON Declarations
               | FuncDeclaration SEMICOLON Declarations {$$ = $1;}
               ;

VarDeclaration: VAR VarSpec
              | VAR LPAR VarSpec SEMICOLON RPAR
              ;

VarSpec: Id AuxVarSpec Type
        |
        ;


AuxVarSpec: COMMA Id AuxVarSpec
          |
          ;


Type: INT 
    | FLOAT32
    | BOOL
    | STRING
    ;

FuncDeclaration:  FUNC Id LPAR Parameters RPAR Type FuncBody  {$$ = createFuncDecl($2,$4,$6,$7);}
               |  FUNC Id LPAR RPAR Type FuncBody    {$$ = createFuncDecl($2,NULL,$5,$6);} 
               |  FUNC Id LPAR Parameters RPAR FuncBody {$$ = createFuncDecl($2,$4,NULL,$6);}   
               |  FUNC Id LPAR RPAR FuncBody  {$$ = createFuncDecl($2,NULL,NULL,$5);} 
               ;


Parameters: Id Type AuxParameters   {if($$ == NULL){addNode("ParamDecl",$1,NULL);} else{ $$ = addNode("ParamDecl",$1,$2);}}
          ;

AuxParameters: COMMA Id Type AuxParameters
             |  {$$ = NULL;}
             ;

FuncBody: LBRACE VarsAndStatements RBRACE { $$ = addchild(createNode("FuncBody",NULL),$2,NULL);}
        ;


VarsAndStatements: VarsAndStatements VarDeclaration SEMICOLON {$$ = addbro($1,$2);}
                 | VarsAndStatements Statement SEMICOLON {$$ = addbro($1,$2);}
                 | VarsAndStatements SEMICOLON {$$ = $1;}
                 | {$$ = NULL;}
                 ;

Statement: Id ASSIGN Expr
         | LBRACE AuxStatement RBRACE
         | IF Expr LBRACE AuxStatement RBRACE 
         | IF Expr LBRACE AuxStatement RBRACE ELSE LBRACE AuxStatement RBRACE
         | FOR Expr LBRACE AuxStatement RBRACE
         | FOR LBRACE AuxStatement RBRACE 
         | RETURN   {$$ = createNode("Return",NULL);}
         | RETURN Expr {$$ = addchild(createNode("Return",NULL),$2,NULL);}
         | FuncInvocation
         | ParseArgs
         | PRINT LPAR Expr RPAR
         | PRINT LPAR STRLIT RPAR
         ;


AuxStatement: Statement SEMICOLON AuxStatement
            |
            ;

ParseArgs: Id COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR
         ;

FuncInvocation: Id LPAR AuxFuncInvocation RPAR
              ;


AuxFuncInvocation: Expr
                 | COMMA Expr
                 ;


Expr: Expr OR Expr { $$ = addchild(createNode("OR",NULL),$1,$2); }
    | Expr AND Expr { $$ = addchild(createNode("AND",NULL),$1,$2); }
    | Expr LT Expr { $$ = addchild(createNode("LT",NULL),$1,$2); }
    | Expr GT Expr { $$ = addchild(createNode("GT",NULL),$1,$2); }
    | Expr EQ Expr { $$ = addchild(createNode("EQ",NULL),$1,$2); }
    | Expr NE Expr { $$ = addchild(createNode("NE",NULL),$1,$2); }
    | Expr LE Expr { $$ = addchild(createNode("LE",NULL),$1,$2); }
    | Expr GE Expr { $$ = addchild(createNode("GE",NULL),$1,$2); }
    | Expr PLUS Expr { $$ = addchild(createNode("PLUS",NULL),$1,$2); }
    | Expr MINUS Expr { $$ = addchild(createNode("MINUS",NULL),$1,$2); }
    | Expr STAR Expr { $$ = addchild(createNode("STAR",NULL),$1,$2); }
    | Expr DIV Expr { $$ = addchild(createNode("DIV",NULL),$1,$2); }
    | Expr MOD Expr { $$ = addchild(createNode("MOD",NULL),$1,$2); }
    | NOT Expr { $$ = addchild(createNode("NOT",NULL),$2,NULL); } 
    | MINUS Expr { $$ = addchild(createNode("MINUS",NULL),$2,NULL); }
    | PLUS Expr { $$ = addchild(createNode("PLUS",NULL),$2,NULL); }
    | INTLIT { $$ = createNode("IntLit",$1); }
    | REALLIT { $$ = createNode("RealLit",$1); }
    | Id {$$ = $1;}
    | FuncInvocation
    | LPAR Expr RPAR
    ;

Id: ID  {$$ = createNode("Id",$1);}
   ; 


%%


void yyerror (const char *s) { 
     printf ("%s: %s\n", s, yytext);
}

int main(int argc, char *argv[])
{   

    // if(argv[1] == NULL){
    //     hide = 1;
    // }

    yyparse();

    return 0;


}