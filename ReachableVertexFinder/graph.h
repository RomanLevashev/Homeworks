#pragma once

// Распечатывает массив длиной n
void printReachableVerticies(int* reachableVerticies, const int n);
// Находит вершины графа, из которых есть в путь во все другие, и возвращает массив длиной n, где в i элементе стоит 1, если вершина таковой является и 0, если нет
int* findReachableVertices(int** adjMatrix, const int n);