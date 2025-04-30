#pragma once

// Отдельный узел списка
typedef struct Node {
    struct Node* next;
    int value;
} Node;
// Создаёт односвязный список и возвращает указатель на его голову по переданной строке
Node* createList(char* source);
// Удаляет элементы с нечетными индексами
void deleteOddIndex(Node* head);
// Очищает память, выделенную под список
void freeList(Node** source);