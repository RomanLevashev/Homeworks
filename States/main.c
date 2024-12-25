#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <stdbool.h>
#include "test.h"

void printStates(State* states, int countStates) {
    for (int i = 0; i < countStates; ++i) {
        State* currentState = states + i;
        printf("State number %d, cities: ", currentState->number);
        for (int j = 0; j < currentState->citiesCount; j++) {
            printf("%d ", (currentState->cities)[j]);
        }
        puts("");
    }
}

void states(FILE* file) {
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
    printStates(states, statesCount);
    free(employmentOfCities);
    for (int i = 0; i < citiesCount; ++i) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    for (int i = 0; i < statesCount; ++i) {
        State* state = states + i;;
        free(state->cities);
    }
    free(states);
    free(roads);
}

int main(void) {
    if (!runTests()) {
        puts("Test failed");
        return 1;
    }
    puts("Tests passed");
    FILE* file = fopen("input.txt", "r");

    states(file);
    fclose(file);
    return 0;
}