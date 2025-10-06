#include <stdlib.h>

typedef struct {
    int* arr;
    int capacity;
    int topIndex;
} myStack;

myStack* createStack(int n) {
    myStack* stack = (myStack*)malloc(sizeof(myStack));
    stack->arr = (int*)malloc(n * sizeof(int));
    stack->capacity = n;
    stack->topIndex = -1;
    return stack;
}

int isEmpty(myStack* stack) {
    return stack->topIndex == -1;
}

int isFull(myStack* stack) {
    return stack->topIndex == stack->capacity - 1;
}

void push(myStack* stack, int x) {
    if (!isFull(stack)) {
        stack->topIndex++;
        stack->arr[stack->topIndex] = x;
    }
}

void pop(myStack* stack) {
    if (!isEmpty(stack)) {
        stack->topIndex--;
    }
}

int peek(myStack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->topIndex];
    }
    return -1;
}
