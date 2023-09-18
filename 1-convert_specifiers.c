#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * handle_int - Handle %d and %i conversion specifiers
 * @args: The va_list containing the argument
 * @count: Pointer to the character count
 */

void handle_int(va_list args, int *count)
{
	int num = va_arg(args, int);
	int digits = 0;
	int temp = num;
	int divisor = 1;
	int j;

	/* Calculate the number of digits */
	while (temp != 0)
	{
	digits++;
	temp /= 10;
	}

	/* Handle negative numbers */
	if (num < 0)
	{
		putchar('-');
		(*count)++;
		num = -num;
		digits--;
	}

	/* Print digits in reverse order */
	for (j = 1; j < digits; j++)
		divisor *= 10;

	while (divisor > 0)
	{
		putchar((num / divisor) + '0');
		(*count)++;
		num %= divisor;
		divisor /= 10;
	}
}

