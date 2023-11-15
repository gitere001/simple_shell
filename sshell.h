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

void ss_print(char *str);
void _printerror(char *error);
void prompt_display(void);
char *read_input(void);
void free_last_command(void);
size_t _strlen(const char *str);
int execute(char *command);




#endif
