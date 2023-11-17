#include "sshell.h"

/**
* _atoi - a function that convertsstring to interger.
* @s: string that will be converted.
* Return: interger equivalent of the string.
*/
int _atoi(const char *s)
{
	int j, sign;

	unsigned int n;

	j = 0;
	sign = 1;
	n = 0;

	while (s[j] != '\0')
	{
		if (s[j] == '-')
			sign *= -1;
		else if (s[j] >= '0' && s[j] <= '9')
			n = (n * 10) + (s[j] - '0');
		else
			break;
		j++;
	}
	return (n * sign);
}
/**
* _memset - fills a block of memory with constant byte
* @a: pointer to the block of memory
* @bytes: byte that will fill *a
* @b: total bytes to be filled
* Return: pointer to the block of memory
*/
char *_memset(char *a, char bytes, unsigned int b)
{
	unsigned int j;

	for (j = 0; j < b; j++)
		a[j] = bytes;
	return (a);
}
/**
* _memcpy - this function copies memory.
* @des: bufer to be copied to.
* @source: what is to be copied.
* @bytes: number of bytes source
* Return: 0 for success
*/
char *_memcpy(char *des, char *source, unsigned int bytes)
{
	unsigned int j;

	for (j = 0; j < bytes; j++)
		des[j] = source[j];
	return (des);
}
/**
* _realloc - reallocates memory
* @pt: pointer to previous allocated memory by malloc
* @p_size: size of the previous block of memory
* @n_size: size of the new block of memory
*
* Return: pointer to the new block of memory
*/
void *_realloc(void *pt, unsigned int p_size, unsigned int n_size)
{
	char *ptr;

	if (pt == NULL)
		return (malloc(n_size));

	if (n_size == 0)
	{
		free(pt);
		return (NULL);
	}

	if (n_size == p_size)
		return (pt);

	ptr = malloc(n_size);
	if (ptr == NULL)
		return (NULL);

	p_size = p_size < n_size ? p_size : n_size;
	while (p_size--)
		ptr[p_size] = ((char *)pt)[p_size];
	free(pt);
	return (ptr);
}
/**
* _calloc - allocates memory for an array of elements
* @nmemb: number of elements
* @size: size of each element in bytes
*
* Return: pointer to the allocated memory, or NULL on failure
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int total_size = nmemb * size;

	void *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);

	_memset(ptr, 0, total_size);

	return (ptr);
}
