#include "shell.h"

/**
 * path_cmd - search in $path for executable cmd
 * @line: parsed input
 *
 * Return: 1 fail 0 success
 */

int path_cmd(char **line)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*line, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*line = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(path);
	return (1);
}

/**
 * _getenv - gets val of env var by name
 * @name: name of env var
 *
 * Return: val of env var else null
 */

char *_getenv(char *name)
{
	size_t nl, vl;
	char *value;
	int i, x, j;

	nl = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], nl) == 0)
		{
			vl = _strlen(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}
			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';
			return (value);
		}
	}
	return (NULL);
}

/**
 * parse_cmd - parse line of input
 * @cmd: user input
 *
 * Return: arr of char parsed
 */

char **parse_cmd(char *cmd)
{
	char **tokens;
	char *token;
	int i, buffsize;

	buffsize = BUFSIZE;
	if (cmd == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}
	token = _strtok(cmd, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * handle_builtin - handle builtin cmd
 * @cmd: parsed cmd
 * @er: state of last execution
 *
 * Return: -1 fail 0 success
 */

int handle_builtin(char **cmd, int er)
{
	bul_t bil[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}
