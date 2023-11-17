CC=gcc -Wall -Werror -Wextra -std=c11

all: s21_string.a
	$(CC) main.c -L. -ls21_string -o main

clean:
	rm main *.o *.a
test:

s21_string.a:
	$(CC) -c s21_string.c
	ar rc libs21_string.a s21_string.o
	ranlib libs21_string.a

gcov_report:

without:
	$(CC) main.c -o main