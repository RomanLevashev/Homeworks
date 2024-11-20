#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

enum options { add = 1, get, inDictionary, del };

bool test(void);

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF && c != NULL);
}

void chooseOption(int choice, Node** root) {
    switch (choice) {
    case add: {
        int key = 0;
        char* value = calloc(150, 1);
        puts("Введите ключ и строку до 150 символов через пробел: ");
        scanf("%d %s", &key, value);
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
        int key;
        puts("Введите ключ, который хотите удалить: ");
        scanf("%d", &key);
        clearBuffer();
        delete(root, key);
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
    return 0;
}