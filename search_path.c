#include "sshell.h"

/**
* search_command_in_path - Searches for a command in directories
* specified in PATH.
* @target_command: Pointer to the command string to locate.
*
* Return: Pointer to the full path of the command (success) or NULL (failure).
*/
char *search_command_in_path(char *target_command)
{
	struct stat fstat;
	int stat_r, index;

	char buffer[PATH_BUFFER_SIZE];

	char *env_path, *result_path, **path_tokens;

	env_path = get_command_path();
	if (!env_path)
		return (NULL);

	path_tokens = tokenize(env_path, PATH_SEPARATOR);
	if (!path_tokens)
	{
		free(env_path);
		return (NULL);
	}

	for (index = 0; path_tokens[index]; index++)
	{
		_memset(buffer, 0, PATH_BUFFER_SIZE);
		_strcpy(buffer, path_tokens[index]);
		_strcat(buffer, "/");
		_strcat(buffer, target_command);

		stat_r = stat(buffer, &fstat);
		if (stat_r == 0 && S_ISREG(fstat.st_mode) && (fstat.st_mode & S_IXUSR))
		{
			free_tokens(path_tokens);
			result_path = malloc(sizeof(char) * (strlen(buffer) + 1));
			if (!result_path)
				return (NULL);

			strcpy(result_path, buffer);
			return (result_path);
		}
	}

	if (stat_r == -1)
		free_tokens(path_tokens);

	return (NULL);
}
