%{
    #include<stdio.h>
%}

%%
[a-zA-Z]*abc {
    for(int i=0;i<yyleng;i++){
        if(yytext[i] == 'a' && yytext[i+1] == 'b' && yytext[i+2] == 'c'){
            yytext[i] = 'A';
            yytext[i+1] = 'B';
            yytext[i+2] = 'C';
       }
    }
    printf("%s",yytext);
}
%%

int yywrap(){
    return 1;
}

int main(){
    printf("Enter Input : ");
    yylex();
    return 0;
}
