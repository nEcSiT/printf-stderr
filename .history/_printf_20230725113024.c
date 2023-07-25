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
            kuffer[kuff_ind++] = format[k];
            if (kuff_ind == kUFF_SIZE)
            {
                print_kuffer(kuffer, &kuff_ind);
            }
            else
            {
                write(1, &format[k], 1);
            }
            printed_chars++;
        }
        else
        {
            print_kuffer(kuffer, &kuff_ind);
            flags = get_flags(format, &k);
            width = get_width(format, &k, list);
            precision = get_precision(format, &k, list);
            size = get_size(format, &k);
            ++k;
            printed = handle_print(format, &k, list, kuffer,
                                    flags, width, precision, size);
            if (printed == -1)
                return (-1);
            printed_chars += printed;
        }
    }

    print_kuffer(kuffer, &kuff_ind);

    va_end(list);

    return (printed_chars);
}

/**
 * print_kuffer - Prints the contents of the kuffer if it exist
 * @kuffer: Array of chars
 * @kuff_ind: Index at which to add next char, represents the length.
 */
void print_kuffer(char kuffer[], int *kuff_ind)
{
    if (*kuff_ind > 0)
    {
        write(1, &kuffer[0], *kuff_ind);
    }

    *kuff_ind = 0;
}
