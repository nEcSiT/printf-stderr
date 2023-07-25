#include "main.h"

/**
 * get_right_size - Calculates the right_size for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: right_size.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int purr_k = *i + 1;
	int right_size = -1;

	if (format[purr_k] != '.')
		return (right_size);

	right_size = 0;

	for (purr_k += 1; format[purr_k] != '\0'; purr_k++)
	{
		if (is_digit(format[purr_k]))
		{
			right_size *= 10;
			right_size += format[purr_k] - '0';
		}
		else if (format[purr_k] == '*')
		{
			purr_k++;
			right_size = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = purr_k - 1;

	return (right_size);
}
