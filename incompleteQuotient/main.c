#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int incompleteQuotient(int dividend, int divisor) {
	if (dividend == 0) {
		return 0;
	}
	if (divisor == 0) {
		printf("Can't divide by zero\n");
		return 0;
	}

	int quotientSign = dividend * divisor > 0 ? 1 : -1;
	int multiplier = 1;

	while (dividend < 0 ? quotientSign * divisor * multiplier >= dividend : quotientSign * divisor * multiplier <= dividend) {
		int resultMultiply = quotientSign * divisor * multiplier;
		if (resultMultiply == dividend) {
			return quotientSign * multiplier;
		}
		multiplier++;

	}
	if (dividend > 0) {
		multiplier--;
	}

	int quotient = multiplier * quotientSign;


	return quotient;
}

bool testing() {
	if (incompleteQuotient(78, 33) != 2) {
		return false;
	}

	if (incompleteQuotient(-78, 33) != -3) {
		return false;
	}

	if (incompleteQuotient(-9, -13) != 1) {
		return false;
	}

	if (incompleteQuotient(9, 90) != 0) {
		return false;
	}

	if (incompleteQuotient(78, 26) != 3) {
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

	int dividend = 0, divisor = 0;
	printf("Enter dividend and divisor through a space: ");
	scanf("%d %d", &dividend, &divisor);
	printf("%d", incompleteQuotient(dividend, divisor));
	
	return 0;
}