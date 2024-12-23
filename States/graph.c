#include <stdlib.h>
#include "graph.h"
#include <stdio.h>
#include <math.h>

void setValueTo(int* array, int length, int value) {
    for (int i = 0; i < length; ++i) {
        array[i] = value;
    }
}

int** createAdjMatrix(int n, int m, Road* roads) {
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
        Road* currentRoad = roads + i;
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
        Road* currentRoad = roads + i;
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

Road* createStates(FILE* file, int countStates, int maxCountOfCities, int* employmentOfCities) {
    State* states = malloc(countStates * sizeof(State));
    if (states == NULL) {
        return NULL;
    }

    for (int i = 0; i < countStates; ++i) {
        State* currentState = states + i;
        int* cities = malloc(maxCountOfCities * sizeof(int));
        setValueTo(cities, maxCountOfCities, -1);

        if (cities == NULL) {
            return NULL;
        }

        currentState->cities = cities;
        fscanf(file, "%d", cities);
        currentState->number = i;
        currentState->citiesCount = 1;
        employmentOfCities[*cities] = 0;
    }
}

void addCityToState(State* state, int** adjMatrix, int* employmentOfCities, int citiesCount) {
    int* stateCities = state->cities;
    int resultCityNumber = -1;
    int minimumPathToCity = -1;
    for (int i = 0; i < citiesCount; ++i) {
        if (employmentOfCities[i] != 0) {
            int minimumumPathLengthToCurrentCity = 0;
            for (int j = 0; j < citiesCount; ++j) {
                if (stateCities[j] == -1) {
                    break;
                }
                int path = adjMatrix[stateCities[j]][i];

                if (path != 0 && (minimumumPathLengthToCurrentCity > path || minimumumPathLengthToCurrentCity == 0)) {
                    minimumumPathLengthToCurrentCity = path;
                }
            }
            if (minimumumPathLengthToCurrentCity != 0 && (minimumumPathLengthToCurrentCity < minimumPathToCity || minimumPathToCity == -1)) {
                minimumPathToCity = minimumumPathLengthToCurrentCity;
                resultCityNumber = i;
            }
        }
    }
    if (resultCityNumber != -1) {
        employmentOfCities[resultCityNumber] = 0;
        for (int i = 0; i < citiesCount; ++i) {
            if ((state->cities)[i] == -1) {
                (state->cities)[i] = resultCityNumber;
                break;
            }
        }
        (state->citiesCount)++;
    }
}