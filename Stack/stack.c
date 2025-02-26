#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <stdbool.h>

typedef struct StackObject {                  
    char data;
    struct StackObject* next;
} StackObject;

bool push(StackObject** top, int data) {
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
    return top != NULL ? top->data : '\0';
}

int pop(StackObject** top) {
    if (*top == NULL) {
        return INT_MAX;
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