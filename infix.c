#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include<ctype.h>

typedef struct {
    /* Declare your stack here */
    char arr[40];
} Stack;

Stack s;
int top = -1;

void push(char ch) {
    s.arr[++top] = ch;
}

char pop() {
    char temp;
    temp = s.arr[top--];
    return temp;
}

int is_operator(char ch) {
    if(ch == '+'||ch == '-'||ch == '*'||ch == '/')
        return 1;
    else
        return 0;
}

int precedence(char ch) {
    if(ch == '/' ||ch == '*')
        return 2;
    else if(ch == '+'||ch == '-')
        return 1;
    else
        return 0;
}

void infoxToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char x,item;
    push('(');
    strcat(infix, ")");
    item = infix[i];

    while (item != '\0') {
        if(item == '(') {
            push(item);
        }
        else if(isdigit(item)||isalpha(item)) {
            postfix[j++] = item;
        }
        else if(is_operator(item)) {
            x = pop();
            while(is_operator(x) && precedence(x) >= precedence(item)) {
                postfix[j++] = x;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if(item == ')') {
            x = pop();
            while (x != '(') {
                postfix[j++] = x;
                x = pop();
            }
        }
        i++;
        item = infix[i];
    }
    postfix[j] = '\0';
    printf("%s",postfix);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char infix[100], postfix[100];
    int size;
    scanf("%d",&size);
    scanf("%s",infix);
    infoxToPostfix(infix, postfix);
    return 0;
}
