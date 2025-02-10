#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <stdbool.h>

typedef struct StackObject {                  
    char data;
    struct StackObj* next;
} StackObject;

bool push(StackObject** top, char data) {
    StackObject* pointer = malloc(sizeof(StackObject));
    if (pointer == NULL) {
        perror("Memory allocate error");
        return false;
    }
    pointer->data = data;
    pointer->next = *top;
    *top = pointer;
    return true;
}

char getStackTopValue(StackObject* top) {
    return top->data;
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

void freeStack(StackObject** root) {
    StackObject* current = *root;
    while (current != NULL) {
        StackObject* temp = current;
        current = current->next;;
        free(temp);
    }
    *root = NULL;
}