#include "sshell.h"

/**
 * execute - Execute a command without arguments.
 * @command: The command to be executed.
 *
 * Return: The exit status of the executed command.
 */
int execute(char *command)
{
	pid_t id;
	int status = 0;

	if (command == NULL)
		return (status);

	id = fork();
	if (id < 0)
	{
		perror("fork");
		return (1);
	}

	if (id == 0)
	{
		char **args = malloc(2 * sizeof(char *));

		if (args == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		args[0] = command;
		args[1] = NULL;

		if (execve(command, args, NULL) == -1)
		{
			perror("execve");
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do

		{
			waitpid(id, &status, 0);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (status);
}
