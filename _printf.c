#include "main.h"
#include <stdio.h>

/**
 * _printf - Print formatted output to stdout.
 * @format: A pointer to a format string.
 * @...: optional arguments to be printed
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0, i;
	va_list args;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			handle_char(format[++i], args, &count);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}

	va_end(args);
	return (count);
}
