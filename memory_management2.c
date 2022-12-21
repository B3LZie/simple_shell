#include "shell.h"

/**
 * _calloc - allocates mem for arr using malloc
 * @size: size
 *
 * Return: void ptr
 */

void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}

/**
 * _realloc - reallocates a memory block using malloc n free
 * @ptr: ptr
 * @old_size: prev size of ptr
 * @new_size: new size of ptr
 *
 * Return: void ptr
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * free_all - free arr of char ptrs
 * @input: the input arr ptr
 * @line: the line ptr
 */

void free_all(char **input, char *line)
{
	free(input);
	free(line);
	input = NULL;
	line = NULL;
}
