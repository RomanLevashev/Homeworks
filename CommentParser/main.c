#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool runTests(void);

void parseCommentFromLine(const char* source, const int length, char* destination) {
    for (int i = 0; i < length; ++i) {
        if (source[i] == ';') {
            for (int j = i, index = 0; j < length; j++, index++) {
                if (source[j] == '\n' || source[j] == EOF) {
                    return;
                }
                destination[index] = source[j];
            }
        }
    }
}

void parseCommentsFromFile(FILE* file) {
    const int maxLineLength = 150;
    char* line = calloc(maxLineLength, 1);
    if (line == NULL) {
        return -1;
    }
    char* comment = calloc(maxLineLength, 1);
    if (comment == NULL) {
        free(line);
        return -1;
    }

    while (fgets(line, 150, file) != NULL) {
        parseCommentFromLine(line, maxLineLength, comment);
        if (comment[0] != '\0') {
            printf("%s\n", comment);
            memset(comment, 0, maxLineLength);
        }
    }
    free(line);
    free(comment);
}

int main(void) {
    if (!runTests()) {
        puts("Tests failed");
        return 1;
    }
    puts("Tests passed");
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        return -1;
    }

    parseCommentsFromFile(file);
    fclose(file);
    return 0;
}