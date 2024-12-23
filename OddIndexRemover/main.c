#include <stdbool.h>
#include <stdio.h>

bool runTests(void);

int main(void) {
    if (!runTests()) {
        puts("Tests failed");
        return 1;
    }
    puts("Tests passed");

    return 0;
}