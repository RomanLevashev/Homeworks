#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "mostCommonElement.h"
#include "test.h"

int main(void) {
    if (runTests()) {
        puts("All test passed successfully");
    }
    else {
        return 1;
    }
    FILE* inputData = fopen("file.txt", "r");
    int maxCount = 10;
    int realCount = 0;

    int* array = getArrayFromFile(inputData, maxCount, &realCount);
    if (array == NULL) {
        return 2;
    }

    printf("%d", mostCommonElement(array, realCount));
    free(array);
    return 0;
}