#pragma once

typedef struct StackObj {                   // ��������� ������� �����, �������� ������ � ��������� �� ��������� �������
    char data;
    struct stackObj* next;
} StackObject;

void push(StackObject** top, char data);    // ��������� ����� ������� �� ������� �����
char pop(StackObject** top);                // ����� ������� � ������� ����� � ������� ���
void freeStack(StackObject* top);           // ����������� ������, ���������� ��� ��� �������� �����
