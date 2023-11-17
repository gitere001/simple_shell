#include "sshell.h"

/**
* free_err - frees allocated pointers after a system error
* @args_array: pointer to a pointer to an array of pointers
* @error_message: pointer to a pointer to an array of characters
*
* Return: void.
*/
void free_err(char **args_array, char *error_message)
{
	int index;

	for (index = 0; args_array[index]; index++)
		free(args_array[index]);
	free(args_array);
	free(error_message);
	exit(EXIT_FAILURE);
}
/**
* free_tokens - frees memory allocated dynamically by tokenize()
* @pt: pointer to allocated memory
*
* Return: void
*/
void free_tokens(char **pt)
{
	int j;

	for (j = 0; pt[j]; j++)
		free((pt[j]));
	free(pt);
}
/**
* free_path - Release the global variable storing the
* PATH environment variable value
*
* This function is responsible for freeing the memory allocated for the global
* variable that holds the value of the PATH environment variable. It searches
* for the "PATH=" entry in the environment variables and frees
* the corresponding
* memory.
*
* Return: Void
*/
void free_path(void)
{
	if (environ != NULL)
	{
		size_t index = 0;

		while (environ[index] != NULL)
		{
			if (_strncmp(environ[index], "PATH=", 5) == 0)
			{
				free(environ[index]);
				environ[index] = NULL;
				break;
			}
			index++;
		}
	}
}
