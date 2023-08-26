#include "main.h"

/**
 * data_print - Console data of ELF file
 * @ptr:  A ptr to an array ELF class
 */
void data_print(unsigned char *ptr)
{
	printf("  Data:                              ");

	switch (ptr[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", ptr[EI_CLASS]);
	}
}

/**
 * version_print - Show version of ELF header
 * @ptr:  A ptr to an array ELF class
 */
void version_print(unsigned char *ptr)
{
	printf("  Version:                           %d",
	       ptr[EI_VERSION]);

	switch (ptr[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}



/**
 * entry_print - Prints the entry point of an ELF header.
 * @e: The address of the ELF entry point.
 * @ptr:  A ptr to an array ELF class
 */
void entry_print(unsigned long int e, unsigned char *ptr)
{
	printf("  Entry point address:               ");

	if (ptr[EI_DATA] == ELFDATA2MSB)
	{
		e = ((e << 8) & 0xFF00FF00) |
			  ((e >> 8) & 0xFF00FF);
		e = (e << 16) | (e >> 16);
	}

	if (ptr[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)e);
	}

	else
	{
		printf("%#lx\n", e);
	}
}

/**
 * elf_close - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 */
void elf_close(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - .Show Info contained in ELF header (start of ELF file)
 * @argc: arguments
 * @argv: ptr arguments
 *
 * Return: always succes.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *hdr;
	int q, p;

	q = open(argv[1], O_RDONLY);
	if (q == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	hdr = malloc(sizeof(Elf64_Ehdr));
	if (hdr == NULL)
	{
		elf_close(q);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	p = read(q, hdr, sizeof(Elf64_Ehdr));
	if (p == -1)
	{
		free(hdr);
		elf_close(q);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	elf_check(hdr->e_ident);
	printf("ELF Header:\n");
	magic_print(hdr->e_ident);
	print_class(hdr->e_ident);
	data_print(hdr->e_ident);
	version_print(hdr->e_ident);
	os_abi_print(hdr->e_ident);
	aBI_print(hdr->e_ident);
	type_print(hdr->e_type, hdr->e_ident);
	entry_print(hdr->e_entry, hdr->e_ident);

	free(hdr);
	elf_close(q);
	return (0);
}