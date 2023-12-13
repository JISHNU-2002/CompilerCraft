%{
    #include<stdio.h>
    #include "y.tab.h"
%}

%%
"switch" { return SWITCH; }
"case" { return CASE; }
"break" { return BREAK; }
"default" { return DEFAULT; }

[ \t\n]
[0-9]+ { return NUM; }
[a-zA-Z][a-zA-Z0-9]* { return ID; }
\"[^\"]*\" { return STRING; }

"<" { return L; }
">" { return G; }
"<=" { return LE; }
">=" { return GE; }
"==" { return EE; }
"!=" { return NE; }
"++" { return INC; }
"--" { return DEC; }
"||" { return OR; }
"&&" { return AND; }
. { return yytext[0]; }
%%

int yywrap(){
    return 1;
}