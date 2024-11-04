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

void insertionSort(int array[], int length) {
	for (int i = 1; i < length; ++i) {
		if (array[i] < array[i - 1]) {
			int j = i;
			while (j > 0 && array[j] < array[j - 1]) {
				swap(array + j, array + j - 1);
				j--;
			}
		}
	}
}

void smartQuickSort(int array[], int length) {
	if (length < 10) {
		insertionSort(array, length);
		return;
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
			flagLeft = false;
			flagRight = false;
			left++;
			right--;
		}
	}
	if (array[0] > array[right]) {
		swap(array, array + right);
		smartQuickSort(array, array + right - array);
		smartQuickSort(array + right, array + length - (array + right));
	}
	else {
		smartQuickSort(array+1, length-1);
	}
	return;
}

void printArray(int array[], int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

bool orderTest(int array[], const int length) {
	for (int i = 0; i < length - 1; ++i) {
		if (array[i] > array[i] + 1) {
			return false;
		}
	}
	return true;
}

bool test() {
	const int length = 20;
	int firstArray[20] = {0, 9, 0, 0, 5, 8, 4, 3, 1, 2, 13, 13, 14, 15, 16, 17, 20, 18, 19};
	int secondArray[3] = {91, 7, 3};
	int thirdArray[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

	if (!orderTest(firstArray, length)) {
		puts("First test failed");
		return false;
	}
	if (!orderTest(secondArray, 3)) {
		puts("Second test failed");
		return false;
	}
	if (!orderTest(thirdArray, length)) {
		puts("Third test failed");
		return false;
	}
	return true;
}

int main(void) {
	const int length = 20;
	int *array = calloc(length, sizeof(int));
	srand(time(NULL));

	if (array == NULL) {
		return 1;
	}

	for (int i = 0; i < length; ++i) {
		array[i] = rand();
	}

	printArray(array, length);
	smartQuickSort(array, length);
	printArray(array, length);
	if (test()) {
		puts("All tests complete.");
	}
	else {
		return 2;
	}
	free(array);
	return 0;
}