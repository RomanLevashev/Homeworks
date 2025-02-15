#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* findPhone(char* name, int maxLength, FILE* file) {
    char* result = calloc(maxLength, 1);
    if (result == NULL) {
        perror("Ошибка выделения памяти");
        return NULL;
    }
    int resultIndex = 0;
    char* pointer = NULL;
    char* line = calloc(maxLength*2 + 3, 1);
    if (line == NULL) {
        free(result);
        perror("Ошибка выделения памяти");
        return NULL;
    }
    char* fgetsResult = NULL;
    fseek(file, 0, SEEK_SET);
    if (strcspn(name, "\n") != maxLength) {
        name[strcspn(name, "\n")] = '\0';
    }

    do {
        fgetsResult = fgets(line, maxLength * 2 + 3, file);
        line[strcspn(line, "\n")] = '\0';
        pointer = strstr(line, name);
        if (pointer == NULL) {
            memset(line, 0, sizeof(line));
        }
        else {
            int i = 0;
            while (pointer[i] != 0 && !isdigit(pointer[i])) {
                i++;
            }
            while (pointer[i] != 0) {
                result[resultIndex++] = pointer[i++];
            }
            break;
        }
    } while (fgetsResult != NULL);

    free(line);
    return result;
}

char* findName(char* phone, int maxLength, FILE* file) {
    char* result = calloc(maxLength, 1);
    if (result == NULL) {
        perror("Ошибка выделения памяти");
        return NULL;
    }
    int resultIndex = 0;
    char* pointer = NULL;
    char* line = calloc(maxLength * 2 + 3, 1);
    if (line == NULL) {
        perror("Ошибка выделения памяти");
        free(result);
        return NULL;
    }
    char* fgetsResult = NULL;

    fseek(file, 0, SEEK_SET);
    if (strcspn(phone, "\n") != maxLength) {
        phone[strcspn(phone, "\n")] = '\0';
    }
    do {
        fgetsResult = fgets(line, maxLength * 2 + 3, file);
        line[strcspn(line, "\n")] = '\0';
        pointer = strstr(line, phone);
        if (pointer == NULL) {
            memset(line, 0, sizeof(line));
        }
        else {
            int i = 0;
            while (line[i] != 0 && !isdigit(line[i]) && line[i] != ' ') {
                result[resultIndex++] = line[i++];
            }
            break;
        }
    } while (fgetsResult != NULL);

    free(line);
    return result;
}