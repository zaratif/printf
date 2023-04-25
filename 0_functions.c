#include "main.h"

/**
 * print_arg - Prints an argument based on its type
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_arg(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int count = 0;

	switch (size)
	{
		case 0:
			switch (*types)
			{
				case 'c':
					count = handle_write_char(va_arg(types, int),
							buffer, flags, width, precision, size);
					break;
				case 's':
					count = print_string(types, buffer, flags, width, precision, size);
					break;
				case '%':
					count = print_percent(types, buffer, flags, width, precision, size);
					break;
				case 'd':
				case 'i':
					count = print_int(types, buffer, flags, width, precision, size);
					break;
				case 'b':
					count = print_binary(types, buffer, flags, width, precision, size);
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	return (count);
}
