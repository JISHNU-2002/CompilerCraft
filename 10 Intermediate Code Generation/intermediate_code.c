#include<stdio.h>
#include<string.h>

int main(){
    int n,i,j=0;
    char input[100],f[10];
    printf("Enter the code : ");
    gets(input);
    n=strlen(input);
    i=n-1;

    while(i>0){
        f[2] = input[i];
        f[1] = input[i-1];
        f[0] = input[i-2];

        if(input[i] == ')'){
            f[2] = input[i-1];
            f[1] = input[i-2];
            f[0] = input[i-3];
            printf("t%d = %s\n",j,f);
            i=i-2;
        }else if(input[i-2] == ')'){
            f[6] = input[i];
            f[5] = input[i-1];
            f[4] = input[i-2];
            f[3] = input[i-3];
            f[2] = input[i-4];
            f[1] = input[i-5];
            f[0] = input[i-6];
            printf("t%d = %c%c%c\n",j,f[1],f[2],f[3]);
            j++;
            printf("t%d = t%d%c%c%d\n",j,j-1,f[5],f[6],j-2);
            i=i-4;
        }else if(i == 2 && f[1] == '='){
            printf("%c = t%d\n",f[0],j-1);
            break;
        }else if(i == (n-1)){        
            printf("t%d = %s\n",j,f);
        }else{
            printf("t%d = %c%c%c%d\n",j,f[0],f[1],f[2],j-1);
        }
        j++;
        i=i-2;
        input[i] = 't';
    }
    return 0;
}