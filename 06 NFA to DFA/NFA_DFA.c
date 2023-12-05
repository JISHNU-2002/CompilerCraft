#include <stdio.h>
#include <string.h>

#define MAX_STATES 10

int n, m = 0;
char a[MAX_STATES][3], b[MAX_STATES][4];

void toDFA(char c, char d, char e) {
    int i, j = 0;
    for (i = 0; i < m; i++) {
        if (b[i][0] == c && b[i][1] == d) {
            return; 
        }
    }
    b[m][0] = c;
    b[m][1] = d;
    strcpy(&b[m][2], e);
    b[m][3] = '\0';
    printf("%s\n", b[m]);
    m++;
}

int main() {
    int i, j;
    char ch, newstate[10];
    printf("Enter the no of transitions = ");
    scanf("%d", &n);

    printf("Enter the NFA transitions\n");
    for (i = 0; i < n; i++) {
        scanf("%s%c", a[i], &ch);
    }

    printf("The Equivalent DFA transitions\n");
    i = 0;
    while (i < n) {
        j = i + 1;
        while (j < n) {
            if (a[i][1] == a[j][1]) {
                strcpy(newstate, "");
                strcat(newstate, &a[i][2]);
                strcat(newstate, &a[j][2]);
                toDFA(a[i][0], a[i][1], newstate);
                j++;
            } else {
                printf("%s\n", a[i]);
                break;
            }
        }
        i = j;
    }
    return 0;
}
