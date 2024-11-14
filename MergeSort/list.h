#pragma once
#include <stdio.h>


typedef struct Node {
    char name[51];
    char phone[16];
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

List* createList(void);
void append(List* list, char* name, char* phone);
void readFileToList(FILE* file, List* list);
void split(Node* source, Node** firstHalf, Node** secondHalf);
Node* merge(Node* first, Node* second, int (*compare)(const char*, const char*));
void printList(List* list);
Node* mergeSort(Node* source, int kind);
void readFileToList(FILE* file, List* list);
int compare(char* first, char* second, const int length, int kind);
void deleteList(List* list);