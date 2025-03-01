#include <stdbool.h>
#include "binaryRepresentation.h"
#include <stdlib.h>

int getSumForTest(int first, int second) {
    int* sumBinary = getSumArrayByBinaries(first, second);
    int sum = 0;
    if (sumBinary == NULL) {
        sum = INT_MAX;
    }
    else {
        sum = convertBinaryToDecimal(sumBinary, sizeof(int) * 8);
    }
    free(sumBinary);
    return sum;
}

bool runTests(void) {
    if (getSumForTest(-1, 1) != 0) {
        return false;
    }
    if (getSumForTest(0, 928) != 928) {
        return false;
    }
    if (getSumForTest(238, -195) != 43) {
        return false;
    }
    if (getSumForTest(-1928, -5137) != -7065) {
        return false;
    }
    if (getSumForTest(123, 456) != 579) {
        return false;
    }
    if (getSumForTest(789, 321) != 1110) {
        return false;
    }
    if (getSumForTest(2048, 4096) != 6144) {
        return false;
    }
    if (getSumForTest(65535, 1) != 65536) {
        return false;
    }
    if (getSumForTest(0, 0) != 0) {
        return false;
    }
    if (getSumForTest(100000, 200000) != 300000) {
        return false;
    }
    if (getSumForTest(32768, 32768) != 65536) {
        return false;
    }
    if (getSumForTest(99999, 1) != 100000) {
        return false;
    }
    if (getSumForTest(42, 58) != 100) {
        return false;
    }
    return true;
}
