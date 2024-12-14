#pragma once
#include "../List/list.h"
#include <stdlib.h>
#define TABLE_SIZE 1000

typedef struct HT {
    Node* elements[TABLE_SIZE];  
} HashTable;

int hashFunction(char* word); // ���-�������
void initTable(HashTable* table);                   // ������ ��� ��������� �� ������� ��������
void addWord(HashTable* table, char* word);         // ��������� ����� � �������, ��� ����������� �������
void printTable(HashTable* table);                  // ������� ������� � ���� (����� ���������� � ������)
void freeTable(HashTable** table);                  // ����������� ��� ������ �������
double calculateLoadFactor(HashTable* table);          // ��������� ����������� ����������
double calculateAvgListLength(HashTable* table);    // ��������� ������� ����� ������
int calculateMaxListLength(HashTable* table);       // ��������� ������������ ����� ������
