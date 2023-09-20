#include "main.h"

/**
 * use_specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*use_specifier(char *s))(va_list arglst, params_t *pmeters)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * use_printfunc - finds the format func
 * @s: the format string
 * @arglst: argument pointer
 * @pmeters: the parameters struct
 *
 * Return: the number of bytes printed
 */
int use_print_func(char *s, va_list arglst, params_t *pmeters)
{
	int (*f)(va_list, params_t *) = use_specifier(s);

	if (f)
		return (f(arglst, pmeters));
	return (0);
}

/**
 * use_flag - finds the flag func
 * @s: the format string
 * @pmeters: the parameters struct
 *
 * Return: if flag was valid
 */
int use_flag(char *s, params_t *pmeters)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = pmeters->plus_flag = 1;
			break;
		case ' ':
			i = pmeters->space_flag = 1;
			break;
		case '#':
			i = pmeters->hashtag_flag = 1;
			break;
		case '-':
			i = pmeters->minus_flag = 1;
			break;
		case '0':
			i = pmeters->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @pmeters: the parameters struct
 *
 * Return: if modifier was valid
 */
int use_modifier(char *s, params_t *pmeters)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = pmeters->h_modifier = 1;
		break;
	case 'l':
		i = pmeters->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * use_width - gets the width from the format string
 * @s: the format string
 * @pmeters: the parameters struct
 * @arglst: the argument pointer
 *
 * Return: new pointer
 */
char *use_width(char *s, params_t *pmeters, va_list arglst)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(arglst, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	pmeters->width = d;
	return (s);
}
