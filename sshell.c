#include "sshell.h"

/**
 * main - entry point
 * Return: 0 for success
 */
int main(void)
{
	char *user_command = NULL;
	size_t user_command_size = 0;

	while (1)
	{
		prompt_display();
		if (getline(&user_command, &user_command_size, stdin) == -1)
		{

			break;
		}

		if (user_command[strlen(user_command) - 1] == '\n')
		{
			user_command[strlen(user_command) - 1] = '\0';
		}
			handle_exit_command(user_command);

		if (strcmp(user_command, "exit") == 0)
		{
			free(user_command);
			break;
		}
		else if (strcmp(user_command, "env") == 0)
		{
			print_environment();
		}
		else
		{
			execute_command(user_command);
		}
	}

	free(user_command);
	return (0);
}
