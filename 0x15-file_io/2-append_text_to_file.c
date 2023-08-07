#include "main.h"

/**
 * append_text_to_file -  function that appends text at the end of a file.
 * @filename: A pointer
 * @text_content: The string to add
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fopen, fwrite, len;

	len = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fwrite = write(fopen, text_content, len);
	fopen = open(filename, O_WRONLY | O_APPEND);

	if (fopen == -1 || fwrite == -1)
	{
		return (-1);
	}

	close(fopen);

	return (1);
}
