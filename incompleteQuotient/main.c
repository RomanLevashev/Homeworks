#include <stdio.h>
#include <stdbool.h>
#include <math.h>


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

void testing() {
	if (incompleteQuotient(78, 33) == 2) {
		printf("Test 1 complete\n");
	}
	else {
		printf("Test 1 failed\n");
		return false;
	}

	if (incompleteQuotient(-78, 33) == -3) {
		printf("Test 2 complete\n");
	}
	else {
		printf("Test 2 failed\n");
		return false;
	}

	if (incompleteQuotient(-9, -13) == 1) {
		printf("Test 3 complete\n");
	}
	else {
		printf("Test 3 failed\n");
		return false;
	}

	if (incompleteQuotient(9, 90) == 0) {
		printf("Test 4 complete\n");
	}
	else {
		printf("Test 4 failed\n");
		return false;
	}

	if (incompleteQuotient(78, 26) == 3) {
		printf("Test 5 complete\n");
		return true;
	}
	else {
		printf("Test 5 failed\n");
		return false;
	}
}


int main(void) {
	// testing();
	int dividend = 0, divisor = 0;
	printf("Enter dividend and divisor through a space: ");
	scanf("%d %d", &dividend, &divisor);
	printf("%d", incompleteQuotient(dividend, divisor));
	
	return 0;
}