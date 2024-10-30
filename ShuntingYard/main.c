#include "../Stack/stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

int getPriority(char operand) {
    if (operand == '+' || operand == '-') {
        return 2;
    }
    if (operand == "*" || operand == '/') {
        return 1;
    }
    return 0;
}

void postfixConverter(char expression[], int length, char resultExpression[]) {
    stackObject* top = NULL;
    int resultIndex = 0;

    for (int i = 0; i < length; ++i) {
        char current = expression[i];
        if (current == 0 || current == '\n') {
            break;
        }
        if (isdigit(current)) {
            resultExpression[resultIndex] = current;
            resultExpression[resultIndex + 1] = ' ';
            resultIndex += 2;
        }

        if (current == '(') {
            add(&top, current);
        }

        if (current == '+' || current == '/' || current == '*' || current == '-') {
            if (top != NULL) {
                int currentPriority = getPriority(current);
                int topStackPriority = getPriority(top->data);

                while (currentPriority <= topStackPriority && top != NULL && top->data != '(') {
                    resultExpression[resultIndex] = pop(&top);
                    resultExpression[resultIndex + 1] = ' ';
                    resultIndex += 2;
                }
            }
            add(&top, current);
        }

        if (current == ')') {
            while (top != NULL && top->data != '(') {
                resultExpression[resultIndex] = pop(&top);
                resultExpression[resultIndex + 1] = ' ';
                resultIndex += 2;
            }
            if (top->data == '(') {
                pop(&top);
            }
        }
    }
    while (top != NULL) {
        resultExpression[resultIndex] = pop(&top);
        resultExpression[resultIndex + 1] = ' ';
        resultIndex += 2;
    }
}

bool testing(void) {
    int length = 100;
    char expression[100] = "(3+4)*(2-(1+5))";
    char result[100] = { 0 };
    char wantedResult[100] = "3 4 + 2 1 5 + - * ";

    postfixConverter(expression, length, result);

    for (int i = 0; i < length; ++ i) {
        if (result[i] == 0) {
            break;
        }
        if (result[i] != wantedResult[i]) {
            return false;
        }
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
    if (!testing()) {
        return 1;
    }

    int length = 100;
    char expression[100] = { 0 };
    char resultExpression[200] = { 0 };
    puts("Enter the expression in infix form:");
    fgets(expression, length - 1, stdin);

    postfixConverter(expression, length, resultExpression);
    printArray(resultExpression, length * 2);
    return 0;
}