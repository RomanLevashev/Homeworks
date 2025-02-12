#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

bool runTestsForStack(void) {
    StackObject* top = NULL;
    push(&top, 'a');
    push(&top, 'b');
    push(&top, 'c');
    push(&top, 'd');
    if (pop(&top) != 'd') {
        freeStack(&top);
        return false;
    }
    if (pop(&top) != 'c') {
        freeStack(&top);
        return false;
    }
    if (pop(&top) != 'b') {
        freeStack(&top);
        return false;
    }
    if (pop(&top) != 'a') {
        freeStack(&top);
        return false;
    }
    if (pop(&top) != NULL) {
        freeStack(&top);
        return false;
    }
    push(&top, 'a');
    push(&top, 'b');
    push(&top, 'c');
    push(&top, 'd');
    freeStack(&top);
    if (top != NULL) {
        return false;
    }
    return true;
}
