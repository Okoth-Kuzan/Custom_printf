#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c module */
int _puts(char *string);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list arglst, params_t *pmeters);
int print_int(va_list arglst, params_t *meters);
int print_string(va_list arglst, params_t *pmeters);
int print_percent(va_list arglst, params_t *pmeters);
int print_S(va_list arglst, params_t *pmeters);

/* number.c module */
char *convert(long int num, int base, int flags, params_t *pmeters);
int print_unsigned(va_list arglst, params_t *pmeters);
int print_address(va_list arglst, params_t *pmeters);

/* specifier.c module */
int (*use_specifier(char *s))(va_list arglst, params_t *pmeters);
int use_print_func(char *s, va_list arglst, params_t *pmeters);
int use_flag(char *s, params_t *pmeters);
int use_modifier(char *s, params_t *pmeters);
char *use_width(char *s, params_t *pmeters, va_list arglst);

/* convert_number.c module */
int print_hex(va_list arglst, params_t *pmeters);
int print_HEX(va_list arglst, params_t *pmeters);
int print_binary(va_list arglst, params_t *pmeters);
int print_octal(va_list arglst, params_t *pmeters);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list arglst, params_t *pmeters);
int print_rot13(va_list arglst, params_t *pmeters);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *string, params_t *pmeters);
int print_number_right_shift(char *string, params_t *pmeters);
int print_number_left_shift(char *string, params_t *pmeters);

/* params.c module */
void init_params(params_t *pmeters, va_list arglst);

/* string_fields.c modoule */
char *get_precision(char *it, params_t *pmeters, va_list arglst);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif

