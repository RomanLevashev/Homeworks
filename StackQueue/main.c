#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool runTests();

int main(void) {
    if (!runTests()) {
        puts("Tests failed");
    }
    puts("Tests passed");
    return 0;
}