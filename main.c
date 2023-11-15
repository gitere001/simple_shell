#include "sshell.h"

/**
 * main - Implements a simple shell
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	char *input;
	int status;

	do {
		input = read_input();

		if (!input || *input == '\0')
			break;

		status = execute(input);

		free_last_command();
		free(input);

	} while (status);

	return (EXIT_SUCCESS);
}

