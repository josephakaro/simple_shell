#include "shell.h"

/**
 * main - simple unix like program.
 *
 * @argc:
 * @argv:
 *
 * Return: Execute the command entered by user.
 */

int main(int argc, char **argv)
{
	int status = 0;
	char **args;
	
	char *buffer = NULL;
	size_t nread = 0;
	ssize_t line = 0;
	char *delim = " \n";

	do {
		if (isatty(STDIN_FILENO))
			printf(":) ");

		line = getline(&buffer, &nread, stdin);

		if (line == -1 || hsh_strcmp("exit\n", buffer) == 0)
		{
			free(buffer);
			break;
		}
		buffer[line - 1] = '\0';

		if (hsh_strcmp("env", buffer) == 0)
		{
			hsh_env();
			continue;
		}

		if (hsh_line(buffer) == 1)
		{
			status = 0;
			continue;
		}

		args = hsh_parse(buffer, delim);

		args[0] = hsh_path(args[0]);

		if (args[0] != NULL)
			status = execute(args);
		else
			perror("Error");
		free(args);

	} while (1);

	return (status);	
}

/**
 * execute - execute the given command.
 *
 * @args: arguments passed by stdin
 *
 * Return: Always Status(success).
 */

int execute(char **args)
{
	int checked, pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&checked);
		if (WIFEXITED(checked))
			checked = WEXITSTATUS(checked);
	}

	return (checked);
}