#include "sshell.h"

/**
* _help - displays help information for built-in commands
* Return: void
*/
void _help(void)
{
	ss_print("\nShell Version 1.0.0\n\n");
	ss_print("Usage: ./hsh\n\n");
	ss_print("Shell built-in commands:\n\n");
	ss_print("help\t\tDisplay this help information\n\n");
	ss_print("cd [dir]\tChange the current working directory\n\n");
	ss_print("env\t\tDisplay the environment variables\n\n");
	ss_print("setenv\t\tSet an environment variable\n\n");
	ss_print("unsetenv\tUnset an environment variable\n\n");
	ss_print("exit\t\tExit the shell\n\n");
}
