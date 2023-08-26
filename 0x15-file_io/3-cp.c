#include "main.h"
#include <stdio.h>



/**
 * error_file - checks if files can be opened.
 * @dest_from: copy from.
 * @dest_to: copy file to.
 * @argv: arguments vector.
 * Return: void.
 */
void error_file(int dest_from, int dest_to, char *argv[])
{
	if (dest_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (dest_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - fuction that copy file to another dest
 * @argc: arguments.
 * @argv: arguments ptr.
 * Return: Always success.
 */


int main(int argc, char *argv[])
{
	int dest_from, dest_to, err_close;
	ssize_t nchars, nwr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	dest_from = open(argv[1], O_RDONLY);
	dest_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(dest_from, dest_to, argv);

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(dest_from, buf, 1024);
		if (nchars == -1)
			error_file(-1, 0, argv);
		nwr = write(dest_to, buf, nchars);
		if (nwr == -1)
			error_file(0, -1, argv);
	}

	err_close = close(dest_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_from);
		exit(100);
	}

	err_close = close(dest_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_from);
		exit(100);
	}
	return (0);
}
