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

void freeStack(StackObject** root) {
    StackObject* current = *root;
    while (current != NULL) {
        StackObject* temp = current;
        current = current->next;;
        free(temp);
    }
    *root = NULL;
}