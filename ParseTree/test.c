#include <stdio.h>
#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

void createFile(const char* filename, const char* expression) {
    FILE* file = fopen(filename, "w");

    fprintf(file, "%s\n", expression);
    fclose(file);

}

bool test() {
    const char* tests[] = {
        "( + 3 5 )",  
        "( * 4 2 )",  
        "( * ( + 1 1 ) 2 )",  
        "( - 10 4 )",  
        "( * ( - 10 4 ) ( + 1 2 ) )",  
        "( / ( + 6 2 ) ( * 2 2 ) )",  
        "( - ( + 10 5 ) ( * 2 3 ) )",  
        "( / 9 3 )",  
        "( / ( + 3 4 ) ( * 2 2 ) )",  
        "( * ( - 10 4 ) ( + 1 1 ) )"   
    };
    for (int i = 0; i < 10; i++) {
        char filename[20];
        snprintf(filename, sizeof(filename), "test%d.txt", i + 1);
        createFile(filename, tests[i]);
        FILE* file = fopen(filename, "r");
        Tree* tree = malloc(sizeof(Tree));
        tree->root = buildTree(file);
        int value = evaluateFromTree(tree->root);
        switch (i + 1) {
        case 1:
            if (value != 8) {
                return false;
            }
            break;
        case 2:
            if (value != 8) {
                return false;
            }
            break;
        case 3:
            if (value != 4) {
                return false;
            }
            break;
        case 4:
            if (value != 6) {
                return false;
            }
            break;
        case 5:
            if (value != 18) {
                return false;
            }
            break;
        case 6:
            if (value != 2) {
                return false;
            }
            break;
        case 7:
            if (value != 9) {
                return false;
            }
            break;
        case 8:
            if (value != 3) {
                return false;
            }
            break;
        case 9:
            if (value != 1) {
                return false;
            }
            break;
        case 10:
            if (value != 12) {
                return false;
            }
            break;
        }
    }
    return true;
}