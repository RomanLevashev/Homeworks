#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

bool runTests(void) {
    Node* root = NULL;
    
    insert(&root, "20", "20");
    insert(&root, "15", "15");
    insert(&root, "25", "25");
    insert(&root, "11", "11");
    insert(&root, "17", "17");
    insert(&root, "19", "19");
    delete(&root, &root, "11");
    delete(&root, &root, "19");
    if (!(compare(getKey(root), "17", 10) == 0 && compare(getKey(getLeft(root)), "15", 10) == 0 && compare(getKey(getRight(root)), "20", 10) == 0)) { // Проверка лево-правого поворота
        freeTree(&root);
        return false;   
    }
    freeTree(&root);
    insert(&root, "25", "25");
    insert(&root, "20", "20");
    insert(&root, "30", "30");
    insert(&root, "29", "29");
    insert(&root, "31", "31");
    insert(&root, "27", "27");
    if (!(compare(getKey(root), "29", 10) == 0 && compare(getKey(getLeft(root)), "25", 10) == 0 && compare(getKey(getRight(root)), "30", 10) == 0)) { // Проверка право-левого поворота
        freeTree(&root);
        return false;
    }
    freeTree(&root);
    
    insert(&root, "20", "20");
    insert(&root, "10", "10");
    insert(&root, "30", "30");
    insert(&root, "5", "5");
    insert(&root, "15", "15");
    insert(&root, "1", "1");
    if (!(compare(getKey(root), "10", 10) == 0 && compare(getKey(getLeft(root)), "5", 10) == 0 && compare(getKey(getRight(root)), "20", 10) == 0)) { // Проверка правого поворота
        freeTree(&root);
        return false;
    }
    freeTree(&root);

    insert(&root, "20", "20");
    insert(&root, "10", "10");
    insert(&root, "25", "25");
    insert(&root, "22", "22");
    insert(&root, "28", "28");
    insert(&root, "30", "30");
    if (!(compare(getKey(root), "25", 10) == 0 && compare(getKey(getLeft(root)), "20", 10) == 0 && compare(getKey(getRight(root)), "28", 10) == 0)) { // Проверка левого поворота
        freeTree(&root);
        return false;
    }
    freeTree(&root);

    insert(&root, "50", "50");
    insert(&root, "20", "20");
    insert(&root, "70", "70");
    insert(&root, "15", "15");
    insert(&root, "30", "30");
    insert(&root, "60", "60");
    insert(&root, "75", "75");
    insert(&root, "10", "10");
    insert(&root, "25", "25");
    insert(&root, "35", "35");
    insert(&root, "55", "55");
    insert(&root, "73", "73");
    insert(&root, "76", "76");
    insert(&root, "74", "74");
    insert(&root, "11", "11");
    insert(&root, "13", "13");
    insert(&root, "27", "27");
    insert(&root, "12", "12");
    insert(&root, "9", "9");
    insert(&root, "36", "36");
    insert(&root, "16", "16");
    delete(&root, &root, "70");
    if (!(compare(getKey(root), "20", 10) == 0 && compare(getKey(getRight(root)), "50", 10) == 0 && compare(getKey(getLeft(root)), "11", 10) == 0)) { // Проверка удаления и правого поворота одновременно
        return false;
    }
    delete(&root, &root, "20");
    if (compare(getKey(root), "25", 1) != 0) { // Проверка удаления корня
        return false;
    }

    if ((compare(search(root, "25"), "25", 10) != 0)) { // Проверка поиска
        return false;
    }
    freeTree(&root);
    return true;
}