%{
    #include "gocompiler.c"
    #include "gocompiler.h"
    int yylex(void);
    void yyerror (const char *s);
    void checkdivision();
    void showList(Tree * head,int point2print);
    extern char * yytext;
    extern int hide;
    extern int columns;
    extern int lines;
    int check = 0;
    int needsBlock = 0;
    Tree * my_tree = NULL;
    int syntatic_errors = 0;
    int yydebug = 0;
%}


%union {
	char * string;
	struct tree * node;
}


%token error PACKAGE SEMICOLON VAR LPAR RPAR COMMA INT FLOAT32 BOOL STRING FUNC LBRACE RBRACE ASSIGN ELSE IF FOR RETURN PRINT BLANKID PARSEINT CMDARGS LSQ RSQ OR AND
%token LT GT EQ NE LE GE PLUS MINUS STAR DIV MOD NOT
%token <string> STRLIT RESERVED INTLIT ID REALLIT


%type <node> Program Declarations VarDeclaration VarSpec AuxVarSpec Type Expr
%type <node> FuncDeclaration Parameters AuxParameters FuncBody VarsAndStatements Statement
%type <node> AuxStatement ParseArgs FuncInvocation AuxFuncInvocation Id

%left COMMA
%right ASSIGN
%left OR
%left AND 
%left GE LE LT GT EQ NE
%left PLUS MINUS NOT
%left STAR DIV MOD
%right UNARY
%left LPAR RPAR LSQ RSQ LBRACE RBRACE


%%

Program: PACKAGE Id SEMICOLON Declarations { $$ = my_tree = addchild(createNode("Program",NULL),$4,NULL);}
        ;

Declarations:    Declarations VarDeclaration SEMICOLON {$$ = addbro($1,$2);}
               | Declarations FuncDeclaration SEMICOLON { $$ = addbro($1,$2);}
               | {$$ = NULL;}
               ;

VarDeclaration: VAR VarSpec {$$ = $2;}
              | VAR LPAR VarSpec SEMICOLON RPAR {$$ = $3;}
              ;

VarSpec: Id AuxVarSpec Type {$$ = createListId(addbro($1,$2),$3,1); }
        | { $$ == NULL;}
        ;


AuxVarSpec: COMMA Id AuxVarSpec { $$ = addbro($3,$2);}
          | {$$ = NULL;}
          ;


Type: INT   { $$ = createNode("Int",NULL);} 
    | FLOAT32 {$$ = createNode("Float32",NULL);}
    | BOOL {$$ = createNode("Bool",NULL);}
    | STRING {$$ = createNode("String",NULL);}
    ;

FuncDeclaration:  FUNC Id LPAR Parameters RPAR Type FuncBody  {$$ = createFuncDecl($2,$4,$6,$7);}
               |  FUNC Id LPAR RPAR Type FuncBody    {$$ = createFuncDecl($2,NULL,$5,$6);} 
               |  FUNC Id LPAR Parameters RPAR FuncBody {$$ = createFuncDecl($2,$4,NULL,$6);}   
               |  FUNC Id LPAR RPAR FuncBody  { $$ = createFuncDecl($2,NULL,NULL,$5);} 
               ;


Parameters: Id Type AuxParameters   {$$ = addbro(addchild(createNode("ParamDecl",NULL),$2,$1),$3);}
          ;

AuxParameters: COMMA Id Type AuxParameters { $$ = addbro(addchild(createNode("ParamDecl",NULL),$3,$2),$4);}
             |  {$$ = NULL;}
             ;

FuncBody: LBRACE VarsAndStatements RBRACE { $$ = addchild(createNode("FuncBody",NULL),$2,NULL);}
        ;


VarsAndStatements: VarsAndStatements VarDeclaration SEMICOLON {$$ = addbro($1,$2);}
                 | VarsAndStatements Statement SEMICOLON {$$ = addbro($1,$2);}
                 | VarsAndStatements SEMICOLON {$$ = $1;}
                 | {$$ = NULL;}
                 ;

