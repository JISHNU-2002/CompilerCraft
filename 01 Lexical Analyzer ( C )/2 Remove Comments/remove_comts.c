#include<stdio.h>
#include<stdlib.h>

void check(char);
void single_comment();
void multi_comment();

FILE *fp, *fs;

void check(char c){
    char d;
    if(c == '/'){
        if((d = fgetc(fp)) == '*'){
            multi_comment();
        }else if(d == '/'){
            single_comment();
        }else{
            fputc(c, fs);
            fputc(d, fs);
        }
    }else{
        fputc(c, fs);
    }
}

void single_comment(){
    char d;
    while((d = fgetc(fp)) != EOF){
        if(d == '\n') {
            fputc(d, fs);
            return;
        }
    }
}

void multi_comment(){
    char d, e;
    while((d = fgetc(fp)) != EOF){
        if(d == '*'){
            if((e = fgetc(fp)) == '/'){
                return;
            }
        }
    }
}

int main(){
    fp = fopen("input.c", "r");
    fs = fopen("output.c", "w");

    if(fp == NULL || fs == NULL){
        perror("Error opening files");
        return 1;
    }

    char c;
    while((c = fgetc(fp)) != EOF){
        check(c);
    }

    printf("Output file without comments ,generated successfully\n");

    fclose(fp);
    fclose(fs);

    return 0;
}
