#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int* left, int* right) {
	if (left != right) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

int insertionSort(int array[], int length) {
	for (int i = 1; i < length; ++i) {
		if (array[i] < array[i - 1]) {
			int j = i;
			while (j > 0 && array[j] < array[j - 1]) {
				swap(array + j, array + j - 1);
				j--;
			}
		}
	}
	return 0;
}

int smartQuickSort(int array[], int length) {
	if (length < 10) {
		return insertionSort(array, length);
	}

	int pivot = array[0];
	int left = 1;
	int right = length - 1;
	bool flagLeft = false;
	bool flagRight = false;

	while (left <= right) {
		if (array[left] >= pivot) {
			flagLeft = true;
		}
		else {
			left++;
		}

		if (array[right] < pivot) {
			flagRight = true;
		}
		else {
			right--;
		}

		if (flagLeft && flagRight) {
			swap(array + left, array + right);
			flagLeft = flagRight = false;
			left++;
			right--;
		}
	}
	if (array[0] > array[right]) {
		swap(array, array + right);
		smartQuickSort(array, array + right - array);
		smartQuickSort(array + right, array + length - (array + right));
		return 0;
	}
	else {
		smartQuickSort(array+1, length-1);
	}
}

void printArray(int array[], int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

bool test() {
	int array[20] = {0, 9, 0, 0, 5, 8, 4, 3, 1, 2, 13, 13, 14, 15, 16, 17, 20, 18, 19};
	int length = 20;

	for (int i = 0; i < length - 1; ++i) {
		if (array[i] > array[i] + 1) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int length = 20;
	int *array = calloc(length, sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < length; ++i) {
		array[i] = rand();
	}

	printArray(array, length);
	smartQuickSort(array, length);
	printArray(array, length);
	if (test) {
		puts("Test complete.");
	}
	free(array);
	return 0;
}