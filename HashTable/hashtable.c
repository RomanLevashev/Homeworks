#include "../List/list.h"
#include <stdlib.h>
#include "hashtable.h"
#include <stdio.h>
#include <string.h>
#define TABLE_SIZE 1000

typedef struct HT {
    Node* elements[TABLE_SIZE];
} HashTable;

HashTable* initTable(void) {
    HashTable* table = malloc(sizeof(HashTable));
    if (table == NULL) {
        perror("Memory allocate error");
        return NULL;
    }
    for (int i = 0; i < TABLE_SIZE; ++i) {
        (table->elements)[i] = NULL;
    }
    return table;
}

unsigned int hashFunction(char* word, int length) {
    int hash = 0;
    for (int i = 0; i < length ; i++) {
        char current = word[i];
        hash += current;
    }
    return hash % TABLE_SIZE;
}

void addWord(HashTable* table, char* word) {
    int length = strlen(word);
    unsigned int index = hashFunction(word, length);
    table->elements[index] = insertOrIncreaseCounter((table->elements)[index], word);
}

void printTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printList((table->elements)[i]);
    }
}

void freeTable(HashTable** table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (((*table)->elements)[i] != NULL) {
            freeList(&((*table)->elements)[i]);
        }
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
    for (int i = 0; i < TABLE_SIZE; i++) {
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

void parseFile(FILE* file, HashTable* table) {
    int c = 0;
    int index = 0;
    char word[151] = { 0 };
    char buffer[151] = {0};

    while ((c = fgetc(file)) != EOF && index < 150) {
        if (c > 0 && isalpha(c)) {
            buffer[index] = c;
            index++;
        }
        if (c == ' ' && index > 0) {
            if (index == 1) {
                index = 0;
                continue;
            }
            if (word == NULL) {
                continue;
            }
            strncpy(word, buffer, 150);
            addWord(table, word);
            memset(buffer, 0, 150);
            memset(word, 0, 150);
            index = 0;
        }
    }
    if (buffer[0] != '\0' && buffer[1] != '\0') {
        if (word == NULL) {
            perror("Error reading file");
            return;
        }
        strncpy(word, buffer, 150);
        addWord(table, word);
        memset(buffer, 0, 150);
        memset(word, 0, 150);
        index = 0;
    }
}

int getElementCountFromTable(HashTable* table, char* word) {
    int index = hashFunction(word, strlen(word));
    Node* node = findNode((table->elements)[index], word);
    if (node == NULL) {
        return 0;
    }
    return getCount(node);
}