#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <string.h>
#include <stdbool.h>
#include "test.h"

enum Options {name = 1, phone};

void clearBuffer() {
    char c = '\0';
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    if (!runTests()) {
        puts("Test failed");
        return 1;
    }
    puts("Tests were passed successfully");
    
    FILE* file = fopen("input.txt", "r");
    List* list = createList();
    if (list == NULL) {
        return -1;
    }
    int choice = 0;
    puts("1 - Sorted by Name\n2 - Sorted by phone");
    scanf("%d", &choice);
    readFileToList(file, list);
    switch (choice) {
    case(name): {
        mergeSort(getHeadPointer(list), name);
        break;
    }
    case(phone): {
        mergeSort(getHeadPointer(list), phone);
        break;
    }
    }    
    printList(list);
    deleteList(&list);
    fclose(file);
}