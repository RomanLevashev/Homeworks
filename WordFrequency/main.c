#include "../List/list.h"
#include "../HashTable/hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void parseFile(FILE* file, HashTable* table) {
    int c = NULL;
    int index = 0;
    char* word = NULL;
    char* buffer = calloc(100, 1);

    while ((c = fgetc(file)) != EOF) {
        if (c > 0 && isalpha(c)) {
            buffer[index % 99] = c;
            index++;
        }
        if (c == ' ' && index > 0) {
            if (index == 1) {
                index = 0;
                continue;
            }
            word = calloc(100, 1);
            if (word == NULL) {
                continue;
            }
            strncpy(word, buffer, 99);
            addWord(table, word);
            memset(buffer, 0, 100);
            index = 0;
        }
    }
    if (buffer[0] != NULL && buffer[1] != NULL) {
        word = calloc(100, 1);
        if (word == NULL) {
            return;
        }
        strncpy(word, buffer, 99);
        addWord(table, word);
        memset(buffer, 0, 100);
        index = 0;
    }
}

bool runTests(void);

int main(void) {
    if (!runTests()) {
        puts("Tests failed");
        return 1;
    }
    puts("All tests were passed successfully");
    FILE* file = fopen("input.txt", "r");
    HashTable* table = malloc(sizeof(HashTable));
    initTable(table);

    parseFile(file, table);
    printf("Load Factor  %f\n", calculateLoadFactor(table));
    printf("Average List Length  %f\n", calculateAvgListLength(table));
    printf("Maximum List Length  %d\n", calculateMaxListLength(table));
    printTable(table);
    return 0;
}