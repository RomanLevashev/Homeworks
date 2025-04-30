#include "stack.h"
#include <stdlib.h>

typedef struct Queue {
    StackObject* inputStack;
    StackObject* outputStack;
} Queue;

Queue* createQueue(void) {
    Queue* queue = calloc(sizeof(Queue), 1);
    return queue;
}

void enqueue(Queue* queue, char value) {
    StackObject** inputStack = &(queue->inputStack);
    push(inputStack, value);
}

char dequeue(Queue* queue) {
    StackObject** outputStack = &(queue->outputStack);

    if (*outputStack == NULL) {
        while (queue->inputStack != NULL) {
            StackObject** current = &(queue->inputStack);
            char value = pop(current);
            push(outputStack, value);
        }
    }
    return pop(outputStack);
}

void freeQueue(Queue** queue) {
    if (*queue == NULL) {
        return;
    }
    if ((*queue)->inputStack != NULL) {
        freeStack((*queue)->inputStack);
    }
    if ((*queue)->outputStack != NULL) {
        freeStack((*queue)->outputStack);

    }
    free(*queue);
    *queue = NULL;
}