#pragma once
#include <stdio.h>
#include <stdbool.h>

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

// ������ ������� ��������� �� �������� �������
int** createAdjMatrix(int n, int m, Road* roads);
// ������ ������ ����� �� ������ �� �����
Road* createRoads(FILE* file, int count);
// ������� ������ ���������� �� ������ �� �����
Road* createStates(FILE* file, int countStates, int maxCountOfCities, bool* employmentOfCities);
// ������������� �������� ��� ������� �������� ������� �� ����������
void setValueTo(int* array, int length, int value);
// ��������� � ����������� ��������� �����, ���� ������� - ���������� true, � ���� ������ false
bool addCityToState(State* state, int** adjMatrix, bool* employmentOfCities, int citiesCount);