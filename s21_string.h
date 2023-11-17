//
// Created by progo111 on 03.11.23.
//

#ifndef STRING__S21_STRING_H
#define STRING__S21_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define X 577
#define SIMPLE 2147483647
#define LEN_S 300

// Вспомогательные функции
int *map_fill(int *map, const char *src);

// Не проверил на valgrind
void *s21_memchr(const void *str, int c, size_t n);

int s21_memcmp(const void *str1, const void *str2, size_t n);

void *s21_memcpy(void *dest, const void *src, size_t n);

char *s21_strncat(char *dest, const char *src, size_t n);

char *s21_strchr(const char *str, int c);

int s21_strncmp(const char *str1, const char *str2, size_t n);

char *s21_strncpy(char *dest, const char *src, size_t n);

size_t s21_strcspn(const char *str1, const char *str2);

size_t s21_strlen(const char *str);

// Проверить надо отсюда
void *s21_memset(void *str, int c, size_t n);

//char *s21_strerror(int errnum); // Надо сделать!!!

char *s21_strpbrk(const char *str1, const char *str2);

char *s21_strrchr(const char *str, int c);

char *s21_strstr(const char *haystack, const char *needle);

char *s21_strtok(char *str, const char *delim);

#endif //STRING__S21_STRING_H
