#include "../List/list.h"
#include "../HashTable/hashtable.h"
#include <stdio.h>
#include <stdbool.h>

bool runTests(void) {
    HashTable* table = initTable();
    FILE* testFile = fopen("test.txt", "w");
    fprintf(testFile, "apple, 123, banana, 'apple', 456, cherry, 'banana', 789, apple, 'cherry', 101112, banana, cherry, 'apple', 131415. a b c");
    fclose(testFile);
    testFile = fopen("test.txt", "r");
    parseFile(testFile, table);
    fclose(testFile);

    if (getElementCountFromTable(table, "apple") != 4) {
        fclose(testFile);
        freeTable(&table);
        return false;
    }
    if (getElementCountFromTable(table, "banana") != 3) {
        fclose(testFile);
        freeTable(&table);
        return false;
    }
    if (getElementCountFromTable(table, "cherry") != 3) {
        fclose(testFile);
        freeTable(&table);
        return false;
    }
    if (getElementCountFromTable(table, "a") != 0 || getElementCountFromTable(table, "b") != 0 || getElementCountFromTable(table, "c") != 0) {
        fclose(testFile);
        freeTable(&table);
        return false;
    }
    fclose(testFile);
    freeTable(&table);
    return true;
}
