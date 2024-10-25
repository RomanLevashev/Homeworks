#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

enum options {quit, add, print, findPhoneByName, findNameByPhone, save};

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Читаем до конца строки или конца файла
}

void chooseOption(int choice, FILE* file) {
    switch (choice) {
    case add: {
        puts("Введите имя: ");
        char name[100] = { 0 };
        fgets(name, 99, stdin);
        name[strcspn(name, "\n")] = '\0';

        puts("Введите телефон: ");
        char phone[100] = { 0 }
        fgets(phone, 99, stdin);
        phone[strcspn(phone, "\n")] = '\0';
        fprintf(file, "%s %s\n", name, phone);
        puts("Запись добавлена");
        break;
    }
    case print: {
        fseek(file, 0, SEEK_SET);
        char line[256] = { 0 };

        while (fgets(line, sizeof(line) - 1, file) != NULL) {
            printf("%s", line);
        }
        break;
    }
    case findPhoneByName: {
        char* pointer = NULL;
        char line[256] = { 0 };
        int count = 0;
        char* fgetsResult = NULL;
        char name[100] = { 0 };
        puts("Введите имя: ");
        fgets(name, 99, stdin);
        fseek(file, 0, SEEK_SET);
        name[strcspn(name, "\n")] = '\0';

        do {
            fgetsResult = fgets(line, sizeof(line) - 1, file);
            line[strcspn(line, "\n")] = '\0';
            pointer = strstr(line, name);
            if (pointer == NULL) {
                memset(line, 0, 256);
            }
            else {
                int i = 0;
                while (!isdigit(pointer[i]) && pointer[i] != 0) {
                    i++;
                }
                while (pointer[i] != 0) {
                    putc(pointer[i++], stdout);
                    count++;
                }
                printf("\n");
                pointer = NULL;
                memset(line, 0, 256);
            }
        } while (pointer == NULL && fgetsResult != NULL);

        if (count < 1) {
            puts("Данного человека нет в базе");
        }
        break;

    }
    case findNameByPhone: {
        char* pointer = NULL;
        char line[256] = { 0 };
        int count = 0;
        char* fgetsResult = NULL;
        char phone[100] = { 0 };
        puts("Введите телефон: ");
        fgets(phone, 99, stdin);
        fseek(file, 0, SEEK_SET);
        phone[strcspn(phone, "\n")] = '\0';

        do {
            fgetsResult = fgets(line, sizeof(line) - 1, file);
            line[strcspn(line, "\n")] = '\0';
            pointer = strstr(line, phone);
            if (pointer == NULL) {
                memset(line, 0, 256);
            }
            else {
                int i = 0;
                while (!isdigit(line[i]) && line[i] != 0) {
                    putc(line[i++], stdout);
                    count++;
                }
                printf("\n");
                pointer = NULL;
                memset(line, 0, 256);
            }
        } while (pointer == NULL && fgetsResult != NULL);

        if (count < 1) {
            puts("Данного человека нет в базе");
        }
        break;
    }
    case save:
        fclose(file);
        file = fopen("TelephoneBook.txt", "a+");
        puts("Сохранение выполнено");
        break;

    case quit:
        fclose(file);
        return 0;

    default:
        puts("Неправильный ввод. Повторите снова.");
    }
}

int main(void) {
    setlocale(LC_ALL, "Russian");
    int choice = 9;
    FILE* file = fopen("TelephoneBook.txt", "a+");

    while (true) {
        puts("0 - Выйти\n\
1 - Добавить запись(имя и телефон)\n\
2 - Распечатать все имеющиеся записи\n\
3 - Найти телефон по имени\n\
4 - Найти имя по телефону\n\
5 - Сохранить текущие данные в файл");
        scanf("%d", &choice);
        clearBuffer();

        chooseOption(choice, file);
    }
}