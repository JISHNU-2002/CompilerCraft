%{
    #include "y.tab.h"

%}

%%
[a-zA-Z][a-zA-Z0-9]* { return ID; }
[0-9]+ { return NUM; }
[ \t\n] {;}
. { return yytext[0]; }
%%

int yywrap(){
    return 1;
}