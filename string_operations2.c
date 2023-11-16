#include "sshell.h"
/**
* _strcpy - function that copies a string.
* @dest: destination string
* @src: source string
* Return: pointer to the destination string
*/
char *_strcpy(char *dest, char *src)
{
	int t = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[t])
	{
		dest[t] = src[t];
		t++;
	}
	dest[t] = 0;
	return (dest);
}
/**
* _strcat - a function that concatinate 2 strings
* @dest: buffer of destination string.
* @src: buffer of source string.
* Return: desination buffer's pointer.
*/
char *_strcat(char *dest, const char *src)
{
	char *tmp = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;

	return (tmp);

}
/**
* _strdup - function that duplicates a string.
* @str: string to be duplicated
* Return: pointer to the duplicated string, or NULL if insufficient memory
*/
char *_strdup(const char *str)
{
	size_t len = 0;
	const char *ptr = str;
	size_t i;
	char *dup_str;

	if (str == NULL)
		return (NULL);

	while (*ptr++ != '\0')
		len++;

	dup_str = (char *)malloc((len + 1) * sizeof(char));

	if (dup_str == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup_str[i] = str[i];

	return (dup_str);
}
/**
* _putchar - writes a character to the standard output
* @c: the character to be written
* Return: On success, the number of characters written is returned.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
* _strspn - gets the length of a prefix substring
* @str: pointer to the string to be checked
* @accept: pointer to the substring prefix to look for
*
* Return: the number of bytes in the initial segment
*/
unsigned int _strspn(char *str, char *accept)
{
	unsigned int count, accept_index;

	count = 0;

	for (count = 0; str[count]; count++)
	{
		for (accept_index = 0; accept[accept_index]; accept_index++)
		{
			if (str[count] == accept[accept_index])
				break;
		}

		if (!accept[accept_index])
			return (count);
	}

	return (count);
}
