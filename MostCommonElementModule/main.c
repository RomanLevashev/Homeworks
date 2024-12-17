#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"

bool testing(void);

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

int main(void) {
	if (testing()) {
		puts("All test passed successfully");
	}
	else {
		return 1;
	}
	int n = 10;
	FILE* inputData = fopen("file.txt", "r");
	int* array = calloc(n, sizeof(int));
	int i = 0;

	while (fscanf(inputData, "%d ", &array[i]) == 1) {
		i++;
	}

	printf("%d", mostCommonElement(array, i + 1));

	return 0;
}