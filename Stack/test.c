#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

bool testing(void) {
    stackObject* top = NULL;
    add(&top, 'a');
    add(&top, 'b');
    add(&top, 'c');
    add(&top, 'd');
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
    return true;
}

int main(void) {
    if (testing()) {
        return 0;
    }

    else {
        return 1;
    }
}
