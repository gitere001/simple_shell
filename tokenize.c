#include "sshell.h"

/**
 * tokenize_command - Tokenizes the user command and fills the args array.
 * @user_command: The user input command to be tokenized.
 * @args: The array to store the tokenized arguments.
 *
 * This function tokenizes the user command based on spaces and stores the
 * individual tokens in the args array. It ensures that the last element of
 * args is set to NULL to mark the end of the arguments.
 */
void tokenize_command(const char *user_command,const char *args[])
{
	int i = 0;
	char *token = strtok(strdup(user_command), " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;
}
