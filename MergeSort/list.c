#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <string.h>

int maxNameLen = 50;
int maxPhoneLen = 15;

List* createList(void) {
    List* list = malloc(sizeof(List));
    list->head = NULL;
}

int compare(char* first, char* second, const int length, int kind) {
    for (int i = 0; i < length; ++i) {
        int firstElement = first[i];
        int secondElement = second[i];

        if (firstElement == 0) {
            if ((secondElement != 0) && kind == 2) {
                return -1;
            }
            else {
                return 0;
            }
        }
        if (secondElement == 0) {
            if ((firstElement != 0) && kind == 2) {
                return 1;
            }
            else {
                return 0;
            }
        }
 
        if (firstElement > secondElement) {
            return 1;
        }
        if (firstElement < secondElement) {
            return -1;
        }
    }
    return 0;
}

void deleteList(List* list) {
    Node* current = list->head;
    
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void split(Node* source, Node** firstHalf, Node** secondHalf) {
    Node* fast = source;
    Node* slow = source;

    if (fast->next != NULL && (fast->next)->next == NULL) {
        *firstHalf = source;
        *secondHalf = source->next;
        source->next = NULL;
        return;
    }

    while (fast != NULL && fast->next != NULL) {
        fast = (fast->next)->next;
        slow = slow->next;
    }

    *firstHalf = source;
    *secondHalf = slow->next;
    slow->next = NULL;
}

Node* merge(Node* firstHalf, Node* secondHalf, int kind) {
    Node* leftCurrent = firstHalf;
    Node* rightCurrent = secondHalf;
    Node* result = NULL;
    Node* previous = NULL;

    if (leftCurrent == NULL || rightCurrent == NULL) {
        return leftCurrent == NULL ? rightCurrent : leftCurrent;
    }

    while (leftCurrent != NULL && rightCurrent != NULL) {
        int compareResult = 0;
        if (kind == 1) {
            compareResult = compare(leftCurrent->name, rightCurrent->name, maxNameLen, kind);
        }
        if (kind == 2) {
            compareResult = compare(leftCurrent->phone, rightCurrent->phone, maxPhoneLen, kind);
        }
        if (compareResult == -1) {
            if (result != NULL) {
                previous->next = leftCurrent;
            }
            else {
                result = leftCurrent;
            }
            previous = leftCurrent;
            leftCurrent = leftCurrent->next;
        }
        else {
            if (result != NULL) {
                previous->next = rightCurrent;
            }
            else {
                result = rightCurrent;
            }
            previous = rightCurrent;
            rightCurrent = rightCurrent->next;
        }
    }
    if (leftCurrent == NULL && rightCurrent != NULL) {
        previous->next = rightCurrent;
    }
    if (leftCurrent != NULL && rightCurrent == NULL) {
        previous->next = leftCurrent;
    }
    return result;
}

void append(List* list, char* name, char* phone) {
    Node** head = &(list->head);

    if (*head == NULL) {
        *head = malloc(sizeof(Node));
        if (*head == NULL) {
            puts("Can't append element, try again.");
            return;
        }
        (*head)->next = NULL;
        strncpy((*head)->name, name, maxNameLen);
        strncpy((*head)->phone, phone, maxPhoneLen);
    }
    else {
        Node* current = malloc(sizeof(Node));
        if (current == NULL) {
            puts("Can't append element, try again.");
            return;
        }
        current->next = *head;
        *head = current;
        strncpy(current->name, name, maxNameLen);
        strncpy(current->phone, phone, maxPhoneLen);
    }
}

void printList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%s %s\n", current->name, current->phone);
        current = current->next;
    }
}

Node* mergeSort(Node* source, int kind) {
    if (source == NULL || source->next == NULL) {
        return source;
    }
    Node* firstHalf = NULL;
    Node* secondHalf = NULL;

    split(source, &firstHalf, &secondHalf);

    firstHalf = mergeSort(firstHalf, kind);
    secondHalf = mergeSort(secondHalf, kind);

    return merge(firstHalf, secondHalf, kind);
}

void readFileToList(FILE* file, List* list) {
    if (file == NULL) {
        return;
    }

    char name[50] = { 0 };
    char phone[15] = { 0 };

    while (fscanf(file, "%s %s", name, phone) == 2) {
        append(list, name, phone);
        memset(name, 0, sizeof(name));
        memset(phone, 0, sizeof(phone));
    }
}