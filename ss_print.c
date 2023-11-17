#include "sshell.h"

/**
* ss_print - a function that print input to stdout
* @input: string passed.
* Return: null
*/
void ss_print(const char *input)
{
	write(STDOUT_FILENO, input, _strlen(input));
}
