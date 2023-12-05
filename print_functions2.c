#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_binary - Prints a binary number.
 * @args: The va_list containing the binary number to print.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    unsigned int mask = 1;
    int count = 0;

    while (mask <= num >> 1)
        mask <<= 1;

    while (mask > 0)
    {
        if (num & mask)
            count += _putchar('1');
        else
            count += _putchar('0');
        mask >>= 1;
    }

    return (count);
}

/**
 * print_unsigned - Prints an unsigned integer.
 * @args: The va_list containing the unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_number(num);

    return (count);
}

/**
 * print_octal - Prints an octal number.
 * @args: The va_list containing the octal number to print.
 *
 * Return: The number of characters printed.
 */
int print_octal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_octal_number(num);

    return (count);
}

/**
 * print_hex - Prints a hexadecimal number.
 * @args: The va_list containing the hexadecimal number to print.
 *
 * Return: The number of characters printed.
 */
int print_hex(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_hex_number(num);

    return (count);
}

/**
 * print_hex_upper - Prints a hexadecimal number in uppercase.
 * @args: The va_list containing the hexadecimal number to print.
 *
 * Return: The number of characters printed.
 */
int print_hex_upper(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_hex_uppercase(num);

    return (count);
}

/**
 * print_string_custom - Prints a string with non-printable characters escaped.
 * @args: The va_list containing the string to print.
 *
 * Return: The number of characters printed.
 */
int print_string_custom(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        return (_printf("(null)"));

    while (*str)
    {
        if ((*str >= 0 && *str < 32) || *str >= 127)
        {
            count += _putchar('\\');
            count += _putchar('x');
            count += print_hex_uppercase(*str / 16);
            count += print_hex_uppercase(*str % 16);
        }
        else
        {
            count += _putchar(*str);
        }
        str++;
    }

    return (count);
}

