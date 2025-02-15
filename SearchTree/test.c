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

bool runTests() {
    int testLength = 150;
    Tree* tree = getTree();
    if (tree == NULL) {
        perror("Ошибка выделения памяти");
        return false;
    }
    Node** rootPointer = getRootPointer(tree);
    insert(rootPointer, 123, "abc");
    insert(rootPointer, 111, "def");
    insert(rootPointer, 133, "gda");
    if (compare(search(*rootPointer, 123), "abc", 123, 1) != 0) {
        freeTree(&tree, rootPointer);
        return false;
    }
    delete(rootPointer, 123);
    if (getKey(*rootPointer) != 133) {
        freeTree(&tree, rootPointer);
        return false;
    }
    delete(rootPointer, 111);
    delete(rootPointer, 133);
    insert(rootPointer, 20, "20");
    insert(rootPointer, 24, "24");
    insert(rootPointer, 23, "23");
    insert(rootPointer, 27, "27");
    delete(rootPointer, 23);
    if (search(*rootPointer, 23) != NULL) {
        freeTree(&tree, rootPointer);
        return false;
    }

    insert(rootPointer, 5, "5");
    insert(rootPointer, 16, "16");
    insert(rootPointer, 2, "2");
    insert(rootPointer, 11, "11");
    insert(rootPointer, 13, "13");
    insert(rootPointer, 18, "18");
    delete(rootPointer, 5);
    if (search(*rootPointer, 5) != NULL) {
        freeTree(&tree, rootPointer);
        return false;
    }
    if (search(*rootPointer, 16) == NULL || search(*rootPointer, 11) == NULL || search(*rootPointer, 18) == NULL || search(*rootPointer, 13) == NULL) {
        freeTree(&tree, rootPointer);
        return false;
    }
    if (compare(search(*rootPointer, 18), "18", 3, 1) != 0) {
        freeTree(&tree, rootPointer);
        return 0;
    }
    delete(rootPointer, 20);
    if (getKey(*rootPointer) != 24) {
        freeTree(&tree, rootPointer);
        return false;
    }
    freeTree(&tree, rootPointer);

    return true;
}