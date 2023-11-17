#include "sshell.h"

/**
* _clear - clears screen
* @args: arguments passed
* Return: 1 for continuation of execution
* 0 to exit
*/
int _clear(char **args)
{
	(void)args;
	ss_print("\033[2J\033[H");
	return (1);
}