Statement: Id ASSIGN Expr   {$$ = addchild(createNode("Assign",NULL),$1,$3);}
         | LBRACE AuxStatement RBRACE { $$ = $2;}
         | IF Expr LBRACE AuxStatement RBRACE {$$ = cicleIf($2,$4,NULL);}
         | IF Expr LBRACE AuxStatement RBRACE ELSE LBRACE AuxStatement RBRACE { $$ = cicleIf($2,$4,$8);}
         | FOR Expr LBRACE AuxStatement RBRACE { $$ = cicleFor($2,$4);}
         | FOR LBRACE AuxStatement RBRACE { $$ = cicleFor(NULL,$3);}
         | RETURN   {$$ = createNode("Return",NULL);}
         | RETURN Expr {$$ = addchild(createNode("Return",NULL),$2,NULL);}
         | FuncInvocation {$$ = $1;}
         | ParseArgs {$$ = $1;}
         | PRINT LPAR Expr RPAR {$$ = addchild(createNode("Print",NULL),$3,NULL);}
         | PRINT LPAR STRLIT RPAR { $$ = addchild(createNode("Print",NULL),createNode("Strlit",$3),NULL);}
         | error { $$ = NULL; syntatic_errors = 1;}
         ;


AuxStatement: AuxStatement Statement SEMICOLON{ $$ = addbro($1,$2);}
            | {$$ = NULL;}
            ;

ParseArgs: Id COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR { $$ = addchild(createNode("ParseArgs",NULL),$1,$9);}
          | Id COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR {$$ = NULL; syntatic_errors = 1;}
         ;

FuncInvocation: Id LPAR AuxFuncInvocation RPAR { $$ = addbro(createListId($1,NULL,0),$3);}
              | Id LPAR error RPAR {$$ = NULL; syntatic_errors = 1;}
              ;


AuxFuncInvocation: Expr { $$ = $1;}
                 | COMMA Expr { $$ = $2;}
                 ;


Expr: Expr OR Expr { $$ = addchild(createNode("Or",NULL),$1,$3);}
    | Expr AND Expr { $$ = addchild(createNode("And",NULL),$1,$3);}
    | Expr LT Expr { $$ = addchild(createNode("Lt",NULL),$1,$3);}
    | Expr GT Expr { $$ = addchild(createNode("Gt",NULL),$1,$3);}
    | Expr EQ Expr { $$ = addchild(createNode("Eq",NULL),$1,$3);}
    | Expr NE Expr { $$ = addchild(createNode("Ne",NULL),$1,$3);}
    | Expr LE Expr { $$ = addchild(createNode("Le",NULL),$1,$3);}
    | Expr GE Expr { $$ = addchild(createNode("Ge",NULL),$1,$3);}
    | Expr PLUS Expr { $$ = addchild(createNode("Plus",NULL),$1,$3);}
    | Expr MINUS Expr { $$ = addchild(createNode("Minus",NULL),$1,$3);}
    | Expr STAR Expr { $$ = addchild(createNode("Star",NULL),$1,$3);}
    | Expr DIV Expr { $$ = addchild(createNode("Div",NULL),$1,$3);}
    | Expr MOD Expr { $$ = addchild(createNode("Mod",NULL),$1,$3);}
    | NOT Expr{ $$ = addchild(createNode("Not",NULL),$2,NULL);} 
    | MINUS Expr { $$ = addchild(createNode("Minus",NULL),$2,NULL);}
    | PLUS Expr { $$ = addchild(createNode("Plus",NULL),$2,NULL);}
    | INTLIT { $$ = createNode("IntLit",$1);}
    | REALLIT { $$ = createNode("RealLit",$1);}
    | Id { $$ = $1;}
    | FuncInvocation {$$ = $1;}
    | LPAR error RPAR { $$ = NULL; syntatic_errors = 1;}
    | LPAR Expr RPAR {printf("b\n"); $$ = $2;}
    ;

Id: ID  { $$ = createNode("Id",$1);}
   ; 



%%



void showList(Tree * head,int point2print)
{   

    if (head == NULL)
    {
        return;
    }
    
    for(int i = 0;i<point2print; i++){
        printf(".");
    }

    if(!head->value){
        printf("%s\n",head->token);
    }
    else{
        printf("%s(%s)\n",head->token,head->value);
    }

    if(head->child){
        showList(head->child,point2print+2);
    }
    if(head->next){
        showList(head->next,point2print);
    }
    
}



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