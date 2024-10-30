#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stackObject* add(stackObject** top, char data) {
    stackObject* pointer = malloc(sizeof(stackObject));
    pointer->data = data;
    pointer->next = *top;
    *top = pointer;
}

char pop(stackObject** top) {
    if (*top == NULL) {
        return *top;
    }
    char data = (*top)->data;
    stackObject* nextObject = (*top)->next;
    free(*top);
    *top = nextObject;
    return data;
}
