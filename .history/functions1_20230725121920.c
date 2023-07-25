#include "main.h"

/**
 * print_unsigned - Prints an unsigned NUMber
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: NUMber of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int NUM = va_arg(types, unsigned long int);

	NUM = convert_size_unsgnd(NUM, size);

	if (NUM == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (NUM > 0)
	{
		buffer[i--] = (NUM % 10) + '0';
		NUM /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned NUMber in octal notation
 * @types: lIST of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: NUMber of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int NUM = va_arg(types, unsigned long int);
	unsigned long int init_NUM = NUM;

	UNUSED(width);

	NUM = convert_size_unsgnd(NUM, size);

	if (NUM == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (NUM > 0)
	{
		buffer[i--] = (NUM % 8) + '0';
		NUM /= 8;
	}

	if (flags & F_HASH && init_NUM != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned NUMber in hexadecimal notation
 * @types: lIST of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: NUMber of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned NUMber in upper hexadecimal notation
 * @types: lIST of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: NUMber of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal NUMber in lower or upper
 * @types: lIST of arguments
 * @map_to: Array of values to map the NUMber to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: NUMber of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int NUM = va_arg(types, unsigned long int);
	unsigned long int init_NUM = NUM;

	UNUSED(width);

	NUM = convert_size_unsgnd(NUM, size);

	if (NUM == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (NUM > 0)
	{
		buffer[i--] = map_to[NUM % 16];
		NUM /= 16;
	}

	if (flags & F_HASH && init_NUM != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
