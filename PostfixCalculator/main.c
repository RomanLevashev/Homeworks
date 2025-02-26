#include "../Stack/stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool isEmpty(StackObject* top) {
    if (top == NULL) {
        return true;
    }
    return false;
}

int calculatePostfixExpression(char* expression) {
    int length = strlen(expression);
    StackObject* top = NULL;
    int result = 0;
    for (int i = 0; i < length; ++i) {
        char current = expression[i];
        if (current == '\n' || current == '\0') {
            break;
        }

        if (isdigit(current)) {
            if (!push(&top, current - '0')) {
                freeStack(&top);
                return INT_MAX;
            }
        }

        if (current == '+' || current == '-' || current == '*' || current == '/') {
            if (isEmpty(top)) {
                perror("Incorrect expression");
                return INT_MAX - 1;
            }

            int secondOperand = pop(&top);
            if (isEmpty(top)) {
                perror("Incorrect expression");
                return INT_MAX - 1;
            }
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
                    perror("Incorrect expression. Divide by zero");
                    freeStack(&top);
                    return INT_MAX - 2;
                }
                result = firstOperand / secondOperand;
            }
            if (!push(&top, result)) {
                freeStack(&top);
                return INT_MAX;
            }
        }
    }
    int returnResult = 0;
    if (top != NULL) {
        returnResult = pop(&top);
        if (!isEmpty(top)) {
            perror("Incorrect expression");
            freeStack(&top);
            return INT_MAX - 1;
        }
    }
    return returnResult;
}

bool runTests(void) {
    const int length = 100;
    if (calculatePostfixExpression("3 4 + ") != 7) {
        return false;
    }

    if (calculatePostfixExpression("5 1 2 + 4 * + 3 -") != 14) {
        return false;
    }

    if (calculatePostfixExpression("3 4 + 2 * 7 -") != 7) {
        return false;
    }

    if (calculatePostfixExpression("9 6 - 1 2 + *") != 9) {
        return false;
    }

    if (calculatePostfixExpression("1 1") != INT_MAX - 1) {
        return false;
    }

    if (calculatePostfixExpression("3 3 + -") != INT_MAX - 1) {
        return false;
    }
    
    if (calculatePostfixExpression("4 + + -") != INT_MAX - 1) {
        return false;
    }

    if (calculatePostfixExpression("+ + -") != INT_MAX - 1) {
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

    printf("Result - %d", calculatePostfixExpression(expression));
    return 0;
}