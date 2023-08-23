#include "shell.h"

/**
 * hsh_strcmp - Comperes the given two strings.
 * @str1: The first string
 * @str2: The second string.
 * Return: The compared strings.
 */

int hsh_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);

		str1++;
		str2++;
	}
	return (0);
}

/**
 * hsh_strcpy - Customize strcpy.
 *
 * @dest_file: Destination
 * @src_file: Source file
 *
 * Return: @File Destinations
 */
char *hsh_strcpy(char *dest_file, char *src_file)
{
	char *s = dest_file;

	while (*src_file != '\0')
	{
		*dest_file = *src_file;
		dest_file++;
		src_file++;
	}
	*dest_file = '\0';
	return (s);
}

/**
 * hsh_parse - parsed string into tokens using delimiters.
 *
 * @str: string
 * @delim: Delimiters
 *
 * Return: The parsed string.
 */

char **hsh_parse(char *str, char *delim)
{
	char *token, **tokens;
	int count = 0;

	token = strtok(str, delim);
	tokens = (char **)hsh_calloc(100, sizeof(char *));

	if (!tokens)
	{
		free(tokens);
		return (NULL);
	}

	while (token)
	{
		tokens[count] = token;
		token = strtok(NULL, delim);
		count++;
	}
	return (tokens);
}

/**
 * hsh_strcat - function that concatenates two strings
 *
 * @dest_file: string Destinations.
 * @src_file: string Source
 *
 * Return: Destination of joined strings.
 */

char *hsh_strcat(char *dest_file, char *src_file)
{
	int i, j;

	for (i = 0; dest_file[i] != '\0'; i += 1)
	{}

	for (j = 0; src_file[j] != '\0'; j += 1)
	{
		dest_file[i] = src_file[j];
		i++;
	}
	dest_file[i] = '\0';
	return (dest_file);
}

/**
 * hsh_strlen - string length
 * @str: string
 * Return: result
 */

int hsh_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}
