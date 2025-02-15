#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "mostCommonElement.h"
#include "test.h"
#include "utils.h"

int main(void) {
    if (runTests()) {
        puts("All test passed successfully");
    }
    else {
        return 1;
    }
    int realCount = 0;

    int* array = getArrayFromFile("file.txt", &realCount);
    if (array == NULL) {
        return 2;
    }

    printf("%d", mostCommonElement(array, realCount));
    free(array);
    return 0;
}