#include <stdlib.h>
#include "graph.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct Road {
    int start;
    int end;
    int length;
} Road;

typedef struct State {
    int number;
    int* cities;
    int citiesCount;
} State;

void updateDistances(int city, int citiesCount, int* distances, int** adjacencyMatrix, bool* alreadyDistributedCities) {
    for (int i = 0; i < citiesCount; i++) {
        if (alreadyDistributedCities[i] != true) {
            int distanceToCity = adjacencyMatrix[city][i];

            if (distanceToCity != 0 && distances[i] > distanceToCity) {
                distances[i] = distanceToCity;
            }
        }
    }
}

int setIntValue(int* array, int value, int length) {
    for (int i = 0; i < length; ++i) {
        array[i] = value;
    }
}

int** createAdjacencyMatrix(int n, int m, Road* roads) {
    int** matrix = calloc(n, sizeof(int*));
    if (matrix == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < n; i++) {
        matrix[i] = calloc(n, sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return;
        }
    }
    for (int i = 0; i < m; ++i) {
        Road* currentRoad = &roads[i];
        matrix[currentRoad->start][currentRoad->end] = currentRoad->length;
    }
    return matrix;
}

Road* createRoads(FILE* file, int count) {
    Road* roads = calloc(count, sizeof(Road));
    if (roads == NULL) {
        return NULL;
    }

    for (int i = 0; i < count; i++) {
        Road* currentRoad = &roads[i];
        int start = 0;
        int end = 0;
        int length = 0;
        fscanf(file, "%d %d %d", &start, &end, &length);
        currentRoad->start = start;
        currentRoad->end = end;
        currentRoad->length = length;
    }
    return roads;
}

State* initStates(FILE* file, int statesCount, int citiesCount, bool* alreadyDistributedCities) {
    State* states = malloc(statesCount * sizeof(State));
    if (states == NULL) {
        return NULL;
    }

    for (int i = 0; i < statesCount; ++i) {
        State* currentState = &states[i];
        int* cities = malloc(citiesCount * sizeof(int));
        if (cities == NULL) {
            for (int j = 0; j < statesCount; ++j) {
                if (j < i) {
                    free((&states[j])->cities);
                }
                free(&states[j]);
            }
            return NULL;
        }
        setIntValue(cities, -1, citiesCount);

        currentState->cities = cities;
        fscanf(file, "%d", cities);
        currentState->number = i;
        currentState->citiesCount = 1;
        alreadyDistributedCities[cities[0]] = true;
    }
    return states;
}


bool addCityToState(State* state, int** adjacencyMatrix, bool* alreadyDistributedCities, int citiesCount) {
    int* stateCities = state->cities;
    int* distances = malloc(sizeof(int) * citiesCount);
    if (distances == NULL) {
        perror("Memory allocate error");
        return false;
    }
    setIntValue(distances, INT_MAX, citiesCount);

    int minDistance = INT_MAX;
    int minCity = -1;

    for (int i = 0; i < citiesCount; ++i) {
        int currentCity = state->cities[i];
        if (currentCity == -1) {
            break;
        }
        updateDistances(currentCity, citiesCount, distances, adjacencyMatrix, alreadyDistributedCities);
    }
    
    for (int i = 0; i < citiesCount; i++) {
        int distanceToCurrentCity = distances[i];

        if (distanceToCurrentCity != 0 && distanceToCurrentCity < minDistance) {
            minDistance = distanceToCurrentCity;
            minCity = i;
        }
    }
    if (minCity == -1) {
        free(distances);
        return false;
    }

    for (int i = 0; i < citiesCount; i++) {
        if (stateCities[i] == -1) {
            stateCities[i] = minCity;
            break;
        }
    }
    alreadyDistributedCities[minCity] = true;
    state->citiesCount++;
    free(distances);
    return true;
}


void printStates(State* states, int countStates) {
    for (int i = 0; i < countStates; ++i) {
        State* currentState = &states[i];
        printf("State number %d, cities: ", currentState->number);
        for (int j = 0; j < currentState->citiesCount; j++) {
            printf("%d ", (currentState->cities)[j]);
        }
        puts("");
    }
}

void freeStates(State** statesPointer, int statesCount) {
    State* states = *statesPointer;
    for (int i = 0; i < statesCount; ++i) {
        State* state = &states[i];
        free(state->cities);
    }
    free(*statesPointer);
    *statesPointer = NULL;
}

int* getCities(State* state) {
    return state->cities;
}

State* getStateWithNumber(State* states, int number) {
    if (states + number != NULL) {
        return states + number;
    }
    return NULL;
}

State* createStates(FILE* file, bool debug) {
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
    bool* alreadyDistributedCities = calloc(citiesCount, sizeof(bool));
    State* states = initStates(file, statesCount, citiesCount, alreadyDistributedCities);
    if (states == NULL) {
        free(roads);
        perror("Memory allocate error");
        return;
    }

    int** adjacencyMatrix = createAdjacencyMatrix(citiesCount, roadsCount, roads);
    if (adjacencyMatrix == NULL) {
        perror("Memory allocate error");
        return NULL;
    }
    int freeCitiesCount = citiesCount - statesCount;
    int index = 0;

    while (freeCitiesCount > 0) {
        State* currentState = &states[index % statesCount];
        bool isAdded = addCityToState(currentState, adjacencyMatrix, alreadyDistributedCities, citiesCount);
        index++;
        if (isAdded) {
            freeCitiesCount--;
        }
    }
    free(alreadyDistributedCities);
    for (int i = 0; i < citiesCount; ++i) {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);
    free(roads);
    if (!debug) {
        printStates(states, statesCount);
        freeStates(&states, statesCount);
    }
    return states;
}
