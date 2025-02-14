#pragma once

// Возвращает массив двоичного представления числа в дополнительном коде
int* getSumArrayByBinaries(int firstNumber, int secondNumber);

// Переводит число из двоичного дополнительного кода в десятичный и возвращает результат
int convertBinaryToDecimal(char binary[], int size);

// Заполняет переданный массив двоичным представлением переданного числа в дополнительном коде
void getBinaryInterpritation(int number, char binaryArray[], int size);
