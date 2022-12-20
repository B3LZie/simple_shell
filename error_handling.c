#include "shell.h"

/**
 * print_number - print unsigned int
 * @n: unsigned int
 */

void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
	{
		print_number(x / 10);
	}
	_putchar(x % 10 + '0');
}

/**
 * print_number_in - print number
 * @n: integer
 */

void print_number_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);
	_putchar(x % 10 + '0');
}

/**
 * print_error - err based on cmd and shell loop #
 * @input: user input
 * @counter: shell count loop
 * @argv: program name
 */

void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}

/**
 * _prerror - custom err
 * @argv: program name
 * @c: err count
 * @cmd: command
 */

void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}
