#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void swap(int *left, int *right) {
	if (left != right) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

void countingSort(int array[], const int length) {
	int maximum = 0;
	for (int i = 0; i < length; ++i) {
		if (array[i] > maximum) {
			maximum = array[i];
		}
	}

	int* countNumbers = calloc(maximum + 1, sizeof(int));

	for (int i = 0; i < length; ++i) {
		countNumbers[array[i]]++;
	}

	for (int i = 0, j = 0; i < length; ++i) {
		while (j <= maximum && countNumbers[j] == 0) {
			j++;
		}
		array[i] = j;
		countNumbers[j]--;
	}
	free(countNumbers);
}

void bubbleSort(int array[], const int length) {
	for (int i = 1; i < length; ++i) {
		if (array[i] < array[i - 1]) {
			int j = i;
			while (j > 0 && array[j] < array[j - 1]) {
				swap(array + j - 1, array + j);
				j--;
			}
		}
	}
}

void printArray(int array[], const int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

bool testing(int array[], int length, void (*sort)(int*, int)) {
	sort(array, length);
	for (int i = 0; i < length - 1; ++i) {
		if (array[i] > array[i + 1]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[]) {
	const int length = 100000;
	int* array = NULL;
	int* copyArray = NULL;

	while (array == NULL) {
		array = calloc(length, sizeof(int));
	}

	while (copyArray == NULL) {
		copyArray = calloc(length, sizeof(int));
	}

	srand(time(NULL));

	for (int i = 0; i < length; ++i) {
		int temp = rand();
		array[i] = copyArray[i] = temp;
	}
	
	if (argc > 1 && strcmp(argv[1], "--test") == 0) {
		if (!testing(array, length, countingSort)) {
			free(array);
			free(copyArray);
			return 1;
		}
		if (!testing(copyArray, length, bubbleSort)) {
			free(array);
			free(copyArray);
			return 1;
		}
		free(array);
		free(copyArray);
		return 0;
	}


	clock_t beforeBubble = clock();
	bubbleSort(array, length);
	clock_t afterBubble = 0, beforeCounting = 0;
	afterBubble = beforeCounting = clock();
	printf("Count of ticks during bubble sort - %d\n", afterBubble-beforeBubble);
	
	countingSort(copyArray, length);
	clock_t afterCounting = clock();
	printf("Count of ticks during counting sort - %d\n", afterCounting-beforeCounting);
	
	printf("Difference in time between counting and bubble sort - %d\n", afterBubble - beforeBubble - afterCounting + beforeCounting);
	//printArray(array, length);
	//printArray(copyArray, length);

	free(array);
	free(copyArray);
	
	return 0;
}