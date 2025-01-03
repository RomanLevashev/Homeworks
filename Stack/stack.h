#pragma once

// Отдельный элемент стэка
typedef struct StackObj StackObject;

// Добавляет новый элемент на вершину стэка
void push(StackObject** top, char data);

// Берет элемент с вершины стэка и удаляет его
char pop(StackObject** top);                

// Освобождает память, выделенную под все элементы стэка
void freeStack(StackObject* top);           
