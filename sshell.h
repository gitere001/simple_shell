#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

/*prompt_display.c*/
void prompt_display(void);

/*read_input.c*/
char *read_input(void);
void free_last_command(void);

/*command_executor.c*/
int execute(char *command);

/*ss_print*/
void ss_print(char *str);
void _printerror(char *error);

/*string_operation1*/
size_t _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *str, char c);

/*string_operations2*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
int _putchar(char c);
unsigned int _strspn(char *str, char *accept);

/*strings_operations3*/
int _atoi(const char *s);
char *_memset(char *a, char bytes, unsigned int b);
char *_memcpy(char *des, char *source, unsigned int bytes);
void *_realloc(void *pt, unsigned int p_size, unsigned int n_size);
void *_calloc(unsigned int nmemb, unsigned int size);

#endif
