#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char c;
    char *str;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr != '%')
        {
            _putchar(*ptr);
            count++;
        }
        else
        {
            ptr++;
            switch (*ptr)
            {
            case 'c':
                c = va_arg(args, int);
                _putchar(c);
                count++;
                break;
            case 's':
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str != '\0')
                {
                    _putchar(*str);
                    count++;
                    str++;
                }
                break;
            case '%':
                _putchar('%');
                count++;
                break;
            default:
                _putchar('%');
                _putchar(*ptr);
                count += 2;
            }
        }
    }

    va_end(args);
    return count;
}

