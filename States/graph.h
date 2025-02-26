#pragma once

#include <stdio.h>
#include <stdbool.h>

typedef struct State State;

// Создаёт государства по файлу и распечатывает их, если debug == true, то возвращает массив государств, в другом случае NULL
State* createStates(FILE* file, bool debug);

// Возвращает указатель на массив городов государства, нужна для отладки
int* getCities(State* state);

// Возвращает указатель на государство с переданным номером, если оно существует и NULL в противном случае, нужна для отладки
State* getStateWithNumber(State* states, int number);

// Освобождает память, выделенную под государства
void freeStates(State** states, int statesCount);
