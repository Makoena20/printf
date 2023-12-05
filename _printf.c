#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function with limited functionality.
 * @format: Format string containing conversion specifiers.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
            case 'c':
                count += write(1, &va_arg(args, int), 1);
                break;
            case 's':
                count += write(1, va_arg(args, char *), 1);
                break;
            case '%':
                count += write(1, "%", 1);
                break;
            default:
                count += write(1, "%", 1);
                count += write(1, format, 1);
                break;
            }
        }
        else
        {
            count += write(1, format, 1);
        }

        format++;
    }

    va_end(args);
    return count;
}

/* Example usage:
int main(void)
{
    _printf("Hello, %c! This is a %s example. The percentage sign:%%\n", 'W', "printf");
    return 0;
}
*/

