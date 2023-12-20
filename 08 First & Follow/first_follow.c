#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void remove_duplicate();
void first(char);
void follow(char);

int n,m=0;
char a[20][20],f[20];

void remove_duplicate(){
    int i,j;
    for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            if(f[i]==f[j]){
                f[j] = '0';
            }
        }
    }
}

void first(char c){
    int i,j;
    if(islower(c)){
        f[m++] = c;
        return;
    }	
    for(i=0;i<n;i++){
        if(a[i][0]==c){
            for(j=2;j<strlen(a[i]);j++){
                if(islower(a[i][j])){
                    f[m++] = a[i][j];
                    break;
                }else{ 
                    first(a[i][j]);
                    if(f[m-1]!='e'){
                        break;
                    }else{
                        if(a[i][j+1]!='\0'){
                            m--;
                            continue;
                        }
                    }
                }
            }
        }
    }
}

void follow(char c){
    int i,j,k,flag;
    if(a[0][0]==c){
        f[m++]='$';
        return;
    }
    for(i=0;i<n;i++){
        for(j=2;j<strlen(a[i]);j++){
            if(a[i][j]==c){	
                if(a[i][j+1]!='\0'){	
                    do{
                        int temp = m;
                        first(a[i][j+1]);
                        flag=0;
                        for(k=temp;k<m;k++){
                            if(f[k] == 'e'){
                                flag=1;
                                j++;
                            }    	 			
                        }
                    }while(flag==1 && a[i][j+1]!='\0');
                }
                if(a[i][j+1]=='\0' && c!=a[i][0]){
                    follow(a[i][0]);
                }
            }
        }
    }
}

int main(){
    int i,j,z;
    char ch,c;

    printf("Enter number of productions : ");
    scanf("%d",&n);
    printf("Enter productions\n");
    for(i=0;i<n;i++){
        scanf("%s%c",a[i],&ch);
    }

    do{
        printf("Enter the element whose first & follow to be found : ");
        scanf(" %c",&c);     
        first(c);
        remove_duplicate();
        printf("\nFirst of %c is = ",c);
        for(i=0;i<m;i++){
            if (f[i]!='0'){
                printf(" %c",f[i]);
            }
        }
        strcpy(f,"");
        m=0;
        
        follow(c);
        remove_duplicate();
        printf("\nFollow of %c is = ",c);
        for(i=0;i<m;i++){
            if(f[i]!='0' && f[i]!='e'){
                printf(" %c",f[i]);
            }
        }
        strcpy(f,"");
        m=0; 

        printf("\nrepeat 1/0 : ");
        scanf("%d",&z);
    }while(z==1);
    
    return 0;
}






