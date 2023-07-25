#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int purr_k = *i + 1;
	int precision = -1;

	if (format[purr_k] != '.')
		return (precision);

	precision = 0;

	for (purr_k += 1; format[purr_k] != '\0'; purr_k++)
	{
		if (is_digit(format[purr_k]))
		{
			precision *= 10;
			precision += format[purr_k] - '0';
		}
		else if (format[purr_k] == '*')
		{
			purr_k++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = purr_k - 1;

	return (precision);
}
