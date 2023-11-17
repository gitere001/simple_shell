#include "sshell.h"

/**
* _setenv - set environment variables
* @args: Arguments passed including nameand value of the variable
*
* Return: void
*/
int _setenv(char **args)
{
	char *variable_name, *variable_value;

	if (args[1] == NULL || args[2] == NULL)
	{
		_printerror("usage: setenv VARIABLE VALUE\n");
		return (-1);
	}
	variable_name = args[1];
	variable_value = args[2];

	if (setenv(variable_name, variable_value, 1) != 0)
	{
		_printerror("setenv");
		return (-1);
	}
	return (0);
}

/**
* _unsetenv - undo environment variable
* @args: Name of variable as argument passed
*
* Return: void
*/
int _unsetenv(char **args)
{
	char *variable_name;

	if (args[1] == NULL)
	{
		_printerror("usage: unsetenv VARIABLE\n");
		return (-1);
	}
	variable_name = args[1];

	if (unsetenv(variable_name) != 0)
	{
		_printerror("unsetenv");
	}
	return (0);
}
