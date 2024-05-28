#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

int isOperand(char symbol) {
    return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z');
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j;
    char item, x;

    push('(');
    strcat(infix, ")");

    i = 0;
    j = 0;
    item = infix[i++];

    while (item != '\0') {
        if (isalnum(item)) {
            postfix[j++] = item;
        } else if (item == '(') {
            push(item);
        } else if (isOperand(item) == 0) {
            while (precedence(stack[top]) >= precedence(item)) {
                x = pop();
                postfix[j++] = x;
            }
            push(item);
        } else if (item == ')') {
            while (stack[top] != '(') {
                x = pop();
                postfix[j++] = x;
            }
            x = pop();  // Remove '(' from the stack
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
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s", postfix);

    return 0;
}
