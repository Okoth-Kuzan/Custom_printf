#include "main.h"

/**
 * print_char - prints character
 * @arglst: argument pointer
 * @pmeters: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list arglst, params_t *pmeters)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(arglst, int);

	if (pmeters->minus_flag)
		sum += _putchar(ch);
	while (pad++ < pmeters->width)
		sum += _putchar(pad_char);
	if (!pmeters->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_string - prints string
 * @arglst: argument pointer
 * @pmeters: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list arglst, params_t *pmeters)
{
	char *string = va_arg(arglst, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)pmeters;
	switch ((int)(!string))
		case 1:
			string = NULL_STRING;

	j = pad = _strlen(string);
	if (pmeters->precision < pad)
		j = pad = pmeters->precision;

	if (pmeters->minus_flag)
	{
		if (pmeters->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*string++);
		else
			sum += _puts(string);
	}
	while (j++ < pmeters->width)
		sum += _putchar(pad_char);
	if (!pmeters->minus_flag)
	{
		if (pmeters->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*string++);
		else
			sum += _puts(string);
	}
	return (sum);
}

/**
 * print_percent - prints string
 * @aarglst: argument pointer
 * @pmeterss: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list arglst, params_t *pmeters)
{
	(void)arglst;
	(void)pmeters;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @arglst: argument pointer
 * @pmeters: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list arglst, params_t *pmeters)
{
	char *string = va_arg(arglst, char *);
	char *hex;
	int sum = 0;

	if ((int)(!string))
		return (_puts(NULL_STRING));
	for (; *string; string++)
	{
		if ((*string > 0 && *string < 32) || *string >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*string, 16, 0, pmeters);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*string);
		}
	}
	return (sum);
}

/**
 * print_int - prints integer
 * @arglst: argument pointer
 * @pmeters: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list arglst, params_t *pmeters)
{
	long l;

	if (pmeters->l_modifier)
		l = va_arg(arglst, long);
	else if (pmeters->h_modifier)
		l = (short int)va_arg(arglst, int);
	else
		l = (int)va_arg(arglst, int);
	return (print_number(convert(l, 10, 0, pmeters), pmeters));
}
