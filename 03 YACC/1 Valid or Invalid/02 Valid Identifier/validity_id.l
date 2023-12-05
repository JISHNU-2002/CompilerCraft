%{
    #include "y.tab.h"
%}

%%
[0-9]+ { return digit; }
[a-zA-Z]+ { return letter; }
[ \t\n] {;}
. { return yytext[0]; }
%%

int yywrap(){
    return 1;
}