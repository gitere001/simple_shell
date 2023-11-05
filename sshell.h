#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_ARGS 100

void prompt_display(void);
void ss_print(const char *input);
void read_user_command(char *user_command, size_t size);
void tokenize_command(const char *user_command, const char *args[]);
void execute_command(const char *user_command);
#endif
