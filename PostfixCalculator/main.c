#include "../Stack/stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

int postfixCalculator(char* expression, int length) {
    stackObject* top = NULL;
    int result = 0;
    for (int i = 0; i < length; ++i) {
        char current = expression[i];
        if (current == '\n' || current == 0) {
            if (top != NULL) {
                return pop(&top);
            }
        }

        if (isdigit(current)) {
            int temp = current - '0';
            add(&top, temp);
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
            add(&top, result);
        }
    }
    if (top != NULL) {
        return pop(&top);
    }
}

bool testing(void) {
    int length = 100;
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
    if (!testing()) {
        return 1;
    }
    int length = 100;
    char expression[100] = { 0 };
    puts("Enter the expression in postfix form: ");
    fgets(expression, length - 1, stdin);

    printf("Result - %d", postfixCalculator(expression, length));
    return 0;
}