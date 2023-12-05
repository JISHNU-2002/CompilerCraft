%{
#include <stdio.h>
FILE *output;  // Declare the file pointer globally
%}

%x COMMENT

%%
"#include" { fprintf(output, "%s\tPreprocessor Directive\n", yytext); }

void|int|main|auto|double|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|volatile|do|if|static|while { fprintf(output, "%s\tkeyword\n", yytext); }

\"[^\"\n]*\" { fprintf(output, "%s\tstring\n", yytext); }
[0-9]+ { fprintf(output, "%s\tdigit\n", yytext); }
[a-zA-Z][a-zA-Z0-9]* { fprintf(output, "%s\tidentifier\n", yytext); }
[][{}();,] { fprintf(output, "%c\tspecial symbol\n", yytext[0]); }
[ \t\n]

"//" { BEGIN(COMMENT); }
<COMMENT>[^\n]*
<COMMENT>\n { BEGIN(INITIAL); }

. { fprintf(output, "%c\toperator\n", yytext[0]); }
%%

int yywrap(){
    return 1;
}

int main() {
    FILE *input = fopen("input.c", "r");
    output = fopen("output.txt", "w");  // Initialize the file pointer
    if (!input || !output) {
        printf("Could not open the file\n");
        return 1;
    }

    fprintf(output, "token\tlexeme\n--------------\n");
    yyin = input;
    yylex();
	printf("output file created successfuly\n");
    fclose(input);
    fclose(output);
    return 0;
}
