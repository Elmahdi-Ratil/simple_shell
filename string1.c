#include "shell_main.h"


/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */

char *_strdup(char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
			return (ptr);
}
/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}
/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(const char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
/**
 * _strtok - This function tokenizes a string
 * @str: string to tokenize
 * @delim: string of delimiters
 *
 * Return: the starting position of the token
 */

char *_strtok(char *str, const char *delim)
{
	static char *input;
	char *tok_start;

	if (str != NULL)
		input = str;
	else if (input == NULL)
		return (NULL);

	while (*input != '\0' && _delim(*input, delim))
		input++;

	if (*input == '\0')
	{
		input = NULL;
		return (NULL);
	}

	tok_start = input;

	while (*input != '\0' && !_delim(*input, delim))
		input++;

	if (*input != '\0')
		*input++ = '\0';

	return (tok_start);
}
/**
 * _delim - This function checks if a given character is a delimiter
 * @c: character to check
 * @delim: string of delimiters
 *
 * Return: 1 if character is found, otherwise 0
 */

int _delim(char c, const char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
			return (1);
	}

	return (0);
}