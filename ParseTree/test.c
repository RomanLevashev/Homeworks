#include <stdio.h>
#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

void createFileWithTest(const char* filename, const char* expression) {
    FILE* file = fopen(filename, "w");
    fprintf(file, "%s\n", expression);
    fclose(file);
}

bool runTests() {
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

    int expectedResults[] = { 8, 8, 4, 6, 18, 2, 9, 3, 1, 12 };
    for (int i = 0; i < 10; i++) {
        char filename[20] = { 0 };
        snprintf(filename, sizeof(filename), "test%d.txt", i + 1);
        createFileWithTest(filename, tests[i]);
        FILE* file = fopen(filename, "r");
        Node* root = buildTree(file);
        int value = evaluateFromTree(root);
        if (value != expectedResults[i]) {
            freeTree(root);
            fclose(file);
            return false;
        }
        freeTree(root);
        fclose(file);
    }
    return true;
}