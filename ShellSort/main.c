#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void shellSort(int array[], int length) {
	int j = 0;
	for (int step = length / 2; step > 0; step /= 2) {
		for (int i = step; i < length; ++i) {
			int element = array[i];

			for (j = i; j >= step; j -= step) {
				if (element < array[j - step]) {
					array[j] = array[j - step];
				}
				else {
					break;
				}
			}
			array[j] = element;
		}
	}
}

void printArray(int array[], int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

bool testing(void) {
	int length = 15;
	int firstArray[15] = {9, 0, 3, 1, 4, 6, 8, 15, 100, 20, 1, 10000};
	int secondArray[15] = {1, 2, 9, 3, 7, 15, 29, 30, 1999, 2789, 1, 12097398};
	int thirdArray[15] = {0, 15555, 1290390, 123970, 791221, 10202, 2822882, 123902, 91863291};
	shellSort(firstArray, length);
	shellSort(secondArray, length);
	shellSort(thirdArray, length);

	for (int i = 0; i < length-1; ++i) {
		if (firstArray[i] > firstArray[i + 1] || secondArray[i] > secondArray[i + 1] || thirdArray[i] > thirdArray[i + 1]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[]) {
	if (!testing()) {
		return 1;
	}

	if (argc > 1 && strcmp(argv[1], "--test") == 0) {
		return 0;
	}

	int length = 20;
	int* array = calloc(length, sizeof(int));
	srand(time(NULL));

	while (array == NULL) {
		array = calloc(length, sizeof(int));
	}

	for (int i = 0; i < length; ++i) {
		array[i] = rand();
	}

	for (int i = 0; i < length; ++i) {
		array[i] = rand();
	}

	printArray(array, length);
	shellSort(array, length);
	printArray(array, length);
	free(array);

	return 0;
}