#pragma once
#include <stdbool.h>

typedef struct Node {
    char* key;
    char* value;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

bool isDigit(char* str); // Проверяет строку на то, число ли она, нужна для функции сравнения
int lenDigit(char* str); // Вычисляет длину числа, нужна для функции сравнения
int compare(char* first, char* second, const int length); // Функция, которая сравнивает две строки, при этом, если в обоих строках числа - сравнение идет по их числовому значению
int getHeight(Node* node); // Выдаёт высоту узла или 0, если в аргументе был нулевой указатель
int updateHeight(Node** node); // Рекурсивно обновляет высоту для узла и всех его дочерних узлов, при этом проверяет баланс в каждом узле, и если возникает дизбаланс - вызывается функция баланса
void rightRotate(Node** oldRoot, Node** newRoot); // Правый поворот, нужен для балансировки
Node* insert(Node** nodePointer, char* key, char* value); // Вставка значения в АВЛ дерево по ключу
void leftRotate(Node** oldRoot, Node** newRoot); // Левый поворот, нужен для балансировки
Node* balanceTree(Node** nodePointer); // Балансирует дерево, в зависимости от вида дизбаланса применяет разные повороты
void deleteNodeWithTwoChild(Node* deletedElement); // Удаляет узел с двумя потомками, вспомогательная функция для удаления
void deleteNodeWithOneChild(Node* parentDeletedElement, Node* deletedElement); // Удаляет узел с одним потомком, вспомогательная функция для удаления
void deleteLeaf(Node* parentDeletedElement, Node* deletedElement); // Удаляет листовой узел
Node* delete(Node** nodePointer, Node** root, char* key); // Удаляет узел по ключу из АВЛ дерева
char* search(Node* source, char* key); // Ищет элемент по ключу в дереве, возвращает указатель в случае наличия и NULL в противном случае
void preOrder(Node* root); // Распечатывает список прямым обходом
void freeTree(Node** source); // Освобождает память всего дерево
