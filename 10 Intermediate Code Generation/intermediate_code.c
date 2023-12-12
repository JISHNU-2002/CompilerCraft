#include<stdio.h>
#include<string.h>

int main(){
    int n,i,j=0;
    char input[100],f[5];
    printf("Enter the code : ");
    gets(input);
    n=strlen(input);
    i=n-1;

    while(i>0){
        f[2] = input[i];
        f[1] = input[i-1];
        f[0] = input[i-2];

        if(i==2 && f[1]=='='){
            printf("%c = t%d\n",input[i-2],j-1);
            break;
        }else if(i==(n-1)){        
            printf("t%d = %s\n",j,f);
        }else{
            printf("t%d = %s%d\n",j,f,j-1);
        }

        input[i] = '\0';
        input[i-1] = '\0';
        input[i-2] = 't';
        j++;
        i=i-2;
    }
    return 0;
}