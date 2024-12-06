#include "../Stack/stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

int postfixCalculator(char* expression, int length) {
    int returnResult = NULL;
    StackObject* top = NULL;
    int result = 0;
    for (int i = 0; i < length; ++i) {
        char current = expression[i];
        if (current == '\n' || current == '\0') {
            if (top != NULL) {
                returnResult =  pop(&top);
                break;
            }
        }

        if (isdigit(current)) {
            push(&top, current - '0');
        }

        if (current == '+' || current == '-' || current == '*' || current == '/') {
            int secondOperand = pop(&top);
            int firstOperand = pop(&top);
            
            if (current == '+') {
                result = firstOperand + secondOperand;
            }

            if (current == '-') {
                result = firstOperand - secondOperand;
            }

            if (current == '*') {
                result = firstOperand * secondOperand;
            }

            if (current == '/') {
                if (secondOperand == 0) {
                    puts("You can't divide by zero");
                    return 0;
                }
                result = firstOperand / secondOperand;
            }
            push(&top, result);
        }
    }
    if (top != NULL && returnResult == NULL) {
        returnResult = pop(&top);
    }
    freeStack(top);
    return returnResult;
}

bool runTests(void) {
    const int length = 100;
    if (postfixCalculator("3 4 + ", length) != 7) {
        return false;
    }

    if (postfixCalculator("5 1 2 + 4 * + 3 -", length) != 14) {
        return false;
    }

    if (postfixCalculator("3 4 + 2 * 7 -", length) != 7) {
        return false;
    }

    if (postfixCalculator("9 6 - 1 2 + *", length) != 9) {
        return false;
    }
    return true;
}

int main(void) {
    if (!runTests()) {
        puts("Tests failed");
        return 1;
    }
    else {
        puts("All tests were passed successfully");
    }
    const int length = 100;
    char expression[100] = { 0 };
    puts("Enter the expression in postfix form: ");
    fgets(expression, length - 1, stdin);

    printf("Result - %d", postfixCalculator(expression, length));
    return 0;
}