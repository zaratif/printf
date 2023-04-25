#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

/**
 * struct parameters - struct to hold format specifiers flag
 * and modifiers
 *
 * @unsign: unsigned int flag
 * @plus_flag: plus sig flag
 * @space_flag: space flag
 * @hash_flag: hash tag flag
 * @zero_flag: zero glag
 * @minus_flag: minus flag
 * @width: minimum field width
 * @precision: precision fornumeric specifiers
 * @h_modifier: h modifier flag
 * @l_modifier: l modifier flag
 */

typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hash_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} params_t;

/**
 * struct format_t - struct to hold format specifier and function
 *
 * @t: format specifier character
 * @f: function pointer to corresponding printf function
 */

typedef struct format_t
{
	char t;
	int (*f)(va_list);
} format;

/* function prototypes */

int _printf(const char *format, ...);
/* putchar handlers */
int _putchar(char c);
int buffer(char c);

/* functions */

int _put_string(char *str);
int _strlen(const char *s);
int print(char *s);
int _is_lower(char c);
int _strcmp(char *s1, char *s2);
char *_to_upper(char *s);

/* % handlers */
int checker(const char *s, va_list list);
int check(const char *s, va_list list, int *i);

/* %c */

int _print_char(va_list list);

/* %d %i */
int _print_int(va_list list);

/* base conversion */
int _print_bin(va_list list);
int _print_octal(va_list list);
int _print_low_hexa(va_list list);
int _print_big_hexa(va_list list);
int _print_unsigned_int(va_list list);

/* %r %R */
int _rev_str((va_list list);
int _rot13(char *s);
int _print_rot13(va_list list);
int _print_rev_string(va_list list);

/* %p */
int _print_pointers(va_list list);

/* %s */
char *switch_me(unsigned long int n, int base, int lowc);
int _print_big_s(va_list list);

#endif
