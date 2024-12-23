#include <string.h>
#include <stdbool.h>

void parseCommentFromLine(const char* source, const int length, char* destination);

bool runTests(void) {
    char lineTest1[] = "Text without a comment;comment after text";
    char commentTest1[42] = { 0 };
    parseCommentFromLine(lineTest1, 42, commentTest1);
    char expectedResult1[] = ";comment after text";
    if (strcmp(commentTest1, expectedResult1) != 0) {
        return false;
    }

    char lineTest2[] = "Line without a comment";
    char commentTest2[23] = { 0 };
    parseCommentFromLine(lineTest2, 23, commentTest2);
    char expectedResult2[23] = { 0 };
    if (strcmp(commentTest2, expectedResult2) != 0) {
        return false;
    }

    char lineTest3[] = ";Comment from the beginning of the line";
    char commentTest3[40] = { 0 };
    parseCommentFromLine(lineTest3, 40, commentTest3);
    char expectedResult3[] = ";Comment from the beginning of the line";
    if (strcmp(commentTest3, expectedResult3) != 0) {
        return false;
    }

    return true;
}