#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "tree.h"
#include <stdbool.h>
#include "test.h"

int main(void) {
    if (!runTests()) {
        puts("Tests failed");
        return 1;
    }
    else {
        puts("Tests passed");
    }
    FILE* file = fopen("input.txt", "r");
    Node* root = buildTree(file);
    printf("Value of expression - %d\n", evaluateFromTree(root));
    freeTree(root);
    fclose(file);
    return 0;
}