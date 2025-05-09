#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include <string.h>
#define N 4

int** createAdjMatrix(int n, int data[N][N]) {
    int** adjMatrix = malloc(n * sizeof(int*));
    if(!adjMatrix) {
        perror("Memory allocate error");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        adjMatrix[i] = malloc(n * sizeof(int));
        if (!adjMatrix[i]) {
            perror("Memory allocate error");
            for (int j = 0; j < i; ++j) {
                free(adjMatrix[j]);
            }
            free(adjMatrix);
            return NULL;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            adjMatrix[i][j] = data[i][j];
        }
    }

    return adjMatrix;
}


bool runTests(void) {
    const int n = N;
    int data1[N][N] = {
     {0, 1, 1, 1},
     {0, 0, 1, 0},
     {0, 0, 0, 1},
     {0, 0, 0, 0}
    };
    int** adjMatrix1 = createAdjMatrix(n, data1);
    if (adjMatrix1 == NULL) {
        perror("Memory allocate error");
        return false;
    }

    int* reachableVerticies1 = findReachableVertices(adjMatrix1, n);
    int expectedResult1[] = {1, 0, 0, 0};
    if (memcmp(reachableVerticies1, expectedResult1, sizeof(reachableVerticies1)) != 0) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        free(adjMatrix1[i]);
    }
    free(adjMatrix1);
    free(reachableVerticies1);
    int data2[N][N] = {
    {0, 1, 1, 0},
    {1, 0, 1, 0},
    {0, 0, 0, 1},
    {0, 0, 0, 0}
    };
    int** adjMatrix2 = createAdjMatrix(n, data2);
    if (adjMatrix2 == NULL) {
        perror("Memory allocate error");
        return false;
    }

    int* reachableVerticies2 = findReachableVertices(adjMatrix2, n);
    int expectedResult2[] = { 1, 1, 0, 0 };
    if (memcmp(reachableVerticies2, expectedResult2, sizeof(reachableVerticies2)) != 0) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        free(adjMatrix2[i]);
    }
    free(adjMatrix2);
    free(reachableVerticies2);

    return true;
}