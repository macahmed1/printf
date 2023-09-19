#include "main.h"

/**
 * print_char - Printing a particular char.
 * @types: Listing of all arguments.
 * @buffer: Array of buffer handling prints.
 * @flags:  The is to calculate current flags that are active.
 * @width: Width of char
 * @precision: Specification for precision.
 * @size: Size for the conversion specifiers
 * Return: Printed number of chars
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - This is to print string
 * @types: Arguments a list
 * @buffer: Array of buffer handling pring
 * @flags:  Calculating flags that active
 * @width: The width
 * @precision: Specification for the precision
 * @size: Specifier for size
 * Return: printed number of chars
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0;
	int d;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (d = width - length; d > 0; d--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (d = width - length; d > 0; d--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * print_percent - Percentage sign printing
 * @types: Arguments list a
 * @buffer: Array of buffer handling print
 * @flags:  Active flags calculating
 * @width: The width in check
 * @precision: Specification of the precision
 * @size: Specifier for the size
 * Return: Printed number of chars
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - int printing
 * @types: Arguments list a
 * @buffer: Array of buffer handling print
 * @flags:  Active flags caluclations
 * @width: The width in place
 * @precision: Specification of the precision
 * @size: Specifier of the size
 * Return: Printed number of chars
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int c = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[c--] = (num % 10) + '0';
		num /= 10;
	}

	c++;

	return (write_number(is_negative, c, buffer, flags, width, precision, size));
}

/**
 * print_binary - Unsigned number printing
 * @types: Arguments of list a
 * @buffer: Array of buffer of print handling
 * @flags:  Active flags calculations
 * @width: The width to ge
 * @precision: Specification for the precision
 * @size: Specifier for the size
 * Return: Printed char numbers
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int d, e, f, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	d = va_arg(types, unsigned int);
	e = 2147483648; /* (2 ^ 31) */
	a[0] = d / e;
	for (f = 1; f < 32; f++)
	{
		e /= 2;
		a[f] = (d / e) % 2;
	}
	for (f = 0, sum = 0, count = 0; f < 32; f++)
	{
		sum += a[f];
		if (sum || f == 31)
		{
			char z = '0' + a[f];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

