%{
    #include <stdio.h>
    int vowel_count = 0;
    int consonant_count = 0;
%}

%%
[aeiouAEIOU] { vowel_count++; }
[a-zA-Z] { consonant_count++; }
. ;  
%%

int yywrap(){
    return 1;
}

int main(){
    printf("Enter text (Ctrl+D to end input):\n");
    yylex();

    printf("Number of vowels: %d\n", vowel_count);
    printf("Number of consonants: %d\n", consonant_count);

    return 0;
}
