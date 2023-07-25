#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char last_c = 0, mark = ' ';
	int blend = BUFF_SIZE - 2, distance = 2, mark_start = 1; /* distance=2, for '0x' */
	unsigned long list_location;
	char draw_to[] = "0123456789abcdef";
	void *location = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (location == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	list_location = (unsigned long)location;

	while (list_location > 0)
	{
		buffer[blend--] = draw_to[list_location % 16];
		list_location /= 16;
		distance++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		mark = '0';
	if (flags & F_PLUS)
		last_c = '+', distance++;
	else if (flags & F_SPACE)
		last_c = ' ', distance++;

	blend++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, blend, distance,
		width, flags, mark, last_c, mark_start));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offcut = 0;
	char *character = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (character == NULL)
		return (write(1, "(null)", 6));

	while (character[i] != '\0')
	{
		if (is_printable(character[i]))
			buffer[i + offcut] = character[i];
		else
			offcut += append_hexa_code(character[i], buffer, i + offcut);

		i++;
	}

	buffer[i + offcut] = '\0';

	return (write(1, buffer, i + offcut));
}

/**
 * print_reverse - Prints reverse charactering.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *character;
	int i, read = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	character = va_arg(types, char *);

	if (character == NULL)
	{
		UNUSED(precision);

		character = ")Null(";
	}
	for (i = 0; character[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = character[i];

		write(1, &z, 1);
		read++;
	}
	return (read);
}

/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *character;
	unsigned int i, j;
	int read = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	character = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (character == NULL)
		character = "(AHYY)";
	for (i = 0; character[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == character[i])
			{
				x = out[j];
				write(1, &x, 1);
				read++;
				break;
			}
		}
		if (!in[j])
		{
			x = character[i];
			write(1, &x, 1);
			read++;
		}
	}
	return (read);
}
