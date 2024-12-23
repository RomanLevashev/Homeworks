#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <stdbool.h>

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
        return;
    }

    fscanf(file, "%d", &statesCount);
    int* employmentOfCities = malloc(citiesCount * sizeof(int));
    setValueTo(employmentOfCities, citiesCount, 1);
    State* states = createStates(file, statesCount, citiesCount, employmentOfCities);
    if (states == NULL) {
        return;
    }

    int** adjMatrix = createAdjMatrix(citiesCount, roadsCount, roads);

}

int main(void) {
    FILE* file = fopen("input.txt", "r");

    /*
    int currentStateNumber = 0;
    int freeCitiesCount = n - k;

    while (freeCitiesCount > 0) {
        State* currentState = states + currentStateNumber;
        addCityToState(currentState, adjMatrix, employmentOfCities, n);
        freeCitiesCount--;
        currentStateNumber = (currentStateNumber + 1) % k;
    }

    printStates(states, k);
    */

    return 0;
}