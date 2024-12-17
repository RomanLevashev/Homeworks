#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isDigit(char* str) {
    int i = 0;
    char current = str[i];
    while (current != 0) {
        if (current <= 57 && current >= 48) {
            i += 1;
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
    char current = str[i];
    int length = 0;
    while (current == '0') {
        i += 1;
        current = str[i];
    }
    while (current != 0) {
        length += 1;
        i += 1;
        current = str[i];
    }
    return length;
}

int compare(char* first, char* second, const int length) {
    if (isDigit(first) && isDigit(second)) {
        if (lenDigit(first) > lenDigit(second)) {
            return 1;
        }
        if (lenDigit(first) < lenDigit(second)) {
            return -1;
        }
    }
    for (int i = 0; i < length; ++i) {
        int firstElement = first[i];
        int secondElement = second[i];

        if (firstElement == 0) {
            if ((secondElement != 0 && secondElement != '\n' && secondElement != ' ')) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if (secondElement == 0) {
            if ((firstElement != 0 && firstElement != '\n' && firstElement != ' ')) {
                return -1;
            }
            else {
                return 0;
            }
        }

        if (firstElement > secondElement) {
            return 1;
        }
        if (firstElement < secondElement) {
            return -1;
        }
    }
    return 0;
}


// Взял кейсы из файла, но переделал их под функции, чтобы протестировать

void addTest(FILE* file, char* inputName, char* inputPhone) {
    char name[100] = { 0 };
    strncpy(name, inputName, 100);
    fseek(file, 0, SEEK_END);
    char phone[100] = { 0 };
    strncpy(phone, inputPhone, 100);
    fprintf(file, "%s %s\n", name, phone);
}

char* findPhoneTest(FILE* file, char* name) {
    FILE* fileOutput = freopen("output.txt", "w", stdout);
    fseek(file, 0, SEEK_SET);
    char* pointer = NULL;
    char line[256] = { 0 };
    int count = 0;
    char* fgetsResult = NULL;

    do {
        fgetsResult = fgets(line, sizeof(line) - 1, file);
        line[strcspn(line, "\n")] = '\0';
        pointer = strstr(line, name);
        if (pointer == NULL) {
            memset(line, 0, 256);
        }
        else {
            int i = 0;
            while (!isdigit(pointer[i]) && pointer[i] != 0) {
                i++;
            }
            while (pointer[i] != 0) {
                putc(pointer[i++], stdout);
                count++;
            }
            printf("\n");
            pointer = NULL;
            memset(line, 0, 256);
        }
    } while (pointer == NULL && fgetsResult != NULL);

    if (count < 1) {
        return NULL;
    }
    fclose(fileOutput);
    fileOutput = fopen("output.txt", "r");
    char result[100] = { 0 };
    fgets(result, 100, fileOutput);
    fclose(fileOutput);
    return result;
}

char* findNameTest(FILE* file, char* phone) {
    FILE* fileOutput = freopen("output.txt", "w", stdout);
    fseek(file, 0, SEEK_SET);
    char* pointer = NULL;
    char line[256] = { 0 };
    int count = 0;
    char* fgetsResult = NULL;

    do {
        fgetsResult = fgets(line, sizeof(line) - 1, file);
        line[strcspn(line, "\n")] = '\0';
        pointer = strstr(line, phone);
        if (pointer == NULL) {
            memset(line, 0, 256);
        }
        else {
            int i = 0;
            while (!isdigit(line[i]) && line[i] != 0) {
                putc(line[i++], stdout);
                count++;
            }
            printf("\n");
            pointer = NULL;
            memset(line, 0, 256);
        }
    } while (pointer == NULL && fgetsResult != NULL);

    if (count < 1) {
        return NULL;
    }
    fclose(fileOutput);
    fileOutput = fopen("output.txt", "r");
    char result[100] = { 0 };
    fgets(result, 100, fileOutput);
    fclose(fileOutput);
    return result;
}

bool test(void) {
    int length = 100;
    FILE* file = fopen("test.txt", "a+");
    char* firstName = "John";
    char* secondName = "Alice";
    char* thirdName = "Bob";
    char* fourthName = "Charlie";
    char* fifthName = "Diana";
    char* sixthName = "Eve";
    char* firstPhone = "1111111111";
    char* secondPhone = "1234567890";
    char* thirdPhone = "9876543210";
    char* fourthPhone = "1928374655";
    char* fifthPhone = "5566778899";
    char* sixthPhone = "1122334455";
    addTest(file, firstName, firstPhone);
    addTest(file, secondName, secondPhone);
    if (compare(findPhoneTest(file, firstName), firstPhone, length) != 0) {
        return false;
    }
    if (compare(findNameTest(file, secondPhone), secondName, length) != 0) {
        return false;
    }
    addTest(file, thirdName, thirdPhone);
    addTest(file, fourthName, fourthPhone);
    if (compare(findPhoneTest(file, fourthName), fourthPhone, length) != 0) {
        return false;
    }
    if (compare(findNameTest(file, thirdPhone), thirdName, length) != 0) {
        return false;
    }
    addTest(file, fifthName, fifthPhone);
    addTest(file, sixthName, sixthPhone);
    if (compare(findPhoneTest(file, fifthName), fifthPhone, length) != 0) {
        return false;
    }
    if (compare(findNameTest(file, sixthPhone), sixthName, length) != 0) {
        return false;
    }
    return true;
    fclose(file);
}