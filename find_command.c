#include "sshell.h"
/**
 * find_command_path - finds the path of the executable file in.
 * the and directories
 * @command: users commands
 * Return: strdup(full_path) and null if no path is found
 */

const char *find_command_path(const char *command)
{
	const char *path = getenv("PATH");
	const char *delimiters = ":";
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, delimiters);

	while (token != NULL)
	{
		char full_path[1024];

		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);

	if (access(full_path, X_OK) == 0)
	{
		free(path_copy);
		return (strdup(full_path));
	}

	token = strtok(NULL, delimiters);
	}

	free(path_copy);
	return (NULL);
}

