#include "sshell.h"

/**
* read_user_command - reads user input command from standard input
* @user_command: a buffer to store user command
* @size: maximum size of the buffer
* Return: null
*/
void read_user_command(char *user_command, size_t size)
{
	if (fgets(user_command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			ss_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			ss_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	user_command[strcspn(user_command, "\n")] = '\0';
}

