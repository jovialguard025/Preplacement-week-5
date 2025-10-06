#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int floor_div(int a, int b) {
    int q = a / b;
    if ((a ^ b) < 0 && a % b != 0) {
        q--;
    }
    return q;
}

int evaluate(char* arr[], int size) {
    int stack[size];
    int top = -1;

    for (int i = 0; i < size; i++) {
        char* token = arr[i];

        if (strcmp(token, "+") == 0 ||
            strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0 ||
            strcmp(token, "^") == 0) {

            int b = stack[top--];
            int a = stack[top--];
            int result;

            if (strcmp(token, "+") == 0) result = a + b;
            else if (strcmp(token, "-") == 0) result = a - b;
            else if (strcmp(token, "*") == 0) result = a * b;
            else if (strcmp(token, "/") == 0) result = floor_div(a, b);
            else if (strcmp(token, "^") == 0) result = (int)pow(a, b);

            stack[++top] = result;
        } else {
            stack[++top] = atoi(token);
        }
    }

    return stack[top];
}

