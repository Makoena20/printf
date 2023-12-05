#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_precision - Handles precision for non-custom conversion specifiers
 * @format: Format specifier string
 * @args: Variable arguments list
 * @printed_chars: Pointer to the total number of characters printed
 */
void print_precision(const char *format, va_list args, int *printed_chars)
{
    int precision = 0;
    int num;

    format++; /* Move past the '%' */

    /* Parse precision if present */
    if (*format == '.')
    {
        format++;
        if (*format >= '0' && *format <= '9')
        {
            while (*format >= '0' && *format <= '9')
            {
                precision = precision * 10 + (*format - '0');
                format++;
            }
        }
    }

    /* Get the integer argument from the variable arguments list */
    num = va_arg(args, int);

    /* Handle precision logic as needed for different conversion specifiers */
    /* Example: */
    if (precision > 0)
    {
        /* Do something with precision, like limiting the number of characters to print */
        /* For simplicity, this example just prints the number itself */
        printf("%.*d", precision, num);
        *printed_chars += precision;
    }
    else
    {
        /* No precision specified, print as usual */
        printf("%d", num);
        *printed_chars += 1; /* Assuming one character is printed */
    }
}

/**
 * _printf - Produces output according to a format.
 * @format: Format specifier string
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            /* Handle different conversion specifiers */
            switch (*format)
            {
                case 'd':
                case 'i':
                    /* Call the function to handle precision for 'd' and 'i' */
                    print_precision(format, args, &printed_chars);
                    break;
                /* Add cases for other conversion specifiers if needed */
                default:
                    /* Unknown specifier, handle accordingly */
                    break;
            }
        }
        else
        {
            /* Regular character, just print it */
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}

