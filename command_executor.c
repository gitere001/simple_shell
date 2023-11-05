#include "sshell.h"
/**
 * execute_command - Execute a user command in a child process
 * @user_command: The user-provided command to execute
 *
 * This function takes a user command, tokenizes it into arguments, and
 * executes it in a child process using execve. It waits for the child
 * process to complete and handles errors.
 *
 * @user_command: The command to execute.
 */
void execute_command(const char *user_command)
{
	const char *args[MAX_ARGS];
	pid_t child_id = fork();

	tokenize_command(user_command, args);

	if (child_id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_id == 0)
	{
		execve(args[0], (char *const *)args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

