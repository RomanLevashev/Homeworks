#include <stdlib.h>
#include "binaryRepresentation.h"

void invert(char array[], int length) {
    for (int i = 0; i < length; ++i) {
        array[i] = array[i] == '\0' ? '\1' : '\0';
    }
}

void minusOne(char array[], int length) {
    for (int i = length - 1; i >= 0; --i) {
        if (array[i] == 1) {
            array[i] = 0;
            break;
        }
        array[i] = 1;
    }
}

void plusOne(char array[], int length) {
    for (int i = length - 1; i >= 0; --i) {
        if (array[i] == 0) {
            array[i] = 1;
            break;
        }
        array[i] = 0;
    }
}

void getBinaryInterpritation(int number, char binaryArray[], int size) {
    for (int i = 0; i < size; ++i) {
        binaryArray[size - 1 - i] = (number >> i) & 1;
    }
}

void binarySum(char firstBinary[], char secondBinary[], char resultBinary[], int size) {
    for (int i = size - 1, carry = 0; i >= 0; --i) {
        int temp = firstBinary[i] ^ secondBinary[i] ^ carry;
        resultBinary[i] = temp;

        carry = (firstBinary[i] && secondBinary[i]) || (carry && (firstBinary[i] ^ secondBinary[i]));
    }
}

int convertBinaryToDecimal(char binary[], int size) {
    int sign = 1;
    if (binary[0] == 1) {
        minusOne(binary, size);
        invert(binary, size);
        sign = -1;
    }
    int result = 0;
    int powerValue = 1;
    for (int i = size - 1, power = 0; i >= 0; --i, ++power) {
        result += binary[i] * powerValue;
        powerValue *= 2;
    }
    return sign * result;
}

int* getSumArrayByBinaries(int firstNumber, int secondNumber) {
    int size = sizeof(int) * 8;
    int sign = 1;
    char* firstBinary = calloc(size, 1);
    if (firstBinary == NULL) {
        perror("Ошибка выделения памяти");
        return NULL;
    }
    char* secondBinary = calloc(size, 1);
    if (secondBinary == NULL) {
        perror("Ошибка выделения памяти");
        free(firstBinary);
        return NULL;
    }
    char* sumBinary = calloc(size, 1);
    if (sumBinary == NULL) {
        perror("Ошибка выделения памяти");
        free(firstBinary);
        free(secondBinary);
        return NULL;
    }

    getBinaryInterpritation(firstNumber, firstBinary, size);
    getBinaryInterpritation(secondNumber, secondBinary, size);
    binarySum(firstBinary, secondBinary, sumBinary, size);

    free(firstBinary);
    free(secondBinary);

    return sumBinary;
}