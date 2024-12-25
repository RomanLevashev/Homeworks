#pragma once
#include <stdio.h>
#include <stdbool.h>

typedef struct Road {
    int start;
    int end;
    int length;
} Road;

typedef struct State {
    int number;
    int* cities;
    int citiesCount;
} State;

// Создаёт матрицу смежности по заданным дорогам
int** createAdjMatrix(int n, int m, Road* roads);
// Создаёт массив дорог по данным из файла
Road* createRoads(FILE* file, int count);
// Создает массив государств по данным из файла
Road* createStates(FILE* file, int countStates, int maxCountOfCities, bool* employmentOfCities);
// Устанавливает значение для каждого элемента массива на переданное
void setValueTo(int* array, int length, int value);
// Добавляет к государству ближайший город, если добавил - возвращает true, в ином случае false
bool addCityToState(State* state, int** adjMatrix, bool* employmentOfCities, int citiesCount);