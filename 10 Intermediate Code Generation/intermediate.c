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
        case '#':return 0;
        case '(':return 1;
        case '+':case '-':return 2;
        case '*':case '/':return 3;
    }
}


void infix_to_postfix() {
    char ch, elem;
    int i = 2, k = 0;
    
    push('#');

    while ((ch = input[i]) != '\0') {
        if (ch == '('){
            push(ch);
        } else if (isalnum(ch)){
            postfix[k++] = ch;
        } else if (ch == ')') {
            while (stack[top] != '('){
                postfix[k++] = pop();
            }
            elem = pop();
        } else {
            while (pr(stack[top]) >= pr(ch)){
                postfix[k++] = pop();
            }
            push(ch);
        }
        i++;
    }

    while (stack[top] != '#'){
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

void intermediate() {
    char ch,num='A';
    int i = 0, op1, op2;
    while((ch = postfix[i]) != '\0') {
        if(isalnum(ch)){
            push(ch);
        }else{
            op2 = pop();
            op1 = pop();
            printf("\n%c=%c%c%c",num,op1,ch,op2);
            push(num);
            num++;
        }
        i++;
    }
    printf("\n%c=%c\n",input[0],stack[top]);
}

void main() {
    printf("Input the expression: ");
    gets(input);
    infix_to_postfix();
    top = -1;
    printf("Intermediate code\n");
    intermediate();
}
