#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m = 0;
char a[10][10]; 

int main() {
    int i,j,z;
    char c, ch;
    printf("Enter the no of transitions = ");
    scanf("%d", &n);

    printf("Enter the DFA transitions\n");
    for (i = 0; i < n; i++) {
        scanf("%s%c", a[i], &ch);
    }

    printf("The Minimized DFA transitions\n");
    i=0;
    while(i<n-1){
        j=i+1;
        while(j<n){
            if(a[i][0]==a[j][0] && a[i][2]!=a[j][2]){
                printf("%s\n",a[i]);
                j++;
            }else{
                break;
            }
        }
        i=j;
    }
    return 0;
}