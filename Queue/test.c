#include "stdbool.h"
#include "queue.h"

bool runTests(void) {
    Queue* queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    dequeue(queue);
    enqueue(queue, 50);

    int temp = 0;
    while (queue->count > 0) {
        temp = dequeue(queue);
    }

    if (temp != 50) {
        return false;
    }
    if (!isEmpty(queue)) {
        return false;
    }
    freeQueue(queue);
    queue = createQueue(3);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    if (queue->tail != 0 || queue->count != 3 || queue->data[queue->count - 1] != 3 || queue->data[queue->head] != 1) {
        return false;
    }
    return true;
}