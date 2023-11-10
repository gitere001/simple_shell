#include"sshell.h"

/**
 * cd_command - Change current directory.
 * Command syntax: cd [DIRECTORY]
 * Handles cd with or without argument,
 * interpreting cd - as cd $HOME.
 * @user_command: User command.
 * Return: void
 */
void cd_command(const char *user_command)
{
	char *user_command_copy = strdup(user_command);
	char *token = strtok(user_command_copy, " ");

	token = strtok(NULL, " ");

	if (token == NULL || strcmp(token, "~") == 0 || strcmp(token, "$HOME") == 0)
	{
		token = getenv("HOME");
	}

	if (token != NULL)
	{
		char current_directory[1024];

		getcwd(current_directory, sizeof(current_directory));

		if (chdir(token) != 0)
		{
			perror("cd");
		}
		else
		{
			setenv("PWD", getcwd(current_directory, sizeof(current_directory)), 1);
		}
	}

	free(user_command_copy);
}

