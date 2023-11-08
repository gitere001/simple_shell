#include "sshell.h"

/**
* main - entry point
* Return: 0 for success
*/
int main(void)
{
	char user_command[150];

	while (1)
	{
		prompt_display();
		read_user_command(user_command, sizeof(user_command));
		if (strcmp(user_command, "exit") == 0)
		{
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

	return (0);
}
