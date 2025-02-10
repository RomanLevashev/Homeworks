#pragma once
#include <stdio.h>

// Возвращает наиболее часто встречающийся элемент
int mostCommonElement(int* array, int length);

// Считывает массив из файла и возвращает его
int* getArrayFromFile(FILE* file, int maxCount, int* realCount);

