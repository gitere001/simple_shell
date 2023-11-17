#include "sshell.h"

/**
* _env - function that prints all environment variables
*
* Return:  void
*/
int _env(void)
{
	int j;

	for (j = 0; environ[j]; j++)
	{
		ss_print(__environ[j]);
		_putchar('\n');
	}

	return (0);
}
