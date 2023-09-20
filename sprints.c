#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - prints string in reverse
 * @arglst: string
 * @pmeters: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list arglst, params_t *pmeters)
{
	int len, sum = 0;
	char *string = va_arg(arglst, char *);
	(void)pmeters;

	if (string)
	{
		for (len = 0; *string; string++)
			len++;
		string--;
		for (; len > 0; len--, string--)
			sum += _putchar(*string);
	}
	return (sum);
}

/**
 * print_rot13 - prints string in rot13
 * @arglst: string
 * @pmeters: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list arglst, params_t *pmeters)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(arglst, char *);
	(void)pmeters;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
