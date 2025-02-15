#pragma once

// Находит телефон по имени и возвращает указатель на строку
char* findPhone(char* name, int maxLength, FILE* file);

// Находит имя по телефону и возвращает указатель на строку
char* findName(char* phone, int maxLength, FILE* file);
