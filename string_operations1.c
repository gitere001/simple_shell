#include "sshell.h"

/**
 * _strlen - Calculate the length of a string
 * @str: The input string
 * Return: The length of the string
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
	len++;
	}

	return (len);
}
/**
 * _strcmp - a function that compares 2 strings
 * @str1: first string.
 * @str2: second string to be compared to first one.
 * Return: when s1 and s2 are equal returns 0.
 * negative value whenever str1 < str2.
 * positive whenever str1 > str2.
*/
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((int) (*str1) - (*str2));
}
/**
 * _strncmp - this function compares strings upto n lenth.
 * @str1: the first string.
 * @str2: second string to be compared to first.
 * @n: max characters to be comapare.
 * Return: 0 whenever string are equal up to n.
 * negative value when str1 is less than str2
 * positive value when str1 is greater than str2
 * If both strings are shorter than n and are equal, returns 0.
*/
int _strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char st1, st2;

	while (n-- > 0)
	{
		st1 = (unsigned char) *str1++;
		st2 = (unsigned char) *str2++;

		if (st1 != st2)
			return (st1 - st2);
		if (st1 == '\0')
			break;
	}
	return (0);
}
/**
 * _strstr - Locates the first occurrence of the substring needle
 *           in the string haystack.
 * @haystack: The string to search in.
 * @needle: The substring to search for.
 *
 * Return: If needle is an empty string, haystack is returned;
 *         if needle occurs nowhere in haystack, NULL is returned;
 *         otherwise, a pointer to the beginning of the first occurrence
 *         of needle is returned.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}
			}

			if (needle[j] == '\0')
			{
				return (&haystack[i]);
			}
		}
	}

	return (NULL);
}
/**
 * _strchr - function that finds a character in string
 * @str: a pointer to array of users input.
 * @c: character to be located in users input.
 * Return: initial occurrence of the char or null when not found.
*/
char *_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

