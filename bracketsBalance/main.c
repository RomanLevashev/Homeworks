#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>	

bool isBalance(char str[], int length) {
	int bracketCounter = 0;
	for (int i = 0; i <= length; ++i) {
		if (bracketCounter < 0) {
			return false;
		}
		if (str[i] == '(') {
			bracketCounter++;
		}

		if (str[i] == ')') {
			bracketCounter--;
		}
	}
	if (bracketCounter != 0) {
		return false;
	}

	return true;
}


bool testing(void) {
	if (isBalance("(())((()))()", 12)) {
		printf("Test 1 complete\n");
	}
	else {
		printf("Test 1 failed\n");
	}

	if (!(isBalance("))((", 4))) {
		printf("Test 2 complete\n");
	}
	else {
		printf("Test 2 failed\n");
	}

	if (!(isBalance("())(", 4))) {
		printf("Test 3 complete\n");
	}
	else {
		printf("Test 3 failed\n");
	}

	if (isBalance("()(())(((())))", 14)) {
		printf("Test 4 complete\n");
	}
	else {
		printf("Test 4 failed\n");
	}
}


int main(void) {
	char str[1001] = { 0 };
	printf("Enter a string up to 1000 elements: ");
	fgets(str, 1000, stdin);

	printf(isBalance(str, strlen(str)) ? "Balanced\n" : "Not balanced\n");
	// testing();
	return 0;
}