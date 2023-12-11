#include<stdio.h>
#include<string.h>

int main(){
    int i,j;
    char input[100],f[5];
    printf("Enter the code : ");
    gets(input);
    
    for(i=strlen(input);i>=0;(i=i-2)){
        strcpy(f[2],input[i]);
        strcpy(f[1],input[i-1]);
        strcpy(f[0],input[i-2]);

        input[i] = '\0';
        input[i-1] = '\0';
        strcat(input[i-2],j);

        printf("%s %s\n",input,f);
    }
}