//
// Created by progo111 on 03.11.23.
//
#include "s21_string.h"

int *map_fill(int *map, const char *src) {
    for (int i = 0; i < LEN_S; ++i) {
        map[i] = 0;
    }
    for (const char *p = src; *p; ++p) {
        map[(int) (*p)] = 1;
    }
    return map;
}

void *s21_memchr(const void *str, int c, size_t n) {
    void *ptr = NULL;
    for (char *p = (char *) str; (size_t) (p - (char *) str) < n; ++p) {
        if (*p == c) {
            ptr = (void *) p;
            break;
        }
    }
    return ptr;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    int res;
    char *ptr1 = (char *) str1;
    char *ptr2 = (char *) str2;
    while ((res = *ptr1 - *ptr2) == 0) {
        ++ptr1;
        ++ptr2;
        if ((size_t) ((void *) ptr1 - str1) >= n) {
            break;
        }
    }
    return res;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
    for (size_t i = 0; i < n && (src + i); ++i) {
        *(char *) (dest + i) = *(char *) (src + i);
    }
    return dest;
}

void *s21_memset(void *str, int c, size_t n) {
    for (void *p = str; (size_t) (p - str) < n; ++p) {
        *(char *) p = (char) c;
    }
    return str;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
    char *p_d = dest;
    while (*p_d) ++p_d;
    size_t i = 0;
    printf("%c", *p_d);
    for (; i < n && *(src + i); ++i) {
        *(p_d + i) = *(src + i);
    }
    return dest;
}

char *s21_strchr(const char *str, int c) {
    char *p = NULL;
    size_t i = 0;
    while (*(str + i)) {
        if (*(str + i) == (char) c) {
            p = (char *) (str + i);
            break;
        }
        ++i;
    }
    return (char *) p;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
    const char *p1 = str1;
    const char *p2 = str2;
    int res = 0;
    while (p1 && p2 && (size_t) (p1 - str1) < n && res == 0) {
        res = *(p1++) - *(p2++);
    }
    return res;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
    for (int i = 0; (size_t) i < n && *(src + i); ++i) {
        *(dest + i) = *(src + i);
    }
    return dest;
}

size_t s21_strcspn(const char *str1, const char *str2) {
    int map[LEN_S];
    map_fill(map, str2);

    size_t len = 0;
    char const *pointer = str1;
    while (*pointer && map[(int) (*pointer)] == 0) {
        len++;
        pointer++;
    }
    return len;
}

//char *s21_strerror(int errnum) {
////    char err_info[LEN_S] = "unknown error";
//    return "f";
//}

size_t s21_strlen(const char *str) {
    size_t i = 0;
    for (; *(str + i); i++) {}
    return i;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *point = NULL;
    int map[LEN_S];
    map_fill(map, str2);

    const char *p = str1;

    while (*p && !point) {
        if (map[(int) (*p)]) {
            point = (char *) p;
        }
        ++p;
    }

    return point;
}

char *s21_strrchr(const char *str, int c) {
    char *point = NULL;
    for (const char *p = (str + s21_strlen(str) - 1); *p; --p) {
        if (*p == c) {
            point = (char *) p;
            break;
        }
    }
    return point;
}

char *s21_strstr(const char *haystack, const char *needle) {
    size_t p = SIMPLE;
    size_t x_ = X;
    size_t n = s21_strlen(haystack);
    size_t x[n + 1];
    x[0] = 1;
    size_t hash_h[n + 1];
    hash_h[0] = 0;
    for (size_t i = 1; i < n + 1; ++i) {
        x[i] = x[i - 1] * x_ % p;
        hash_h[i] = (hash_h[i - 1] * x_ + haystack[i - 1]) % p;
    }

    size_t hash_needle = 0;
    size_t len_needle = s21_strlen(needle);

    for (const char *point = needle; *point; ++point) {
        hash_needle = (hash_needle * x_ + *point) % p;
    }


    char *point_result = NULL;
    for (size_t i = 0; i + len_needle < n + 1; ++i) {
        if (hash_h[len_needle + i] % p == (hash_needle % p + hash_h[i] * x[len_needle] % p) % p) {
            point_result = (char *) (haystack + i);
            break;
        }
    }
    return point_result;
}

char *s21_strtok(char *str, const char *delim) {
    int map[LEN_S];
    map_fill(map, delim);

    static char *cur_str = NULL;
    if (str != NULL) {
        cur_str = str;
    }

    char *result = NULL;
    char *pointer = cur_str;
    while (*pointer) {
        if (map[(int) (*pointer)] == 0) {
            result = pointer;
            break;
        }
        ++pointer;
    }

    int flag = 0;
    if (*pointer == '\0') {
        flag = 1;
    }

    pointer = result;
    while (pointer && *pointer) {
        if (map[(int) (*pointer)]) {
            *pointer = '\0';
            cur_str = pointer + 1;
            break;
        }
        pointer++;
        if (*pointer == '\0') {
            cur_str = pointer;
        }
    }

    if (flag) {
        result = NULL;
    }
    return result;
}

