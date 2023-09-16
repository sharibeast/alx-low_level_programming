#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _strncmp - function to compare two strings
 * @t1: param for the first string
 * @t2: param for the second string
 * @p: param for  the max number of bytes to compare
 *
 * Return: 0 if the first n bytes of s1 and s2 are equal, otherwise non-zero
 */
int _strncmp(const char *t1, const char *t2, size_t p)
{
	for ( ; p && *t1 && *t2; --p, ++t1, ++t2)
	{
		if (*t1 != *t2)
			return (*t1 - *t2);
	}
	if (p)
	{
		if (*t1)
			return (1);
		if (*t2)
			return (-1);
	}
	return (0);
}

/**
 * _close - functon to close a file descriptor and print an error message upon failure
 * @fd: param for the file descriptor to close
 */
void _close(int fd)
{
	if (close(fd) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't close fd\n", 22);
	exit(98);
}

/**
 * _read - function to  read from a file and show error if failed
 * @fd: param for the file descriptor (to read from)
 * @buf: param for the buffer (to write)
 * @count: params for the number of bytes (to read)
 */
void _read(int fd, char *buf, size_t count)
{
	if (read(fd, buf, count) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't read from file\n", 28);
	_close(fd);
	exit(98);
}

/**
 * elf_magic - function to print the ELF magic
 * @buffer: param for the ELF header
 */
void elf_magic(const unsigned char *buffer)
{
	unsigned int n;

	if (_strncmp((const char *) buffer, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
		exit(98);
	}

	printf("ELF Header:\n  Magic:   ");

	for (n = 0; n < 16; ++n)
		printf("%02x%c", buffer[n], n < 15 ? ' ' : '\n');
}

/**
 * elf_class - function to print ELF class
 * @buffer: param for the ELF header
 *
 * Return: bit mode (32 or 64)
 */
size_t elf_class(const unsigned char *buffer)
{
	printf("  %-34s ", "Class:");

	if (buffer[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}
	if (buffer[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}
	printf("<unknown: %x>\n", buffer[EI_CLASS]);
	return (32);
}

/**
 * elf_data - function to print ELf data
 * @buffer:  param for ELF header
 *
 * Return: 1 if big endian, otherwise 0
 */
int elf_data(const unsigned char *buffer)
{
	printf("  %-34s ", "Data:");

	if (buffer[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
		return (1);
	}
	if (buffer[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}
	printf("Invalid data encoding\n");
	return (0);
}

/**
 * elf_version -  function to print  ELF version
 * @buffer: parameter for ELF header
 */
void elf_version(const unsigned char *buffer)
{
	printf("  %-34s %u", "Version:", buffer[EI_VERSION]);

	if (buffer[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * elf_osabi - This function print the ELF OS/ABI
 * @buffer: the ELF header
 */
void elf_osabi(const unsigned char *buffer)
{
	const char *ostable_var[19] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI",
		"Stratus Technologies OpenVOS"
	};

	printf("  %-34s ", "OS/ABI:");

	if (buffer[EI_OSABI] < 19)
		printf("%s\n", ostable_var[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buffer[EI_OSABI]);
}

/**
 * elf_abivers - print ELF ABI version
 * @buffer: the ELF header
 */
void elf_abivers(const unsigned char *buffer)
{
	printf("  %-34s %u\n", "ABI Version:", buffer[EI_ABIVERSION]);
}

/**
 * elf_type - Print the ELF type
 * @buffer: ElF header parameter
 * @big_endian: endianness (param) the  big endian if non-zero
 */
void elf_type(const unsigned char *buffer, int big_endian)
{
	char *type_table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};
	unsigned int type;

	printf("  %-34s ", "Type:");

	if (big_endian)
		type = 0x100 * buffer[16] + buffer[17];
	else
		type = 0x100 * buffer[17] + buffer[16];

	if (type < 5)
		printf("%s\n", type_table[type]);
	else if (type >= ET_LOOS && type <= ET_HIOS)
		printf("OS Specific: (%4x)\n", type);
	else if (type >= ET_LOPROC && type <= ET_HIPROC)
		printf("Processor Specific: (%4x)\n", type);
	else
		printf("<unknown: %x>\n", type);
}

/**
 * elf_entry - print address of the entry point
 * @buffer:  String contain entry point address
 * @bit_mode: (32 or 64) bit mode
 * @big_endian: endianness (big endian if non-zero)
 */
void elf_entry(const unsigned char *buffer, size_t bit_mode, int big_endian)
{
	int addsize_var = bit_mode / 8;

	printf("  %-34s 0x", "Entry point address:");

	if (big_endian)
	{
		while (addsize_var && !*(buffer))
			--addsize_var, ++buffer;

		printf("%x", *buffer & 0xff);

		while (--addsize_var > 0)
			printf("%02x", *(++buffer) & 0xff);
	}
	else
	{
		buffer += addsize_var;

		while (addsize_var && !*(--buffer))
			--addsize_var;

		printf("%x", *buffer & 0xff);

		while (--addsize_var > 0)
			printf("%02x", *(--buffer) & 0xff);
	}

	printf("\n");
}

/**
 * main - Fle contents to another file (COPY)
 * @argc: number of arguments
 * @argv: values of args
 *
 * Return: Always 0
 */
int main(int argc, const char *argv[])
{
	int fd;
	unsigned int bitmode_var;
	unsigned char buffer_var[18];
	int bigendian_var;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error: Can't read from file\n", 28);
		exit(98);
	}

	_read(fd, (char *) buffer_var, 18);

	elf_magic(buffer_var);
	bitmode_var = elf_class(buffer_var);
	bigendian_var = elf_data(buffer_var);
	elf_version(buffer_var);
	elf_osabi(buffer_var);
	elf_abivers(buffer_var);
	elf_type(buffer_var, bigendian_var);

	lseek(fd, 24, SEEK_SET);
	_read(fd, (char *) buffer_var, bitmode_var / 8);

	elf_entry(buffer_var, bitmode_var, bigendian_var);

	_close(fd);

	return (0);
}
