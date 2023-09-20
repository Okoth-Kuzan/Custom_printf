#include "main.h"

/**
 * _puts - prints a string with newline
 * @string: the string to print
 *
 * Return: void
 */
int _puts(char *string)
{
	char *a = string;

	while (*string)
		_putchar(*string++);
	return (string - a);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
