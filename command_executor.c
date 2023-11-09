#include "sshell.h"

/**
 * execute_command - Tokenize the user input, find the command path,
 * and execute it in a child process.
 * @user_command: The user-provided command to execute.
 * Return: void
*/

void execute_command(const char *user_command)
{
	const char *command = user_command;
	char *args[MAX_ARGS];
	size_t num_args = 0;
	pid_t child_id;

	char *user_command_copy = strdup(user_command);

	char *token = strtok(user_command_copy, " ");

	while (token != NULL && num_args < MAX_ARGS - 1)
	{
		args[num_args++] = token;
		token = strtok(NULL, " ");
	}
	args[num_args] = NULL;

	if (num_args == 0)
	{

		free(user_command_copy);
		return;
	}

	if (strchr(args[0], '/'))
	{
		command = args[0];
	}
	else
	{
		const char *full_path = find_command_path(args[0]);

		if (full_path != NULL)
		{
		command = full_path;
		}
		else
		{
			ss_print("Command not found: ");
			ss_print(args[0]);
			ss_print("\n");
			free(user_command_copy);
			return;
		}
	}

	child_id = fork();

	if (child_id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_id == 0)
	{
		execve(command, args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	free(user_command_copy);
}
