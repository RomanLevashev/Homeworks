#include <stdio.h>
#include <stdbool.h>
#include "../Stack/stack.h"

bool isBalanced(char* string, int length) {
    StackObject* top = NULL;

    for (int i = 0; i < length; ++i) {
        if (string[i] == '\0') {
            break;
        }
        if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
            if (!push(&top, string[i])) {
                freeStack(&top);
                return false;
            }
        }
        if (string[i] == ')' || string[i] == ']' || string[i] == '}') {
            char lastBracket = pop(&top);
            if (lastBracket == NULL) {
                freeStack(&top);
                return false;
            }
            if ((string[i] == ')' && lastBracket != '(') ||
                (string[i] == ']' && lastBracket != '[') ||
                (string[i] == '}' && lastBracket != '{')) {
                freeStack(&top);
                return false;
            }
        }
    }
    if (top != NULL) {
        freeStack(&top);
        return false;
    }
    return true;
}

bool runTests(void) {
    const int length = 100;
    if (isBalanced("({[])}", length)) {
        return false;
    }

    if (!isBalanced("({[]})", length)) {
        return false;
    }

    if (isBalanced("(", length)) {
        return false;
    }

    if (isBalanced("]", length)) {
        return false;
    }

    if (!isBalanced("(())([{}{}])", length)) {
        return false;
    }
    return true;
}

int main(void) {
    if (!runTests()) {
        puts("Tests failed");
        return 1;
    }
    puts("All tests were passed successfully");
    
    const int length = 100;
    char string[100] = { "\0" };
    puts("Enter a string up to 100 symbols");
    fgets(string, length - 1, stdin);

    if (isBalanced(string, length)) {
        puts("Balanced");
    }
    else {
        puts("Not balanced");
    }
    return 0;
}