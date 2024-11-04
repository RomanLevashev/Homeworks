#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int fibonacciRec(int number) {
	if (number == 1 || number == 2) {
		return 1;
	}

	return fibonacciRec(number - 1) + fibonacciRec(number - 2);
}

int fibonacciIter(int number) {
	if (number <= 2) {
		return 1;
	}
	int pastPrevious = 1;
	int previous = 1;
	int current = 0;

	for (int i = 3; i <= number; ++i) {
		current = pastPrevious + previous;
		pastPrevious = previous;
		previous = current;
	}
	return current;
}

bool test() {
	if (fibonacciIter(7) == 13 && fibonacciRec(7) == 13) {
		puts("Test 1 complete");
	}
	else {
		puts("Test 1 failed");
		return false;
	}

	if (fibonacciIter(8) == 21 && fibonacciRec(8) == 21) {
		puts("Test 2 complete");
	}
	else {
		puts("Test 2 failed");
		return false;
	}

	if (fibonacciIter(9) == 34 && fibonacciRec(9) == 34) {
		puts("Test 3 complete");
	}
	else {
		puts("Test 3 failed");
		return false;
	}

	if (fibonacciIter(10) == 55 && fibonacciRec(10) == 55) {
		puts("Test 4 complete");
	}
	else {
		puts("Test 4 failed");
		return false;
	}

	return true;
}

int main(void) {
	if (!test()) {
		return 1;
	}

	for (int i = 1; i < 45; ++i) {
		clock_t timeBeforeRec = clock();
		fibonacciRec(i);
		clock_t timeAfterRec = clock();
		int recursiveTime = timeAfterRec - timeBeforeRec;

		clock_t timeBeforeIter = clock();
		fibonacciIter(i);
		clock_t timeAfterIter = clock();
		int iterTime = timeAfterIter - timeBeforeIter;

		printf("Difference in time between iterative and recursive at %d number - %d\n", i, abs(iterTime - recursiveTime));
	}
}