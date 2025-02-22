#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void swap(int* left, int* right) {
	if (left != right) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

void qSort(int array[], int length) {
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
	}
}

void printArray(int array[], int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

bool test() {
	int array[20] = {0};
	int length = 20;

	for (int i = 0; i < 20; ++i) {
		array[i] = rand();
	}

	int pivot = array[0];
	qSort(array, 20);
	bool needMore = false;

	for (int i = 0; i < length; ++i) {
		if (array[i] == pivot) {
			needMore = true;
		}

		if (needMore) {
			if (array[i] < pivot) {
				return false;
			}
		}

		else {
			if (array[i] > pivot) {
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char* argv[]) {
	if (!test()) {
		return 1;
	}

	if (argc > 1 && strcmp(argv[1], "--test") == 0) {
		return 0;
	}
	srand(time(NULL));
	int array[20] = { 0 };

	for (int i = 0; i < 20; ++i) {
		array[i] = rand();
	}

	printArray(array, 20);
	qSort(array, 20);
	printArray(array, 20);
	return 0;
}