#include "shell.h"

/**
 * _strtok - tokenize a string
 * @str: the string
 * @tok: the other const
 *
 * Return: pointer to the next token or null
 */

char *_strtok(char *str, const char *tok)
{
	static char *ts;
	static char *nt;
	unsigned int i;

	if (str != NULL)
		nt = str;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	for (i = 0; ts[i] != '\0'; i++)
	{
		if (check_delim(ts[i], delim) == 0)
			break;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + i;
	nt = ts;
	for (i = 0; nt[i] != '\0'; i++)
	{
		if (check_delim(nt[i], delim) == 1)
			break;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (ts);
}

/**
 * check_delim - check in char matched any char
 * @c: char
 * @s: string to check
 *
 * Return: 1 success 0 failure
 */

unsigned int check_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			retunr (1);
	}
	return (0);
}

/**
 * _strncpy - copy str
 * @dest: the dest
 * @src: the source
 * @n: the num of chars
 *
 * Return: copied str
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strlen - len of str
 * @s: char
 *
 * Return: length
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _atoi - convert to int
 * @s: string
 *
 * Return: int
 */

int _atoi(char *s)
{
	int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}

/**
 * _puts - print a string
 * @str: the str
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
	return;
}

/**
 * strcmp - compare 2 strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if same otherwise num in difference
 */

int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i, len1, len2;
	
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _isalpha - is alphabet?
 * @c: the char
 *
 * Return: the 1 true or 0 false
 */

int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
		return (1);
	else
		return (0);
}

/**
 * array_rev - reverse arr
 * @arr: arr to rev
 * @len: length of arr
 */

void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * int_len - determine length of int
 * @num: the int
 *
 * Return: the length of the int
 */

int intlen(int num)
{
	int len;
       
	len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * _itoa - convert int to char
 * @n: int to convert
 *
 * Return: the char
 */

char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 * _strcat - concat two strings
 * @dest: string 1
 * @src: string 2
 *
 * Return: string 1 + string 2
 */

char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

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
	do
	{
		if (*s == c)
		{
			break;
		}
		while (*s++);
	}
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
