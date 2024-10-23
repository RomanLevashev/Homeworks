#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

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
		else {
			array[i] = 1;
		}
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
		moduleNumber = floor((double)moduleNumber / 2.0);
		binaryCount++;
	}

	if (number < 0) {
		invert(binaryArray, size);
		plusOne(binaryArray,size);
	}
}

void binarySum(char firstBinary[], char secondBinary[], char resultBinary[], int size) {
	for (int i = size - 1, remainder = 0; i >= 0; --i) {
		int temp = firstBinary[i] + secondBinary[i];
		if (temp == 2) {
			if (remainder == 1) {
				resultBinary[i] = 1;
			}
			else {
				resultBinary[i] = 0;
				remainder = 1;
			}
		}
		if (temp == 1) {
			if (remainder == 1) {
				resultBinary[i] = 0;
			}
			else {
				resultBinary[i] = 1;
			}
		}
		if (temp == 0) {
			if (remainder == 1) {
				resultBinary[i] = 1;
				remainder--;
			}
		}
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
	int size = 32;
	int sign = 1;
	char firstBinary[32] = { 0 };
	char secondBinary[32] = { 0 };
	char sumBinary[32] = { 0 };

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

bool testing(void) {
	if (decimalSumByBinaries(-1, 1) != 0) {
		return false;
	}
	if (decimalSumByBinaries(0, 928) != 928) {
		return false;
	}
	if (decimalSumByBinaries(238, -195) != 43) {
		return false;
	}
	if (decimalSumByBinaries(-1928, -5137) != -7065) {
		return false;
	}
	if (decimalSumByBinaries(8921, 9122) != 18043) {
		return false;
	}
	return true;
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	int firstNumber = 0, secondNumber = 0;
	int inputCount = 0;
	if (testing()) {
		puts("Все тесты прошли успешно.");
	}
	else {
		return 9;
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