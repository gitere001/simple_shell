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


extern char **environ;

#define BUFFER_SIZE 1024
#define PATH_BUFFER_SIZE 4095
#define PATH_SEPARATOR ":"

/*prompt_display.c*/
void prompt_display(void);

/*read_input.c*/
char *read_input(void);
void free_last_command(void);

/*buildins functions*/
int check_buildins(char **args);
void _cd(char **args);
int _clear(char **args);
int _env(void);
void _exit1(char **args);
void _help(void);
int _setenv(char **args);
int _unsetenv(char **args);


/*sshell_free.c*/
void free_err(char **args_array, char *error_message);
void free_tokens(char **pt);
void free_path(void);

/*sshell_getenv.c*/
char *custom_getenv(const char *env_var);

/*get_command_path.c*/
char *get_command_path(void);

/*search_path.c*/
char *search_command_in_path(char *target_command);

/*sshell_getline.c*/
void *custom_getline(void);

/*command_executor.c*/
int execute(char **argv);

/*parsing.c*/
char **tokenize(char *inputString, const char *delimiter);
char **tokenize_input(char *user_input);

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
