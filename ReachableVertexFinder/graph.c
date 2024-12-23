#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void dfs(int source, int* visited, int** adjMatrix, const int n) {
    visited[source] = 1;

    for (int i = 0; i < n; ++i) {
        if (adjMatrix[source][i] && !visited[i]) {
            dfs(i, visited, adjMatrix, n);
        }
    }
}

void printReachableVerticies(int* reachableVerticies, const int n) {
    printf("Reachable verticies: ");
    for (int i = 0; i < n; ++i) {
        if (reachableVerticies[i] == 1) {
            printf("%d ", i);
        }
    }
}

void setValueTo(int* destination, const int length, const int value) {
    for (int i = 0; i < length; ++i) {
        destination[i] = value;
    }
}

int* findReachableVertices(int** adjMatrix, const int n) {
    int* visited = malloc(n * sizeof(int));
    if (visited == NULL) {
        perror("Memory allocate error");
        return NULL;
    }

    int* reachableVertices = malloc(n * sizeof(int));
    if (reachableVertices == NULL) {
        perror("Memory allocate error");
        free(visited);
        return NULL;
    }
    setValueTo(reachableVertices, n, 0);

    for (int start = 0; start < n; ++start) {
        setValueTo(visited, n, 0);
        dfs(start, visited, adjMatrix, n);

        bool isReachable = true;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                isReachable = false;
                break;
            }
        }

        if (isReachable) {
            reachableVertices[start] = 1;
        }
    }
    free(visited);
    return reachableVertices;
}