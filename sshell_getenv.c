#include "sshell.h"

/**
* custom_getenv - Get the value of an environment variable
* @env_var: Name of the environment variable
*
* Return: Value of the environment variable, or NULL if it doesn't exist
*/
char *custom_getenv(const char *env_var)
{
	char **env_ptr;

	size_t len = _strlen(env_var);

	for (env_ptr = environ; *env_ptr != NULL; env_ptr++)
	{
		if (_strncmp(*env_ptr, env_var, len) == 0 && (*env_ptr)[len] == '=')
		{
			return (&(*env_ptr)[len + 1]);
		}
	}
	return (NULL);
}
