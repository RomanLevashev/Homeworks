#include "list.h"
#include <stdbool.h>
#include <stdlib.h>

bool isEqual(Node* head, int* list, int length) {
    Node* current = head;
    for (int i = 0; i < length; i++) {
        if (list[i] != current->value) {
            return false;
        }
        current = current->next;
    }
    if (current != NULL) {
        return false;
    }
}

bool runTests(void) {
    Node* list = createList("1 2 3 4 5");
    deleteOddIndex(list);
    int wantedResult1[] = { 1, 3, 5 };
    if (!isEqual(list, wantedResult1, 3)) {
        return false;
    }
    freeList(&list);
    list = createList("1 2");
    deleteOddIndex(list);
    if (list->value != 1 || list->next != NULL) {
        return false;
    }
    freeList(&list);
    list = createList("123 456 789 101 112 131 415 161 718 192, 333");
    deleteOddIndex(list);
    int wantedResult2[] = { 123, 789, 112, 415, 718, 333 };
    if (!isEqual(list, wantedResult2, 6)) {
        return false;
    }
    freeList(&list);
    return true;
}