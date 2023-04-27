#include "main.h"

/**
 * _strlen - counts the length of a string
 *
 * @s: the string to be counted
 *
 * Return: the length of the string
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	i++;
	return (i);
}

/**
 * check_percent - writes a percent sign to standard output
 * and updates the character count
 *
 * @count_char: pointer to an integer that keeps track of the
 * number of characters written.
 */
void check_percent(int *count_char)
{
	_putchar('%');
	(*count_char) += 1;
}

/**
 * num_len - calculates the length of an integer
 *
 * @num: the integer to measure
 *
 * Return: the length of the integer
 */
int num_len(int num)
{
	int len = 0;

	if (num == 0)
	return (1);

	while (num != 0)
	{
		num /= 10;
		len++;
	}

	return (len);
}

/**
 * int_to_str - converts an integer to a string
 *
 * @n: the integer to convert
 *
 * Return: a pointer to the resulting string
 */
int int_to_str(int n)
{
	int i = 0;

	if (n < 0)
	{
		i += _putchar('-');
		if (n == -2147483648)
		{
			i += _putchar('2');
			n %= 1000000000;
		}

		i += int_to_str(-n);
	}
	else if (n >= 0 && n <= 9)
		i += _putchar(n + '0');
	else
	{
		i += int_to_str(n / 10);
		i += int_to_str(n % 10);
	}
	return (i);
}
/**
 * handle_char - handles the conversion specifier and writes
 * the corresponding output to standard output
 *
 * @c: the conversion specifier character
 * @args: the argument list containing the value to print
 * @count: pointer to an integer that keeps track of the
 *         number of characters written.
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
                        handle_string(args, count);
                        break;
                case 'd':
                case 'i':
                        handle_decimal(args, count);
                        break;
                case '%':
                        check_percent(count);
                        break;
                default:
                        _putchar('%');
                        _putchar(c);
                        (*count) += 2;
                        break;
        }
}
