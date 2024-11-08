#include <stdbool.h>
#include "doubleLinkedList.h"
#include <stdlib.h>

bool testing(void) {
    List* list = createList();
    Node** head = &(list->head);
    Node** tail = &(list->tail);
    append(9, list);
    if ((*head)->value != 9 || (*tail)->value != 9) {
        return false;
    }
    deleteElement(9, list);
    if (*head != NULL || *tail != NULL) {
        return false;
    }
    append(10, list);
    append(11, list);
    if ((*tail)->value != 11 || (*tail)->previous != *head) {
        return false;
    }
    append(12, list);
    if ((*tail)->value != 12 || (((*tail)->previous)->value) != 11) {
        return false;
    }
    deleteElement(10, list);
    deleteElement(11, list);
    deleteElement(12, list);
    append(24, list);
    append(19, list);
    append(20, list);
    append(14, list);
    if ((*head)->value != 14 || (*tail)->value != 24 || ((*head)->next)->value != 19 || ((*tail)->previous)->value != 20) {
        return false;
    }
    return true;
}