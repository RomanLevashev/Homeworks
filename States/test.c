#include <stdbool.h>
#include <stdio.h>
#include "test.h"
#include "graph.h"
#include <stdlib.h>

bool runTests(void) {
    FILE* firstFile = fopen("test1.txt", "r");
    FILE* secondFile = fopen("test2.txt", "r");
    FILE* thirdFile = fopen("test3.txt", "r");

    State* firstStates = createStates(firstFile, true);
    int expectedStatesFirst[2][6] = { {2, 1, 3}, {4, 5, 0} };
    int* firstStatesStateOne = getCities(getStateWithNumber(firstStates, 0));
    int* firstStatesStateTwo = getCities(getStateWithNumber(firstStates, 1));

    if (firstStatesStateOne[0] != expectedStatesFirst[0][0] || firstStatesStateOne[1] != expectedStatesFirst[0][1] || firstStatesStateOne[2] != expectedStatesFirst[0][2]) {
        freeStates(&firstStates, 2);
        fclose(firstFile);
        return false;
    }
    if (firstStatesStateTwo[0] != expectedStatesFirst[1][0] || firstStatesStateTwo[1] != expectedStatesFirst[1][1] || firstStatesStateTwo[2] != expectedStatesFirst[1][2]) {
        freeStates(&firstStates, 2);
        fclose(firstFile);
        return false;
    }
    freeStates(&firstStates, 2);
    fclose(firstFile);

    State* secondStates = createStates(secondFile, true);
    int expectedStatesSecond[2][6] = { {0, 2, 1, 3}, {4, 5} };

    int* secondStatesStateOne = getCities(getStateWithNumber(secondStates, 0));
    int* secondStatesStateTwo = getCities(getStateWithNumber(secondStates, 1));

    if (secondStatesStateOne[0] != expectedStatesSecond[0][0] || secondStatesStateOne[1] != expectedStatesSecond[0][1] || secondStatesStateOne[2] != expectedStatesSecond[0][2]) {
        freeStates(&secondStates, 2);
        fclose(secondFile);
        return false;
    }
    if (secondStatesStateTwo[0] != expectedStatesSecond[1][0] || secondStatesStateTwo[1] != expectedStatesSecond[1][1]) {
        freeStates(&secondStates, 2);
        fclose(secondFile);
        return false;
    }
    freeStates(&secondStates, 2);
    fclose(secondFile);

    State* thirdStates = createStates(thirdFile, true);
    int expectedStatesThird[7] = { 0, 1, 2, 3, 4, 5, 6 };
    int* thirdState = getCities(getStateWithNumber(thirdStates, 0));

    for (int i = 0; i < 7; ++i) {
        if (thirdState[i] != expectedStatesThird[i]) {
            freeStates(&thirdStates, 1);
            fclose(thirdFile);
            return false;
        }
    }
    freeStates(&thirdStates, 1);
    fclose(thirdFile);
    return true;
}
