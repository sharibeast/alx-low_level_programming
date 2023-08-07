#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - function that reads a text file and
 * prints it to the POSIX standard output.
 * @filename: A pointer
 * @letters: The number of letters.
 * Return: 0 if cant open filee
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *temp;
	ssize_t rc;
	ssize_t name_of_file;
	ssize_t c;

	if (filename == NULL)
	{
		return (0);
	}

	temp = malloc(sizeof(char) * letters);
	if (temp == NULL)
	{
		return (0);
	}

	name_of_file = open(filename, O_RDONLY);
	rc = read(name_of_file, temp, letters);
	c = write(STDOUT_FILENO, temp, rc);

	if (name_of_file == -1 || rc == -1 || c == -1 || c != rc)
	{
		free(temp);
		return (0);
	}

	free(temp);
	close(name_of_file);

	return (c);
}
