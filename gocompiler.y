%{

    #include "gocompiler.h"
    #include "gocompiler.c"
    int yylex(void);
    void yyerror (const char *s);
    void checkdivision();
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

Program: PACKAGE ID SEMICOLON  {addNode("Program",$2); showList();}
        ;

// Declarations:
//             | VarDeclaration SEMICOLON Declarations
//             | FuncDeclaration SEMICOLON Declarations
//             ;

// VarDeclaration: VAR VarSpec
//               | VAR LPAR VarSpec SEMICOLON RPAR
//               ;

// VarSpec: ID AuxVarSpec Type
//         |
//         ;


// AuxVarSpec: COMMA ID AuxVarSpec
//           |
//           ;


// Type: INT 
//     | FLOAT32
//     | BOOL
//     |STRING
//     ;

// FuncDeclaration:  FUNC ID LPAR Parameters RPAR Type FuncBody
//                |  FUNC ID LPAR RPAR Type FuncBody
//                |  FUNC ID LPAR Parameters RPAR FuncBody  
//                |  FUNC ID LPAR RPAR FuncBody
//                ;


// Parameters: ID Type AuxParameters
//           |
//           ;

// AuxParameters: COMMA ID Type AuxParameters
//              |
//              ;

// FuncBody: LBRACE VarsAndStatements RBRACE
//         ;


// VarsAndStatements: VarsAndStatements VarDeclaration SEMICOLON
//                  | VarsAndStatements Statement SEMICOLON
//                  | VarsAndStatements SEMICOLON
//                  |
//                  ;

// Statement: ID ASSIGN Expr
//          | LBRACE AuxStatement RBRACE
//          | IF Expr LBRACE AuxStatement RBRACE
//          | IF Expr LBRACE {Statement SEMICOLON} RBRACE ELSE LBRACE AuxStatement RBRACE
//          | FOR Expr LBRACE AuxStatement RBRACE
//          | FOR LBRACE AuxStatement RBRACE 
//          | RETURN
//          | RETURN Expr
//          | FuncInvocation
//          | ParseArgs
//          | PRINT LPAR Expr RPAR
//          | PRINT LPAR STRLIT RPAR
//          ;


// AuxStatement: Statement SEMICOLON AuxStatement
//             |
//             ;

// ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR
//          ;

// FuncInvocation: ID LPAR AuxFuncInvocation RPAR
//               ;


// AuxFuncInvocation: Expr
//                  | COMMA Expr
//                  ;


// Expr: Expr OR Expr
//     | Expr AND Expr
//     | Expr LT Expr
//     | Expr GT Expr
//     | Expr EQ Expr
//     | Expr NE Expr
//     | Expr LE Expr
//     | Expr GE Expr
//     | Expr PLUS Expr
//     | Expr MINUS Expr
//     | Expr STAR Expr
//     | Expr DIV Expr
//     | Expr MOD Expr
//     | NOT Expr
//     | MINUS Expr
//     | PLUS Expr
//     | Expr MOD Expr
//     | INTLIT
//     | REALLIT
//     | ID
//     | FuncInvocation
//     | LPAR Expr RPAR
//     ;



%%
int main(int argc, char *argv[])
{   

    // if(argv[1] == NULL){
    //     hide = 1;
    // }

    yyparse();

    return 0;


}