#include<stdio.h>
#include<string.h>
#include<ctype.h>

void first(char);
void follow(char);

int n,m=0,i,j,k,flag;
char a[10][10],f[10];

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

void first(char c){
    if(islower(c)){
        f[m++]=c;
        return;
    }
    for(i=0;i<n;i++){
        if(a[i][0]==c){
            for(j=2;j<strlen(a[i]);j++){
                if(islower(a[i][j])){
                    f[m++]=a[i][j];
                    break;
                }else{ 
                    first(a[i][j]);
                    if(f[m-1] != 'e'){
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
    if(a[0][0]==c){
        f[m++]='$';
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
    int z;
    char c,ch;
    printf("Enter the no of productions = ");
    scanf("%d",&n);
    printf("Enter the productions\n");
    for(i=0;i<n;i++){
        scanf("%s%c",a[i],&ch);
    }

    do{
        m=0;
        printf("Enter the elemet whose first & follow is to be found : ");
        scanf("%c",&c);
        first(c);
        rem_duplicate();
        printf("First(%c) = { ",c);
        for(i=0;i<m;i++){
            printf("%c ",f[i]);
        }printf("}\n");

        strcpy(f," ");
        m=0;
        follow(c);
        rem_duplicate();
        printf("Follow(%c) = { ",c);
        for(i=0;i<m;i++){
            if(f[i] != 'e'){
                printf("%c ",f[i]);
            }
        }printf("}\n");

        printf("Continue(0/1) = ");
        scanf("%d%c",&z,&ch);
    }while(z==1);
    
    return 0;
}
