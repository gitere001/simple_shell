#include "sshell.h"

/**
 * print_environment - Prints the current environment.
 * Return: void
 */
void print_environment(void)
{
	int i = 0;
	char *env_var = NULL;

	while ((env_var = environ[i]) != NULL)
	{
	ss_print(env_var);
	ss_print("\n");
	i++;
	}
}
