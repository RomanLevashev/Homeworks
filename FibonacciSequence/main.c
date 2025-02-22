#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>

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
	if (fibonacciIter(7) != 13 || fibonacciRec(7) != 13) {
		return false;
	}

	if (fibonacciIter(8) != 21 || fibonacciRec(8) != 21) {
		return false;
	}

	if (fibonacciIter(9) != 34 || fibonacciRec(9) != 34) {
		return false;
	}

	if (fibonacciIter(10) != 55 || fibonacciRec(10) != 55) {
		return false;
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