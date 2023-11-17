#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_ARGS 100
extern char **environ;

void prompt_display(void);
void handle_exit_command(const char *command);
void ss_print(const char *input);
void read_user_command(char *user_command, size_t size);
const char *find_command_path(const char *command);
void execute_command(const char *user_command);
void print_environment(void);
void clear_command(void);
void cd_command(const char *user_command);
size_t tokenize_user_input(const char *user_command, char *args[]);
int execute_builtin_commands(char *args[], const char *user_command);
void execute_external_command(const char *command, char *args[]);

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
size_t _strcspn(const char *str, const char *reject);


#endif
