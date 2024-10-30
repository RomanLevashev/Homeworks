#include <stdio.h>
#include <stdbool.h>
#include "../Stack/stack.h"

bool isBalance(char* string, int length) {
    stackObject* top = NULL;

    for (int i = 0; i < length; ++i) {
        if (string[i] == 0) {
            break;
        }
        if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
            add(&top, string[i]);
        }
        else if (string[i] == ')' || string[i] == ']' || string[i] == '}') {
            char lastBracket = pop(&top);
            if (lastBracket == NULL) {
                return false;
            }
            if ((string[i] == ')' && lastBracket != '(') ||
                (string[i] == ']' && lastBracket != '[') ||
                (string[i] == '}' && lastBracket != '{')) {
                return false;
            }
        }
    }
    return top == NULL;
}

bool testing(void) {
    int length = 100;
    if (isBalance("({[])}", length)) {
        return false;
    }

    if (!isBalance("({[]})", length)) {
        return false;
    }

    if (isBalance("(", length)) {
        return false;
    }

    if (isBalance("]", length)) {
        return false;
    }

    if (!isBalance("(())([{}{}])", length)) {
        return false;
    }
}

int main(void) {
    if (!testing()) {
        return 1;
    }
    int length = 100;
    char string[100] = { 0 };
    puts("Enter a string up to 100 symbols");
    fgets(string, length - 1, stdin);

    if (isBalance(string, length)) {
        puts("Balanced");
    }
    else {
        puts("No balanced");
    }
}