%{
    #include<stdio.h>
%}

%token FOR L G LE GE EE NE INC DEC OR AND ID NUM STRING

%%
for : FOR '(' asn ';' cond ';' asn ')' '{' stmt '}' { printf("valid for loop\n"); };
asn : ID '=' E | ID INC | ID DEC ;

cond : scond | scond AND cond | scond OR cond ;
scond : nid | nid relop nid ;
nid : ID | NUM ;
relop : L | G | LE | GE | EE | NE ;
stmt : ID '(' STRING other ')' ';' stmt | asn ';' stmt | ;
other : ',' ID other | ',' '&' ID other | ;

E : E'+'E
| E'-'E
| E'*'E
| E'/'E
| E INC
| E DEC
| nid
| '(' nid ')'
;
%%

int yyerror(){
    printf("invalid for loop\n");
    return 1;
}

int main(){
    printf("Enter the for loop (press ctrl+D to get output)\n");
    yyparse();
    return 0;
}