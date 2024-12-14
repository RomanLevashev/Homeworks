#include "../List/list.h"
#include "../HashTable/hashtable.h"
#include <stdio.h>
#include <stdbool.h>

void parseFile(FILE* file, HashTable* table);

int getElementCountFromTable(HashTable* table, char* word) {
    int index = hashFunction(word);
    Node* node = findNode((table->elements)[index], word);
    if (node == NULL) {
        return 0;
    }
    return node->count;
}

bool runTests(void) {
    HashTable* table = malloc(sizeof(HashTable));
    initTable(table);
    FILE* testFile = fopen("test.txt", "w");
    fprintf(testFile, "apple, 123, banana, 'apple', 456, cherry, 'banana', 789, apple, 'cherry', 101112, banana, cherry, 'apple', 131415. a b c");
    fclose(testFile);
    testFile = fopen("test.txt", "r");
    parseFile(testFile, table);
    
    if (getElementCountFromTable(table, "apple") != 4) {
        return false;
    }
    if (getElementCountFromTable(table, "banana") != 3) {
        return false;
    }
    if (getElementCountFromTable(table, "cherry") != 3) {
        return false;
    }
    if (getElementCountFromTable(table, "a") != 0 || getElementCountFromTable(table, "b") != 0 || getElementCountFromTable(table, "c") != 0) {
        return false;
    }
    fclose(testFile);
    freeTable(&table);
    return true;
}