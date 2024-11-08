#pragma once

typedef struct Node {
    int value;
    struct Node* previous;
    struct Node* next;
} Node;

typedef struct doubleLinkedList {
    struct Node* head;
    struct Node* tail;
} List;

List* createList();
void append(int value, List* list);
void printList(List* list);
void sort(List* list);
void deleteElement(int searchingValue, List* list);