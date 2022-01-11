%{ 
    // Criado por Gonçalo Correia (2018306132) e Tomas Ferreira (2019224786) - 2021 
    
    #include "gocompiler.h"
    // #include "symbols_table.h"
    #include "y.tab.h"
    
    #define MAX_STRING 100 
    void countColumns();
    void countLines();
    void checknewLine();
    void helpoutput(char *string, int state);
    void helperrorstate(int state);
    void helperrorString(int state);
    void helperrorIntegerLiterals();
    void checkEOF();
    void clearString();
    int columns = 1;
    int lines = 1;
    int insertSemicolon = 0;
    int isComment = 0;
    int saveMarks = 0;
    int saveComm = 0;
    int saveColumns = 1;
    int saveLines = 1;
    int hide = 0;
    int checkmarks = 0;
    int newline = 0;
    int strCheck = 0;
    char final[MAX_STRING] = "";
    extern int syntatic_errors;
    int lexical_errors = 0;
    // table_element *symtab=NULL;
%}



letra               [a-zA-Z_] 
decimal             [0-9]+
octal               [0-7]+
hex                 [0-9A-Fa-f]+

octalstring         0{octal}
hexstring           0[xX]{hex}
octalinvalidestring 0(([0-9])*([8-9])([0-9])*([8-9])*)


