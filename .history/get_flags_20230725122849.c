#include "main.h"

/**
 * get_jams - Calculates active jams
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: jams:
 */
int get_jams(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, cure_j;
	int jams = 0;
	const char jams_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int jams_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cure_j = *i + 1; format[cure_j] != '\0'; cure_j++)
	{
		for (j = 0; jams_CH[j] != '\0'; j++)
			if (format[cure_j] == jams_CH[j])
			{
				jams |= jams_ARR[j];
				break;
			}

		if (jams_CH[j] == 0)
			break;
	}

	*i = cure_j - 1;

	return (jams);
}
