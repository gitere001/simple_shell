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
		exec_command(user_command);
	}

	return (0);
}
