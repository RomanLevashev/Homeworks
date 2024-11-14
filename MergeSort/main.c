#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <string.h>
#include <stdbool.h>

enum options {name = 1, phone};
bool test();

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    if (test()) {
        puts("Test complete");
    }
    else {
        return 1;
    }
    
    FILE* file = fopen("input.txt", "r");
    List* list = createList();
    int choice = 0;
    puts("1 - Sorted by Name\n2 - Sorted by phone");
    scanf("%d", &choice);
    readFileToList(file, list);
    switch (choice) {
    case(name): {
        list->head = mergeSort(list->head, name);
        break;
    }
    case(phone): {
        list->head = mergeSort(list->head, phone);
        break;
    }
    }    
    printList(list);
    deleteList(list);
    free(list);
    fclose(file);
}