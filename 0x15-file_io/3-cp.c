#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * checkArgumentsNumber - checks for the correct number of arguments
 * @args: number of arguments
 *
 * Return: void
 */
void checkArgumentsNumber(int args)
{
	if (args != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * fileFromDoesntExist - checks that file_from exists and can be read
 * @check: checks if true of false
 * @source: file_from name
 * @from: file descriptor of file_from, or -1
 * @to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void fileFromDoesntExist(ssize_t check, char *source, int from, int to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		if (from != -1)
			close(from);
		if (to != -1)
			close(to);
		exit(98);
	}
}

/**
 * createFail - checks that file_to was created and/or can be written to
 * @check: checks if true of false
 * @destination: file_to name
 * @d_from: file descriptor of file_from, or -1
 * @d_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void createFail(ssize_t check, char *destination, int d_from, int d_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", destination);
		if (d_from != -1)
			close(d_from);
		if (d_to != -1)
			close(d_to);
		exit(99);
	}
}

/**
 * check100 - checks that file descriptors were closed properly
 * @check: checks if true or false
 * @fd: file descriptor
 *
 * Return: void
 */
void check100(int check, int fd)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - opies the content of a file to another file.
 * @args: number of arguments passed
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int args, char *argv[])
{
	int fd_from, fd_to, close_to, close_from;
	ssize_t lenr, lenw;
	char buffer[1024];
	mode_t file_perm;

	checkArgumentsNumber(args);
	fd_from = open(argv[1], O_RDONLY);
	fileFromDoesntExist((ssize_t)fd_from, argv[1], -1, -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	createFail((ssize_t)fd_to, argv[2], fd_from, -1);
	lenr = 1024;
	while (lenr == 1024)
	{
		lenr = read(fd_from, buffer, 1024);
		fileFromDoesntExist(lenr, argv[1], fd_from, fd_to);
		lenw = write(fd_to, buffer, lenr);
		if (lenw != lenr)
			lenw = -1;
		createFail(lenw, argv[2], fd_from, fd_to);
	}
	close_to = close(fd_to);
	close_from = close(fd_from);
	check100(close_to, fd_to);
	check100(close_from, fd_from);
	return (0);
}