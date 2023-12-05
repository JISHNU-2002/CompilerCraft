%{
    #include<stdio.h>
    #include "y.tab.h"
    extern int yylval;
%}

%%
[0-9]+ { yylval = atoi(yytext); return NUM; }
[a-zA-Z][a-zA-Z0-9]* { return ID; }
[ \t\n] {;}
. { return yytext[0]; }
%%

int yywrap(){
    return 1;
}