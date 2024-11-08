#include "doubleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

bool testing(void);

enum options {add = 1,delete , print};

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void chooseOption(int choice, List* list) {
    switch (choice) {
    case(add): {
        puts("Введите число: ");
        int enterValue = 0;
        scanf("%d", &enterValue);
        clearBuffer();
        append(enterValue, list);
        return;
    }
    case(delete): {
        puts("Введите число, которое хотите удалить: ");
        int enterValue = 0;
        scanf("%d", &enterValue);
        clearBuffer();
        deleteElement(enterValue, list);
        return;
    }
    case(print): {
        printList(list);
    }
    }
}

int main(void) {
   setlocale(LC_ALL, "Russian");
   if (!testing()) {
        puts("Тесты не пройдены");
        return 1;
    }
   else {
       puts("Тесты пройдены");
   }
    List* list = createList();
    int choice = -1;
    do {
        puts("0 – выйти\n\
1 – добавить значение в сортированный список\n\
2 – удалить значение из списка\n\
3 – распечатать список\n");
        scanf("%d", &choice);
        clearBuffer();
        chooseOption(choice, list);
    } while (choice != 0);

    /*
    append(12, list);
    deleteElement(12, list);

    append(10, list);
    append(7, list);
    deleteElement(7, list);
    append(1, list);
    append(302, list);
    append(1122, list);
    append(182, list);
    append(1092, list);

    printList(list);

    return 0;
    */
}