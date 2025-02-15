#include <stdbool.h>
#include "list.h"
#include <stdio.h>
#include <string.h>

bool runTests(void) {
    FILE* file = fopen("test.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return false;
    }
    FILE* fileWithSortedNames = fopen("testNames.txt", "r");
    if (fileWithSortedNames == NULL) {
        perror("Failed to open file");
        free(file);
        return false;
    }
    FILE* fileWithSortedPhones = fopen("testPhones.txt", "r");
    if (fileWithSortedNames == NULL) {
        perror("Failed to open file");
        free(file);
        free(fileWithSortedNames);
        return false;
    }
    List* listForNames = createList();
    List* listForPhones = createList();
    List* listWithSortedNames = createList();
    List* listWithSortedPhones = createList();
    readFileToList(file, listForNames);
    fseek(file, 0, SEEK_SET);
    readFileToList(file, listForPhones);
    readFileToList(fileWithSortedNames, listWithSortedNames);
    readFileToList(fileWithSortedPhones, listWithSortedPhones);
    mergeSort(listForNames, 1);
    mergeSort(listForPhones, 2);
    Node* currentNames = *getHeadPointer(listForNames);
    Node* currentWantedNames = *getHeadPointer(listWithSortedNames);

    while (currentNames != NULL && currentWantedNames != NULL) {
        if (compare(getName(currentNames), getName(currentWantedNames), 50, 1) != 0) {
            puts("Name sort failed");
            fclose(file);
            fclose(fileWithSortedNames);
            fclose(fileWithSortedPhones);
            deleteList(&listForNames);
            deleteList(&listForPhones);
            deleteList(&listWithSortedNames);
            deleteList(&listWithSortedPhones);
            return false;
        }
        currentNames = getNext(currentNames);
        currentWantedNames = getNext(currentWantedNames);
    }
    if (currentNames == NULL && currentWantedNames != NULL || currentWantedNames == NULL && currentNames != NULL) {
        puts("Name sort failed");
        fclose(file);
        fclose(fileWithSortedNames);
        fclose(fileWithSortedPhones);
        deleteList(&listForNames);
        deleteList(&listForPhones);
        deleteList(&listWithSortedNames);
        deleteList(&listWithSortedPhones);
        return false;
    }

    Node* currentPhones = *getHeadPointer(listForPhones);
    Node* currentWantedPhones = *getHeadPointer(listWithSortedPhones);

    while (currentPhones != NULL && currentWantedPhones != NULL) {
        if (compare(getPhone(currentPhones), getPhone(currentWantedPhones), 15, 2) != 0) {
            puts("Phone sort failed");
            fclose(file);
            fclose(fileWithSortedNames);
            fclose(fileWithSortedPhones);
            deleteList(&listForNames);
            deleteList(&listForPhones);
            deleteList(&listWithSortedNames);
            deleteList(&listWithSortedPhones);
            return false;
        }
        currentPhones = getNext(currentPhones);
        currentWantedPhones = getNext(currentWantedPhones);
    }
    if (currentPhones == NULL && currentWantedPhones != NULL || currentPhones == NULL && currentWantedPhones != NULL) {
        puts("Phone sort failed");
        fclose(file);
        fclose(fileWithSortedNames);
        fclose(fileWithSortedPhones);
        deleteList(&listForNames);
        deleteList(&listForPhones);
        deleteList(&listWithSortedNames);
        deleteList(&listWithSortedPhones);
        return false;
    }

    fclose(file);
    fclose(fileWithSortedNames);
    fclose(fileWithSortedPhones);
    deleteList(&listForNames);
    deleteList(&listForPhones);
    deleteList(&listWithSortedNames);
    deleteList(&listWithSortedPhones);

    return true;
}
