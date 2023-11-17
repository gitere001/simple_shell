#include "sshell.h"

/**
* _exit1 - function to exit simple_shell
* @args: passed arguments
*
* Return: void
*/
void _exit1(char **args)
{
	int result = 0;

	if (args[1] != NULL)
	{
		result = _atoi(args[1]);
	}
	free_tokens(args);
	free_last_command();
	exit(result);
}
