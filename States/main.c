#include <stdio.h>
#include "graph.h"
#include <stdbool.h>
#include "test.h"

int main(void) {
    if (!runTests()) {
        puts("Test failed");
        return 1;
    }
    
    puts("Tests passed");
    FILE* file = fopen("input.txt", "r");

    createStates(file, false);
    fclose(file);
    return 0;
}