#include "main.h"
/**
 * elf_check -  verify is file is ELF file
 * @e_ident:  A ptr to array with ELG magic num
 *
 * file not ELF exit code 98
 */
void elf_check(unsigned char *e_ident)
{
	int n;

	for (n = 0; n < 4; n++)
	{
		if (e_ident[n] != 127 &&
		    e_ident[n] != 'L' &&
		    e_ident[n] != 'E' &&
		    e_ident[n] != 'F')
		{
			dprintf(STDERR_FILENO, "Error Message: This is Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * magic_print - Console magic number of ELF file
 * @e_ident: A ptr to an array
 *
 * Description: Magic numbers are separated by spaces.
 */
void magic_print(unsigned char *e_ident)
{
	int n;

	printf("  Magic Log:   ");

	for (n = 0; n < EI_NIDENT; n++)
	{
		printf("%02x", e_ident[n]);

		if (n == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
}

/**
 * os_abi_print - Prints the OS/ABI of an ELF header.
 * @e_ident:  A ptr to an array ELF class
 */
void os_abi_print(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
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
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * ABI_print -  Print ABI version of ELF header
 * @e_ident:  A ptr to an array ELF class
 */
void ABI_print(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * type_print - Show type of AN ELF
 * @type_elf: The ELF type.
 * @e_ident:  A ptr to an array ELF class
 */
void type_print(unsigned int type_elf, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		type_elf >>= 8;
	}

	printf("  Type:                              ");

	switch (type_elf)
	{
	case ET_NONE:
		printf("NONE (None)\n");
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
	default:
		printf("<unknown: %x>\n", type_elf);
	}
}


