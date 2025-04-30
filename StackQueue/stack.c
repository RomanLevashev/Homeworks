#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct StackObj { 
    char data;
    struct stackObj* next;
} StackObject;

void push(StackObject** top, char data) {
    StackObject* pointer = malloc(sizeof(StackObject));
    if (pointer == NULL) {
        return;
    }
    pointer->data = data;
    pointer->next = *top;
    *top = pointer;
}

StackObject* createStack(void) {
    StackObject* stack = calloc(1, sizeof(StackObject));
    return stack;
}

char pop(StackObject** top) {
    if (*top == NULL) {
        return NULL;
    }
    char data = (*top)->data;
    StackObject* nextObject = (*top)->next;
    free(*top);
    *top = nextObject;
    return data;
}

void freeStack(StackObject* top) {
    while (top != NULL) {
        StackObject* temp = top;
        top = top->next;
        free(temp);
    }
}