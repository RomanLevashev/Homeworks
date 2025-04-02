#pragma once
#include <stdio.h>

// Узел дерева
typedef struct Node Node;

// Строит дерево и возвращает указатель на его корень
 Node* buildTree(FILE* file);

 // Вычисляет выражение с помощью дерева
 int evaluateFromTree(Node* node);

 // Освобождает память, выделенную на дерево
 void freeTree(Node* node);

