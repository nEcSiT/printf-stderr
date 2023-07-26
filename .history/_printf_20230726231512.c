#include "main.h"

void print_kuffer(char kuffer[], int *kuff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    int k, printed = 0, printed_chars = 0;
    int flags, width, precision, size, kuff_ind = 0;
    va_list list;
    char kuffer[kUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (k = 0; format && format[k] != '\0'; k++)
    {
        if (format[k] != '%')
        {
            buffer[buff_ind++] = format[k];
            if (buff_ind == BUFF_SIZE)
            {
                print_buffer(buffer, &buff_ind);
            }
            else
            {
                write(1, &format[k], 1);
            }
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            flags = get_flags(format, &k);
            width = get_width(format, &k, list);
            precision = get_precision(format, &k, list);
            size = get_size(format, &k);
            ++k;
            printed = handle_print(format, &k, list, buffer,
                                    flags, width, precision, size);
            if (printed == -1)
                return (-1);
            printed_chars += printed;
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(list);

    return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char uffer[], int *kuff_ind)
{
    if (*kuff_ind > 0)
    {
        write(1, &kuffer[0], *kuff_ind);
    }

    *kuff_ind = 0;
}
