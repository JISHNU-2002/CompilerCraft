%{
    #include<stdio.h>
%}

%token IF ELSE L G LE GE EE NE INC DEC OR AND ID NUM STRING ELSEIF

%%
S : ladder { printf("valid if else ladder statement\n"); };
ladder : if elseif else ;
if : IF '(' cond ')' '{' stmt '}' ;
elseif : ELSEIF '(' cond ')' '{' stmt '}' elseif | ;
else : ELSE '{' stmt '}' | ;

cond : scond | scond AND cond | scond OR cond ;
scond : nid | nid relop nid ;
nid : ID | NUM ;
relop : L | G | LE | GE | EE | NE ;
stmt : ID '(' STRING other ')' ';' stmt | E ';' stmt | ;
other : ',' ID other | ',' '&' ID other | ;

E : ID'='E
| E'+'E
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
    printf("invalid if else statement\n");
    return 1;
}

int main(){
    printf("Enter the if else statement (press ctrl+D to get output)\n");
    yyparse();
    return 0;
}
