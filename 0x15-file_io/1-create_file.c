#include "main.h"

/**
 * create_file - function that creates a file.
 * @filename:  name of the file to create and text_content
 * @text_content: content of file
 * Return: 1 on success, -1 on failure 
 */
int create_file(const char *filename, char *text_content)
{
	int file;
            int file_write;
            int file_length;

	file_length = 0;
	if (!filename)
            {
		return (-1);
            }
	if (text_content)
	{
		for (; text_content[file_length];)
			file_length++;
	}
	file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	file_write = write(file, text_content, file_length);
	if (file == -1 || file_write == -1)
            {
		return (-1);
            }
	close(file);
	return (1);
}
