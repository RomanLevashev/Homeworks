#include <stdbool.h>
#include <math.h>
#include <stdio.h>


void arraySwap(int array[], int start, int end) {
	for (int i = 0; remainder(end - start + 1, 2) == 1 ? i <= (end - start + 1) / 2 : i <= (end - start + 1) / 2 - 1; ++i) {
		
		if (start + i != end - i) {
			array[start + i] ^= array[end - i];
			array[end - i] ^= array[start + i];
			array[start + i] ^= array[end - i];
		}
	}

}


bool test(void) {
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int wantedArray[10] = {4, 5, 6, 7, 8, 9, 0, 1, 2, 3};
	int m = 4;
	int n = 6;
	arraySwap(array, 0, m - 1);
	arraySwap(array, m, m + n - 1);
	arraySwap(array, 0, m + n - 1);

	for (int i = 0; i <= 9; ++i) {
		if (array[i] != wantedArray[i]) {
			printf("Test failed\n");
			return false;
		}
	}
	printf("Test complete\n");
	return true;
}

int main(void) {
	int array[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	int m = 5;
	int n = 10;
	arraySwap(array, 0, m - 1);
	arraySwap(array, m, m + n - 1);
	arraySwap(array, 0, m + n - 1);

	for (int i = 0; i <= 14; ++i) {
		printf("%d ", array[i]);
	}
	// test();
}