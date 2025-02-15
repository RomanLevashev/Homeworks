#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "test.h"
#include "mostCommonElement.h"
#include "utils.h"

bool runTests(void) {
    int firstArray[20] = { 0, 2, 3, 4, 5, 5, 5, 7, 7, 5, 5, 7, 5, 5, 7, 7, 9, 1, 1, 1 };
    if (mostCommonElement(firstArray, 20) != 5) {
        puts("Test 1 failed.");
        return false;
    }

    int secondArray[21] = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6 };
    if (mostCommonElement(secondArray, 21) != 6) {
        puts("Test 2 failed.");
        return false;
    }

    int thirdArray[11] = { 2, 3, 4, 5, 3, 2, 2, 2, 2, 3, 3 };
    if (mostCommonElement(thirdArray, 11) != 2) {
        puts("Test 3 failed.");
        return false;
    }

    int fourthArray[15] = { -1, -3, -4, -5, -5, -5, 10, 29, 32, 10, 29, 29, 3, 3, 3 };
    if (mostCommonElement(fourthArray, 15) != -5) {
        puts("Test 4 failed");
        return false;
    }

    int unitArray[1] = { 9 };
    if (mostCommonElement(unitArray, 1) != 9) {
        puts("Test 5 failed");
        return false;
    }

    int realCount = 0;
    int* fileArray = getArrayFromFile("test.txt", &realCount);
    if (fileArray == NULL) {
        return false;
    }
    if (mostCommonElement(fileArray, realCount) != 62) {
        puts("Test 6 failed");
        free(fileArray);
        return false;
    }
    free(fileArray);
    return true;
}