#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int* getArrayFromFile(char fileName[], int* realCount) {
    int count = 0;
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return NULL;
    }
    while (fscanf(file, "%*d ") != EOF) {
        count++;
    }
    fseek(file, 0, SEEK_SET);
    int* array = calloc(count, sizeof(int));
    if (array == NULL) {
        perror("Ошибка выделения памяти");
        fclose(file);
        return NULL;
    }
    int i = 0;

    while (fscanf(file, "%d ", &array[i]) == 1) {
        i++;
        (*realCount)++;
    }
    fclose(file);
    return array;
}