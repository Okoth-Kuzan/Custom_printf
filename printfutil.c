#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @pmeters: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *pmeters)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)pmeters;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @arglst: argument pointer
 * @pmeters: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list arglst, params_t *pmeters)
{
	unsigned long l;

	if (pmeters->l_modifier)
		l = (unsigned long)va_arg(arglst, unsigned long);
	else if (pmeters->h_modifier)
		l = (unsigned short int)va_arg(arglst, unsigned int);
	else
		l = (unsigned int)va_arg(arglst, unsigned int);
	pmeters->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, pmeters), pmeters));
}



/**
 * print_address - prints address
 * @arglst: argument pointer
 * @pmeters: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list arglst, params_t *pmeters)
{
	unsigned long int n = va_arg(arglst, unsigned long int);
	char *string;

	if (!n)
		return (_puts("(nil)"));

	string = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pmeters);
	*--string = 'x';
	*--string = '0';
	return (print_number(string, pmeters));
}

