%{  
    #include "y.tab.h"
    #include "gocompiler.h"
    
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
    int saveColumns = 0;
    int saveLines = 0;
    int hide = 0;
    int checkmarks = 0;
    int newline = 0;
    char final[MAX_STRING] = "";
    extern int syntatic_errors;
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
{semicolon}                         {helpoutput("SEMICOLON\n",0); if(hide != 0) return SEMICOLON;  countColumns();}
{comma}                             {helpoutput("COMMA\n",0); if(hide != 0) return COMMA;   countColumns();}
{blankid}                           {helpoutput("BLANKID\n",0); if(hide != 0) return BLANKID;  countColumns();}
{assign}                            {helpoutput("ASSIGN\n",0); if(hide != 0) return ASSIGN;  countColumns();}
{star}                              {helpoutput("STAR\n",0); if(hide != 0) return STAR;  countColumns();}
{div}                               {helpoutput("DIV\n",0); if(hide != 0) return DIV;  countColumns();}
{minus}                             {helpoutput("MINUS\n",0); if(hide != 0) return MINUS;  countColumns();}
{plus}                              {helpoutput("PLUS\n",0); if(hide != 0) return PLUS;  countColumns();}
{eq}                                {helpoutput("EQ\n",0); if(hide != 0) return EQ;  countColumns();}
{ge}                                {helpoutput("GE\n",0); if(hide != 0) return GE;  countColumns();}
{gt}                                {helpoutput("GT\n",0); if(hide != 0) return GT;  countColumns();} 
{lbrace}                            {helpoutput("LBRACE\n",0); if(hide != 0) return LBRACE;  printf("%d\n",columns); countColumns();}
{le}                                {helpoutput("LE\n",0); if(hide != 0) return LE;  countColumns();}
{lpar}                              {helpoutput("LPAR\n",0); if(hide != 0) return LPAR;  countColumns();}
{lsq}                               {helpoutput("LSQ\n",0); if(hide != 0) return LSQ;  countColumns();}
{lt}                                {helpoutput("LT\n",0); if(hide != 0) return LT;  countColumns();}
{mod}                               {helpoutput("MOD\n",0); if(hide != 0) return MOD;  countColumns();}
{ne}                                {helpoutput("NE\n",0); if(hide != 0) return NE;  countColumns();}
{not}                               {helpoutput("NOT\n",0); if(hide != 0) return NOT;  countColumns();} 
{and}                               {helpoutput("AND\n",0); if(hide != 0) return AND;  countColumns();}
{or}                                {helpoutput("OR\n",0); if(hide != 0) return OR;  countColumns();}
{rbrace}                            {helpoutput("RBRACE\n",1); if(hide != 0) return RBRACE;  printf("%d\n ",columns); countColumns();}
{rpar}                              {helpoutput("RPAR\n",1); if(hide != 0) return RPAR;  countColumns();}
{rsq}                               {helpoutput("RSQ\n",1); if(hide != 0) return RSQ;  countColumns();}
{package}                           {helpoutput("PACKAGE\n",0); if(hide != 0) return PACKAGE;  countColumns();}
{return}                            {helpoutput("RETURN\n",1); if(hide != 0) return RETURN;  countColumns();}
{else}                              {helpoutput("ELSE\n",0); if(hide != 0) return ELSE;  countColumns();}
{for}                               {helpoutput("FOR\n",0); if(hide != 0) return FOR;  countColumns();}
{if}                                {helpoutput("IF\n",0); if(hide != 0) return IF;  countColumns();}
{var}                               {helpoutput("VAR\n",0); if(hide != 0) return VAR;  countColumns();}
{int}                               {helpoutput("INT\n",0); if(hide != 0) return INT;  countColumns();}
{float32}                           {helpoutput("FLOAT32\n",0); if(hide != 0) return FLOAT32;  countColumns();}
{bool}                              {helpoutput("BOOL\n",0); if(hide != 0) return BOOL;  countColumns();}
{string}                            {helpoutput("STRING\n",0); if(hide != 0) return STRING;  countColumns();}
{fmtPrintln}                        {helpoutput("PRINT\n",0); if(hide != 0) return PRINT;  countColumns();}
{strconvAtoi}                       {helpoutput("PARSEINT\n",0); if(hide != 0) return PARSEINT;  countColumns();}
{func}                              {helpoutput("FUNC\n",0); if(hide != 0) return FUNC;  countColumns();}
{osArgs}                            {helpoutput("CMDARGS\n",0); if(hide != 0) return CMDARGS;  countColumns();}
{octalinvalidestring}               {helperrorIntegerLiterals();}
{marks}                             {saveMarks = columns; checkmarks=1 ; saveColumns=columns; countColumns(); BEGIN STRLIT1 ; }
{intlit}                            {if(hide == 0) {printf("INTLIT(%s)\n",yytext);} yylval.string=(char*)strdup(yytext); insertSemicolon = 1; if(hide != 0) return INTLIT; countColumns();}
{reallit}                           {if(hide == 0) {printf("REALLIT(%s)\n",yytext);} yylval.string=(char*)strdup(yytext); insertSemicolon = 1; if(hide != 0) return REALLIT; countColumns();}
{reserved}                          {if(hide == 0) {printf("RESERVED(%s)\n",yytext);} yylval.string=(char*)strdup(yytext); insertSemicolon=0; if(hide != 0) return RESERVED; countColumns();}
{ids}                               {if(hide == 0) {printf("ID(%s)\n",yytext);} yylval.string=(char*)strdup(yytext); insertSemicolon = 1; if(hide != 0) return ID; countColumns();}
{whitespace}                        { countColumns();}
{newline}                           {if(insertSemicolon == 1 && isComment == 0){ if(hide == 0){ printf("SEMICOLON\n");} else{newline = lines; return SEMICOLON;} insertSemicolon = 0;  } columns = 1; countLines();}
{comment}.*                         {;}
{startcomment}                      {isComment = 1; saveComm=columns; saveLines=lines; countColumns(); BEGIN STARTCOMMENT ;}




<STARTCOMMENT><<EOF>>               { helperrorstate(1); insertSemicolon =0; BEGIN 0; }
<STARTCOMMENT>.                     { countColumns();}
<STARTCOMMENT>{newline}             { countLines(); }
<STARTCOMMENT>{endcomment}          { countColumns(); isComment = 0;BEGIN 0; }

<STRLIT1>{marks}                     {if(hide == 0) {printf("STRLIT(\"%s\")\n",final);} insertSemicolon=1; checkmarks=0;  BEGIN 0; yylval.string=(char*)strdup(final); clearString(); if(hide != 0){ printf("a\n"); columns = saveColumns; return STRLIT;} columns+=strlen(yylval.string)+2; }
<STRLIT1>{whitespace}                {strcat(final,yytext);countColumns();}
<STRLIT1>{newline}                   {helperrorString(0); countLines() ; clearString(); BEGIN 0 ; }
<STRLIT1><<EOF>>                     {helperrorString(0); checkmarks= 0;BEGIN 0 ; }
<STRLIT1>{invalidescape}             {helperrorString(1);  countColumns(); BEGIN INVALIDSTRLIT; }
<STRLIT1>{strlit}			         {strcat(final,yytext); countColumns();}
<STRLIT1>.                           {countColumns();}


<INVALIDSTRLIT>{marks}              {clearString();countColumns(); checkmarks= 0; BEGIN 0; /*   String aceite */}
<INVALIDSTRLIT>"\\"{newline}        {helperrorString(1); if(checkmarks== 1) helperrorString(0); countLines() ; clearString();  BEGIN 0 ;}
<INVALIDSTRLIT>{whitespace}         {strcat(final,yytext);countColumns();}
<INVALIDSTRLIT>{invalidescape}      {helperrorString(1); countColumns(); BEGIN INVALIDSTRLIT;}
<INVALIDSTRLIT>{newline}            {helperrorString(0); countLines() ; clearString(); checkmarks= 0; BEGIN 0 ; }
<INVALIDSTRLIT><<EOF>>              {helperrorString(0); checkmarks= 0; BEGIN 0 ; }
<INVALIDSTRLIT>{strlit}			    {countColumns();clearString();}
<INVALIDSTRLIT>.                    {countColumns();}


<<EOF>>                             {if (insertSemicolon == 1){
                                        if(hide == 0){ 
                                            printf("SEMICOLON\n");
                                                return SEMICOLON;
                                        }
                                        insertSemicolon = 0;
                                        } return 0;
                                    }
.                                   { helperrorstate(0); }



%%
void helpoutput(char * string,int state){


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
        if(hide == 0 || hide == 1) printf("Line %d, column %d: invalid octal constant (%s)\n",lines,columns,yytext);
        countColumns();
    
}

void helperrorString(int state){

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


void checknewLine(){
    if(insertSemicolon == 1 && isComment == 0){
        if(hide == 0) printf("SEMICOLON\n");
        insertSemicolon = 0;
    }

    columns = 1;

     countLines();
    
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
    //  syntatic_errors = 1;
    // if(newline !=0){
    //     int auxcolumns = 1; 
    //  printf ( "Line %d , column %d: %s: %s\n" ,newline+1,auxcolumns,s, yytext);
    // }
    // else{
     printf ( "Line %d , column %d: %s: %s\n" ,lines,columns,s, yytext);   
    // }
}


int yywrap() {
    return 1;
}


