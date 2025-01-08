#pragma once
#include "../List/list.h"
#include <stdlib.h>
#include <stdio.h>
#define TABLE_SIZE 1000

// Хэш-Таблица
typedef struct HT HashTable;

// Конструктор хэш-таблицы
HashTable* initTable(void);

// Выводит таблицу в виде (слово количество в тексте)
void printTable(HashTable* table);

// Освобождает все ячейки таблицы
void freeTable(HashTable** table);

// Вычисляет коэффициент заполнения
double calculateLoadFactor(HashTable* table);      

// Вычисляет среднюю длину списка
double calculateAvgListLength(HashTable* table);    

// Вычисляет максимальную длину списка
int calculateMaxListLength(HashTable* table); 

// Возвращает счетчик элемента, хранящийся в таблице, нужен для отладки
int getElementCountFromTable(HashTable* table, char* word);

// По переданному файлу заполняет хеш-таблицу ячейками
void parseFile(FILE* file, HashTable* table);