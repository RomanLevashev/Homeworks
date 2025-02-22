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
	
	return bracketCounter == 0;
}

bool testing(void) {
	if (!isBalance("(())((()))()", 12)) {
		return false;
	}

	if ((isBalance("))((", 4))) {
		return false;
	}

	if ((isBalance("())(", 4))) {
		return false;
	}

	if (!isBalance("()(())(((())))", 14)) {
		return false;
	}

	return true;
}

int main(int argc, char* argv[]) {
	if (!testing()) {
		puts("Tests failed");
		return 1;
	}
	if (argc > 1 && strcmp(argv[1], "--test") == 0) {
		return 0;
	}
	char str[1001] = { 0 };
	printf("Enter a string up to 1000 elements: ");
	fgets(str, 1000, stdin);

	printf(isBalance(str, strlen(str)) ? "Balanced\n" : "Not balanced\n");

	return 0;
}