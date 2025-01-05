#include "tree.h"
#include "test.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

enum Options { add = 1, get, inDictionary, del };
int maxLength = 150;


void clearBuffer() {
    char c = '\0';
    while ((c = getchar()) != '\n' && c != EOF && c != NULL);
}

void chooseOption(int choice, Node** root) {
    switch (choice) {
    case add: {
        int key = 0;
        char value[151] = { 0 };
        puts("Введите ключ и строку до 150 символов через пробел: ");
        scanf("%d %150s", &key, value);
        clearBuffer();
        insert(root, key, value);
        break;
    }
    case get: {
        int key = 0;
        char* value = NULL;
        puts("Введите ключ, по которому хотите найти значение: ");
        scanf("%d", &key);
        clearBuffer();
        value = search(*root, key);
        if (value == NULL) {
            puts("Значение по данному ключу не найдено");
            return;
        }
        printf("%s\n", value);
        break;
    }
    case inDictionary: {
        int key = 0;
        puts("Введите ключ, который хотите проверить на наличие: ");
        scanf("%d", &key);
        clearBuffer();
        if (search(*root, key) == NULL) {
            puts("Ключ не в списке");
        }
        else {
            puts("Ключ в списке");
        }
        break;
    }
    case del: {
        int key = -1;
        puts("Введите ключ, который хотите удалить: ");
        scanf("%d", &key);
        clearBuffer();
        delete(root, key);
    }
    }
}

int main(void) {
    setlocale(LC_ALL, "Russian");
    if (!runTests()) {
        puts("Тесты провалились");
        return 1;
    }
    puts("Тесты прошли успешно");
    Tree* tree = getTree();
    Node** rootPointer = getRootPointer(tree);
    int choice = -1;

    while (choice != 0) {
        puts("0 - Выход\n\
1 - Добавить значение по ключу\n\
2 - Получить значению по ключу\n\
3 - Проверить наличие ключа\n\
4 - Удалить значению по ключу\n");
        scanf("%d", &choice);
        clearBuffer();
        chooseOption(choice, rootPointer);
    }
    freeTree(&tree, rootPointer);
    return 0;
}