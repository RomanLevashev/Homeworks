#pragma once
#include <stdbool.h>

// Отдельный узел
typedef struct Node Node;

// Функция, которая сравнивает две строки, при этом, если в обоих строках числа - сравнение идет по их числовому значению, нужна для отладки
int compare(char* first, char* second, const int length); 

// Вставка значения в АВЛ дерево по ключу
Node* insert(Node** nodePointer, char* key, char* value); 

// Удаляет узел по ключу из АВЛ дерева
Node* delete(Node** nodePointer, Node** root, char* key); 

// Ищет элемент по ключу в дереве, возвращает указатель в случае наличия и NULL в противном случае
char* search(Node* source, char* key);

// Освобождает память всего дерева
void freeTree(Node** source);

// Распечатывает список прямым обходом, нужна для отладки
void preOrder(Node* root);

// Получить ключ из узла, нужна для отладки
char* getKey(Node* node);

// Получить левого потомка из узла, нужна для отладки   
Node* getLeft(Node* node);

// Получить правого потомка из узла, нужна для отладки
Node* getRight(Node* node);
