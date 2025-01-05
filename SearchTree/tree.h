#pragma once

// Узел дерева
typedef struct Node Node;

// Само дерево
typedef struct Tree Tree;

// Вставляет элемент в дерево
void insert(Node** source, int key, char* value); 

// Удаляет элемент по ключу
void delete(Node** source, int key); 

// Находит элемент в дереве
char* search(Node* source, int key);

// Выделяет память под дерево и возвращает указатель на нее
Tree* getTree(void);

// Возвращает указатель на корень дерева
Node** getRootPointer(Tree* tree);

// Освобождает всю память, выделенную под дерево
void freeTree(Tree** tree, Node** source);

// Возвращает ключ, данного узла, нужна для отладки
int getKey(Node* node);