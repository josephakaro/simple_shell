#include "shell.h"

/**
 * main - simple unix like program.
 *
 * @argc:
 * @argv:
 *
 * Return: Execute the command entered by user.
 */

int main(int argc, char **argv, char *envp[])
{
	/* == Variables == */
	(void)argc;
	char *args, *token;
	char *lineptr = NULL, *prompt = ":) ";
	int status;
	size_t len;
	ssize_t line;
	pid_t pid;

	/* == Run through the loop == */
	while (1)
	{
		if(isatty(0))
			printf("%s", prompt);

		line = getline(&lineptr, &len, stdin);

		if(line == -1)
		{
			free(lineptr);
			break;
		}

		strcpy(lineptr, args);

		token = parse(args);

		pid = fork();

		if (pid == 0)
		{
			if(execve(args[], args, envp))
			{
				perror(":( ");
				exit(EXIT_FAILURE);
			}
		}

		if(pid > 0)
			wait(&status);
	}

	/* == Clean Ups and shutdown == */
	_putchar('\n');

	free(lineptr);
	exit(status);
}
