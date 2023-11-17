#include "s21_string.h"
#include "string.h"
#include <stdio.h>

int main() {
    // Массив со строкой для поиска
    char str[100] = "////test1////a/test2/test3/test4/";
    // Набор символов, которые должны входить в искомый сегмент
    char sep[10] = "/";
    // Переменная, в которую будут заноситься начальные адреса частей
    // строки str
    char *istr;

    printf("Исходная строка: %s\n", str);
    printf("Результат разбиения:\n");
    // Выделение первой части строки
    istr = s21_strtok(str, sep);

    // Выделение последующих частей
    while (istr != NULL) {
        // Вывод очередной выделенной части
        printf("%s\n", istr);
        // Выделение очередной части строки
        istr = s21_strtok(NULL, sep);
    }
    return 0;
}
