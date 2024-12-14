#include "../List/list.h"
#include <stdlib.h>
#include "hashtable.h"
#define TABLE_SIZE 1000

void initTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        (table->elements)[i] = NULL;
    }
}

int hashFunction(char* word) {
    int hash = 0;
    while (word != NULL && *word != NULL) {
        hash += *word++;
    }
    return hash % TABLE_SIZE;
}

void addWord(HashTable* table, char* word) {
    int index = hashFunction(word);
    (table->elements)[index] = insertOrIncreaseCounter((table->elements)[index], word);
}

void printTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printList((table->elements)[i]);
    }
}

void freeTable(HashTable** table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        freeList(((*table)->elements)[i]);
        ((*table)->elements)[i] = NULL;
    }
    free(*table);
    *table = NULL;
}

double calculateLoadFactor(HashTable* table) {
    int nonEmptySegments = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if ((table->elements)[i] != NULL) {
            nonEmptySegments++;
        }
    }
    return (double)nonEmptySegments / TABLE_SIZE;
}

double calculateAvgListLength(HashTable* table) {
    int totalLength = 0;
    int nonEmptySegments = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        int length = 0;
        Node* current = (table->elements)[i];
        while (current) {
            length++;
            current = current->next;
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
    for (int i = 0; i < TABLE_SIZE; i++) {
        int length = 0;
        Node* current = (table->elements)[i];
        while (current) {
            length++;
            current = current->next;
        }
        if (length > maxLength) {
            maxLength = length;
        }
    }
    return maxLength;
}

