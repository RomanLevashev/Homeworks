#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "mostCommonElement.h"
#include "test.h"

int main(void) {
	if (runTests()) {
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
	free(array);
	return 0;
}