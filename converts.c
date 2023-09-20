#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @arglst: the argument pointer
 * @pmeters: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list arglst, params_t *pmeters)
{
	unsigned long l;
	int c = 0;
	char *string;

	if (pmeters->l_modifier)
		l = (unsigned long)va_arg(arglst, unsigned long);
	else if (pmeters->h_modifier)
		l = (unsigned short int)va_arg(arglst, unsigned int);
	else
		l = (unsigned int)va_arg(arglst, unsigned int);

	string = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pmeters);
	if (pmeters->hashtag_flag && l)
	{
		*--string = 'x';
		*--string = '0';
	}
	pmeters->unsign = 1;
	return (c += print_number(string, pmeters));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @arglst: the argument pointer
 * @pmeters: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list arglst, params_t *pmeters)
{
	unsigned long l;
	int c = 0;
	char *string;

	if (pmeters->l_modifier)
		l = (unsigned long)va_arg(arglst, unsigned long);
	else if (pmeters->h_modifier)
		l = (unsigned short int)va_arg(arglst, unsigned int);
	else
		l = (unsigned int)va_arg(arglst, unsigned int);

	string = convert(l, 16, CONVERT_UNSIGNED, pmeters);
	if (pmeters->hashtag_flag && l)
	{
		*--string = 'X';
		*--string = '0';
	}
	pmeters->unsign = 1;
	return (c += print_number(string, pmeters));
}
/**
 * print_binary - prints unsigned binary number
 * @arglist: the argument pointer
 * @pmeters: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list arglst, params_t *pmeters)
{
	unsigned int n = va_arg(arglst, unsigned int);
	char *string = convert(n, 2, CONVERT_UNSIGNED, pmeters);
	int c = 0;

	if (pmeters->hashtag_flag && n)
		*--string = '0';
	pmeters->unsign = 1;
	return (c += print_number(string, pmeters));
}

/**
 * print_octal - prints unsigned octal numbers
 * @arglst: the argument pointer
 * @pmeters: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list arglst, params_t *pmeters)
{
	unsigned long l;
	char *string;
	int c = 0;

	if (pmeters->l_modifier)
		l = (unsigned long)va_arg(arglst, unsigned long);
	else if (pmeters->h_modifier)
		l = (unsigned short int)va_arg(arglst, unsigned int);
	else
		l = (unsigned int)va_arg(arglst, unsigned int);
	string = convert(l, 8, CONVERT_UNSIGNED, pmeters);

	if (pmeters->hashtag_flag && l)
		*--string = '0';
	pmeters->unsign = 1;
	return (c += print_number(string, pmeters));
}
