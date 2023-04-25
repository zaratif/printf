#include" main.h"

/**
 * _printf - produces output acoording to a format
 *
 * @format: character string
 *
 * Return: number of chars printed excluding the null byte
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
				count += handle_char(args);
			else if (format[i] == 's')
				count += handle_string(args);
			else if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
		}
	}

	va_end(args);
	return (count);
}

/**
 * handle_char - handles the %c format specifier
 *
 * @args: va_list of arguments
 *
 * Return: number of characters printed
 */
int handle_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * handle_string - handles the %s format specifier
 * @args: va_list containing the string to print
 *
 * Return: number of characters printed
 */

int handle_string(va_list args)
{
	char *s = va_arg(args, char *);
	int i, cout = 0;

	if (!s)
		s = "(null)";

	for (i = 0; s[i]; i++)
	{
		_putchar(s[i]);
		count++;
	}

	return (count);
}
