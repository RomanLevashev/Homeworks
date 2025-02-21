#include "tree.h"
#include "test.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

bool testBalance(Node* source) {
    bool leftResult = true;
    bool rightResult = true;

    if (getLeft(source)) {
        leftResult = testBalance(getLeft(source));
    }

    if (getRight(source)) {
        rightResult = testBalance(getRight(source));
    }

    return leftResult && rightResult && abs(getBalanceFactor(source)) < 2;
}

bool runTests(void) {
    int testLength = 20;
    int keyLength = 4;
    char randValues[20][5] = { 0 };
    bool isSuccess = true;
    srand(time(NULL));

    for (int i = 0; i < testLength; ++i) {
        for (int j = 0; j < keyLength; ++j) {
            randValues[i][j] = rand();
            }
    }

    Tree* tree = createTree();
    Node** rootPointer = getRootPointer(tree);

    if (tree == NULL) {
        return false;
    }

    for (int i = 0; i < testLength; ++i) {
        insert(rootPointer, randValues[i], "0", &isSuccess);

        if (!isSuccess) {
            deleteTree(rootPointer);
            free(tree);
            return false;
        }
    }

    if (!testBalance(*rootPointer)) {
        deleteTree(rootPointer);
        free(tree);
        return false;
    }

    deleteTree(rootPointer);

    insert(rootPointer, "20", "20", &isSuccess);
    insert(rootPointer, "15", "15", &isSuccess);
    insert(rootPointer, "25", "25", &isSuccess);
    insert(rootPointer, "11", "11", &isSuccess);
    insert(rootPointer, "17", "17", &isSuccess);
    insert(rootPointer, "19", "19", &isSuccess);
    delete(rootPointer, "11", &isSuccess);
    delete(rootPointer, "19", &isSuccess);

    if (!isSuccess || strcmp(getKey(*rootPointer), "17") != 0 || strcmp(getKey(getLeft(*rootPointer)), "15") != 0 || strcmp(getKey(getRight(*rootPointer)), "20") != 0) { // Проверка лево-правого поворота
        deleteTree(rootPointer);
        free(tree);
        return false;
    }
    
    if (!testBalance(*rootPointer)) {
        deleteTree(rootPointer);
        free(tree);
        return false;
    }
    deleteTree(rootPointer);
    
    insert(rootPointer, "25", "25", &isSuccess);
    insert(rootPointer, "20", "20", &isSuccess);
    insert(rootPointer, "30", "30", &isSuccess);
    insert(rootPointer, "29", "29", &isSuccess);
    insert(rootPointer, "31", "31", &isSuccess);
    insert(rootPointer, "27", "27", &isSuccess);

    if (!isSuccess || strcmp(getKey(*rootPointer), "29") != 0 || strcmp(getKey(getLeft(*rootPointer)), "25") != 0 || strcmp(getKey(getRight(*rootPointer)), "30") != 0) { // Проверка право-левого поворота
        deleteTree(rootPointer);
        free(tree);
        return false;
    }

    if (!testBalance(*rootPointer)) {
        deleteTree(rootPointer);
        free(tree);
        return false;
    }
    deleteTree(rootPointer);

    insert(rootPointer, "20", "20", &isSuccess);
    insert(rootPointer, "10", "10", &isSuccess);
    insert(rootPointer, "30", "30", &isSuccess);
    insert(rootPointer, "1", "1", &isSuccess);
    insert(rootPointer, "15", "15", &isSuccess);
    insert(rootPointer, "0", "0", &isSuccess);

    if (!isSuccess || strcmp(getKey(*rootPointer), "10") != 0 || strcmp(getKey(getLeft(*rootPointer)), "1") != 0 || strcmp(getKey(getRight(*rootPointer)), "20") != 0) { // Проверка правого поворота
        deleteTree(rootPointer);
        free(tree);
        return false;
    }

    if (!testBalance(*rootPointer)) {
        deleteTree(rootPointer);
        free(tree);
        return false;
    }
    deleteTree(rootPointer);

    insert(rootPointer, "20", "20", &isSuccess);
    insert(rootPointer, "10", "10", &isSuccess);
    insert(rootPointer, "25", "25", &isSuccess);
    insert(rootPointer, "22", "22", &isSuccess);
    insert(rootPointer, "28", "28", &isSuccess);
    insert(rootPointer, "30", "30", &isSuccess);

    if (!isSuccess || strcmp(getKey(*rootPointer), "25") != 0 || strcmp(getKey(getLeft(*rootPointer)), "20") != 0 || strcmp(getKey(getRight(*rootPointer)), "28") != 0) { // Проверка левого поворота
        deleteTree(rootPointer);
        free(tree);
        return false;
    }

    if (!testBalance(*rootPointer)) {
        deleteTree(rootPointer);
        free(tree);
        return false;
    }
    deleteTree(rootPointer);

    insert(rootPointer, "50", "50", &isSuccess);
    insert(rootPointer, "20", "20", &isSuccess);
    insert(rootPointer, "70", "70", &isSuccess);
    insert(rootPointer, "15", "15", &isSuccess);
    insert(rootPointer, "30", "30", &isSuccess);
    insert(rootPointer, "60", "60", &isSuccess);
    insert(rootPointer, "75", "75", &isSuccess);
    insert(rootPointer, "10", "10", &isSuccess);
    insert(rootPointer, "25", "25", &isSuccess);
    insert(rootPointer, "35", "35", &isSuccess);
    insert(rootPointer, "55", "55", &isSuccess);
    insert(rootPointer, "73", "73", &isSuccess);
    insert(rootPointer, "76", "76", &isSuccess);
    insert(rootPointer, "74", "74", &isSuccess);
    insert(rootPointer, "17", "17", &isSuccess);
    insert(rootPointer, "16", "16", &isSuccess);
    insert(rootPointer, "11", "11", &isSuccess);
    insert(rootPointer, "0", "0", &isSuccess);
    insert(rootPointer, "37", "37", &isSuccess);
    insert(rootPointer, "13", "13", &isSuccess);
    insert(rootPointer, "27", "27", &isSuccess);
    insert(rootPointer, "12", "12", &isSuccess);
    insert(rootPointer, "9", "9", &isSuccess);
    insert(rootPointer, "36", "36", &isSuccess);
    insert(rootPointer, "16", "99", &isSuccess);

    delete(rootPointer, "50", &isSuccess);

    if (!isSuccess || strcmp(getKey(*rootPointer), "55") != 0) { // Проверка удаления корня
        deleteTree(rootPointer);
        free(tree);
        return false;
    }

    if (!testBalance(*rootPointer)) {
        deleteTree(rootPointer);
        free(tree);
        return false;
    }

    if (strcmp(search(*rootPointer, "16"), "99") != 0) { // Проверка поиска
        deleteTree(rootPointer);
        free(tree);
        return false;
    }

    if (strcmp(search(*rootPointer, "70"), "70") != 0) { // Проверка поиска
        deleteTree(rootPointer);
        free(tree);
        return false;
    }

    if (strcmp(search(*rootPointer, "15"), "15") != 0) { // Проверка поиска
        deleteTree(rootPointer);
        free(tree);
        return false;
    }

    deleteTree(rootPointer);
    free(tree);

    return true;
}