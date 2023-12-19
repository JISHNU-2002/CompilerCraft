%{
    #include<stdio.h>
%}

%token DO WHILE L G LE GE EE NE INC DEC OR AND ID NUM STRING

%%
S : do while { printf("valid do-while loop\n"); };
do : DO '{' stmt '}' ;
while : WHILE '(' cond ')' ';' ;

cond : scond | scond AND cond | scond OR cond ;
scond : nid | nid relop scond | ;
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
    printf("invalid do-while loop\n");
    return 1;
}

int main(){
    printf("Enter the do-while loop (press ctrl+D to get output)\n");
    yyparse();
    return 0;
}