%{
    #include<stdio.h>
    int flag = 0;
%}

%token digit letter

%%
S : letter A;
A : letter A | digit A | ;
%%

int yyerror(){
    flag = 1;
    printf("invalid identifier\n");
    return 1;
}

int main(){
    printf("Enter the identifier : ");
    yyparse();
    if(flag == 0){
        printf("valid identifier\n");
    }
    return 0;
}