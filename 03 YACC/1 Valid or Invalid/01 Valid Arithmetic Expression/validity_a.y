%{
    #include<stdio.h>
    int flag = 0;
%}

%token NUM ID
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
E:E'+'E 
|E'-'E 
|E'*'E 
|E'/'E { if($3 == 0){
            yyerror();
         }  } 
|E'%'E { if($3 == 0){
            yyerror();
         }  } 
|'('E')'
|'-'NUM
|NUM 
;
%%

int yyerror(){
    flag = 1;
    printf("invalid arithmetic expression\n");
    return 1;
}

int main(){
    printf("Enter the arithmetic expression : ");
    yyparse();
    if(flag == 0){
        printf("valid arithmetic expression\n");
    }
    return 0;
}