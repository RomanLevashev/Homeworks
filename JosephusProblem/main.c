#include "warrior.h"
#include <stdbool.h>
#include <stdio.h>

bool runTests(void) {
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

    if (!runTests()) {
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
    if (result < 0) {
        return 2;
    }
    printf("Last warrior was with number %d\n", result);
    return 0;
}