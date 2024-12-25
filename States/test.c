#include <stdbool.h>
#include <stdio.h>
#include "test.h"
#include "graph.h"
#include <stdlib.h>

State* statesForTest(FILE* file) {
    int citiesCount = 0;
    int roadsCount = 0;
    int statesCount = 0;

    fscanf(file, "%d %d", &citiesCount, &roadsCount);
    Road* roads = createRoads(file, roadsCount);
    if (roads == NULL) {
        perror("Memory allocate error");
        return;
    }

    fscanf(file, "%d", &statesCount);
    bool* employmentOfCities = calloc(citiesCount, sizeof(bool));
    State* states = createStates(file, statesCount, citiesCount, employmentOfCities);
    if (states == NULL) {
        for (int i = 0; i < roadsCount; ++i) {
            free(roads + i);
        }
        perror("Memory allocate error");
        return;
    }

    int** adjMatrix = createAdjMatrix(citiesCount, roadsCount, roads);
    int freeCitiesCount = citiesCount - statesCount;
    int index = 0;

    while (freeCitiesCount > 0) {
        State* currentState = states + (index % statesCount);
        bool isAdded = addCityToState(currentState, adjMatrix, employmentOfCities, citiesCount);
        index++;
        if (isAdded) {
            freeCitiesCount--;
        }
    }
    free(employmentOfCities);
    for (int i = 0; i < citiesCount; ++i) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    free(roads);
    return states;
}

void freeStates(State* states, int statesCount) {
    for (int i = 0; i < statesCount; ++i) {
        State* state = states + i;;
        free(state->cities);
    }
    free(states);
}

bool runTests(void) {
    FILE* firstFile = fopen("test1.txt", "r");
    FILE* secondFile = fopen("test2.txt", "r");
    FILE* thirdFile = fopen("test3.txt", "r");

    State* firstStates = statesForTest(firstFile);
    int expectedStatesFirst[2][6] = { {2, 1, 3}, {4, 5, 0} };
    int* firstStatesStateOne = firstStates->cities;
    int* firstStatesStateTwo = (firstStates + 1)->cities;

    if (firstStatesStateOne[0] != expectedStatesFirst[0][0] || firstStatesStateOne[1] != expectedStatesFirst[0][1] || firstStatesStateOne[2] != expectedStatesFirst[0][2]) {
        return false;
    }
    if (firstStatesStateTwo[0] != expectedStatesFirst[1][0] || firstStatesStateTwo[1] != expectedStatesFirst[1][1] || firstStatesStateTwo[2] != expectedStatesFirst[1][2]) {
        return false;
    }

    State* secondStates = statesForTest(secondFile);
    int expectedStatesSecond[2][6] = { {0, 2, 1, 3}, {4, 5} };

    int* secondStatesStateOne = secondStates->cities;
    int* secondStatesStateTwo = (secondStates + 1)->cities;

    if (secondStatesStateOne[0] != expectedStatesSecond[0][0] || secondStatesStateOne[1] != expectedStatesSecond[0][1] || secondStatesStateOne[2] != expectedStatesSecond[0][2]) {
        return false;
    }
    if (secondStatesStateTwo[0] != expectedStatesSecond[1][0] || secondStatesStateTwo[1] != expectedStatesSecond[1][1]) {
        return false;
    }

    State* thirdStates = statesForTest(thirdFile);
    int expectedStatesThird[7] = { 0, 1, 2, 3, 4, 5, 6 };
    int* thirdState = thirdStates->cities;

    for (int i = 0; i < 7; ++i) {
        if (thirdState[i] != expectedStatesThird[i]) {
            return false;
        }
    }
    freeStates(firstStates, 2);
    freeStates(secondStates, 2);
    freeStates(thirdStates, 1);

    fclose(firstFile);
    fclose(secondFile);
    fclose(thirdFile);
    return true;
}