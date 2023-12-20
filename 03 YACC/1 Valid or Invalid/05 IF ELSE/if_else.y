%{
    #include<stdio.h>
%}

%token IF ELSEIF ELSE L G LE GE EE NE INC DEC OR AND ID NUM STRING

%%
S : if elseif else { printf("valid if-elseif-else statement\n"); };
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
    printf("invalid if-elseif-else statement\n");
    return 1;
}

int main(){
    printf("Enter the if-elseif-else statement (press ctrl+D to get output)\n");
    yyparse();
    return 0;
}
