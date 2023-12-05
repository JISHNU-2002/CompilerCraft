%{
    #include<stdio.h>
%}

%token SWITCH CASE BREAK DEFAULT L G LE GE EE NE INC DEC OR AND ID NUM STRING

%%
switch : SWITCH '(' nid ')' '{' casedefault '}' { printf("valid switch case\n"); return 0; } ;
casedefault : case | case default ;
case : CASE nid ':' stmt BREAK ';' case | ;
default : DEFAULT ':' stmt BREAK ';' ;

nid : ID | NUM ;
stmt : ID '(' STRING other ')' ';' stmt | E ';' stmt | ;
other : ',' ID other | ;

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
    printf("invalid switch case\n");
    return 1;
}

int main(){
    printf("Enter the switch case\n : ");
    yyparse();
    return 0;
}