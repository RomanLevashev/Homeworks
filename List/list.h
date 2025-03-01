#pragma once

#include <stdlib.h>

typedef struct Node Node;

// Найти узел по слову и корню
Node* findNode(Node* node, char* word);             

// Освободить память, выделенную под список
void freeList(Node** root);                

// Вставляет элемент или увеличивает счетчик элемента, если он уже есть
Node* insertOrIncreaseCounter(Node* root, char* word);

// Печатает список в формате (слово количество)
void printList(Node* root);

// Возвращает следующий элемент в списке, нужна для отладки
Node* getNext(Node* node);

// Возвращает количество элемента в тексте, нужна для отладки
int getCount(Node* node);

// Возвращает слово, записанное в узле
char* getNodeWord(Node* node);