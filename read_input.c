#include "sshell.h"

static char *last_input;

/**
 * read_input - Reads users input.
 * Return: Pointer to where the user's input is stored.
 */
char *read_input(void)
{
	size_t command_size = 0;
	ssize_t bytes_read;
	char *command;

	prompt_display();

	do

	{
		bytes_read = getline(&command, &command_size, stdin);

		if (bytes_read == -1)
		{
			free(command);
			ss_print("\n");
			return (NULL);
		}

		command[bytes_read - 1] = '\0';

	} while (command[0] == '\0' || isspace(command[0]));

	last_input = command;
	return (command);
}

/**
 * free_last_command - Frees the recent user's command.
 * Frees memory allocated to the recent command.
 * Return: void
 */
void free_last_command(void)
{
	if (last_input != NULL)
	{
		free(last_input);
		last_input = NULL;
	}
}
