#include <stdio.h>
#include <stdbool.h>
#include <string.h>

double linearExponentiation(int digit, int degree) {
	if (degree == 0) {
		return 1;
	}
	if (degree < 0) {
		return (double)1 / (double)linearExponentiation(digit, -degree);
	}
	int originalNumber = digit;

	for (int i = 1; i < degree; ++i) {
		digit *= originalNumber;
	}
	return digit;
}


double logarifmicExponentiation(int digit, int degree) {
	if (degree == 0) {
		return 1;
	}

	if (degree < 0) {
		return (double)1 / (double)logarifmicExponentiation(digit, -degree);
	}

	if (digit < 0) {
		return degree % 2 == 0 ? logarifmicExponentiation(-digit, degree) : -logarifmicExponentiation(-digit, degree);
	}

	double temp = degree % 2 == 1 ? linearExponentiation(digit, (degree - 1) / 2): linearExponentiation(digit, degree / 2);
	return degree % 2 == 1? temp * temp * digit: temp * temp;
}


bool testing(void) {
	if (logarifmicExponentiation(2, 9) != 512 || linearExponentiation(2, 9) != 512) {
		return false;
	}

	if (logarifmicExponentiation(2, -3) != 0.125 || linearExponentiation(2, -3) != 0.125) {
		return false;
	}

	if (logarifmicExponentiation(-2, 9) != -512 || linearExponentiation(-2, 9) != -512) {
		return false;
	}

	if (logarifmicExponentiation(-2, 8) != 256 || linearExponentiation(-2, 8) != 256) {
		return false;
	}

	if (logarifmicExponentiation(-2, -3) != -0.125 || linearExponentiation(-2, -3) != -0.125) {
		return false;
	}

}


int main(int argc, char* argv[]) {
	if (!testing()) {
		return 1;
	}
	if (argc > 1 && strcmp(argv[1], "--test") == 0) {
		return 0;
	}
	double a = logarifmicExponentiation(2, -3);
	printf("%.2f", a);
	return 0;
}