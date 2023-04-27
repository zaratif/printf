#include "main.h"

/**
 * handle_decimal - handles the conversion specifier "d" and "i"
 * by converting an integer to a string and printing it to standard output
 *
 * @args: the argument list containing the integer to print
 * @count: pointer to an integer that keeps track of the
 * number of characters written.
 */
void handle_decimal(va_list args, int *count)
{
	int num = va_arg(args, int);
	char buffer[BUFF_SIZE];
	int len;

	len = int_to_str(num);
	buffer[len] = '\0';
	len = len - 1;

	while (len >= 0)
	{
		_putchar(buffer[len]);
		(*count)++;
		len--;
	}
}
