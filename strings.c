#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @it: the format string
 * @pmeters: the parameters struct
 * @arglst: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *it, params_t *pmeters, va_list arglst)
{
	int d = 0;

	if (*it != '.')
		return (it);
	it++;
	if (*it == '*')
	{
		d = va_arg(arglst, int);
		it++;
	}
	else
	{
		while (_isdigit(*it))
			d = d * 10 + (*it++ - '0');
	}
	pmeters->precision = d;
	return (it);
}
