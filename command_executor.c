#include "sshell.h"

/**
* execute - Execute a command arguments.
* @argv: the string containing command plus arguments
*
* Return: The exit status of the executed command.
*/
int execute(char **argv)
{
	pid_t child_id;
	int result = 0;

	if (argv == NULL || *argv == NULL)
		return (result);

	if (check_buildins(argv))
		return (result);

	child_id = fork();
	if (child_id < 0)
	{
		_printerror("fork");
		return (1);
	}

	if (child_id == -1)
	{
		perror(argv[0]);
		free_tokens(argv);
		free_last_command();
	}
	else if (child_id == 0)
	{
		result = execute_child(argv);
	}
	else
	{
		wait_for_child(child_id, &result);
	}

	return (result);
}

/**
* execute_child - Function executed by the child process.
* @argv: the string containing command plus arguments
*
* Return: The exit status of the executed command.
*/
int execute_child(char **argv)
{
	char *command_path;

	char *envcp[2];

	envcp[0] = get_command_path();
	envcp[1] = NULL;

	command_path = determine_command_path(argv[0]);

	if (command_path == NULL)
		command_path = argv[0];

	if (execve(command_path, argv, envcp) == -1)
	{
		perror(argv[0]);
		free_tokens(argv);
		free_last_command();
		exit(EXIT_FAILURE);
	}

	return (0);
}

/**
* wait_for_child - Wait for the child process to complete.
* @child_id: the process ID of the child
* @result: pointer to store the exit status of the child
*/
void wait_for_child(pid_t child_id, int *result)
{
	do

	{
		waitpid(child_id, result, WUNTRACED);
	} while (!WIFEXITED(*result) && !WIFSIGNALED(*result));
}

/**
* determine_command_path - Determine the path of the command.
* @command: the command to search for in PATH
*
* Return: The full path of the command, or NULL if not found.
*/
char *determine_command_path(char *command)
{
	if (command[0] != '/')
		return (search_command_in_path(command));

	return (NULL);
}
