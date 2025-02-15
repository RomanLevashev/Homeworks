#include "doubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* previous;
    struct Node* next;
} Node;

typedef struct DoubleLinkedList {
    struct Node* head;
    struct Node* tail;
} List;

List* createList() {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        perror("Ошибка выделения памяти");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void deleteElement(int searchingValue, List* list) {
    Node** head = &(list->head);
    Node** tail = &(list->tail);
    Node* current = *head;

    while (current != NULL) {
        int currentValue = current->value;
        if (currentValue == searchingValue) {
            if (current == *head) {
                if (current->next != NULL) {
                    Node* temp = current->next;
                    free(*head);
                    *head = temp;
                    temp->previous = NULL;
                    return;
                }
                free(*head);
                *head = NULL;
                *tail = NULL;
                return;
            }
            if (current == *tail) {
                if (current->previous != NULL) {
                    Node* temp = current->previous;
                    free(*tail);
                    *tail = temp;
                    temp->next = NULL;
                    return;
                }
                free(*tail);
                *tail = NULL;
                return;
            }
            Node* previousElement = current->previous;
            Node* nextElement = current->next;
            previousElement->next = nextElement;
            nextElement->previous = previousElement;
            free(current);
            return;
        }
        current = current->next;
    }
}

void printList(List* list) {
    Node* current = list->head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void sort(List* list) {
    Node* tail = list->tail;
    Node* head = list->head;
    Node* current = tail;
    Node* previous = current->previous;

    while (previous != NULL && current->value < previous->value) {
        int temp = current->value;
        current->value = previous->value;
        previous->value = temp;
        current = previous;
        previous = current->previous;
    }
}

bool append(int value, List* list) {
    Node** tail = &list->tail;
    Node** head = &list->head;
    
    if (*head == NULL) {
        *head = malloc(sizeof(Node));
        if (*head == NULL) {
            perror("Ошибка выделения памяти");
            return false;
        }
        (*head)->value = value;
        (*head)->previous = NULL;
        (*head)->next = NULL;
        *tail = *head;
        return true;
    }
    if (*tail == *head) {
        *tail = malloc(sizeof(Node));
        if (*tail == NULL) {
            perror("Ошибка выделения памяти");
            return false;
        }
        (*tail)->value = value;
        (*head)->next = *tail;
        (*tail)->previous = *head;
        (*tail)->next = NULL;
        sort(list);
        return true;
    }
    
    Node* newElement = malloc(sizeof(Node));
    if (newElement == NULL) {
        perror("Ошибка выделения памяти");
        return;
    }
    newElement->value = value;
    newElement->previous = *tail;
    newElement->next = NULL;
    (*tail)->next = newElement;
    *tail = newElement;
    sort(list);
}

Node** getPointerToPointerToHead(List* list) {
    return list != NULL? &(list->head): NULL;
}

Node** getPointerToPointerToTail(List* list) {
    return list != NULL? &(list->tail): NULL;
}

int getValueFromNode(Node* node) {
    return node != NULL? node->value: INT_MAX;
}

void freeList(List** list) {
    Node* current = (*list)->head;

    while (current != NULL) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }
    free(*list);
    *list = NULL;
}