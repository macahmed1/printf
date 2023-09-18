#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string containing conversion specifiers
 * @...: The values to be printed based on the format
 *
 * Return: The number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			putchar('%');
			count++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			char c = va_arg(args, int);

			putchar(c);
			count++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
		char *str = va_arg(args, char *);

			if (str)
			{
				while (*str)
				{
					putchar(*str);
					count++;
					str++;
				}
			}
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
