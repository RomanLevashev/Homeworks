#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

Queue* createQueue(int size) {
    Queue* queue = malloc(sizeof(Queue));
    queue->data = calloc(size, sizeof(int));
    queue->size = size;
    queue->count = 0;
    queue->head = 0;
    queue->tail = 0;
    queue->count = 0;
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->count == 0;
}

bool isFull(Queue* queue) {
    return queue->count == queue->size;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        puts("Queue is full");
        return;
    }
    (queue->data)[queue->tail] = value;
    queue->tail = (queue->tail + 1) % queue->size;
    queue->count++;
    }

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        puts("Queue is empty");
        return;
    }
    int value = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    queue->count--;
    return value;
}

void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}