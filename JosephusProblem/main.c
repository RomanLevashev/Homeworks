#include "warrior.h"
#include <stdbool.h>
#include <stdio.h>

int josephusProblem(int n, int k) {
    if (n <= 0 || k <= 0) {
        puts("Invalid input");
        return 0;
    }
    if (k == 1) {
        return n;
    }
    Warrior* head = createÑircularList(n);
    Warrior* current = head;

    while (current->next != current) {
        for (int i = 1; i < k - 1; ++i) {
            current = current->next;
        }
        current = deleteNextWarrior(current);
    }
    int lastPosition = current->position;
    free(current);
    return lastPosition;
}

bool testing(void) {
    if (josephusProblem(5, 2) != 3) {
        return false;
    }
    if (josephusProblem(10, 3) != 4) {
        return false;
    }
    if (josephusProblem(41, 3) != 31) {
        return false;
    }
    if (josephusProblem(100, 10) != 26) {
        return false;
    }
    if (josephusProblem(10, 1) != 10) {
        return false;
    }
    if (josephusProblem(1, 1) != 1) {
        return false;
    }
    if (josephusProblem(7, 4) != 2) {
        return false;
    }
    return true;
}

int main(void) {
    int n = -1;
    int k = -1;

    if (!testing()) {
        return 1;
    }
    else {
        puts("All tests have completed");
    }
    do {
        puts("Enter a n and k through a space: ");
        scanf("%d %d", &n, &k);
    } while (n <= 0 && k <= 0);

    int result = josephusProblem(n, k);
    printf("Last warrior was with number %d\n", result);
    return 0;
}