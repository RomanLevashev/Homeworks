#pragma once

// ��������� ���� ������
typedef struct Node {
    struct Node* next;
    int value;
} Node;
// ������ ����������� ������ � ���������� ��������� �� ��� ������ �� ���������� ������
Node* createList(char* source);
// ������� �������� � ��������� ���������
void deleteOddIndex(Node* head);
// ������� ������, ���������� ��� ������
void freeList(Node** source);