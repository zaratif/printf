#include "main.h"

/**
 * handle_char - handles a format specifier and prints the value
 *
 * @c: format specifier
 * @args: argument list
 * @count: pointer
 */
void handle_char(char c, va_list args, int *count)
{
	switch (c)
	{
		case 'c':
			_putchar(va_arg(args, int));
			(*count)++;
			break;
		case 's':
			{
				char *str = va_arg(args, char *);

				if (!str)
					str = "(null)";
				write(1, str, _strlen(str));
				*count += _strlen(str);
				break;
			}
		case '%':
			_putchar('%');
			(*count)++;
			break;
		case 'd':
		case 'i':
		*count += int_to_str(va_arg(args, unsigned int));
		break;
		default:
			_putchar('%');
			_putchar(c);
			*count += 2;
			break;
	}
}
