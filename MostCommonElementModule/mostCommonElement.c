#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "mostCommonElement.h"

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
		return 0;
	}
	else {
		quickSort(array + 1, length - 1);
		return 0;
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
			count++;
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