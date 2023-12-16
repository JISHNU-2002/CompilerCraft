#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void first(char);
void follow(char);

int n,m=0;
char a[20][20],f[20];

void rem_duplicate(){
	int cnt=0;
	int i,j;
	char res[20];
	for(i=0;i<m;i++){
		int flag=1;
		for(j=0;j<cnt;j++){
			if(f[i]==res[j] || f[i]==' '){
			    flag=0;
			    break;
			}
		}
		if(flag==1){
			res[cnt++]=f[i];
		}
	}
	strcpy(f,"");
	m=cnt;
	for(i=0;i<cnt;i++){
		f[i]=res[i];
	}
}

int main(){
    printf("enter number of productions : ");
    scanf("%d",&n);
    printf("\nenter productions - \n");
    int i,j;
    char ch;
    for(i=0;i<n;i++){
        scanf("%s%c",a[i],&ch);
    }

    int repeat;
    do{
        printf("\nenter the element whose first is to be discovered : ");
        char element;
        scanf(" %c",&element);     
        first(element);
        rem_duplicate();
        printf("\nFirst of %c is = ",element);
        for(i=0;i<m;i++){
                printf(" %c",f[i]);
        }
        strcpy(f,"");
        m=0;
        
        follow(element);
        for(i=0;i<m;i++){
            if(f[i]=='e'){
                f[i]=' '; 
            }
        }
        rem_duplicate();
        printf("\nFollow of %c is = ",element);
        for(i=0;i<m;i++){
            printf(" %c",f[i]);
        }
        
        strcpy(f,"");
        m=0; 

        printf("\ndo you want to repeat 1/0 : ");
        scanf("%d",&repeat);
    }while(repeat==1);
    
    return 0;
}

void first(char element){
	int i,j;
	if(islower(element)){
		f[m++] = element;
		return;
	}	
	for(i=0;i<n;i++){
		if(a[i][0]==element){
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

void follow(char element){
	if(a[0][0]==element){
	    f[m++]='$';
	}
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=2;j<strlen(a[i]);j++){
			if(a[i][j]==element){	
				if(a[i][j+1]!='\0'){	
					int repeat;
					do{
						int temp = m;
						first(a[i][j+1]);
						repeat=0;
						for(k=temp;k<m;k++){
		               	 	if(f[k] == 'e'){
		               	 		repeat=1;
		               	 		j++;
		               	 	}    	 			
		               	}
                    }while(repeat==1 && a[i][j+1]!='\0');
				}
				if(a[i][j+1]=='\0' && element!=a[i][0]){
					follow(a[i][0]);
				}
			}
		}
	}
}





