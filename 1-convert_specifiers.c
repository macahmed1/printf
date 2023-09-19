#include "main.h"

/**
 * print_unsigned - unsigned number printing
 * @types: arguments list a
 * @buffer: Array of buffer handling print
 * @flags:  active flags calculate
 * @width: width getting
 * @precision: Specification for precision
 * @size: Specifier of size
 * Return: Printed number of char
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Octal notation of printing an unsigned number
 * @types: Arguments of list a
 * @buffer: Array of buffer of print handling
 * @flags:  Active flags calculations
 * @width: The width to ge
 * @precision: Specification for the precision
 * @size: Specifier for the size
 * Return: Printed char numbers
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Hexadecimal notation in unsigned number printing
 * @types: Arguments of list a
 * @buffer: Array of buffer of print handling
 * @flags:  Active flags calculations
 * @width: The width to ge
 * @precision: Specification for the precision
 * @size: Specifier for the size
 * Return: Printed char numbers
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Upper hexadecimal notation in unsigned number prints
 * @types: Arguments of list a
 * @buffer: Array of buffer of print handling
 * @flags:  Active flags calculations
 * @width: The width to ge
 * @precision: Specification for the precision
 * @size: Specifier for the size
 * Return: Printed char numbers
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Hexadecimal number prints in lower or upper case
 * @types: Arguments of list a
 * @map_to: Values array of the number to map
 * @buffer: Array of buffer handling prints
 * @flags:  Active flags calculation
 * @flag_ch: Active flags calculation
 * @width: width to get
 * @precision: specification of the precision
 * @size: Specifier for the size
 * @size: Specification of the size
 * Return: Printed chars number
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

