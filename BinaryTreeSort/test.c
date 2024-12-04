#include <stdbool.h>
#include "tree.h"

bool isSorted(int* array, const int length) {
    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }   
    }
    return true;
}

bool runTests() {
    int singleElement[] = { 42 };
    const int singleSize = 1;
    if (!isSorted(singleElement, singleSize)) {
        return false;
    }
    int sortedArray[] = { 1, 2, 3, 4, 5 };
    const int sortedSize = 5;
    if (!isSorted(sortedArray, sortedSize)) {
        return false;
    }
    int unsortedArray[] = { 5, 3, 2, 4, 1 };
    const int unsortedSize = 5;
    treeSort(unsortedArray, unsortedSize);
    if (!isSorted(unsortedArray, unsortedSize)) {
        return false;
    }
    int duplicateArray[] = { 5, 3, 8, 5, 2, 7, 3 };
    const int duplicateSize = 7;
    treeSort(duplicateArray, duplicateSize);
    if (!isSorted(duplicateArray, duplicateSize)) {
        return false;
    }

    int largeArray[] = { 20, 15, 30, 10, 25, 5, 35, 90, 1278, 22, 178, 17298, 181, 8920, 871238, 881, 78111, 72, 108 };
    int largeSize = 19;
    treeSort(largeArray, largeSize);
    if (!isSorted(largeArray, largeSize)) {
        return false;
    }
    return true;
}