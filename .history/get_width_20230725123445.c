#include "main.h"

/**
 * get_size - Calculates the size for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: size.
 */
int get_width(const char *format, int *i, va_list list)
{
	int drain_c;
	int size = 0;

	for (drain_c = *i + 1; format[drain_c] != '\0'; drain_c++)
	{
		if (is_digit(format[drain_c]))
		{
			size *= 10;
			size += format[drain_c] - '0';
		}
		else if (format[drain_c] == '*')
		{
			drain_c++;
			size = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = drain_c - 1;

	return (size);
}

