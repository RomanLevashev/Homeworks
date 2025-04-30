#include "stack.h"
#include "queue.h"
#include <stdbool.h>
#include <stdlib.h>

bool runTests(void) {
    StackObject* stackTest = createStack();
    push(&stackTest, 9);
    push(&stackTest, 10);
    if (pop(&stackTest) != 10) {
        return false;
    }
    push(&stackTest, 11);
    push(&stackTest, 12);
    if (pop(&stackTest) != 12) {
        return false;
    }
    if (pop(&stackTest) != 11) {
        return false;
    }
    if (pop(&stackTest) != 9) {
        return false;
    }
    if (pop(&stackTest) != NULL) {
        return false;
    }

    Queue* queue = createQueue();
    enqueue(queue, 15);
    enqueue(queue, 20);
    enqueue(queue, 30);
    if (dequeue(queue) != 15) {
        return false;
    }
    if (dequeue(queue) != 20) {
        return false;
    }
    if (dequeue(queue) != 30) {
        return false;
    }
    if (dequeue(queue) != NULL) {
        return false;
    }
    freeQueue(&queue);
    freeStack(stackTest);
    return true;
}