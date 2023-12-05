%{
    #include<stdio.h>
%}

%token A B NL

%%
T: A A A A A S B NL {printf("valid string\n");
   		 return 0;
};
S: S A | ;
%%

int yyerror(){
    printf("invalid string\n");
    return 1;
}

int main(){
    printf("enter the string\n");
    yyparse();
    return 0;
}
