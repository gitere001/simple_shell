#include "sshell.h"

/**
 * main - Implements a simple shell
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	char *command;
	char **arguments;
	int result;

	do {
		command = read_input();

		if (!command || *command == '\0')
			break;

		arguments = tokenize_input(command);
		if (!arguments || !*arguments)
		{
			free(command);
			free_tokens(arguments);
			continue;
		}

		result = execute(arguments);
		free(command);
		free_tokens(arguments);

		result = 1;
	} while (result);

	return (EXIT_SUCCESS);
}

