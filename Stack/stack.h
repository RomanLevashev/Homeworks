#pragma once

typedef struct stackObj {
    char data;
    struct stackObj* next;
} stackObject;

stackObject* add(stackObject** top, char data);
char pop(stackObject** top);
