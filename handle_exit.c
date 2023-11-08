#include "sshell.h"

/**
 * handle_exit_command- command with an optional status.
 * If no status is provided, it defaults to 0.
 * Usage: exit [status]
 * @command: user command
 * Return: void
 */
void handle_exit_command(const char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}
	else if (strncmp(command, "exit ", 5) == 0)
	{
		const char *status_str = command + 5;
		int exit_status = atoi(status_str);

		exit(exit_status);
	}

}
