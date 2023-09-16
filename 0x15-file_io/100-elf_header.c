#include "main.h"


/**
 * get_data - get endianness of ELF file
 * @ehdr: pointer to struct of ELF header features
 */
void get_data(Elf64_Ehdr *ehdr)
{
	printf("%-35s", "Data:");
	switch (ehdr->e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("Unknown data format\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little-endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement big-endian\n");
		break;
	}
}

/**
 * get_velf - get version of ELF file
 * @ehdr: pointer to struct of ELF header features
 */
void get_velf(Elf64_Ehdr *ehdr)
{
	printf("%-35s", "Version:");
	switch (ehdr->e_ident[EI_VERSION])
	{
	case EV_NONE:
		printf("%d (invalid)\n", EV_NONE);
		break;
	case EV_CURRENT:
		printf("%d (current)\n", EV_CURRENT);
		break;
	}
}

/**
 * get_osabi - determine which ABI convention is in use
 * @ehdr: pointer to struct of ELF header features
 */
void get_osabi(Elf64_Ehdr *ehdr)
{
	printf("%-35s", "OS/ABI:");
	switch (ehdr->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Stand-alone (embedded)\n");
		break;
	default:
		printf("<unknown: %d>\n", ehdr->e_ident[EI_OSABI]);
	}
}

/**
 * get_vabi - get ABI version
 * @ehdr: pointer to struct of ELF header features
 */
void get_vabi(Elf64_Ehdr *ehdr)
{
	printf("%-35s%d\n", "ABI Version:", ehdr->e_ident[EI_ABIVERSION]);
}

/**
 * main - display information contained in ELF file header
 * @argc: number of arguments
 * @argv: array of string arguments
 *
 * Return: EXIT_SUCCESS on success, otherwise 98 on error
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t r;
	Elf64_Ehdr *helf;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <elf_file>\n", argv[0]);
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: could not open %s\n", argv[1]);
		exit(98);
	}
	helf = malloc(sizeof(Elf64_Ehdr));
	if (helf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: out of memory\n");
		close(fd);
		exit(98);
	}
	r = read(fd, helf, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(helf);
		dprintf(STDERR_FILENO, "Error: could not read %s\n", argv[1]);
		close(fd);
		exit(98);
	}
	if (close(fd))
		dprintf(STDERR_FILENO, "Problem closing fd %d", fd);
	get_magic(helf, argv[1], fd);
	get_class(helf);
	get_data(helf);
	get_velf(helf);
	get_osabi(helf);
	get_vabi(helf);
	get_type(helf);
	get_entry(helf);
	free(helf);
	exit(EXIT_SUCCESS);
}
