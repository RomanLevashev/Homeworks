#include "warrior.h"
#include <stdlib.h>

typedef struct Warrior {
    int position;
    struct Warrior* next;
} Warrior;

Warrior* createCircularList(int n) {
    Warrior* head = malloc(sizeof(Warrior));
    if (head == NULL) {
        perror("Memory allocate error");
        return NULL;
    }
    head->position = 1;
    Warrior* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = malloc(sizeof(Warrior));
        current = current->next;
        current->position = i;
    }
    current->next = head;

    return head;
}

Warrior* deleteNextWarrior(Warrior* current) {
    if (current != NULL) {
        Warrior* toDelete = current->next;
        current->next = toDelete->next;    
        if (current == toDelete) {
            free(toDelete);
            return NULL;
        }
        free(toDelete);
        return current->next;
    }
    return NULL;
}

int getPoition(Warrior* warrior) {
    return warrior->position;
}

int josephusProblem(int n, int k) {
    if (k == 1) {
        return n;
    }
    Warrior* head = createCircularList(n);
    if (head == NULL) {
        return -1;
    }
    Warrior* current = head;

    while (current->next != current) {
        for (int i = 1; i < k - 1; ++i) {
            current = current->next;
        }
        current = deleteNextWarrior(current);
    }
    int lastPosition = getPoition(current);
    free(current);
    return lastPosition;
}