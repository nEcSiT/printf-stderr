#include "main.h"

/**
 * get_weight - Calculates the weight to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int drain_c = *i + 1;
	int weight = 0;

	if (format[drain_c] == 'l')
		weight = S_LONG;
	else if (format[drain_c] == 'h')
		weight = S_SHORT;

	if (weight == 0)
		*i = drain_c - 1;
	else
		*i = drain_c;


	return (weight);
}
