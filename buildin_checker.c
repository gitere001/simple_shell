#include "sshell.h"

/**
* check_buildins(char **args)

* @args: command arguments
*
* Return: 0 if command is not builtin
* 1 if command is buildin
*/
int check_buildins(char **args)
{
	if (!args[0])
		return (0);
	if (!_strcmp(args[0], "exit"))
		_exit1(args);
	else if (!_strcmp(args[0], "env"))
		_env();
	else if (!_strcmp(args[0], "setenv"))
		_setenv(args);
	else if (!_strcmp(args[0], "unsetenv"))
		_unsetenv(args);
	else if (!_strcmp(args[0], "help"))
		_help();
	else if (!_strcmp(args[0], "cd"))
		_cd(args);
	else if (!_strcmp(args[0], "clear"))
		_clear(args);
	else
		return (0);
	return (1);

}