#include "shell.h"

/**
 * print_echo - execute normal echo
 * @cmd: parsed cmd
 *
 * Return: always 0
 */

int print_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
			return (-1);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * exit_bul - exit shell
 * @cmd: parsed cmd
 * @input: user input
 * @argv: program name
 * @c: count
 */

void  exit_bul(char **cmd, char *input, char **argv, int c)
{
	int statue, i;

	i = 0;
	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_prerror(argv, c, cmd);
			break;
		}
		else
		{
			statue = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(statue);
		}
	}
}

/**
 * echo_bul - execute echo cases
 * @cmd: parsed cmd
 * @st: state of last cmd executed
 *
 * Return: always 0
 */

int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_in(st);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);
	}
	else
		return (print_echo(cmd));
	return (1);
}

/**
 * display_help - displaying hekp for bultin
 * @cmd: parsed cmd
 * @er: state of last cmd
 *
 * Return: always 0
 */

int display_help(char **cmd, int er)
{
	int fd, fw, rd;
	char c;

	rd = 1;
	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
			return (-1);
	}
	_putchar('\n');
	return (0);
}
