#include "main.h"

/**
 * _printf - custom printf function
 * By Terance & Edward
 * @format: the format string
 * @...: arguments
 *
 * Return: no of chars printed
 */
int _printf(const char *format, ...)
{
	int num = 0;
	va_list arglst;
	char *it, *start;
	params_t pmeters = PARAMS_INIT;

	va_start(arglst, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (it = (char *)format; *it; it++)
	{
		init_params(&pmeters, arglst);
		if (*it != '%')
		{
			num += _putchar(*it);
			continue;
		}
		start = it;
		it++;
		while (use_flag(it, &pmeters)) 
		{
			it++; /* next char */
		}
		it = use_width(it, &pmeters, arglst);
		it = get_precision(it, &pmeters, arglst);
		if (use_modifier(it, &pmeters))
			it++;
		if (!use_specifier(it))
			num += print_from_to(start, it,
				pmeters.l_modifier || pmeters.h_modifier ? it - 1 : 0);
		else
			num += use_print_func(it, arglst, &pmeters);
	}
	_putchar(BUF_FLUSH);
	va_end(arglst);
	return (num);
}
