#include "sshell.h"

/**
* custom_getline - Read input from the standard input.
*
* Return: The string entered by the user.
*/
void *custom_getline(void)
{
	static char input_buffer[BUFFER_SIZE];

	static int buffer_position, buffer_size;

	char *user_input = NULL;

	char current_character;

	int input_length = 0;

	while (1)
	{
		if (buffer_position >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
			buffer_position = 0;

			if (buffer_size == 0)
				return (user_input);
			else if (buffer_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		current_character = input_buffer[buffer_position];
		buffer_position++;

		if (current_character == '\n')
		{
			user_input = realloc(user_input, input_length + 1);
			user_input[input_length] = '\0';
			return (user_input);
		}
		else
		{
			user_input = realloc(user_input, input_length + 1);
			user_input[input_length] = current_character;
			input_length++;
		}
	}
}
