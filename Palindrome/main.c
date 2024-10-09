#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getLength(char str[]) {
	int length = 0;
	int i = 0;

	while (str[i] != 0 && str[i] != '\n') {
		length++;
		i++;
	}
	return length;
}

bool isPalindrome(char* str) {
	int length = getLength(str);

	if (length < 2) {
		return true;
	}

	int left = 0;
	int right = length - 1;

	while (right > left) {
		while (str[right] == ' ') {
			right--;
		}

		while (str[left] == ' ') {
			left++;
		}

		if (right > left) {
			if (str[right] != str[left]) {
				return false;
			}
			left++;
			right--;
		}
	}
	return true;
}

bool testing(void) {
	char firstStr[26] = "Ужа сопливого в ил посажУ";
	
	if (!isPalindrome(firstStr)) {
		puts("Test 1 failed");
		return false;
	}

	char secondStr[30] = "Дивен мне вид";

	if (isPalindrome(secondStr)) {
		puts("Test 2 failed");
		return false;
	}

	char thirdStr[30] = "Коту тащат уток";

	if (!isPalindrome(thirdStr)) {
		puts("Test 3 failed");
		return false;
	}

	return true;
}

int main(void) {
	if (testing) {
		puts("All tests passed successfully");
	}
	int arrayLength = 1000;
	char* str = calloc(arrayLength, arrayLength);
	while (str == NULL) {
		str = calloc(arrayLength, arrayLength);
	}

	puts("Enter a string up to 1000 symbols: ");
	fgets(str, arrayLength - 1, stdin);
	printf(isPalindrome(str) ? "This string is a palindrome" : "This string is not a palindrome");
	free(str);
	return 0;
}