escape              \\n|\\f|\\r|\\\\|\\\"|\\t
invalidescape		\\[^nfrt\\"]?

sinal               [+-]
exp                 [eE]{sinal}?{decimal}

ids                 {letra}({letra}|{decimal})*
intlit              {decimal}|{octalstring}|{hexstring}
reallit             {decimal}"."{decimal}?{exp}?|{decimal}{exp}|"."{decimal}{exp}?
strlit              ([^\n\r\\\"]|{escape}*)

marks               "\""
startcomment        "/*"
endcomment          "*/"
comment             "//"

semicolon           ";"     
comma               ","     
blankid             "_"     
assign              "="     
star                "*"     
div                 "/"    
minus               "-"     
plus                "+"     
eq                  "=="     
ge                  ">="     
gt                  ">"     
lbrace              "{"     
le                  "<="    
lpar                "("    
lsq                 "["     
lt                  "<"     
mod                 "%"     
ne                  "!="     
not                 "!"   
and                 "&&"     
or                  "||"     
rbrace              "}"     
rpar                ")"    
rsq                 "]"     
package             "package"     
return              "return"     
else                "else"     
for                 "for"     
if                  "if"     
var                 "var"     
int                 "int"     
float32             "float32"     
bool                "bool"     
string              "string"     
fmtPrintln          "fmt.Println"     
strconvAtoi         "strconv.Atoi"     
func                "func"    
osArgs              "os.Args" 
whitespace          " "|"\t"|"\b"
newline             "\n"|"\r\n"    
reserved            break|default|interface|select|case|defer|go|map|struct|chan|goto|switch|const|fallthrough|range|type|continue|import|"++"|"--"

%X INCOMMENT STARTCOMMENT NEWLINE STRLIT1 RETURN1 INVALIDSTRLIT 
%%
{semicolon}                         {helpoutput("SEMICOLON\n",0); countColumns(); if(hide != 0) return SEMICOLON;}
{comma}                             {helpoutput("COMMA\n",0); countColumns(); if(hide != 0) return COMMA;}
{blankid}                           {helpoutput("BLANKID\n",0); countColumns(); if(hide != 0) return BLANKID;  }
{assign}                            {helpoutput("ASSIGN\n",0); countColumns(); if(hide != 0) return ASSIGN;  }
{star}                              {helpoutput("STAR\n",0); countColumns(); if(hide != 0) return STAR; }
{div}                               {helpoutput("DIV\n",0); countColumns(); if(hide != 0) return DIV;  }
{minus}                             {helpoutput("MINUS\n",0); countColumns(); if(hide != 0) return MINUS; }
{plus}                              {helpoutput("PLUS\n",0); countColumns(); if(hide != 0) return PLUS;  }
{eq}                                {helpoutput("EQ\n",0); countColumns(); if(hide != 0) return EQ;  }
{ge}                                {helpoutput("GE\n",0); countColumns(); if(hide != 0) return GE;  }
{gt}                                {helpoutput("GT\n",0); countColumns(); if(hide != 0) return GT;  } 
{lbrace}                            {helpoutput("LBRACE\n",0); countColumns(); if(hide != 0) return LBRACE; }
{le}                                {helpoutput("LE\n",0); countColumns(); if(hide != 0) return LE;  }
{lpar}                              {helpoutput("LPAR\n",0); countColumns(); if(hide != 0) return LPAR;  }
{lsq}                               {helpoutput("LSQ\n",0); countColumns(); if(hide != 0) return LSQ;  }
{lt}                                {helpoutput("LT\n",0); countColumns(); if(hide != 0) return LT;  }
{mod}                               {helpoutput("MOD\n",0); countColumns(); if(hide != 0) return MOD;  }
{ne}                                {helpoutput("NE\n",0); countColumns(); if(hide != 0) return NE;  }
{not}                               {helpoutput("NOT\n",0); countColumns(); if(hide != 0) return NOT;  } 
{and}                               {helpoutput("AND\n",0); countColumns(); if(hide != 0) return AND;  }
{or}                                {helpoutput("OR\n",0); countColumns(); if(hide != 0) return OR;  }
{rbrace}                            {helpoutput("RBRACE\n",1); countColumns(); if(hide != 0) return RBRACE; }
{rpar}                              {helpoutput("RPAR\n",1); countColumns(); if(hide != 0) return RPAR; }
{rsq}                               {helpoutput("RSQ\n",1); countColumns(); if(hide != 0) return RSQ;  }
{package}                           {helpoutput("PACKAGE\n",0); countColumns(); if(hide != 0) return PACKAGE;  }
{return}                            {helpoutput("RETURN\n",1); countColumns(); if(hide != 0) return RETURN;  }
{else}                              {helpoutput("ELSE\n",0); countColumns(); if(hide != 0) return ELSE;  }
{for}                               {helpoutput("FOR\n",0); countColumns(); if(hide != 0) return FOR;  }
{if}                                {helpoutput("IF\n",0); countColumns(); if(hide != 0) return IF;  }
{var}                               {helpoutput("VAR\n",0); countColumns(); if(hide != 0) return VAR;  }
{int}                               {helpoutput("INT\n",0); countColumns(); if(hide != 0) return INT;  }
{float32}                           {helpoutput("FLOAT32\n",0); countColumns(); if(hide != 0) return FLOAT32;  }
{bool}                              {helpoutput("BOOL\n",0); countColumns(); if(hide != 0) return BOOL;  }
{string}                            {helpoutput("STRING\n",0); countColumns(); if(hide != 0) return STRING;  }
{fmtPrintln}                        {helpoutput("PRINT\n",0); countColumns(); if(hide != 0) return PRINT;  }
{strconvAtoi}                       {helpoutput("PARSEINT\n",0); countColumns(); if(hide != 0) return PARSEINT;  }
{func}                              {helpoutput("FUNC\n",0); countColumns(); if(hide != 0) return FUNC;  }
{osArgs}                            {helpoutput("CMDARGS\n",0); countColumns(); if(hide != 0) return CMDARGS;  }
{octalinvalidestring}               {helperrorIntegerLiterals();}
{marks}                             {saveMarks = columns; checkmarks=1 ; saveColumns=columns; countColumns(); clearString(); BEGIN STRLIT1 ; }
{intlit}                            {if(hide == 0) {printf("INTLIT(%s)\n",yytext);} yylval.token.token=(char*)strdup(yytext); yylval.token.line = lines; yylval.token.column = columns; insertSemicolon = 1; countColumns(); if(hide != 0) return INTLIT;}
{reallit}                           {if(hide == 0) {printf("REALLIT(%s)\n",yytext);} yylval.token.token=(char*)strdup(yytext); yylval.token.line = lines; yylval.token.column = columns; insertSemicolon = 1; countColumns(); if(hide != 0) return REALLIT; }
{reserved}                          {if(hide == 0) {printf("RESERVED(%s)\n",yytext);} yylval.token.token=(char*)strdup(yytext); yylval.token.line = lines; yylval.token.column = columns; insertSemicolon=0; countColumns(); if(hide != 0) return RESERVED;}
{ids}                               {if(hide == 0) {printf("ID(%s)\n",yytext);} yylval.token.token=(char*)strdup(yytext); yylval.token.line = lines; yylval.token.column = columns; insertSemicolon = 1; countColumns(); if(hide != 0) return ID;}
{whitespace}                        { countColumns();}
{newline}                           { if(insertSemicolon == 1 && isComment == 0){ if(hide == 0){ printf("SEMICOLON\n");} strCheck = 0; insertSemicolon = 0; yylval.token.line = lines; yylval.token.column = columns; countLines(); if(hide != 0){ return SEMICOLON;} }  else{strCheck=0; countLines();}}
{comment}.*                         {;}
{startcomment}                      {isComment = 1; saveComm=columns; saveLines=lines; countColumns(); BEGIN STARTCOMMENT ;}



<STARTCOMMENT><<EOF>>               { helperrorstate(1); insertSemicolon = 0; BEGIN 0; }
<STARTCOMMENT>.                     { countColumns();}
<STARTCOMMENT>{newline}             { countLines(); }
<STARTCOMMENT>{endcomment}          { countColumns(); isComment = 0;BEGIN 0; }

<STRLIT1>{marks}                     {if(hide == 0) {printf("STRLIT(\"%s\")\n",final);} insertSemicolon=1; checkmarks=0;  BEGIN 0; yylval.token.token=(char*)strdup(final); yytext = final; yylval.token.line = lines; yylval.token.column = columns-strlen(yytext)-1; countColumns();  if(hide != 0){ strCheck = 1; return STRLIT;}}
<STRLIT1>{whitespace}                {strcat(final,yytext);countColumns();}
<STRLIT1>{newline}                   {helperrorString(0); countLines() ; clearString(); BEGIN 0 ; }
<STRLIT1><<EOF>>                     {helperrorString(0); checkmarks= 0;clearString(); BEGIN 0 ; }
<STRLIT1>{invalidescape}             {helperrorString(1);  countColumns(); BEGIN INVALIDSTRLIT; }
<STRLIT1>{strlit}			         {strcat(final,yytext); countColumns();}
<STRLIT1>.                           {countColumns();}


<INVALIDSTRLIT>{marks}              {clearString();countColumns(); checkmarks= 0; BEGIN 0; /*   String aceite */}
<INVALIDSTRLIT>"\\"{newline}        {helperrorString(1); if(checkmarks== 1) helperrorString(0); countLines() ; clearString();  BEGIN 0 ;}
<INVALIDSTRLIT>{whitespace}         {strcat(final,yytext);countColumns();}
<INVALIDSTRLIT>{invalidescape}      {helperrorString(1); countColumns(); BEGIN INVALIDSTRLIT;}
<INVALIDSTRLIT>{newline}            {helperrorString(0); countLines() ; clearString(); checkmarks= 0; BEGIN 0 ; }
<INVALIDSTRLIT><<EOF>>              {helperrorString(0); checkmarks= 0; clearString(); BEGIN 0 ; }
<INVALIDSTRLIT>{strlit}			    {countColumns();clearString();}
<INVALIDSTRLIT>.                    {countColumns();}


<<EOF>>                             { yylval.token.line = lines;
                                        yylval.token.column = columns;
                                        if (insertSemicolon == 1){
                                            if(hide == 0){ 
                                                printf("SEMICOLON\n");
                                            }
                                        insertSemicolon = 0;
                                        if(hide!=0) return SEMICOLON;
                                        }
                                        return 0;
                                    }
            
.                                   { helperrorstate(0); }



%%
void helpoutput(char * string,int state){

    yylval.token.line = lines;
    yylval.token.column = columns;

    if(hide == 0)
        printf("%s",string);

    if(state == 0){
        insertSemicolon = 0;
    }

    else if(state == 1){
        insertSemicolon = 1;
    }

}

void helperrorstate(int state){
    lexical_errors = 1;

    if(state == 0){
        if(hide == 0 || hide == 1) printf("Line %d, column %d: illegal character (%s)\n",lines,columns,yytext);
        countColumns();
    }
    else if( state == 1){
        if(hide == 0 || hide == 1) printf("Line %d, column %d: unterminated comment\n",saveLines,saveComm);
        saveComm = 0;
        saveLines = 0;
    }

}



void helperrorIntegerLiterals(){
        lexical_errors = 1;

        if(hide == 0 || hide == 1) printf("Line %d, column %d: invalid octal constant (%s)\n",lines,columns,yytext);
        countColumns();
    
}



void helperrorString(int state){
        lexical_errors = 1;


    if(state == 0){
        if(hide == 0 || hide == 1) printf("Line %d, column %d: unterminated string literal\n",lines,saveMarks);
        saveMarks = 0;
    }

    else if(state == 1){
        for (int i = 0; i<=yyleng;i++){
            if(yytext[i] == '\n' && (hide == 0 || hide == 1)){
                printf("Line %d, column %d: invalid escape sequence (\\)\n",lines,columns);
                return;
            }
        }
        if(hide == 0 || hide == 1) printf("Line %d, column %d: invalid escape sequence (%s)\n",lines,columns,yytext);
    }

}



void clearString(){

    for(int i = 0;i<100;i++){
        
        final[i]='\0';
    }
}



void countColumns(){
    if(yyleng == 1){
        columns++;
    }
    else{
        columns+=yyleng;
    }
}



void countLines(){
        lines++;
        columns=1;
}



void yyerror (const char *s) { 
     syntatic_errors = 1;
     if(strCheck == 0){
        printf ( "Line %d, column %d: %s: %s\n" ,yylval.token.line,yylval.token.column,s, yytext);   
     }
     else{
        printf ( "Line %d, column %d: %s: \"%s\"\n" ,yylval.token.line,yylval.token.column,s, yytext);
        strCheck = 0;
     }
}


int yywrap() {
    return 1;
}


