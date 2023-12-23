#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,m = 0,p=0;
char a[10][10],f[10],d[10];

int check(){
    int i,flag=0;
    if(p>=3){
        for(i=0;i<p;i=i+4){
            if(d[i]==d[i+3]){
                d[i]='.';
                d[i+3]=',';
                flag=1;
            }else{
                flag=0;
            }
        }
    }
    return flag;
}

void eclosure(char c) {
    int i,j,ret;
    for(i=0;i<n;i++) {
        if(a[i][0]==c && a[i][1]=='e'){
            d[p++] = c;
            d[p++] = a[i][2];
            
            ret = check();

            if(ret == 0){
                f[m] = a[i][2];
                m++;
                eclosure(a[i][2]);
            }
        }
    }
}


int main() {
    int i,z;
    char c,ch;
    printf("Enter the no of transitions = ");
    scanf("%d", &n);

    printf("Enter the transitions\n");
    for(i=0;i<n;i++) {
        scanf("%s%c",a[i],&ch);
    }

    do{
        m = 0;
        p = 0; 
        printf("Enter the state whose e-closure to be found : ");
        scanf("%c",&c);

        printf("e-closure(%c) = { %c ",c,c);
        eclosure(c);
        for(i=0;i<m;i++) {
            printf("%c ",f[i]);
        }
        printf("}\n");
        strcpy(f," ");
        strcpy(d," ");

        printf("Continue(0/1) = ");
        scanf("%d%c", &z, &ch);
    }while(z==1);

    return 0;
}