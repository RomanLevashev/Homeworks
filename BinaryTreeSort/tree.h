#pragma once

typedef struct Node {
    int value; // Значение
    int count; // Сколько раз встречается данный элемент в массиве
    struct Node* left; // Левый потомок
    struct Node* right; // Правый потомок
} Node;

Node* createNode(int value); // Создаёт узел с заданным значением
Node* insertNode(Node* source, int value); // Вставляет узел с заданным значением в дерево
void inOrderTraversal(Node* source, int* array, int* index); // Симметрично обходит дерево и перезаписывает массив в порядке возрастания
void freeTree(Node* source);  // Освобождает память, выделенную под все узлы дерева
void treeSort(int* array, const int length); // Сортирует переданный массив, указанной длины

