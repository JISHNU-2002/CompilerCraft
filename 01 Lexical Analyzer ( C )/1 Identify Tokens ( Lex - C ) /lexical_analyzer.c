#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    FILE *input = fopen("input.c", "r");
    FILE *output = fopen("output.txt", "w");
    char ch, str[20];
    int i, flag = 0;
    char keyword[32][32] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    fprintf(output, "token\tlexeme\n--------------\n");

    while((ch = fgetc(input)) != EOF){
        if(ch == '#'){
            i = 0;
            str[i] = ch;
            ch = fgetc(input);

            while(ch != '>'){
                i++;
                str[i] = ch;
                ch = fgetc(input);
            }
            str[i+1] = '>';
            fprintf(output, "%s\theader file\n", str);
            str[i+2] = '\0';
        }else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            fprintf(output, "%c\toperator\n", ch);
        }else if (ch == '%' || ch == ':' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == ';' || ch == ',' || ch == '?' || ch == '@' || ch == '"'){
            fprintf(output, "%c\tspecial symbol\n", ch);

            if(ch == '"'){
                i = 0;
                ch = fgetc(input);

                while(ch != '"'){
                    str[i] = ch;
                    i++;
                    ch = fgetc(input);
                }
                str[i] = '\0';
                fprintf(output, "%s\tstring\n", str);
            }
        }else if(isdigit(ch)){
            fprintf(output, "%c\tdigit\n", ch);
        }else if(isalpha(ch)){
            i = 0;
            str[i] = ch;
            ch = fgetc(input);

            while(isalnum(ch) && i < 19){
                i++;
                str[i] = ch;
                ch = fgetc(input);
            }
            str[i + 1] = '\0';
            flag = 0;

            for(i = 0; i < 32; i++){
                if(strcmp(str, keyword[i]) == 0){
                    flag = 1;
                    break;
                }
            }

            if(flag == 1){
                fprintf(output, "%s\tkeyword\n", str);
            }else{
                fprintf(output, "%s\tidentifier\n", str);
            }
        }
    }

	printf("output file created successfully\n");
    fclose(input);
    fclose(output);

    return 0;
}
