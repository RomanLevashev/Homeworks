#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool runTests(void);

int pow2(int n) {
    return 1 << n;
}

void binaryToDecimal(char* binary, char* decimal) {
    int decimalNumber = 0;
    int length = strlen(binary);

    for (int i = length - 1, degree = 0; i >= 0; --i) {
        if (binary[i] == '1') {
            decimalNumber += pow2(degree);
        }
        if (binary[i] == '0' || binary[i] == '1') {
            degree++;
        }
    }
    sprintf(decimal, "%d", decimalNumber);
}

int main(void) {
    if (!runTests()) {
        puts("Tests failed");
    }
    puts("Tests passed");
    int maxLength = 100;
    char* binary = calloc(maxLength * 3, 1);
    char* decimal = calloc(maxLength, 1);
    if (binary == NULL || decimal == NULL) {
        puts("Memory allocate error.");
        return 1;
    }

    puts("Enter a binary number");
    fgets(binary, (maxLength*3)-1, stdin);

    binaryToDecimal(binary, decimal);
    printf("In Decimal %s", decimal);
    free(binary);
    free(decimal);
    return 0;
}