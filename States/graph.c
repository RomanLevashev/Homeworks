#include <stdlib.h>
#include "graph.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

void setValueTo(int* array, int length, int value) {
    for (int i = 0; i < length; ++i) {
        array[i] = value;
    }
}

bool allIsVisited(bool* visitedCities, bool* allowedCities, int citiesCount) {
    for (int i = 0; i < citiesCount; i++) {
        if (visitedCities[i] == false && allowedCities[i] == true) {
            return false;
        }
    }
    return true;
}

void dijkstra(int start, int previousLength, int** adjMatrix, bool* allowedCities, bool* visitedCities, int citiesCount, int* distances, bool* employmentOfCities) {
    visitedCities[start] = true;
    int minDistance = INT_MAX;
    int minCity = -1;
    for (int end = 0; end < citiesCount; end++) {
        if (!visitedCities[end] && !employmentOfCities[end]) {
            if (adjMatrix[start][end] != 0) {
                int currentDistance = adjMatrix[start][end];
                if (distances[end] > currentDistance + previousLength) {
                    distances[end] = currentDistance + previousLength;
                }
            }
        }
    }
    for (int i = 0; i < citiesCount; i++) {
        if (distances[i] != 0 && distances[i] < minDistance & allowedCities[i]) {
            minDistance = distances[i];
            minCity = i;
        }
    }   
    if (minCity != -1) {
        if (!allIsVisited(visitedCities, allowedCities, citiesCount)) {
            dijkstra(minCity, minDistance, adjMatrix, allowedCities, visitedCities, citiesCount, distances, employmentOfCities);
        }
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

Road* createStates(FILE* file, int statesCount, int citiesCount, bool* employmentOfCities) {
    State* states = malloc(statesCount * sizeof(State));
    if (states == NULL) {
        return NULL;
    }

    for (int i = 0; i < statesCount; ++i) {
        State* currentState = states + i;
        int* cities = malloc(citiesCount * sizeof(int));
        if (cities == NULL) {
            for (int j = 0; j < statesCount; ++j) {
                if (j < i) {
                    free((states + j)->cities);
                }
                free(states + j);
            }
            return NULL;
        }
        setValueTo(cities, citiesCount, -1);

        currentState->cities = cities;
        fscanf(file, "%d", cities);
        currentState->number = i;
        currentState->citiesCount = 1;
        employmentOfCities[*cities] = true;
    }
    return states;
}

bool* getAllowedCities(State* state, int citiesCount) {
    bool* allowedCities = calloc(citiesCount, sizeof(bool));

    if (allowedCities == NULL) {
        perror("Memory allocate error");
        return NULL;
    }

    for (int i = 0; i < citiesCount; ++i) {
        int stateCity = (state->cities)[i];
        if (stateCity == -1) {
            break;
        }
        allowedCities[stateCity] = true;
    }
    return allowedCities;
}

int getMinCity(int* distances, int citiesCount) {
    int minDistance = INT_MAX;
    int minCity = -1;
    for (int i = 0; i < citiesCount; i++) {
        if (distances[i] != 0 && distances[i] < minDistance) {
            minDistance = distances[i];
            minCity = i;
        }
    }
    return minCity;
}

bool addCityToState(State* state, int** adjMatrix, bool* employmentOfCities, int citiesCount) {
    int* stateCities = state->cities;
    int* distances = malloc(sizeof(int) * citiesCount);
    bool* allowedCities = getAllowedCities(state, citiesCount);
    if (allowedCities == NULL) {
        return false;
    }
    bool* visitedCities = calloc(citiesCount, sizeof(bool));
    if (visitedCities == NULL) {
        perror("Memory allocate error");
        free(allowedCities);
        return false;
    }
    int minDistanceOfAllCities = INT_MAX;
    int minCity = -1;

    for (int i = 0; i < citiesCount; ++i) {
        memset(visitedCities, 0, citiesCount);
        int currentCity = (state->cities)[i];
        if (currentCity == -1) {
            break;
        }
        setValueTo(distances, citiesCount, INT_MAX);
        distances[i] = 0;
        dijkstra(currentCity, 0, adjMatrix, allowedCities, visitedCities, citiesCount, distances, employmentOfCities);
        int minCurrentCity = getMinCity(distances, citiesCount);

        if (minCurrentCity == -1) {
            continue;
        }

        if (distances[minCurrentCity] < minDistanceOfAllCities) {
            minDistanceOfAllCities = distances[minCurrentCity];
            minCity = minCurrentCity;
        }
    }
    if (minCity == -1) {
        return false;
    }

    employmentOfCities[minCity] = 1;
    state->citiesCount++;
    for (int i = 0; i < citiesCount; ++i) {
        if ((state->cities)[i] == -1) {
            (state->cities)[i] = minCity;
            break;
        }
    }
    free(allowedCities);
    free(visitedCities);
    free(distances);
    return true;
}