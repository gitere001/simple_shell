#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
void prompt_display(void);
void ss_print(const char *input);
void exec_command(const char *user_command);
void read_user_command(char *user_command, size_t size);

#endif
