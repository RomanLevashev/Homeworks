#pragma once
#include "../List/list.h"
#include <stdlib.h>
#define TABLE_SIZE 1000

typedef struct HT {
    Node* elements[TABLE_SIZE];  
} HashTable;

int hashFunction(char* word); // Хэш-функция
void initTable(HashTable* table);                   // Делает все указатели из массива нулевыми
void addWord(HashTable* table, char* word);         // Добавляет слово в таблицу, или увеличивает счетчик
void printTable(HashTable* table);                  // Выводит таблицу в виде (слово количество в тексте)
void freeTable(HashTable** table);                  // Освобождает все ячейки таблицы
double calculateLoadFactor(HashTable* table);          // Вычисляет коэффициент заполнения
double calculateAvgListLength(HashTable* table);    // Вычисляет среднюю длину списка
int calculateMaxListLength(HashTable* table);       // Вычисляет максимальную длину списка
