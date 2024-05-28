#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int precedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void reverse(char *exp) {
    int len = strlen(exp);
    int i;
    char temp;
    for (i = 0; i < len / 2; i++) {
        temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix) {
    int i, j;
    char item, x;

    reverse(infix);
    strcat(infix, ")");
    push('(');

    i = 0;
    j = 0;
    item = infix[i++];

    while (item != '\0') {
        if (isalnum(item)) {
            prefix[j++] = item;
        } else if (item == ')') {
            push(item);
        } else if (isalnum(item) == 0) {
            while (precedence(stack[top]) > precedence(item)) {
                x = pop();
                prefix[j++] = x;
            }
            push(item);
        } else if (item == '(') {
            while (stack[top] != ')') {
                x = pop();
                prefix[j++] = x;
            }
            x = pop();  // Remove ')' from the stack
        } else {
            printf("Invalid infix Expression.\n");
            exit(1);
        }
        item = infix[i++];
    }
    if (top > 0) {
        printf("Invalid infix Expression.\n");
        exit(1);
    }
    reverse(prefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s", prefix);

    return 0;
}
