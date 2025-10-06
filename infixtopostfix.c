#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 5000

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isRightAssociative(char op) {
    return op == '^';
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

char* infixToPostfix(char* s) {
    char* result = (char*)malloc(MAX);
    char stack[MAX];
    int top = -1, k = 0;

    for (int i = 0; s[i]; i++) {
        char ch = s[i];

        if (isalnum(ch)) {
            result[k++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                result[k++] = stack[top--];
            }
            if (top >= 0) top--; // pop '('
        } else if (isOperator(ch)) {
            while (top >= 0 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch) && !isRightAssociative(ch)))) {
                result[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top >= 0) {
        result[k++] = stack[top--];
    }

    result[k] = '\0';
    return result;
}
