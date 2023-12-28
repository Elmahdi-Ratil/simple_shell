#include "shell_main.h"

/**
 * _getline - custom get line function
 * @lineptr: pointer to memory
 * @n: line buffer size
 * @stream: the file stream the line is gotten from
 *
 * Return: number of characters read
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char c;
	size_t num = 0;
	static char buff[BUFFER_SIZE];
	static size_t idx, B_read;

	(void)stream;
	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{	*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{	perror("Memory allocation failed");
			exit(EXIT_FAILURE); } }
	for (;;)
	{
		if (idx == B_read)
		{	B_read = read(STDIN_FILENO, buff, BUFFER_SIZE);
			if (B_read <= 0)
			{
				if (num == 0)
					return (-1); }
			idx = 0; }
		while (idx < B_read)
		{
			c = buff[idx++];
			if (c == '\n')
			{	(*lineptr)[num] = '\0';
				return (num); }
			if (num + 1 >= *n)
			{	*n += BUFFER_SIZE;
				*lineptr = realloc(*lineptr, *n);
				if (*lineptr == NULL)
				{
					perror("Memory reallocation failed");
					exit(EXIT_FAILURE); } }
			(*lineptr)[num++] = c; } }
	return (num);
}
