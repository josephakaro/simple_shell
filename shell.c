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
	char *buf = NULL, *delim = " \n";
	ssize_t line = 0;
	size_t nread = 0;
	int status = 0;
	(void)argc;	
	
	

	do {

		if (isatty(STDIN_FILENO))
			printf(":) ");

		line = getline(&buf, &nread, stdin);

		if (line == -1 || hsh_strcmp("exit\n", buf) == 0)
		{
			free(buf);
			break;
		}
		buf[line - 1] = '\0';

		if (hsh_strcmp("env", buf) == 0)
		{
			hsh_env();
			continue;
		}

		if (hsh_line(buf) == 1)
		{
			status = 0;
			continue;
		}

		argv = hsh_parse(buf, delim);

		argv[0] = hsh_path(argv[0]);

		if (argv[0] != NULL)
			status = execute(argv);
		else
			perror("Error");
		free(argv);

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

int execute(char **argv)
{
	int checked, pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
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
