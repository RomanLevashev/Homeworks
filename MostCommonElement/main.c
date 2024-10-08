#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* left, int* right) {
	if (left != right) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

int quickSort(int array[], int length) {
	if (length < 2) {
		return 0;
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
		quickSort(array, array + right - array);
		quickSort(array + right, array + length - (array + right));
		return 0;
	}
	else {
		quickSort(array + 1, length - 1);
	}
}

int mostCommonElement(int array[], int length) {
	quickSort(array, length);
	int count = 1;
	int max_count = 1;
	int commonElement = array[0];
	int last = array[0];

	for (int i = 1; i < length; ++i) {
		if (array[i] == last) {
			count += 1;
		}
		if (array[i] != last || i == length - 1) {
			if (count > max_count) {
				commonElement = last;
				max_count = count;
			}
			last = array[i];
			count = 1;
		}
	}
	return commonElement;
}

bool testing(void) {
	int first_array[20] = { 0, 2, 3, 4, 5, 5, 5, 7, 7, 5, 5, 7, 5, 5, 7, 7, 9, 1, 1, 1 };
	if (mostCommonElement(first_array, 20) != 5) {
		puts("Test 1 failed.");
		return false;
	}

	int second_array[21] = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6 };
	if (mostCommonElement(second_array, 21) != 6) {
		puts("Test 2 failed.");
		return false;
	}

	int third_array[11] = {2, 3, 4, 5, 3, 2, 2, 2, 2, 3, 3};
	if (mostCommonElement(third_array, 11) != 2) {
		puts("Test 3 failed.");
		return false;
	}
}

int main(void) {
	if (testing()) {
		puts("All test passed successfully");
	}
	return 0;
}