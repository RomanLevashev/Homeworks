#pragma once
#include <stdio.h>

// Отдельный узел списка
typedef struct Node Node;

// Список
typedef struct List List;

// Создаёт список и возвращает указатель на него
List* createList(void);

// Читает данные с файла в список
void readFileToList(FILE* file, List* list);

// Распечатывает список
void printList(List* list);

// Сортирует список по имени или телефону в зависимости от kind
void mergeSort(Node** source, int kind);

// Функция сравнения, нужна для отладки
int compare(char* first, char* second, const int length, int kind);

// Освобождает память, выделянную под список
void deleteList(List** list);

// Возвращает указатель на указатель на голову списка, нужна для отладки
Node** getHeadPointer(List* list);

// Возвращает имя узла, нужна для отладки
char* getName(Node* node);

// Возвращает телефон узла, нужна для отладки
char* getPhone(Node* node);

// Возвращает указатель на следующий элемент узла, нужна для отладки
Node* getNext(Node* node);
