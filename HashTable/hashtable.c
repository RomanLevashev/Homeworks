#include "../List/list.h"
#include <stdlib.h>
#include "hashtable.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct HashTable {
    Node** elements;
    unsigned int size;
} HashTable;

HashTable* initTable(int size) {
    HashTable* table = malloc(sizeof(HashTable));
    if (table == NULL) {
        perror("Memory allocate error");
        return NULL;
    }
    table->size = (unsigned int)size;
    table->elements = (Node**)malloc(table->size*sizeof(Node*));

    if (table->elements == NULL) {
        perror("Memory allocate error");
        free(table);
        return NULL;
    }

    for (int i = 0; i < table->size; ++i) {
        table->elements[i] = NULL;
    }

    return table;
}

unsigned int hashFunction(char* word, int length, unsigned int tableSize) {
    unsigned int hash = 0;
    for (int i = 0; i < length ; i++) {
        hash += (unsigned int)word[i];
    }
    return hash % tableSize;
}

HashTable* getNewHashTable(HashTable* table, int previousSize) {
    unsigned int newSize = previousSize * 2;
    HashTable* newTable = initTable(newSize);

    if (newTable == NULL) {
        return NULL;
    }

    for (int i = 0; i < previousSize; i++) {
        Node* node = (table->elements)[i];

        if (node != NULL) {        
            char* word = getNodeWord(node);
            unsigned int newHash = hashFunction(word, strlen(word), newSize);
            newTable->elements[newHash] = node;
        }
    }
    free(table->elements);
    free(table);
    return newTable;
}

bool addWord(HashTable** tablePointer, char* word) {
    HashTable* table = *tablePointer;
    int length = strlen(word);
    unsigned int index = hashFunction(word, length, getTableSize(table));
    table->elements[index] = insertOrIncreaseCounter((table->elements)[index], word);
    double loadFactor = calculateLoadFactor(table);

    if (loadFactor > 0.7) {
        HashTable* newTable = getNewHashTable(table, table->size);

        if (newTable == NULL) {
            return false;
        }

        *tablePointer = newTable;
    }
    return true;
}

void printTable(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        printList((table->elements)[i]);
    }
}

void freeTable(HashTable** table) {
    for (int i = 0; i < (*table)->size; i++) {
        if (((*table)->elements)[i] != NULL) {
            freeList(&((*table)->elements)[i]);
        }
    }
    free((*table)->elements);
    free(*table);
    *table = NULL;
}

double calculateLoadFactor(HashTable* table) {
    int nonEmptySegments = 0;
    for (int i = 0; i < table->size; i++) {
        if ((table->elements)[i] != NULL) {
            nonEmptySegments++;
        }
    }
    return (double)nonEmptySegments / table->size;
}

double calculateAvgListLength(HashTable* table) {
    int totalLength = 0;
    int nonEmptySegments = 0;
    for (int i = 0; i < table->size; i++) {
        int length = 0;
        Node* current = (table->elements)[i];
        while (current) {
            length++;
            current = getNext(current);
        }
        if (length > 0) {
            totalLength += length;
            nonEmptySegments++;
        }
    }
    return nonEmptySegments ? (double)totalLength / nonEmptySegments : 0.0;
}

int calculateMaxListLength(HashTable* table) {
    int maxLength = 0;
    for (int i = 0; i < table->size; i++) {
        int length = 0;
        Node* current = (table->elements)[i];
        while (current) {
            length++;
            current = getNext(current);
        }
        if (length > maxLength) {
            maxLength = length;
        }
    }
    return maxLength;
}

void parseFile(FILE* file, HashTable** tablePointer) {
    int c = 0;
    int index = 0;
    char word[MAX_WORD_LENGTH + 1] = { 0 };

    while ((c = fgetc(file)) != EOF && index < MAX_WORD_LENGTH) {
        if (c > 0 && isalpha(c)) {
            word[index] = c;
            index++;
        }
        if (c == ' ' && index > 0) {
            if (index == 1) {
                memset(word, 0, MAX_WORD_LENGTH + 1);
                index = 0;
                continue;
            }
            bool isSuccess = addWord(tablePointer, word);

            if (!isSuccess) {
                freeTable(tablePointer);
                return;
            }

            memset(word, 0, MAX_WORD_LENGTH + 1);
            index = 0;
        }
    }
    if (word[0] != '\0' && word[1] != '\0') {
        bool isSuccess = addWord(tablePointer, word);

        if (!isSuccess) {
            freeTable(tablePointer);
            return;
        }
    }
}

int getElementCountFromTable(HashTable* table, char* word) {
    int index = hashFunction(word, strlen(word), table->size);
    Node* node = findNode((table->elements)[index], word);
    if (node == NULL) {
        return 0;
    }
    return getCount(node);
}

int getTableSize(HashTable* table) {
    return table != NULL ? table->size: 0;
}