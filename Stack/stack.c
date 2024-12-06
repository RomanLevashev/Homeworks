#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(StackObject** top, char data) {
    StackObject* pointer = malloc(sizeof(StackObject));
    if (pointer == NULL) {
        return;
    }
    pointer->data = data;
    pointer->next = *top;
    *top = pointer;
}

char pop(StackObject** top) {
    if (*top == NULL) {
        return *top;
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