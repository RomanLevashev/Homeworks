#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

bool test(void);

void invert(char array[], int length) {
	for (int i = 0; i < length; ++i) {
		array[i] = array[i] == 0 ? 1 : 0;
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

void binaryInterpritation(int number, char binaryArray[], int size) {
	int moduleNumber = abs(number);
	int binaryCount = 0;
	
	for (int i = size - 1; i >= 0 && moduleNumber > 0; --i) {
		binaryArray[i] = moduleNumber % 2;
		moduleNumber /= 2;
		binaryCount++;
	}

	if (number < 0) {
		invert(binaryArray, size);
		plusOne(binaryArray,size);
	}
}

void binarySum(char firstBinary[], char secondBinary[], char resultBinary[], int size) {
	for (int i = size - 1, carry = 0; i >= 0; --i) {
		int temp = firstBinary[i] ^ secondBinary[i] ^ carry;
		resultBinary[i] = temp;

		carry = (firstBinary[i] && secondBinary[i]) || (carry && (firstBinary[i] ^ secondBinary[i]));
	}
}

int binaryToDecimal(char binary[], int size) {
	int result = 0;
	for (int i = size - 1, power = 0; i >= 0; --i, ++power) {
		result += binary[i] * pow(2, power);
	}
	return result;
}

void printArray(char array[], int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d", array[i]);
	}
	printf("\n");
}

int decimalSumByBinaries(int firstNumber, int secondNumber) {
	int size = sizeof(int) * 8;
	int sign = 1;
	char* firstBinary = calloc(size, 1);
	char* secondBinary = calloc(size, 1);
	char* sumBinary = calloc(size, 1);

	binaryInterpritation(firstNumber, firstBinary, size);
	binaryInterpritation(secondNumber, secondBinary, size);
	binarySum(firstBinary, secondBinary, sumBinary, size);
	if (sumBinary[0] == 1) {
		minusOne(sumBinary, size);
		invert(sumBinary, size);
		sign = -1;
	}

	return sign * binaryToDecimal(sumBinary, size);
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	int firstNumber = 0;
	int secondNumber = 0;
	int inputCount = 0;
	if (test()) {
		puts("Все тесты прошли успешно.");
	}
	else {
		puts("Тесты провалились");
		return 1;
	}

	do {
		printf("Введите два числа через пробел: ");
		inputCount = scanf("%d %d", &firstNumber, &secondNumber);

		if (inputCount != 2) {
			puts("Неправильный ввод. Пожалуйста, повторите.");
			while (getchar() != '\n');
		}
	} while (inputCount != 2);

	printf("Сумма = %d", decimalSumByBinaries(firstNumber, secondNumber));
	return 0;
}