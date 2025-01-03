#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "test.h"
#include "telephonebook.h"

enum Options {quit, add, print, findPhoneByName, findNameByPhone, save};

void clearBuffer() {
    char c = '\0';
    while ((c = getchar()) != '\n' && c != EOF); 
}

void chooseOption(int choice, int maxLength, FILE** file) {
    switch (choice) {
    case add: {
        printf("������� ��� �� %d ��������: ", maxLength-1);
        char* name = calloc(maxLength, 1);
        if (name == NULL) {
            perror("������ ��������� ������");
            return;
        }
        fgets(name, maxLength, stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("������� ������� �� %d ��������: ", maxLength-1);
        char* phone = calloc(maxLength, 1);
        if (phone == NULL) {
            perror("������ ��������� ������");
            free(name);
            return;
        }
        fgets(phone, maxLength, stdin);
        phone[strcspn(phone, "\n")] = '\0';
        fprintf(*file, "%s %s\n", name, phone);
        puts("������ ���������");
        free(name);
        free(phone);
        return;
    }
    case print: {
        fseek(*file, 0, SEEK_SET);
        char* buffer = calloc(maxLength*2+3, 1);
        if (buffer == NULL) {
            perror("������ ��������� ������");
            return;
        }

        while (fgets(buffer, maxLength*2+3, *file) != NULL) {
            printf("%s", buffer);
        }
        free(buffer);
        return;
    }
    case findPhoneByName: {
        char* name = calloc(maxLength, 1);
        printf("������� ��� �� %d ��������: ", maxLength - 1);
        fgets(name, maxLength, stdin);
        char* phone = findPhone(name, maxLength, *file);
        if (phone != NULL && phone[0] != '\0') {
            printf("%s\n", phone);
            free(name);
            free(phone);
        }
        else {
            puts("������� �� ������");
        }
        return;
    }

    case findNameByPhone: {
        char* phone = calloc(maxLength, 1);
        printf("������� ������� �� %d ��������: ", maxLength - 1);
        fgets(phone, maxLength, stdin);
        char* name = findName(phone, maxLength, *file);
        if (name != NULL && name[0] != '\0') {
            printf("%s\n", name);
            free(name);
            free(phone);
        }
        else {
            puts("��� �� �������");
        }
        return;
    }
    case save:
        fclose(*file);
        *file = fopen("TelephoneBook.txt", "a+");
        puts("���������� ���������");
        return;
    case quit:
        return;
    default:
        puts("������������ ����. ��������� �����.");
    }
}

int main(void) {
    int maxLength = 150;
    setlocale(LC_ALL, "Russian");
    if (!runTests()) {
        puts("����� �����������");
        return 1;
    }
    puts("����� ������ �������");
    int choice = -1;
    FILE* file = fopen("TelephoneBook.txt", "a+");

    while (choice != quit) {
        puts("0 - �����\n\
1 - �������� ������(��� � �������)\n\
2 - ����������� ��� ��������� ������\n\
3 - ����� ������� �� �����\n\
4 - ����� ��� �� ��������\n\
5 - ��������� ������� ������ � ����");
        scanf("%d", &choice);
        clearBuffer();

        chooseOption(choice, maxLength, &file);
    }
    fclose(file);
    return 0;
}