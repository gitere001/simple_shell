#include "sshell.h"

/**
* main - entry point
* Return: 0 for success
*/
int main(void)
{
	char user_command[150];
	const char *args[MAX_ARGS];

	while (1)
	{
		prompt_display();
		read_user_command(user_command, sizeof(user_command));
		tokenize_command(user_command, args);
		execute_command(user_command);
	}

	return (0);
}
