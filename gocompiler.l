%{
    int columns = 1;
    int lines = 1;
    int insertSemicolon = 0;
    int isComment = 0;
    void countColumns();
    void countLines();
    void checknewLine();
    void helpoutput(char * string,int state);
    void helperrorstate(int state);
    void helperrorString(int state);
%}
letra               [a-zA-Z"_"] 
decimal             [0-9]+
octal               [0-7]+
hex                 [0-9A-Fa-f]+

octalstring         0{octal}
hexstring           0[xX]{hex}

escape              \\n|\\f|\\r|\\\\|\\\"|\\t
invalidescape		\\[^trnf\"\\]

sinal               [+-]
exp                 [eE]{sinal}?{decimal}

ids                 {letra}({letra}|{decimal})*
intlit              {decimal}|{octalstring}|{hexstring}
reallit             {decimal}"."{decimal}?{exp}?|{decimal}{exp}|"."{decimal}{exp}?
strlit              ([^\n\r\\\"]|{escape})*

quotationmarks      "\""
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

%X STARTCOMMENT NEWLINE QUOTATIONMARKS
%%
{semicolon}                         {helpoutput("SEMICOLON\n",0);}
{comma}                             {helpoutput("COMMA\n",2); }
{blankid}                           {helpoutput("BLANKID\n",2); }
{assign}                            {helpoutput("ASSIGN\n",2); }
{star}                              {helpoutput("STAR\n",2); }
{div}                               {helpoutput("DIV\n",2); }
{minus}                             {helpoutput("MINUS\n",2); }
{plus}                              {helpoutput("PLUS\n",2); }
{eq}                                {helpoutput("EQ\n",2); }
{ge}                                {helpoutput("GE\n",2); }
{gt}                                {helpoutput("GT\n",2);} 
{lbrace}                            {helpoutput("LBRACE\n",2); }
{le}                                {helpoutput("LE\n",2); }
{lpar}                              {helpoutput("LPAR\n",2);}
{lsq}                               {helpoutput("LSQ\n",2); }
{lt}                                {helpoutput("LT\n",2); }
{mod}                               {helpoutput("MOD\n",2); }
{ne}                                {helpoutput("NE\n",2); }
{not}                               {helpoutput("NOT\n",2); } 
{and}                               {helpoutput("AND\n",2); }
{or}                                {helpoutput("OR\n",2); }
{rbrace}                            {helpoutput("RBRACE\n",1);}
{rpar}                              {helpoutput("RPAR\n",1);}
{rsq}                               {helpoutput("RSQ\n",1);}
{package}                           {helpoutput("PACKAGE\n",2);}
{return}                            {helpoutput("RETURN\n",2);}
{else}                              {helpoutput("ELSE\n",2);}
{for}                               {helpoutput("FOR\n",2);}
{if}                                {helpoutput("IF\n",2);}
{var}                               {helpoutput("VAR\n",2);}
{int}                               {helpoutput("INT\n",2);}
{float32}                           {helpoutput("FLOAT32\n",2);}
{bool}                              {helpoutput("BOOL\n",2);}
{string}                            {helpoutput("STRING\n",2);}
{fmtPrintln}                        {helpoutput("PRINT\n",2);}
{strconvAtoi}                       {helpoutput("PARSEINT\n",2);}
{func}                              {helpoutput("FUNC\n",2);}
{osArgs}                            {helpoutput("CMDARGS\n",2);}
{quotationmarks}                    { BEGIN QUOTATIONMARKS ; }
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



<QUOTATIONMARKS>{quotationmarks}    { BEGIN 0; /*   String aceite */}
<QUOTATIONMARKS>{newline}           { helperrorString(0); BEGIN 0 ; }
<QUOTATIONMARKS><<EOF>>             { helperrorString(0); BEGIN 0 ; }
<QUOTATIONMARKS>{invalidescape}     { helperrorString(1); BEGIN 0 ; }
<QUOTATIONMARKS>{strlit}            { BEGIN 0; }


.                                   {helperrorstate(0);}


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

void helperrorIntegerLiterals(int state){
    if(state == 0){
        printf("Line %d, column %d: illegal octal constant (%s)\n",lines,columns,yytext);
        countColumns();
    }
    else if( state == 1){
        printf("Line %d, column %d: illegal hexa constant (%s)\n",lines,columns,yytext);

    }
}

void helperrorString(int state){

    if(state == 0){
        printf("Line %d, column %d: unterminated string literal (%s)\n",lines,columns,yytext);
    }

    else if(state == 1){
        printf("Line %d, column %d: invalid escape sequence (%s)\n",lines,columns,yytext);

    }

}


void checknewLine(){
    
    countLines();

    if(insertSemicolon == 1 && isComment != 0){
        printf("SEMICOLON\n");
    }

    isComment = 0;
    columns = 1;

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