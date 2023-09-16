#include "main.h"

/**
 * get_magic - print magic numbers from ELF header if they exist, or exit
 * with error 98 if file is not ELF format
 * @ehdr: pointer to struct containing header features
 * @fname: name of file
 * @fd: file descriptor for `filename'
 */
void get_magic(Elf64_Ehdr *ehdr, char *fname, int fd)
{
	size_t i = 0;
	unsigned char *mgc = ehdr->e_ident;

	if (mgc[EI_MAG0] == ELFMAG0 &&
	    mgc[EI_MAG1] == ELFMAG1 &&
	    mgc[EI_MAG2] == ELFMAG2 &&
	    mgc[EI_MAG3] == ELFMAG3)
	{
		printf("Magic:  ");
		while (i < EI_NIDENT)
			printf(" %02x", ehdr->e_ident[i++]);
		printf("\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", fname);
		if (close(fd))
			dprintf(STDERR_FILENO, "Problem closing fd %d", fd);
		exit(98);
	}
}


/**
 * get_class - check class of ELF file
 * @ehdr: pointer to struct of header features
 */
void get_class(Elf64_Ehdr *ehdr)
{
	printf("%-35s", "Class:");
	switch (ehdr->e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("INVALID\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	}
}


/**
 * get_entry - determine entry point function address
 * @ehdr: pointer to struct of ELF header features
 */
void get_entry(Elf64_Ehdr *ehdr)
{
	printf("%-35s0x%lx\n", "Entry point address:",
	       (unsigned long) ehdr->e_entry);
}


/**
 * get_type - determine file type
 * @ehdr: pointer to struct of ELF header features
 */
void get_type(Elf64_Ehdr *ehdr)
{
	printf("%-35s", "Type:");
	switch (ehdr->e_type)
	{
	case ET_NONE:
		printf("NONE (Unknown type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	}
}


