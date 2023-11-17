#include "sshell.h"

/**
* _cd - change current directory in simple_shell
* @args: argument passed
* Return: void
*/
void _cd(char **args)
{
	char *target_directory = args[1];

	int result;

	if (target_directory == NULL)
	{
		target_directory = custom_getenv("HOME");
		if (target_directory == NULL)
		{
			ss_print("cd: HOME directory not found\n");
			return;
		}

	}
	result = chdir(target_directory);
	if (result == -1)
	{
		perror("cd");
	}
}
