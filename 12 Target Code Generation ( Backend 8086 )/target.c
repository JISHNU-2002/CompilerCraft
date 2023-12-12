#include<stdio.h>
#include<string.h>

int main(){
    char op[2],arg1[5],arg2[5],res[5];
    FILE *fp = fopen("input.txt","r");
    FILE *fs = fopen("output.txt","w");
    
    while(!feof(fp)){
        fscanf(fp,"%s%s%s%s",op,arg1,arg2,res);
        fprintf(fs,"MOV R0,%s\n",arg1);
        if(strcmp(op,"+")==0){
            fprintf(fs,"ADD R0,%s\n",arg2);
        }else if(strcmp(op,"-")==0){
            fprintf(fs,"SUB R0,%s\n",arg2);
        }else if(strcmp(op,"*")==0){
            fprintf(fs,"MUL R0,%s\n",arg2);
        }else if(strcmp(op,"/")==0){
            fprintf(fs,"DIV R0,%s\n",arg2);
        }
        fprintf(fs,"MOV %s,R0\n",res);
    }
    printf("output file created successfully\n");

    return 0;
}