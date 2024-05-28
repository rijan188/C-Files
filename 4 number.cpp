#include <stdio.h>
#include <conio.h>
#include <ctype.h>

// Function prototypes
int is_operator(char ch);
int precedence(char op);
int evaluate_postfix(char* expression);
int evaluate_prefix(char* expression);

int main() {
    int choice;
    char expression[100];

    printf("Enter 1 for postfix evaluation, 2 for prefix evaluation: ");
    scanf("%d", &choice);

    printf("Enter the expression: ");
    scanf(" %s", expression);

    switch (choice) {
        case 1:
            printf("Postfix evaluation: %d\n", evaluate_postfix(expression));
            break;
        case 2:
            printf("Prefix evaluation: %d\n", evaluate_prefix(expression));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

// Function to check if a character is an operator
int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to get precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to evaluate postfix expression
int evaluate_postfix(char* expression) {
    char stack[100];
    int top = -1, val1, val2, result;

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (isdigit(ch)) {
            stack[++top] = ch - '0'; // Convert digit to integer
        } else if (is_operator(ch)) {
            if (top < 1) {
                printf("Invalid expression\n");
                return -1;
            }
            val2 = stack[top--];
            val1 = stack[top--];

            switch (ch) {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    if (val2 == 0) {
                        printf("Division by zero\n");
                        return -1;
                    }
                    result = val1 / val2;
                    break;
            }
            stack[++top] = result;
        }
    }

    if (top != 0) {
        printf("Invalid expression\n");
        return -1;
    }

    return stack[top];
}

// Function to evaluate prefix expression (reverse of postfix logic)
int evaluate_prefix(char* expression) {
    char stack[100];
    int top = -1, val1, val2, result;

    // Reverse the expression for prefix evaluation
    int len = strlen(expression) - 1;
    for (int i = 0; i < len / 2; i++) {
        char temp = expression[i];
        expression[i] = expression[len - i - 1];
        expression[len - i - 1] = temp;
    }

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (isdigit(ch)) {
            stack[++top] = ch - '0'; // Convert digit to integer
        } else if (is_operator(ch)) {
            if (top < 1) {
                printf("Invalid expression\n");
                return -1;
            }
            val1 = stack[top--];
            val2 = stack[top--];

            switch (ch) {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    if (val2 == 0) {
                        printf("Division by zero\n");
                        return -1;
                    }
                    result = val1 / val2;
                    break;
            }
            
