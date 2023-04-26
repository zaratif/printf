#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/* Function prototypes */
int _putchar(char c);
int _strlen(char *s);
int num_len(int num);
int int_to_str(int n);
void check_percent(int *count_char);
void handle_char(char c, va_list args, int *count);
int _printf(const char *format, ...);

/* Advanced function prototypes */
int number_to_binary(unsigned int num);
void handle_hex(unsigned int num, char base, char *buffer);
void handle_octal(unsigned int num, char *buffer);
void handle_decimal(unsigned int num, char *buffer);
int number_to_hx_to_octal(unsigned int num, char base);

#endif
