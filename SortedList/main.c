#include "doubleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include "test.h"

enum Options {add = 1,delete, print};

void clearBuffer() {
    char c = '\0';
    while ((c = getchar()) != '\n' && c != EOF);
}

void chooseOption(int choice, List* list) {
    switch (choice) {
    case add: {
        puts("Введите число: ");
        int enterValue = 0;
        scanf("%d", &enterValue);
        clearBuffer();

        append(enterValue, list);
        return;
    }
    case delete: {
        puts("Введите число, которое хотите удалить: ");
        int enterValue = 0;
        scanf("%d", &enterValue);
        clearBuffer();
        deleteElement(enterValue, list);
        return;
    }
    case print: {
        printList(list);
    }
    }
}

int main(void) {
    setlocale(LC_ALL, "Russian");
    if (!runTests()) {
         puts("Тесты не пройдены");
         return 1;
    }
    puts("Тесты пройдены");

    List* list = createList();
    if (list == NULL) {
        return -1;
    }
    int choice = -1;
    do {
       puts("0 – выйти\n\
1 – добавить значение в сортированный список\n\
2 – удалить значение из списка\n\
3 – распечатать список\n");
         scanf("%d", &choice);
         clearBuffer();
         chooseOption(choice, list);
    }  while (choice != 0);
    freeList(&list);
    return 0;
}