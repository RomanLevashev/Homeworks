#include <stdbool.h>
#include "doubleLinkedList.h"
#include <stdlib.h>
#include "test.h"

bool runTests(void) {
    List* list = createList();
    Node** head = getPointerToPointerToHead(list);
    Node** tail = getPointerToPointerToTail(list);
    append(9, list);
    if (getValueFromNode(*head) != 9 || getValueFromNode(*tail) != 9) {
        return false;
    }
    deleteElement(9, list);
    if (*head != NULL || *tail != NULL) {
        return false;
    }
    append(10, list);
    append(11, list);
    if (getValueFromNode(*tail) != 11 || getValueFromNode(*head) != 10) {
        return false;
    }
    
    append(14, list);

    if (getValueFromNode(*tail) != 14) {
        return false;
    }

    append(1, list);

    if (getValueFromNode(*head) != 1) {
        return false;
    }
    freeList(&list);
    return true;
}