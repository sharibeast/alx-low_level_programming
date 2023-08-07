#include "main.h"

/**
 * append_text_to_file -  function that appends text at the end of a file.
 * @filename: A pointer
 * @text_content: The string to add
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int x, y, length;

	length = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	x = open(filename, O_WRONLY | O_APPEND);
	y = write(x, text_content, length);

	if (x == -1 || y == -1)
	{
		return (-1);
	}

	close(x);

	return (1);
}
