#pragma once

typedef struct Warrior {
    int position;
    struct Warrior* next;
} Warrior;

Warrior* createĐircularList(int);
Warrior* deleteNextWarrior(Warrior*);
