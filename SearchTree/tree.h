#pragma once

typedef struct Node { // Узел
    int key;
    char* value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree { // Дерево
    Node* root;
} Tree;

void insert(Node** source, int key, char* value); // Вставляет элемент в дерево, строки передавать только те, которые выделены на куче
void deleteLeaf(Node* parentDeletedElement, Node* deletedElement); // Удаляет листовой элемент, вспомогательная функция для удаления
void deleteNodeWithOneChild(Node* parentDeletedElement, Node* deletedElement); // Удаялет элемент с одним потомком, вспомогательная функция для удаления
void deleteNodeWithTwoChild(Node* deletedElement); // Удаляет элемент с двумя потомками, вспомогательная функция для удаления
void delete(Node** source, int key); // Удаляет элемент по ключу
char* search(Node* source, int key); // Находит элемент в дереве