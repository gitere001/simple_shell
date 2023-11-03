#include "sshell.h"

/**
 * exec_command - execute the command of the child process
 * @user_command: the command that the user input
 * Return: 0 for success
 */
void exec_command(const char *user_command)
{
	pid_t child_id = fork();
	char **argv = malloc(2 * sizeof(char *));

	if (argv == NULL)
	{
	perror("malloc");
	exit(EXIT_FAILURE);
	}

	argv[0] = (char *)user_command;
	argv[1] = NULL;

	if (child_id == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (child_id == 0)
	{
	execve(user_command, argv, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	free(argv);
}
