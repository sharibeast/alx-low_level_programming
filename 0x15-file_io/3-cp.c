#include "main.h"
#define MAX_SIZE 1024

/**
 * createBuffer - create a 1024 bytes buffer
 * @file_buff: buffer file
 * Return: created buffer
 */
char *createBuffer(char *file_buff)
{
	char *buffer;

	buffer = (char *)malloc(sizeof(char) * MAX_SIZE);
	if (!buffer)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_buff);
		exit(99);
	}
	return (buffer);
}


/**
 * f_close - function to close a file when file descriptor cant closed
 * @file_d: file descriptor to be closed
 */
void f_close(int file_d)
{
	int d;

	d = close(file_d);
	if (d == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd FD_VALUE\n");
		exit(100);
	}
}


/**
 * main - main function
 * @argc: number of arguments
 * @argv: argument lists
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *bufferCreated;
	int from, to, fileRead, file_write;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fileRead = read(from, bufferCreated, MAX_SIZE);
	bufferCreated = createBuffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while (fileRead > 0)
	{
		if (fileRead == -1 || from == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		file_write = write(to, bufferCreated, fileRead);
		if (to == -1 || file_write == 1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
		fileRead = read(from, bufferCreated, MAX_SIZE);
		to = open(argv[2], O_WRONLY | O_APPEND);
	}
	free(bufferCreated);
	close(from);
	close(to);
	return (0);
}
