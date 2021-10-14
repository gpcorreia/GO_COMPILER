%{
    int columns = 1;
    int lines = 1;
    void countColumns();
    void countLines();
%}
letra               [a-zA-Z"_"] 
decimal             [0-9]+
octal               [0-8]+
hex                 [0-9A-Fa-f]+

octalstring         0{octal}
hexstring           0[xX]{hex}

sinal               [+-]
exp                 [eE]{sinal}?{decimal}


ids                 {letra}({letra}|{decimal})*
intlit              {decimal}|{octalstring}|{hexstring}
reallit             {decimal}"."{decimal}?{exp}?|{decimal}{exp}|"."{decimal}{exp}?

starcomment         "/*"
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
mod                 "&"     
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

%X BIGCOMMENT COMMENT
%%
{semicolon}         {printf("SEMICOLON\n"); countColumns();}
{comma}             {printf("COMMA\n"); countColumns();}
{blankid}           {printf("BLANKID\n"); countColumns();}
{assign}            {printf("ASSIGN\n"); countColumns();}
{star}              {printf("STAR\n"); countColumns();}
{div}               {printf("DIV\n"); countColumns();}
{minus}             {printf("MINUS\n"); countColumns();}
{plus}              {printf("PLUS\n"); countColumns();}
{eq}                {printf("EQ\n"); countColumns();}
{ge}                {printf("GE\n"); countColumns();}
{gt}                {printf("GT\n");} countColumns();
{lbrace}            {printf("LBRACE\n"); countColumns();}
{le}                {printf("LE\n"); countColumns();}
{lpar}              {printf("LPAR\n"); countColumns();}
{lsq}               {printf("LSQ\n"); countColumns();}
{lt}                {printf("LT\n"); countColumns();}
{mod}               {printf("MOD\n"); countColumns();}
{ne}                {printf("NE\n"); countColumns();}
{not}               {printf("NOT\n"); countColumns();} 
{and}               {printf("AND\n"); countColumns();}
{or}                {printf("OR\n"); countColumns();}
{rbrace}            {printf("RBRACE\n");  countColumns();}
{rpar}              {printf("RPAR\n"); countColumns();}
{rsq}               {printf("RSQ\n"); countColumns();}
{package}           {printf("PACKAGE\n"); countColumns();}
{return}            {printf("RETURN\n"); countColumns();}
{else}              {printf("ELSE\n"); countColumns();}
{for}               {printf("FOR\n"); countColumns();}
{if}                {printf("IF\n"); countColumns();}
{var}               {printf("VAR\n"); countColumns();}
{int}               {printf("INT\n"); countColumns();}
{float32}           {printf("FLOAT32\n"); countColumns();}
{bool}              {printf("BOOL\n"); countColumns();}
{string}            {printf("STRING\n"); countColumns();}
{fmtPrintln}        {printf("PRINT\n"); countColumns();}
{strconvAtoi}       {printf("PARSEINT\n"); countColumns();}
{func}              {printf("FUNC\n"); countColumns();}
{osArgs}            {printf("CMDARGS\n"); countColumns();}
{ids}               {printf("ID(%s)\n",yytext); countColumns();}
{intlit}            {printf("INTLIT(%s)\n",yytext); countColumns();}
{reallit}           {printf("REALLIT(%s)\n",yytext); countColumns();}
{reserved}          {printf("RESERVED(%s)\n",yytext); countColumns();}
{whitespace}        {countColumns();}
{newline}           {countLines();}


.                   {printf("Line <%d>, column <%d>: illegal character (%s)\n",lines,columns,yytext);}

{comment}   {BEGIN COMMENT ;} 
<COMMENT>
<COMMENT>{newline} {BEGIN 0; }



%%
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