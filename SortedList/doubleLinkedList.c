#include "doubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

List* createList() {
    List* list = malloc(sizeof(List));
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

void append(int value, List* list) {

    Node** tail = &list->tail;
    Node** head = &list->head;
    
    if (*head == NULL) {
        *head = malloc(sizeof(Node));
        (*head)->value = value;
        (*head)->previous = NULL;
        (*head)->next = NULL;
        *tail = *head;
        return;
    }
    if (*tail == *head) {
        *tail = malloc(sizeof(Node));
        (*tail)->value = value;
        (*head)->next = *tail;
        (*tail)->previous = *head;
        (*tail)->next = NULL;
        sort(list);
        return;
    }
    
    Node* newElement = malloc(sizeof(Node));
    newElement->value = value;
    newElement->previous = *tail;
    newElement->next = NULL;
    (*tail)->next = newElement;
    *tail = newElement;
    sort(list);
}