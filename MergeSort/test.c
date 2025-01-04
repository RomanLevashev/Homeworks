#include <stdbool.h>
#include "list.h"
#include <stdio.h>
#include <string.h>

bool runTests() {
    FILE* file = fopen("test.txt", "r");
    FILE* fileWithSortedNames = fopen("testNames.txt", "r");
    FILE* fileWithSortedPhones = fopen("testPhones.txt", "r");
    List* listForNames = createList();
    List* listForPhones = createList();
    List* listWithSortedNames = createList();
    List* listWithSortedPhones = createList();
    readFileToList(file, listForNames);
    fseek(file, 0, SEEK_SET);
    readFileToList(file, listForPhones);
    readFileToList(fileWithSortedNames, listWithSortedNames);
    readFileToList(fileWithSortedPhones, listWithSortedPhones);
    mergeSort(getHeadPointer(listForNames), 1);
    mergeSort(getHeadPointer(listForPhones), 2);
    Node* currentNames = *getHeadPointer(listForNames);
    Node* currentWantedNames = *getHeadPointer(listWithSortedNames);

    while (currentNames != NULL && currentWantedNames != NULL) {
        if (compare(getName(currentNames), getName(currentWantedNames), 50, 1) != 0) {
            puts("Name sort failed");
            return false;
        }
        currentNames = getNext(currentNames);
        currentWantedNames = getNext(currentWantedNames);
    }
    if (currentNames == NULL && currentWantedNames != NULL || currentWantedNames == NULL && currentNames != NULL) {
        puts("Name sort failed");
        return false;
    }

    Node* currentPhones = *getHeadPointer(listForPhones);
    Node* currentWantedPhones = *getHeadPointer(listWithSortedPhones);

    while (currentPhones != NULL && currentWantedPhones != NULL) {
        if (compare(getPhone(currentPhones), getPhone(currentWantedPhones), 15, 2) != 0) {
            puts("Phone sort failed");
            return false;
        }
        currentPhones = getNext(currentPhones);
        currentWantedPhones = getNext(currentWantedPhones);
    }
    if (currentPhones == NULL && currentWantedPhones != NULL || currentPhones == NULL && currentWantedPhones != NULL) {
        puts("Phone sort failed");
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
