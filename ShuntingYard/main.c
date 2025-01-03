#include "../Stack/stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int getPriority(char operand) {
    if (operand == '+' || operand == '-') {
        return 1;
    }
    if (operand == '*' || operand == '/') {
        return 2;
    }
    return 0;
}

void addSymbolToExpression(int* resultIndex, char* resultExpression,  char current) {
    resultExpression[*resultIndex] = current;
    resultExpression[*resultIndex + 1] = ' ';
    *resultIndex += 2;
}

void postfixConverter(char expression[], int length, char resultExpression[]) {
    StackObject* top = NULL;
    int resultIndex = 0;

    for (int i = 0; i < length; ++i) {
        char current = expression[i];
        if (current == 0 || current == '\n') {
            break;
        }
        if (isdigit(current)) {
            addSymbolToExpression(&resultIndex, resultExpression, current);
        }

        if (current == '(') {
            push(&top, current);
        }

        if (current == '+' || current == '/' || current == '*' || current == '-') {
            if (top != NULL) {
                int currentPriority = getPriority(current);
                int topStackPriority = getPriority(top->data);

                while (currentPriority <= topStackPriority && top != NULL && top->data != '(') {
                    topStackPriority = getPriority(top->data);
                    addSymbolToExpression(&resultIndex, resultExpression, pop(&top));
                }
            }
            push(&top, current);
        }

        if (current == ')') {
            while (top != NULL && top->data != '(') {
                addSymbolToExpression(&resultIndex, resultExpression, pop(&top));
            }
            if (top != NULL && top->data == '(') {
                pop(&top);
            }
        }
    }
    while (top != NULL) {
        addSymbolToExpression(&resultIndex, resultExpression, pop(&top));
    }
    free(top);
}

bool runTests(void) {
    const int length = 100;
    char expression[100] = "(3+4)*(2-(1+5))";
    char result[100] = { 0 };
    char expectedResult[100] = "3 4 + 2 1 5 + - * ";

    postfixConverter(expression, length, result);
    if (strncmp(result, expectedResult, 100) != 0) {
        return false;
    }

    char secondExpression[100] = "2 - 2 * 3";
    char secondResult[100] = { 0 };
    char secondExpectedResult[100] = "2 2 3 * - ";
    postfixConverter(secondExpression, length, secondResult);

    if (strncmp(secondResult, secondExpectedResult, 100) != 0) {
        return false;
    }
    return true;
}

void printArray(char array[], int length) {
    for (int i = 0; i < length; ++i) {
        if (array[i] == 0) {
            break;
        }
        printf("%c", array[i]);
    }
}

int main(void) {
    if (!runTests()) {
        puts("Tests failed");
        return 1;
    }

    puts("All tests were passed successfully");
    const int length = 100;
    char expression[100] = { 0 };
    char resultExpression[200] = { 0 };
    puts("Enter the expression in infix form:");
    fgets(expression, length - 1, stdin);

    postfixConverter(expression, length, resultExpression);
    printArray(resultExpression, length * 2);
    return 0;
}