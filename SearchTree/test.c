#include <stdbool.h>
#include "tree.h"
#include <stdlib.h>
#include <string.h>

int compare(char* first, char* second, const int length, int kind) {
    for (int i = 0; i < length; ++i) {
        int firstElement = first[i];
        int secondElement = second[i];

        if (firstElement == 0) {
            if ((secondElement != 0) && kind == 2) {
                return -1;
            }
            else {
                return 0;
            }
        }
        if (secondElement == 0) {
            if ((firstElement != 0) && kind == 2) {
                return 1;
            }
            else {
                return 0;
            }
        }

        if (firstElement > secondElement) {
            return 1;
        }
        if (firstElement < secondElement) {
            return -1;
        }
    }
    return 0;
}

void insertForTest(Node** root, int key, const char* source) {
    char* str = calloc(150, 1);
    strncpy(str, source, 150);
    insert(root, key, str);
}

bool test() {
    Tree* tree = malloc(sizeof(Tree));
    tree->root = NULL;
    Node* root = tree->root;
    insertForTest(&root, 123, "abc");
    insertForTest(&root, 111, "def");
    insertForTest(&root, 133, "gda");
    if (compare(search(root, 123), "abc", 123, 1) != 0) {
        return false;
    }
    delete(&root, 123);
    if (root->key != 133) {
        return false;
    }
    delete(&root, 111);
    delete(&root, 133);
    insertForTest(&root, 20, "20");
    insertForTest(&root, 24, "24");
    insertForTest(&root, 23, "23");
    insertForTest(&root, 27, "27");
    delete(&root, 23);
    if (search(root, 23) != NULL) {
        return false;
    }

    insertForTest(&root, 5, "5");
    insertForTest(&root, 16, "16");
    insertForTest(&root, 2, "2");
    insertForTest(&root, 11, "11");
    insertForTest(&root, 13, "13");
    insertForTest(&root, 18, "18");
    delete(&root, 5);
    if (search(root, 5) != NULL) {
        return false;
    }
    if (search(root, 16) == NULL || search(root, 11) == NULL || search(root, 18) == NULL || search(root, 13) == NULL) {
        return false;
    }
    if (compare(search(root, 18), "18", 3, 1) != 0) {
        return 0;
    }
    delete(&root, 20);
    if (root->key != 24) {
        return false;
    }
    delete(&root, 16);
    delete(&root, 2);
    delete(&root, 11);
    delete(&root, 13);
    delete(&root, 18);
    delete(&root, 20);
    delete(&root, 24);
    delete(&root, 27);
    
    if (root != NULL) {
        return false;
    }
    return true;
}