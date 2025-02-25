#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(int* left, int* right) {
	if (left != right) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

void quickSort(int array[], int length) {
	if (length < 2) {
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
		quickSort(array, array + right - array);
		quickSort(array + right, array + length - (array + right));
	}
	else {
		quickSort(array + 1, length - 1);
	}
	return;
}

bool inArray(int array[], int length, int searchingElement) {
	int left = 0;
	int right = length - 1;

	while (left <= right) {
		int middle = (left + right) / 2;
		if (array[middle] == searchingElement) {
			return true;
		}
		
		if (array[middle] > searchingElement) {
			right = middle - 1;
		}

		if (array[middle] < searchingElement) {
			left = middle + 1;
		}
	}
	return false;
}

void printArray(int array[], int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

bool testing() {
	const int length = 20;
	int array[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -7, -1, - 30, -5, -229, -137};
	quickSort(array, length);
	
	if (!inArray(array, length, 0)) {
		return false;
	}
	if (!inArray(array, length, 9)) {
		return false;
	}

	if (!inArray(array, length, 2)) {
		return false;
	}

	if (!inArray(array, length, -30)) {
		return false;
	}

	if (!inArray(array, length, -229)) {
		return false;
	}

	if (!inArray(array, length, -7)) {
		return false;
	}
	return true;
}

void search(int n, int nArray[], int k, int kArray[]) {
	quickSort(nArray, n);
	printf("nArray: ");
	printArray(nArray, n);
	printf("kArray: ");
	printArray(kArray, k);

	for (int i = 0; i < k; ++i) {
		if (inArray(nArray, n, kArray[i])) {
			printf("%d in nArray\n", kArray[i]);
		}
		else {
			printf("%d not in nArray\n", kArray[i]);
		}
	}
}

int main(int argc, char* argv[]) {
	if (!testing()) {
		return 1;
	}

	if (argc > 1 && strcmp(argv[1], "--test") == 0) {
		return 0;
	}

	srand(time(NULL));
	int n = 0;
	int k = 0;
	int inputCount = 0;

	while (n < 1 || k < 1) {
		do {
			printf("Enter n and k through a space: ");
			inputCount = scanf("%d %d", &n, &k);

			if (inputCount != 2) {
				puts("Invalid input. Please try again.");
				while (getchar() != '\n');
			}
		} while (inputCount != 2);
	}

	int* nArray = calloc(n, sizeof(int));
	int* kArray = calloc(k, sizeof(int));

	for (int i = 0; i < n; ++i) {
		nArray[i] = rand() % 10;
	}
	for (int i = 0; i < k; ++i) {
		kArray[i] = rand() % 10;
	}
	search(n, nArray, k, kArray);
	free(nArray);
	free(kArray);

	return 0;
}