#pragma once

typedef struct StackObj StackObject;        // Элемент стэка
void push(StackObject** top, char data);    // Добавляет новый элемент на вершину стэка
char pop(StackObject** top);                // Берет элемент с вершины стэка и удаляет его
void freeStack(StackObject* top);           // Освобождает память, выделенную под все элементы стэка
StackObject* createStack(void);              // Инициализирует стэк