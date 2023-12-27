#include "shell_main.h"


/**
 * _strncmp - This function compares two strings up to a specific length
 * @str1: string one
 * @str2: string two
 * @n: amount of bytes to compare
 *
 * Return: 0 if string two is found in string one.
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	int i = 0;

	while (n > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if ((str1[i] == '\0') || (str2[i] == '\0'))
			break;
		i++;
		n--;
	}

	return (0);
}
/**
 * _memcpy - This function copies memory area
 * @dest: destination
 * @src: source
 * @n: number of bytes to copy
 *
 * Return: a pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
