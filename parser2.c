#inlcude "shell.h"

/**
 * read_file - read cmd from file
 * @filename: name of file
 * @argv: program name
 */

void read_file(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		treat_file(line, counter, fp, argv);
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * build - build cmd
 * @token: executable token
 * @value: dir containing cmd
 *
 * Return: parsed full path of smd or null fail
 */

char *build(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}
	memset(cmd, 0, len);
	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);
	return (cmd);
}

/**
 * check_builtin - check builtin
 * @cmd: cmd to check
 *
 * Return: 0 sucess 1 fail
 */

int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
		};
	int i;

	i = 0;
	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * creat_envi - Create an arr of env vars
 * @envi: Array of Enviroment Variable
 */

void creat_envi(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}
