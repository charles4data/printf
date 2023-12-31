#include "main.h"
#include <unistd.h>
#include <string.h>

/**
 * int _printf - prints formatted string on stdout
 * @format: string to print,
 * Return: length of arguments printed.
 */

int _printf(const char *format, ...)
{
    va_list args;
    int count;

    va_start(args, format);
    count = 0;

    if (format != NULL)
    {
        process_format_string(format, args, &count);
    }
    else
    {
        return (0);
    }

    va_end(args);
    return (count);
}

/**
 * int process_format_string - processes the format string for printing,
 * @format: string to print,
 * @args: list of arguments to be printed,
 * @count: Number of arguments to be printed,
 * Return: pointer to number of arguments printed.
 */

int process_format_string(const char *format, va_list args, int *count)
{
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    *count += print_char(args);
                    break;
                case 's':
                    *count += print_str(args);
                    break;
                case '%':
                    *count += print_percent(args);
                    break;
                case 'd':
                    *count += print_integer_d(args);
                    break;
                case 'i':
                    *count += print_integer_i(args);
                    break;
                case 'u':
                    *count += print_unsigned_integer(args);
                    break;
                case 'o':
                    *count += print_octal_integer(args);
                    break;
                case 'x':
                    *count += print_hexadecimal_integer(args);
                    break;
                case 'X':
                    *count += print_hexadecimal_upper(args);
                    break;
                case 'b':
                    *count += print_binary(args);
                    break;
                case 'S':
                    *count += print_ascii_char(args);
                    break;
                default:
                    /* unsupported specifier, print an error message or handle it in a specific way */
                    *count += _putchar('%');
                    *count += _putchar(*format);
            }
        } else
        {
            *count += _putchar(*format);
        }
        format++;
    }
    return (*count);
}
