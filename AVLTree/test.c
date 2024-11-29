#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

void insertForTest(Node** root, char* key) {
    char* str = calloc(150, 1);
    char* keyStr = calloc(150, 1);
    strncpy(str, key, 150);
    strncpy(keyStr, key, 150);
    insert(root, keyStr, str);
}

bool test(void) {
    Tree* tree = malloc(sizeof(Tree));
    tree->root = NULL;
    Node* root = tree->root;
    
    insertForTest(&root, "20");
    insertForTest(&root, "15");
    insertForTest(&root, "25");
    insertForTest(&root, "11");
    insertForTest(&root, "17");
    insertForTest(&root, "19");
    delete(&root, &root, "11");
    delete(&root, &root, "19");
    if (!(compare(root->key, "17", 10) == 0 && compare((root->left)->key, "15", 10) == 0 && compare((root->right)->key, "20", 10) == 0)) { // Проверка лево-правого поворота
        return false;   
    }
    freeTree(&root);
    
    insertForTest(&root, "25");
    insertForTest(&root, "20");
    insertForTest(&root, "30");
    insertForTest(&root, "29");
    insertForTest(&root, "31");
    insertForTest(&root, "27");
    if (!(compare(root->key, "29", 10) == 0 && compare((root->left)->key, "25", 10) == 0 && compare((root->right)->key, "30", 10) == 0)) { // Проверка право-левого поворота
        return false;
    }
    freeTree(&root);
    
    insertForTest(&root, "20");
    insertForTest(&root, "10");
    insertForTest(&root, "30");
    insertForTest(&root, "5");
    insertForTest(&root, "15");
    insertForTest(&root, "1");
    if (!(compare(root->key, "10", 10) == 0 && compare((root->left)->key, "5", 10) == 0 && compare((root->right)->key, "20", 10) == 0)) { // Проверка правого поворота
        return false;
    }
    freeTree(&root);

    insertForTest(&root, "20");
    insertForTest(&root, "10");
    insertForTest(&root, "25");
    insertForTest(&root, "22");
    insertForTest(&root, "28");
    insertForTest(&root, "30");
    if (!(compare(root->key, "25", 10) == 0 && compare((root->left)->key, "20", 10) == 0 && compare((root->right)->key, "28", 10) == 0)) { // Проверка левого поворота
        return false;
    }
    freeTree(&root);

    insertForTest(&root, "50");
    insertForTest(&root, "20");
    insertForTest(&root, "70");
    insertForTest(&root, "15");
    insertForTest(&root, "30");
    insertForTest(&root, "60");
    insertForTest(&root, "75");
    insertForTest(&root, "10");
    insertForTest(&root, "25");
    insertForTest(&root, "35");
    insertForTest(&root, "55");
    insertForTest(&root, "73");
    insertForTest(&root, "76");
    insertForTest(&root, "74");
    insertForTest(&root, "11");
    insertForTest(&root, "13");
    insertForTest(&root, "27");
    insertForTest(&root, "12");
    insertForTest(&root, "9");
    insertForTest(&root, "36");
    insertForTest(&root, "16");
    delete(&root, &root, "70");
    if (!(compare(root->key, "20", 10) == 0 && compare((root->right)->key, "50", 10) == 0 && compare((root->left)->key, "11", 10) == 0)) { // Проверка удаления и правого поворота одновременно
        return false;
    }
    delete(&root, &root, "20");
    if (compare(root->key, "25", 1) != 0) { // Проверка удаления корня
        return false;
    }

    if ((compare(search(root, "25"), "25", 10) != 0)) { // Проверка поиска
        return false;
    }
    freeTree(&root);
    free(root);
    free(tree);
    return true;
}