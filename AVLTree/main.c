#include <stdbool.h>
#include "tree.h"
#include "test.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef enum Options {
    add = 1,
    get,
    check,
    del
} Options;

void clearBuffer() {
    char c = '\0';
    while ((c = getchar()) != '\n' && c != EOF && c != NULL);
}

void chooseOption(Options choice, Tree* tree) {
    Node** rootPointer = getRootPointer(tree);
    bool isSuccess = true;

    switch (choice) {
    case add: {
        isSuccess = true;
        char key[151] = { 0 };
        char value[151] = { 0 };
        puts("Введите ключ до 150 символов: ");
        scanf("%150s", key);
        clearBuffer();
        puts("Введите значение до 150 символов: ");
        scanf("%150s", value);
        clearBuffer();
        insert(rootPointer, key, value, &isSuccess);

        if (isSuccess) {
            puts("Элемент успешно добавлен");
        }
        else {
            puts("Элемент не добавлен");
        }
        break;
    }
    case get: {
        char key[151] = { 0 };
        puts("Введите ключ, по которому хотите найти значение: ");
        scanf("%150s", key);
        clearBuffer();
        char* value = NULL;
        value = search(*rootPointer, key);
        if (value == NULL) {
            puts("Элемент не найден");
        }
        printf("%s\n", value);
        break;
    }
    case check: {
        char key[151] = { 0 };
        puts("Введите ключ, который хотите проверить на наличие: ");
        scanf("%150s", key);
        clearBuffer();
        if (search(*rootPointer, key) == NULL) {
            puts("Ключ не в списке");
        }
        else {
            puts("Ключ в списке");
        }
        break;
    }
    case del: {
        isSuccess = true;
        char key[151] = { 0 };
        puts("Введите ключ, который хотите удалить: ");
        scanf("%150s", key);
        clearBuffer();
        delete(rootPointer, key, &isSuccess);

        if (isSuccess) {
            puts("Элемент успешно удалён");
        }
        else {
            puts("Элемент не удалён");
        }
    }
    }
}

int main(void) {
    setlocale(LC_ALL, "Russian");
    if (!runTests()) {
        puts("Тесты провалились");
        return 1;
    }
    else {
        puts("Тесты прошли успешно");
    }

    
    Tree* tree = createTree();
    int choice = -1;

    while (choice != 0) {
        puts("0 - Выход\n\
1 - Добавить значение по ключу\n\
2 - Получить значению по ключу\n\
3 - Проверить наличие ключа\n\
4 - Удалить значению по ключу\n");
        scanf("%d", &choice);
        clearBuffer();
        chooseOption(choice, tree);
    }
    deleteTree(getRootPointer(tree));
    free(tree);
    return 0;
}
