#include "../List/list.h"
#include "../HashTable/hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "test.h"

int main(void) {
    if (!runTests()) {
        puts("Tests failed");
        return 1;
    }
    
    puts("All tests were passed successfully");
    HashTable* table = initTable(INIT_TABLE_SIZE);

    if (table == NULL) {
        return 2;
    }
    FILE* file = fopen("input.txt", "r");
    parseFile(file, &table);
    fclose(file);
    printf("Load Factor  %f\n", calculateLoadFactor(table));
    printf("Average List Length  %f\n", calculateAvgListLength(table));
    printf("Maximum List Length  %d\n", calculateMaxListLength(table));
    printTable(table);
    freeTable(&table);
    return 0;
}