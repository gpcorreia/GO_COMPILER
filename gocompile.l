%{  
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
    int hide = 0;
    int aux = 0;
    int auxS = 0;
    char final[MAX_STRING] = "";

%}
letra               [a-zA-Z_] 
decimal             [0-9]+
octal               [0-7]+
hex                 [0-9A-Fa-f]+

octalstring         0{octal}
hexstring           0[xX]{hex}
octalinvalidestring 0{decimal}*[8-9]+


escape              \\n|\\f|\\r|\\\\|\\\"|\\t
invalidescape		\\[^nfrt\\"]

sinal               [+-]
exp                 [eE]{sinal}?{decimal}

ids                 {letra}({letra}|{decimal})*
intlit              {decimal}|{octalstring}|{hexstring}
reallit             {decimal}"."{decimal}?{exp}?|{decimal}{exp}|"."{decimal}{exp}?
strlit              ([^\n\r\\"]|{escape}*)

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
newline             "\n"    
endline             "\r\n"|"\n"
reserved            break|default|interface|select|case|defer|go|map|struct|chan|goto|switch|const|fallthrough|range|type|continue|import|"++"|"--"

%X STARTCOMMENT NEWLINE STRLIT RETURN INVALIDSTRLIT
%%
{semicolon}                         {if(hide == 0) helpoutput("SEMICOLON\n",0);}
{comma}                             {if(hide == 0) helpoutput("COMMA\n",0); }
{blankid}                           {helpoutput("BLANKID\n",0); }
{assign}                            {helpoutput("ASSIGN\n",0); }
{star}                              {helpoutput("STAR\n",0); }
{div}                               {helpoutput("DIV\n",0); }
{minus}                             {helpoutput("MINUS\n",0); }
{plus}                              {helpoutput("PLUS\n",0); }
{eq}                                {helpoutput("EQ\n",0); }
{ge}                                {helpoutput("GE\n",0); }
{gt}                                {helpoutput("GT\n",0);} 
{lbrace}                            {helpoutput("LBRACE\n",0); }
{le}                                {helpoutput("LE\n",0); }
{lpar}                              {helpoutput("LPAR\n",0);}
{lsq}                               {helpoutput("LSQ\n",0); }
{lt}                                {helpoutput("LT\n",0); }
{mod}                               {helpoutput("MOD\n",0); }
{ne}                                {helpoutput("NE\n",0); }
{not}                               {helpoutput("NOT\n",0); } 
{and}                               {helpoutput("AND\n",0); }
{or}                                {helpoutput("OR\n",0); }
{rbrace}                            {helpoutput("RBRACE\n",1);}
{rpar}                              {helpoutput("RPAR\n",1);}
{rsq}                               {helpoutput("RSQ\n",1);}
{package}                           {helpoutput("PACKAGE\n",0);}
{return}                            {helpoutput("RETURN\n",1);}
{else}                              {helpoutput("ELSE\n",0);}
{for}                               {helpoutput("FOR\n",0);}
{if}                                {helpoutput("IF\n",0);}
{var}                               {helpoutput("VAR\n",0);}
{int}                               {helpoutput("INT\n",0);}
{float32}                           {helpoutput("FLOAT32\n",0);}
{bool}                              {helpoutput("BOOL\n",0);}
{string}                            {helpoutput("STRING\n",0);}
{fmtPrintln}                        {helpoutput("PRINT\n",0);}
{strconvAtoi}                       {helpoutput("PARSEINT\n",0);}
{func}                              {helpoutput("FUNC\n",0);}
{osArgs}                            {helpoutput("CMDARGS\n",0);}
{octalinvalidestring}               {helperrorIntegerLiterals();}
{marks}                             {BEGIN STRLIT ; saveMarks = columns; aux = 0; countColumns();}
{intlit}                            {if(hide == 0) {printf("INTLIT(%s)\n",yytext);} insertSemicolon = 1; countColumns();}
{reallit}                           {if(hide == 0) {printf("REALLIT(%s)\n",yytext);} insertSemicolon = 1; countColumns();}
{reserved}                          {if(hide == 0) {printf("RESERVED(%s)\n",yytext);} countColumns();}
{ids}                               {if(hide == 0) {printf("ID(%s)\n",yytext);} insertSemicolon = 1; countColumns();}
{whitespace}                        {countColumns();}
{newline}                           {checknewLine();}
{comment}.*                         {isComment = 1;}
{startcomment}                      {isComment = 1; saveComm=columns; BEGIN STARTCOMMENT ;}


<STARTCOMMENT>.                     {;}
<STARTCOMMENT>{endline}             { countLines(); }
<STARTCOMMENT><<EOF>>               { helperrorstate(1); BEGIN 0; }
<STARTCOMMENT>{endcomment}          { isComment = 0;BEGIN 0; }

<STRLIT>{endline}                   {helperrorstate(0); clearString(); countLines(); BEGIN 0; }
<STRLIT>{invalidescape}             {helperrorstate(0); clearString(); countColumns(); aux = 1 ;}
<STRLIT><<EOF>>                     {helperrorString(0); clearString(); BEGIN 0;}
<STRLIT>{strlit}                    {clearString(); strcat(final,yytext); auxS = 1; countColumns();}
<STRLIT>{marks}                     {

                                        if(auxS == 0 && aux == 0){
                                            if(hide == 0) printf("STRLIT(\"\")\n");
                                            clearString();
                                        }
                                        if(auxS == 1 && aux == 0){
                                            if(hide == 0) printf("STRLIT(\"%s\")\n",final);
                                            clearString();
                                        }
                                        if(auxS == 1 && aux == 1){
                                            clearString();
                                            aux = 0;
                                            auxS = 0;
                                            BEGIN 0;
                                        }
                                        clearString();
                                        countColumns();
                                        aux = 0;
                                        auxS = 0;
}

<<EOF>>                             {checkEOF(); return yywrap();}
.                                   { helperrorstate(0); }



%%
void helpoutput(char * string,int state){
    
    countColumns();
    

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
        if(hide == 0 || hide == 1) printf("Line %d, column %d: unterminated comment\n",lines,saveComm);
        saveComm = 0;
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

void checkEOF(){

    if (insertSemicolon == 1){
        if(hide == 0) printf("SEMICOLON\n");
        insertSemicolon = 0;
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
    if(isComment == 0){
        lines++;
        columns=1;
    }
}

int main(int argc, char *argv[])
{   

    if(argv[1] == NULL){
        hide = 1;
    }

    yylex();

    return 0;


}


int yywrap()
{
return 1;
}