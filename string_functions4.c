#include "shell.h"

/**
 * _strcpy - copy src to dest
 * @dest: destination
 * @src: source
 *
 * Return: copy of src ie dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strchr - Locate char in str
 * @s: string
 * @c: char
 *
 * Return: Pointer to char
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);
	return (s);
}

/**
 * _strncmp - compare n chars of 2 strings
 * @s1: string 1
 * @s2: string 2
 * @n: the number of chars to compare
 * Return: 1 if strings dont match else 0
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}

/**
 * _strdup - duplicate a string
 * @str: string
 *
 * Return: duplicated string
 */

char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}
	return (str2);
}
