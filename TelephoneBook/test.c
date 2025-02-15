#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "telephonebook.h"

bool isDigit(char* str) {
    int i = 0;
    char current = str[i];
    while (current != 0) {
        if (current <= '9' && current >= '0') {
            ++i;
            current = str[i];
        }
        else {
            return false;
        }
    }
    return true;
}

int lenDigit(char* str) {
    int i = 0;
    int length = 0;
    while (str[i] == '0') {
        ++i;
    }
    while (str[i] != '\0') {
        ++length;
        ++i;
    }
    return length;
}

bool runTests(void) {
    int length = 100;
    FILE* file = fopen("test.txt", "r");
    char firstName[100] = "John";
    char secondName[100] = "Alice";
    char thirdName[100] = "Bob";
    char fourthName[100] = "Charlie";
    char fifthName[100] = "Diana";
    char sixthName[100] = "Eve";
    char firstPhone[100] = "1111111111";
    char secondPhone[100] = "1234567890";
    char thirdPhone[100] = "9876543210";
    char fourthPhone[100] = "1928374655";
    char fifthPhone[100] = "5566778899";
    char sixthPhone[100] = "1122334455";
    char* result = NULL;

    result = findPhone(firstName, length, file);
    if (strncmp(result, firstPhone, length) != 0) {
        free(result);
        fclose(file);
        return false;
    }
    free(result);

    result = findName(secondPhone, length, file);
    if (strncmp(result, secondName, length) != 0) {
        free(result);
        fclose(file);
        return false;
    }
    free(result);

    result = findPhone(fourthName, length, file);
    if (strncmp(result, fourthPhone, length) != 0) {
        free(result);
        fclose(file);
        return false;
    }
    free(result);

    result = findName(thirdPhone, length, file);
    if (strncmp(result, thirdName, length) != 0) {
        free(result);
        fclose(file);
        return false;
    }
    free(result);

    result = findPhone(fifthName, length, file);
    if (strncmp(result, fifthPhone, length) != 0) {
        free(result);
        fclose(file);
        return false;
    }
    free(result);

    result = findName(sixthPhone, length, file);
    if (strncmp(findName(sixthPhone, length, file), sixthName, length) != 0) {
        free(result);
        fclose(file);
        return false;
    }
    free(result);
    fclose(file);
    return true;
}