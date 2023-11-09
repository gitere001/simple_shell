#include "sshell.h"
/**
 * clear_command - Clears the terminal screen.
 */
void clear_command(void)
{
	ss_print("\033[H\033[J");
}
