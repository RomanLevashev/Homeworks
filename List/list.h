#pragma once

typedef struct Node {
    char* word;
    int count;
    struct Node* next;
} Node;

Node* findNode(Node* node, char* word);                // Найти узел по слову и корню
void freeList(Node* root);                             // Освободить память
Node* insertOrIncreaseCounter(Node* root, char* word); // Вставляет элемент или увеличивает счетчик элемента, если он уже есть
void printList(Node* root);                            // Печатает список в формате (слово количество)