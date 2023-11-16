#include "sshell.h"

/**
 * execute - Execute a command arguments.
 * @argv: the string containing command plusn arguments
 *
 * Return: The exit status of the executed command.
 */
int execute(char **argv)
{
	pid_t child_id;
	int result = 0;
	char *command_path, *envcp[2];

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
		perror(argv[0]), free_tokens(argv), free_last_command();
	if (child_id == 0)
	{
		envcp[0] = get_command_path();
		envcp[1] = NULL;
		command_path = NULL;
		if (argv[0][0] != '/')
			command_path = search_command_in_path(argv[0]);
		if (command_path == NULL)
			command_path = argv[0];
		if (execve(command_path, argv, envcp) == -1)
		{
			perror(argv[0]), free_tokens(argv), free_last_command();
			exit(EXIT_FAILURE);
		}
	}
	else
	{

	do
	{
    waitpid(child_id, &result, WUNTRACED);
	}while (!WIFEXITED(result) && !WIFSIGNALED(result));
	}

	return (result);
 }
