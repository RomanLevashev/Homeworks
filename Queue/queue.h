#pragma once
#include <stdbool.h>

typedef struct Queue {
    int* data; // Сам массив
    int size; // Максимальный размер очереди
    int head; // Индекс головы
    int tail; // Индекс хвоста
    int count; // Текущее количество элементов в очереди
} Queue;

Queue* createQueue(int size); // Создаёт очередь
void enqueue(Queue* queue, int value); // Добавляет элемент в хвост и увеличивает индекс хвоста на единицу
void freeQueue(Queue* queue);
int dequeue(Queue* queue); // Берёт элемент из головы и увеличивает индекс головы на единицу
bool isEmpty(Queue* queue); // Проверяет пустая ли очередь
bool isFull(Queue* queue); // Проверяет полная ли очередь