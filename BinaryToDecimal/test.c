#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void binaryToDecimal(char* binary, char* decimal);

bool runTests(void) {
    char firstBinary[] = "11100010010110011001";
    char secondBinary[] = "110101010000111";
    char thirdBinary[] = "0";
    char decimal[10] = {0};
    binaryToDecimal(firstBinary, decimal);
    if (strcmp(decimal, "927129") != 0) {
        return false;
    }
    memset(decimal, 0, 10);

    binaryToDecimal(secondBinary, decimal);
    if (strcmp(decimal, "27271") != 0) {
        return false;
    }
    memset(decimal, 0, 10);
    binaryToDecimal(thirdBinary, decimal);
    if (strcmp(decimal, "0") != 0) {
        return false;
    }
    memset(decimal, 0, 10);

    return true;
}