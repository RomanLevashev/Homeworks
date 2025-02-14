#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include "test.h"
#include "binaryRepresentation.h"

void printArray(char array[], int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d", array[i]);
	}
	printf("\n");
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	int size = sizeof(int) * 8;
	int firstNumber = 0;
	int secondNumber = 0;
	int inputCount = 0;
	if (!runTests()) {
		puts("Тесты провалились");
		return 1;
	}
	puts("Все тесты прошли успешно");
	
	do {
		printf("Введите два числа через пробел: ");
		inputCount = scanf("%d %d", &firstNumber, &secondNumber);

		if (inputCount != 2) {
			puts("Неправильный ввод. Пожалуйста, повторите.");
			while (getchar() != '\n');
		}
	} while (inputCount != 2);

	int* sumBinary = getSumArrayByBinaries(firstNumber, secondNumber);
	if (sumBinary == NULL) {
		return -1;
	}
	int* firstBinary = calloc(1, size);
	if (firstBinary == NULL) {
		perror("Ошибка выделения памяти");
		free(sumBinary);
	}

	int* secondBinary = calloc(1, size);
	if (secondBinary == NULL) {
		perror("Ошибка выделения памяти");
		free(sumBinary);
		free(firstBinary);
	}

	getBinaryInterpritation(firstNumber, firstBinary, size);
	getBinaryInterpritation(secondNumber, secondBinary, size);
	printArray(firstBinary, size);
	printArray(secondBinary, size);
	printArray(sumBinary, size);
	printf("Сумма = %d", convertBinaryToDecimal(sumBinary, size));
	free(sumBinary);
	free(firstBinary);
	free(secondBinary);
	return 0;
}