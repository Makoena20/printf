#include "main.h"

/**
 * handle_char - Handles the %c conversion specifier
 * @args: Arguments list
 * @buffer: Buffer to store the result
 * @index: Index in the buffer
 * Return: Number of characters printed
 */
int handle_char(va_list args, char *buffer, int index)
{
    char c = va_arg(args, int);

    buffer[index] = c;
    return 1;
}

/**
 * handle_string - Handles the %s conversion specifier
 * @args: Arguments list
 * @buffer: Buffer to store the result
 * @index: Index in the buffer
 * Return: Number of characters printed
 */
int handle_string(va_list args, char *buffer, int index)
{
    char *str = va_arg(args, char *);
    int i, len = 0;

    if (str == NULL)
        str = "(null)";

    for (i = 0; str[i] != '\0'; i++)
    {
        buffer[index + i] = str[i];
        len++;
    }

    return len;
}

/**
 * handle_percent - Handles the %% conversion specifier
 * @args: Arguments list
 * @buffer: Buffer to store the result
 * @index: Index in the buffer
 * Return: Number of characters printed
 */
int handle_percent(va_list args, char *buffer, int index)
{
    (void)args;
    buffer[index] = '%';
    return 1;
}

/**
 * handle_integer - Handles the %d and %i conversion specifiers
 * @args: Arguments list
 * @buffer: Buffer to store the result
 * @index: Index in the buffer
 * Return: Number of characters printed
 */
int handle_integer(va_list args, char *buffer, int index)
{
    int num = va_arg(args, int);
    int len = 0;

    // Convert integer to string (you need to implement it)
    char *num_str = convert_integer_to_string(num);

    // Copy the string to the buffer
    for (int i = 0; num_str[i] != '\0'; i++)
    {
        buffer[index + i] = num_str[i];
        len++;
    }

    // Free the memory allocated for num_str
    free(num_str);

    return len;
}

