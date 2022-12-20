#include "shell.h"

/**
 * free_env - free env var arr
 * @env: env variables
 */

void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}

/**
 * fill_an_array - Fill An Array By Constant Byte
 * @a: pointer
 * @el: int
 * @len: length
 *
 * Return: void pointer
 */

void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i;

	i = 0;
	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * _memcpy - copy byte from src to dest
 * @dest: dest pointer
 * @src: src pointer
 * @n: size to copy
 *
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
