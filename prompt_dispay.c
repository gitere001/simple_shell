#include "sshell.h"

/**
* prompt_display - displays a prompt to show that shell is ready to
* accept input
* Return: void
*/
void prompt_display(void)
{
	ss_print("simple shell$ ");
	fflush(stdout);
}
