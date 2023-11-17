#include "sshell.h"
/**
* _strcspn - Calculate the length of the initial segment of str
* consisting of characters not in the reject string.
* @str: The string to be checked.
* @reject: The string containing characters to be excluded.
*
* Return: The length of the initial segment.
*/

size_t _strcspn(const char *str, const char *reject)
{

	const char *s;

	const char *r;

	for (s = str; *s != '\0'; ++s)
	{
		for (r = reject; *r != '\0'; ++r)
		{
			if (*s == *r)
			{
				return (s - str);
			}
		}
	}

	return (s - str);
}
