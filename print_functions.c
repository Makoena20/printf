#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char *str;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%' && *(ptr + 1) != '\0')
        {
            ptr++;
            switch (*ptr)
            {
            case 'c':
                count += _print_char(va_arg(args, int));
                break;
            case 's':
                str = va_arg(args, char *);
                count += _print_str(str == NULL ? "(null)" : str);
                break;
            case '%':
                count += _print_percent();
                break;
            // Add cases for other conversion specifiers as needed
            default:
                count += _print_unknown(*ptr);
                break;
            }
        }
        else
        {
            count += _putchar(*ptr);
        }
    }

    va_end(args);

    return count;
}

/**
 * _print_char - Print a character
 * @c: Character to print
 *
 * Return: Number of characters printed
 */
int _print_char(char c)
{
    return _putchar(c);
}

/**
 * _print_str - Print a string
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int _print_str(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        count += _putchar(*str);
        str++;
    }
    return count;
}

/**
 * _print_percent - Print a percent sign
 *
 * Return: Number of characters printed
 */
int _print_percent(void)
{
    return _putchar('%');
}

/**
 * _print_unknown - Print an unknown conversion specifier
 * @c: Unknown conversion specifier
 *
 * Return: Number of characters printed
 */
int _print_unknown(char c)
{
    _putchar('%');
    _putchar(c);
    return 2;
}

/**
 * _putchar - Write a character to stdout
 * @c: Character to write
 *
 * Return: On success, return the number of characters written. On error, return -1.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

