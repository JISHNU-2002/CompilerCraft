%{
    #include<stdio.h>
    int flag = 0;
%}

%token NUM ID 

%%
start : ID '=' E ';' ;
nid : ID | NUM ;
E : E'+'E
| E'-'E
| E'*'E
| E'/'E
| nid
| '(' nid ')'     
;
%%

int yyerror(){
    flag = 1;
    printf("Invalid expression\n");
    return 0;
}

int main(){
    printf("Enter the expression : ");
    yyparse();
    if(flag == 0){
        printf("Valid expression\n");
    }
    return 0;
}