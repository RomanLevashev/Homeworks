#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "tree.h"
#include <stdbool.h>

bool test();

int main(void) {
    if (!test()) {
        puts("Tests failed");
        return 1;
    }
    else {
        puts("Tests passed");
    }
    FILE* file = fopen("input.txt", "r");
    Tree* tree = malloc(sizeof(Tree));
    tree->root = buildTree(file);
    printf("Value of expression - %d\n", evaluateFromTree(tree->root));
    freeTree(tree->root);
 
    return 0;
}