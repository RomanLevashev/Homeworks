#include "warrior.h"
#include <stdlib.h>

Warrior* createÑircularList(int n) {
    Warrior* head = malloc(sizeof(Warrior));
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
        return current->next;
    }
    return NULL;
}