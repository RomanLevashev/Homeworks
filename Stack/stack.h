#pragma once
#include <stdbool.h>

// Отдельный элемент стэка
typedef struct StackObj StackObject;

// Добавляет новый элемент на вершину стэка, возвращает true, если успешно, а false в противном случае
bool push(StackObject** top, char data);

// Берет элемент с вершины стэка и удаляет его
char pop(StackObject** top);                

// Освобождает память, выделенную под все элементы стэка
void freeStack(StackObject* top);           

// Возвращает значение, лежащее в вершине стэка
char getStackTopValue(StackObject* top);