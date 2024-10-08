#include <stdio.h>
#include <stdbool.h>
#include <string.h>	


int countSubstringInString(char string[], char subString[]) {
	int i = 0;
	int count = 0;
	int j = 0;
	
	while (string[i] != 0) {
		j = 0;

		while (string[i+j] == subString[j]) {
			if (subString[j + 1] == '\n' || subString[j + 1] == 0) {
				count++;
				j++;
				break;
			}
			j++;
		}
		i += 1;
	}
	return count;
}

bool testing(void) {
	if (countSubstringInString("asd", "") == 0) {
		printf("Test 1 complete\n");
	}
	else {
		printf("Test 1 failed\n");
		return false;
	}

	if (countSubstringInString("asdaaaasdbjkolkjaa", "a") == 7) {
		printf("Test 2 complete\n");
	}
	else {
		printf("Test 2 failed\n");
		return false;
	}

	if (countSubstringInString("asdjkljkllkj;bnmasdkkkkasdjl;qwehjklasdasd", "asd") == 5) {
		printf("Test 3 complete\n");
	}
	else {
		printf("Test 3 failed\n");
		return false;
	}
	return true;
}


int main(void) {
	char string[1001] = { 0 };
	char substring[1001] = { 0 };
	puts("Enter a string up to 1000 elements: ");
	fgets(string, 1000, stdin);
	puts("Enter a substring up to 1000 elements: ");
	fgets(substring, 1000, stdin);

	printf("Count of substring in stirng: %d\n", countSubstringInString(string, substring));

	if (testing()) {
		puts("All tests passed successfully");
	}

	return 0;
}