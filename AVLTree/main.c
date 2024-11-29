#include <stdbool.h>
#include "tree.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

bool test(void);

enum options { add = 1, get, check, del };

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF && c != NULL);
}

void chooseOption(int choice, Node** root) {
    switch (choice) {
    case add: {
        char* key = calloc(150, 1);
        char* value = calloc(150, 1);
        puts("Введите ключ до 150 символов: ");
        scanf("%s", key);
        clearBuffer();
        puts("Введите значение до 150 символов: ");
        scanf("%s", value);
        clearBuffer();
        insert(root, key, value);
        break;
    }
    case get: {
        char* key = calloc(150, 1);
        char* value = NULL;
        puts("Введите ключ, по которому хотите найти значение: ");
        scanf("%s", key);
        clearBuffer();
        value = search(*root, key);
        printf("%s\n", value);
        free(key);
        break;
    }
    case check: {
        char* key = calloc(150, 1);
        puts("Введите ключ, который хотите проверить на наличие: ");
        scanf("%s", key);
        clearBuffer();
        if (search(*root, key) == NULL) {
            puts("Ключ не в списке");
        }
        else {
            puts("Ключ в списке");
        }
        free(key);
        break;
    }
    case del: {
        char* key = calloc(150, 1);
        puts("Введите ключ, который хотите удалить: ");
        scanf("%s", key);
        clearBuffer();
        delete(root, root, key);
        free(key);
    }
    }
}

int main(void) {
    setlocale(LC_ALL, "Russian");
    if (!test()) {
        puts("Тесты провалились");
        return 1;
    }
    else {
        puts("Тесты прошли успешно");
    }

    Tree* tree = malloc(sizeof(Tree));
    tree->root = NULL;
    Node* root = tree->root;
    int choice = -1;

    while (choice != 0) {
        puts("0 - Выход\n\
1 - Добавить значение по ключу\n\
2 - Получить значению по ключу\n\
3 - Проверить наличие ключа\n\
4 - Удалить значению по ключу\n");
        scanf("%d", &choice);
        clearBuffer();
        chooseOption(choice, &root);
    }
    freeTree(&root);
    return 0;
}