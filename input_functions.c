#include "shell.h"

/**
 * prompt - display shell prompt
 */

void prompt(void)
{
	PRINTER("$ ");
}

/**
 * signal_to_handle - handle ^C
 * @sig: captured signal
 */

void signal_to_handle(int sig)
{
	if (sig == SIGINT)
		PRINTER("\n$ ");
}

/**
 * _getline - read user inputfrom stdin
 * Return: the input
 */

char *_getline(void)
{
	int i, buffsize, rd;
	char c;
	char *buff;
       
	c = 0;
	buffsize = BUFSIZE;
	buff = malloc(buffsize);
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
				return (NULL);
		}
	}
	buff[i] = '\0';
	hashtag_handle(buff);
	return (buff);
}
