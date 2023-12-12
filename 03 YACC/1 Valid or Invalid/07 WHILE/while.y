%{
    #include<stdio.h>
%}

%token WHILE L G LE GE EE NE INC DEC OR AND ID NUM STRING

%%
while : WHILE '(' cond ')' '{' stmt '}' { printf("valid while loop\n"); };

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
;
%%

int yyerror(){
    printf("invalid while loop\n");
    return 1;
}

int main(){
    printf("Enter the while loop (press ctrl+D to get output)\n");
    yyparse();
    return 0;
}