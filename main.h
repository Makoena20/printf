#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 * by Joseph and Ciny
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt {
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
};

/* Function to get precision from format string */
int get_precision(const char *format, int *i, va_list args);

/* Function to get size from format string */
int get_size(const char *format, int *i);

/* Function to print string in reverse */
int print_reverse(va_list args, char buffer[],
                  int flags, int width, int precision, int size);

/* Function to print a string in rot13 */
int print_rot13string(va_list args, char buffer[],
                      int flags, int width, int precision, int size);

/* Width handler functions */
int handle_write_char(char c, char buffer[],
                      int flags, int width, int precision, int size);

int write_number(int is_positive, int ind, char buffer[],
                 int flags, int width, int precision, int size);

int write_num(int ind, char bff[], int flags, int width, int precision,
              int length, char padd, char extra_c);

int write_pointer(char buffer[], int ind, int length,
                  int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
                 char buffer[], int flags, int width, int precision, int size);

/* Utility functions */
int is_printable(char c);
int append_hexa_code(char c, char buffer[], int ind);
int is_digit(char c);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif

