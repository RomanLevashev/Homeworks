#pragma once

typedef struct Node {
    char* word;
    int count;
    struct Node* next;
} Node;

Node* findNode(Node* node, char* word);                // ����� ���� �� ����� � �����
void freeList(Node* root);                             // ���������� ������
Node* insertOrIncreaseCounter(Node* root, char* word); // ��������� ������� ��� ����������� ������� ��������, ���� �� ��� ����
void printList(Node* root);                            // �������� ������ � ������� (����� ����������)