#include <stdbool.h>
#include "list.h"
#include <stdio.h>
#include <string.h>

bool test() {
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
    listForNames->head = mergeSort(listForNames->head, 1);
    listForPhones->head = mergeSort(listForPhones->head, 2);
    Node* currentNames = listForNames->head;
    Node* currentWantedNames = listWithSortedNames->head;

    while (currentNames != NULL && currentWantedNames != NULL) {
        if (compare(currentNames->name,currentWantedNames->name, 50, 1) != 0) {
            puts("Name sort failed");
            return false;
        }
        currentNames = currentNames->next;
        currentWantedNames = currentWantedNames->next;
    }
    if (currentNames == NULL && currentWantedNames != NULL || currentWantedNames == NULL && currentNames != NULL) {
        puts("Name sort failed");
        return false;
    }

    Node* currentPhones = listForPhones->head;
    Node* currentWantedPhones = listWithSortedPhones->head;

    while (currentPhones != NULL && currentWantedPhones != NULL) {
        if (compare(currentPhones->phone, currentWantedPhones->phone, 15, 2) != 0) {
            puts("Phone sort failed");
            return false;
        }
        currentPhones = currentPhones->next;
        currentWantedPhones = currentWantedPhones->next;
    }
    if (currentPhones == NULL && currentWantedPhones != NULL || currentPhones == NULL && currentWantedPhones != NULL) {
        puts("Phone sort failed");
        return false;
    }

    return true;
}