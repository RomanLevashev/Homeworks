#pragma once
#include <stdbool.h>

// Дерево
typedef struct Tree Tree;

// Узел дерева
typedef struct Node Node;

// Вставляет элемент в дерево, isSuccess будет true, если удачно и false в противном, изначально передавать указатель на переменную со значением true
void insert(Node** source, char key[], char value[], bool* isSuccess);

// Создает дерево
Tree* createTree(void);

// Удаляет узел в дереве, isSuccess будет true, если удачно и false в противном случае, изначально передавать указатель на переменную со значением true
void delete(Node** source, char key[], bool* isSuccess);

// Удаляет все элементы дерева
void deleteTree(Node** source);

// Находит значение по ключу и возвращает, если не было найдено, то возвращает NULL
char* search(Node* source, char* key);

// Возвращает указатель на корень дерева
Node** getRootPointer(Tree* tree);

// Возвращает левого потомка, нужна для отладки
Node* getLeft(Node* node);

// Возвращает правого потомка, нужна для отладки
Node* getRight(Node* node);

// Возвращает баланс-фактор вершины, нужна для отладки
int getBalanceFactor(Node* node);

// Возвращает ключ вершины, нужна для отладки
char* getKey(Node* node);