#pragma once

typedef struct Queue Queue;
void enqueue(Queue* queue, char value);     // Добавляет элемент в очередь
char dequeue(Queue* queue);                 // Берет элемент из очереди
Queue* createQueue(void);                   // Инициализирует очередь
void freeQueue(Queue** queue);              // Освобождает очередь