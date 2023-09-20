#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *string, params_t *pmeters)
{
	unsigned int i = _strlen(string);
	int neg = (!pmeters->unsign && *string == '-');

	if (!pmeters->precision && *string == '0' && !string[1])
		string = "";
	if (neg)
	{
		string++;
		i--;
	}
	if (pmeters->precision != UINT_MAX)
		while (i++ < pmeters->precision)
			*--string = '0';
	if (neg)
		*--string = '-';

	if (!pmeters->minus_flag)
		return (print_number_right_shift(string, pmeters));
	else
		return (print_number_left_shift(string, pmeters));
}

/**
 * print_number_right_shift - prints a number with options
 * @string: the base number as a string
 * @pmeters: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *string, params_t *pmeters)
{
	unsigned int n = 0, neg, neg2, i = _strlen(string);
	char pad_char = ' ';

	if (pmeters->zero_flag && !pmeters->minus_flag)
		pad_char = '0';
	neg = neg2 = (!pmeters->unsign && *string == '-');
	if (neg && i < pmeters->width && pad_char == '0' && !pmeters->minus_flag)
		string++;
	else
		neg = 0;
	if ((pmeters->plus_flag && !neg2) ||
		(!pmeters->plus_flag && pmeters->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (pmeters->plus_flag && !neg2 && pad_char == '0' && !pmeters->unsign)
		n += _putchar('+');
	else if (!pmeters->plus_flag && pmeters->space_flag && !neg2 &&
		!pmeters->unsign && pmeters->zero_flag)
		n += _putchar(' ');
	while (i++ < pmeters->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (pmeters->plus_flag && !neg2 && pad_char == ' ' && !pmeters->unsign)
		n += _putchar('+');
	else if (!pmeters->plus_flag && pmeters->space_flag && !neg2 &&
		!pmeters->unsign && !pmeters->zero_flag)
		n += _putchar(' ');
	n += _puts(string);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @string: the base number as a string
 * @pmeters: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *string, params_t *pmeters)
{
	unsigned int n = 0, neg, neg2, i = _strlen(string);
	char pad_char = ' ';

	if (pmeters->zero_flag && !pmeters->minus_flag)
		pad_char = '0';
	neg = neg2 = (!pmeters->unsign && *string == '-');
	if (neg && i < pmeters->width && pad_char == '0' && !pmeters->minus_flag)
		string++;
	else
		neg = 0;

	if (pmeters->plus_flag && !neg2 && !pmeters->unsign)
		n += _putchar('+'), i++;
	else if (pmeters->space_flag && !neg2 && !pmeters->unsign)
		n += _putchar(' '), i++;
	n += _puts(string);
	while (i++ < pmeters->width)
		n += _putchar(pad_char);
	return (n);
}
