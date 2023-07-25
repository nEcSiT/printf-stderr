#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int drain_c;
	int width = 0;

	for (drain_c = *i + 1; format[drain_c] != '\0'; drain_c++)
	{
		if (is_digit(format[drain_c]))
		{
			width *= 10;
			width += format[drain_c] - '0';
		}
		else if (format[drain_c] == '*')
		{
			drain_c++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = drain_c - 1;

	return (width);
}

