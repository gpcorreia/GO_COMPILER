%{
    int columns = 1;
    int lines = 1;
    int insertSemicolon = 0;
    int isComment = 0;
    char result[100] = "";
    void countColumns();
    void countLines();
    void checknewLine();
    void helpoutput(char * string,int state);
    void helperrorstate(int state);
    void helperrorString(int state);
    void helperrorIntegerLiterals();
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

%X STARTCOMMENT NEWLINE STRLIT RETURN
%%
{semicolon}                         {helpoutput("SEMICOLON\n",0);}
{comma}                             {helpoutput("COMMA\n",0); }
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
\"                                  {BEGIN STRLIT ; }
{intlit}                            {printf("INTLIT(%s)\n",yytext); insertSemicolon = 1; countColumns();}
{reallit}                           {printf("REALLIT(%s)\n",yytext); insertSemicolon = 1; countColumns();}
{reserved}                          {printf("RESERVED(%s)\n",yytext); countColumns();}
{ids}                               {printf("ID(%s)\n",yytext); insertSemicolon = 1; countColumns();}
{whitespace}                        {countColumns();}
{newline}                           {checknewLine();}
{comment}.*                         {isComment = 1;}
{startcomment}                      {isComment = 1; BEGIN STARTCOMMENT ;}


<STARTCOMMENT>.                     {;}
<STARTCOMMENT>{endline}             { countLines(); }
<STARTCOMMENT><<EOF>>               { helperrorstate(1); BEGIN 0; }
<STARTCOMMENT>{endcomment}          { BEGIN 0; }

<STRLIT>{marks}             { printf("STRLIT(\"%s\")\n",result); result[0] = '\0'; BEGIN 0; /*   String aceite */}
<STRLIT>{endline}           { helperrorString(0); BEGIN 0 ; }
<STRLIT><<EOF>>             { helperrorString(0); BEGIN 0 ; }
<STRLIT>{invalidescape}     { helperrorString(1); }
<STRLIT>{strlit}			{ strcat(result,yytext); countColumns();}
<STRLIT>.                   {;}


.                           { helperrorstate(0); }


%%

void helpoutput(char * string,int state){
    


    countColumns();
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
        printf("Line %d, column %d: illegal character (%s)\n",lines,columns,yytext);
        countColumns();
    }
    else if( state == 1){
        printf("Line %d, column %d: unterminated comment\n",lines,columns);
    }


}

void helperrorIntegerLiterals(){
        printf("Line %d, column %d: illegal octal constant (%s)\n",lines,columns,yytext);
        countColumns();
    
}

void helperrorString(int state){

    if(state == 0){
        printf("Line %d, column %d: unterminated string literal\n",lines,columns);
    }

    else if(state == 1){
        printf("Line %d, column %d: invalid escape sequence (%s)\n",lines,columns,yytext);

    }

}



void checknewLine(){

    if(insertSemicolon == 1 && isComment == 0){
        printf("SEMICOLON\n");
        insertSemicolon = 0;
    }

    columns = 1;

     countLines();
    
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
    }
}

int main()
{
yylex();
return 0;
}

int yywrap()
{
return 1;
}