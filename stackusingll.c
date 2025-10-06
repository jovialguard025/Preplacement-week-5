#include <stdlib.h>
#include <stdbool.h>

// Stack structure
typedef struct {
    Node* top;
    int currSize;
} myStack;

// Initialize stack
void initStack(myStack* s) {
    s->top = NULL;
    s->currSize = 0;
}

bool isEmpty(myStack* s) {
    return s->top == NULL;
}

void push(myStack* s, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
    s->currSize++;
}

void pop(myStack* s) {
    if (!isEmpty(s)) {
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
        s->currSize--;
    }
}

int peek(myStack* s) {
    if (!isEmpty(s)) {
        return s->top->data;
    }
    return -1;
}

int size(myStack* s) {
    return s->currSize;
}
