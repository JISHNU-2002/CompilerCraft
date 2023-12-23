#include <ctype.h>
#include <stdio.h>

char stack[50];
int top = -1;
char input[50];
char postfix[50];

void push(char elem) {
    top++;
    stack[top] = elem;
}

char pop() {
    return (stack[top--]);
}


int pr(char elem) {
    switch (elem) {
        case '#' : return 0;
        case '(' : return 1;
        case '+' : case '-' : return 2;
        case '*' : case '/' : return 3;
    }
}

void infix_to_postfix() {
    char ch, d;
    int i = 2, k = 0;
    
    push('#');

    while ((ch = input[i]) != '\0') {
        if (ch == '('){
            push(ch);
        } else if (isalnum(ch)){
            postfix[k] = ch;
            k++;
        } else if (ch == ')') {
            while (stack[top] != '('){
                postfix[k] = pop();
                k++;
            }
            d = pop();
        } else {
            while (pr(stack[top]) >= pr(ch)){
                postfix[k] = pop();
                k++;
            }
            push(ch);
        }
        i++;
    }

    while (stack[top] != '#'){
        postfix[k] = pop();
        k++;
    }
    postfix[k] = '\0';
}

void intermediate() {
    char ch,op1,op2,num = 'A';
    int i = 0;
    while((ch = postfix[i]) != '\0') {
        if(isalnum(ch)){
            push(ch);
        }else{
            op2 = pop();
            op1 = pop();
            printf("%c = %c %c %c\n",num,op1,ch,op2);
            push(num);
            num++;
        }
        i++;
    }
    printf("%c = %c\n",input[0],stack[top]);
}

void main() {
    printf("Input the expression : ");
    gets(input);
    infix_to_postfix();
    top = -1;
    printf("Intermediate code\n");
    intermediate();
}
