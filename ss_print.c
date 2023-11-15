#include "sshell.h"

/**
* ss_print - a function that print input to stdout
* @str: string passed
* Return: null
*/
void ss_print(char *str)
{
	size_t len;
	ssize_t bytes_written;

	len = _strlen(str);
	bytes_written = write(STDOUT_FILENO, str, len);
	if (bytes_written == -1)
	{
		perror("write");
	}

}

/**
 * _printerror - prints error in standard error
 * @error: error to be printed
 * Return: void
*/
void _printerror(char *error)
{
	size_t len;
	ssize_t bytes_written;

	len = _strlen(error);
	bytes_written = write(STDERR_FILENO, error, len);
	if (bytes_written == -1)
	{
		perror("write");
	}

}
