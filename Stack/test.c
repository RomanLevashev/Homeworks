#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

bool runTests(void) {
    StackObject* top = NULL;
    push(&top, 'a');
    push(&top, 'b');
    push(&top, 'c');
    push(&top, 'd');
    if (pop(&top) != 'd') {
        return false;
    }
    if (pop(&top) != 'c') {
        return false;
    }
    if (pop(&top) != 'b') {
        return false;
    }
    if (pop(&top) != 'a') {
        return false;
    }
    if (pop(&top) != NULL) {
        return false;
    }
    push(&top, 'a');
    push(&top, 'b');
    push(&top, 'c');
    push(&top, 'd');
    freeStack(top);
    top = NULL;
    return true;
}

int main(void) {
    runTests();
}
