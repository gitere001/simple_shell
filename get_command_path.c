#include "sshell.h"

/**
* get_command_path - finds and return the evironment variable value
*
* Return: the found path pointer
*/
char *get_command_path(void)
{
	return (custom_getenv("PATH"));
}
