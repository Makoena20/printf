#include "main.h"
#include <stdarg.h>

/**
 * handle_printf - Handles the conversion specifiers for _printf.
 * @format: The format string.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed.
 */
int handle_printf(const char *format, va_list args)
{
    print_info info;
    int count = 0;

    initialize_info(&info);

    count += handle_flags(format, &info);
    count += get_width(format, &info, args);

    switch (*format)
    {
    case 'c':
        count += print_char(args, &info);
        break;
    case 's':
        count += print_str(args, &info);
        break;
    case '%':
        count += print_percent(&info);
        break;
    case 'd':
    case 'i':
        count += print_int(args, &info);
        break;
    case 'b':
        count += print_binary(args, &info);
        break;
    // Add cases for other conversion specifiers
    }

    return (count);
}
