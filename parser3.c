#include "shell.h"

/**
 * check_cmd - execute simple shell cmda fork wait execute
 * @cmd: parsed smd
 * @input: user input
 * @c: shell exec time
 * @argv: program name
 *
 * Return: 1- null 0- good -1- 1wrong
 */

int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}
		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}

/**
 * treat_file - parse cmd fork wait execute
 * @line: line of file
 * @counter: error counter
 * @fd: file descriptor
 * @argv: program name
 */

void treat_file(char *line, int counter, FILE *fd, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = parse_cmd(line);
	if (_strncmp(cmd[0], "exit", 4) == 0)
		exit_bul_for_file(cmd, line, fd);
	else if (check_builtin(cmd) == 0)
	{
		st = handle_builtin(cmd, st);
		free(cmd);
	}
	else
	{
		st = check_cmd(cmd, line, counter, argv);
		free(cmd);
	}
}

/**
 * exit_bul_for_file - exit shell case of file
 * @cmd: parsed cmd
 * @line: line from file
 * @fd: file descriptor
 */

void exit_bul_for_file(char **cmd, char *line, FILE *fd)
{
	int statue, i;

	i = 0;
	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
			perror("illegal number");
	}
	statue = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(statue);
}
