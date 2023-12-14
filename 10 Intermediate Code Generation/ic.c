#include<stdio.h>
#include<string.h>
int n,i,j=0;
char input[100],f[10],temp[5];

void parenthesis(){
    i=i-3;
    while(input[i-1] != '('){
        f[2] = input[i];
        f[1] = input[i-1];
        f[0] = input[i-2];
        if(input[i+1] == ')'){
            printf("t%d = %c%c%c\n",j,f[0],f[1],f[2]);
        }else{
            printf("t%d = %c%ct%d\n",j,f[0],f[1],j-1);
        }
        j++;
        i=i-2;
        input[i] = 't';
    }
}

int main(){
    printf("Enter the code : ");
    gets(input);
    n=strlen(input);
    i=n-1;

    while(i>0){
        f[2] = input[i];
        f[1] = input[i-1];
        f[0] = input[i-2];

        if(input[i] == ')'){
            i=i+2;
            parenthesis();
        }else if(input[i-2] == ')'){
            temp[0] = input[i-1];
            temp[1] = input[i];
            int m = j-1;
            parenthesis();
            if(m < 0){
                printf("t%d = t%d%c%c\n",j,j-1,temp[0],temp[1]);
            }else{
                printf("t%d = t%d%c%c%d\n",j,j-1,temp[0],temp[1],m);
            }
        }else if(i == 2 && f[1] == '='){
            printf("%c = t%d\n",f[0],j-1);
            break;
        }else if(i == (n-1)){        
            printf("t%d = %s\n",j,f);
        }else{
            printf("t%d = %c%c%c%d\n",j,f[0],f[1],f[2],j-1);
        }

        if(input[i-1] != '('){
            i=i-2;
            j++;
        }else{
            i--;
        }
        input[i] = 't';
    }
    return 0;
}