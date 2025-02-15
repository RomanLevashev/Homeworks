#pragma once

#include <stdbool.h>

// Узел списка, нужен для отладки
typedef struct Node Node;

// Список
typedef struct doubleLinkedList List;

// Возвращает указатель на указатель на голову, нужен для отладки
Node** getPointerToPointerToHead(List* list);

// Возвращает указатель на указатель на хвост, нужен для отладки
Node** getPointerToPointerToTail(List* list);

// Возвращает значение, хранящееся в узле, нужен для отладки
int getValueFromNode(Node* node);

// Сощдаёт список и возвращает указатель на него
List* createList(void);

// Добавляет элемент в список
bool append(int value, List* list);

// Распечатывает список
void printList(List* list);

// Удаляет элемент из списка
void deleteElement(int searchingValue, List* list);

// Освобождает память, выделенную под список
void freeList(List** list);