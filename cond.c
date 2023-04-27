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
