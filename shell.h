#ifndef SHELL_H
#define SHELL_H

/* == Global Variables == */
extern char **environ;

/* == Standard Libraries == */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* == Struct Varaibles == */

/* == Prototype functions */
int hsh_line(char *buf);
char *hsh_strcpy(char *dest_file, char *src_file);
char *hsh_strcat(char *dest_file, char *src_file);
int hsh_strcmp(char *str1, char *str2);
char **hsh_parse(char *str, char *delim);
void *hsh_calloc(unsigned int ar, unsigned int s);
int hsh_strlen(char *str);
char *hsh_getenv(char *hsh_env);
void hsh_env(void);
char *hsh_path(char *cmd);
int execute(char **argv);

#endif
