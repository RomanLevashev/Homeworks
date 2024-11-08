#pragma once

typedef struct Warrior {
    int position;
    struct Warrior* next;
} Warrior;

Warrior* create—ircularList(int);
Warrior* deleteNextWarrior(Warrior*);
