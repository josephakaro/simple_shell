#include "shell.h"

/**
 * hsh_line - If there is empty buffer (line);
 *
 * @buffer: Copied line by the buffer.
 *
 * Return: Always 1 on char found or 0 on empty char.
 */

int hsh_line(char *buffer)
{
	int i = 0, status = 1;

	while (buffer[i] != '\0')
	{
		if (buffer[i] != ' ')
			return (0);
		i++;
	}

	return (status);
}

/**
 * hsh_calloc - custom malloc function
 *
 * @ar: array
 * @s: bit size
 *
 * Return: Either a pointer or NULL character.
 */

void *hsh_calloc(unsigned int ar, unsigned int s)
{
	char *p = NULL;
	unsigned int i = 0;

	if (ar && s)
	{
		if (ar == 0 || s == 0)
			return (NULL);

		p = malloc(ar * s);
			if (p == NULL)
				return (NULL);
		for (; i < (ar * s); i++)
			p[i] = 0;
	}
	return (p);
}

/**
 * hsh_getenv - customized get env function.
 *
 * @hsh_env: environment variable
 *
 * Return: The env contents to the console.
 */

char *hsh_getenv(char *hsh_env)
{
	int i = 0;
	int count;
	int t;

	while (environ[i])
	{
		t = 1;

		for (count = 0; environ[i][count] != '='; count++)
		{
			if (environ[i][count] != hsh_env[count])
				t = 0;
		}
		if (t == 1)
			break;
		i++;
	}
	return (&environ[i][count + 1]);
}

/**
 * hsh_env - Customize environment function.
 *
 * Return: The printed env to the console.
*/

void hsh_env(void)
{
	int i;

	for (i = 0; environ[i] ; i++)
	{
		printf("%s\n", environ[i]);
	}
}

/**
 * hsh_path - Customized path finder.
 *
 * @cmd: command to look for.
 *
 * Return: The found command path.
 */

char *hsh_path(char *cmd)
{
	char *path = hsh_getenv("PATH");
	char *path_linked = NULL;
	char *path_copy;
	char **path_parsed;
	char *delim = ":";

	struct stat index;
	int path_len = 0;
	int i = 0;

	if (stat(cmd, &index) == 0)
		return (cmd);
	path_copy = malloc(hsh_strlen(path) + 1);
	path_copy = hsh_strcpy(path_copy, path);
	path_parsed = hsh_parse(path_copy, delim);

	for (; path_parsed[i] ; i++)
	{
		path_len = hsh_strlen(path_parsed[i]);

		if (path_parsed[i][path_len - 1] != '/')
			path_linked = hsh_strcat(path_parsed[i], "/");
		path_linked = hsh_strcat(path_parsed[i], cmd);

		if (stat(path_linked, &index) == 0)
			break;
	}

	free(path_copy);

	if (!path_parsed[i])
	{
		free(path_parsed);
		return (NULL);
	}

	free(path_parsed);
	return (path_linked);
}
