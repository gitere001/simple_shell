#include "sshell.h"

/**
 * execute_command - Tokenize the user input, find the command path,
 * and execute it in a child process.
 * @user_command: The user-provided command to execute.
 * Return: void
 */
void execute_command(const char *user_command)
{
	const char *args[MAX_ARGS];
	pid_t child_id = fork();

	size_t num_args = 0;
	char *token = strtok(strdup(user_command), " ");

	while (token != NULL && num_args < MAX_ARGS - 1)
	{
		args[num_args++] = token;
		token = strtok(NULL, " ");
	}

	args[num_args] = NULL;

	if (child_id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_id == 0)
	{
		const char *full_path = find_command_path(args[0]);

		if (full_path != NULL)
		{
			execve(full_path, (char *const *)args, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			ss_print("Command not found: ");
			ss_print(args[0]);
			ss_print("\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
