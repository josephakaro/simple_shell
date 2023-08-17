#include "shell.h"

char parse(char *args)
{
    char *token, *delim = " \t\n\r";
    size_t i;

    token = strtok(args, delim);

    for(i = 0; token != NULL; i++)
    {
        args[i] = token;

        token = strtok(NULL, delim);
    }

    args[i] = NULL;

    return (args);
}