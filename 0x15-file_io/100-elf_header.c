#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>
#include <string.h>

#define BUFF 4096

void look_elf(char *elf_header);
void print_error(const char *message);
void print_magic(unsigned char *elf_header);
void print_class(unsigned char *elf_header);
void print_data(unsigned char *elf_header);
void print_version(unsigned char *elf_header);
void print_type(unsigned char *elf_header, unsigned int e_type);
void print_entry_point(unsigned char *elf_header, unsigned long int entry);
void print_osabi(unsigned char *elf_header);
void print_abi_version(unsigned char *elf_header);

/**
 * look_elf - confirm if a file is elf
 * @elf_header: header of file
 * Return: void
 */
void look_elf(char *elf_header)
{
	int ink;

	for (ink = 0; ink < 4; ink++)
	{
		if (elf_header[ink] != 127 &&
				elf_header[ink] != 'E' &&
				elf_header[ink] != 'L' &&
				elf_header[ink] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * print_error - prints error
 * @message: error message
 * Return: 98
 */
void print_error(const char *message)
{
	dprintf(STDERR_FILENO, "Error: %s\n", message);
	exit(98);
}
/**
 * print_magic - show elf magic
 * @elf_header: header of the file
 * Return: void
 */
void print_magic(unsigned char *elf_header)
{
	int ink;

	printf("Magic:                              ");
	for (ink = 0; ink < EI_NIDENT; ink++)
	{
		printf("%02X ", elf_header[ink]);
		if (ink == EI_NIDENT -1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * print_class - show class
 * @elf_header: header of the file
 * Return: void
 */
void print_class(unsigned char *elf_header)
{
	printf("Class:                              ");
	switch (elf_header[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Unknown: %x>\n", elf_header[EI_CLASS]);
			break;
	}
}
/**
 * print_data - display data
 * @elf_header: header of the file
 * Return: void
 */
void print_data(unsigned char *elf_header)
{
	printf("Data:                               ");
	switch (elf_header[EI_DATA])
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
			printf("<unknown: %x>\n", elf_header[EI_DATA]);
			break;
	}
}
/**
 * print_version - prints version of elf header
 * @elf_header: the printed header
 * Return: void
 */
void print_version(unsigned char *elf_header)
{
	printf("Version:                            %d (current)\n",
			elf_header[EI_VERSION]);
	switch (elf_header[EI_VERSION])
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
 * print_type - diplays file types
 * @elf_header: header of the file
 * @e_type: unsigned int to be used
 * Return: void
 */
void print_type(unsigned char *elf_header, unsigned int e_type)
{
	if (elf_header[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("Type:                               ");
	switch (e_type)
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
			printf("Unknown: %x>\n", e_type);
			break;
	}
}
/**
 * print_entry_point - entry point of elf header
 * @elf_header: header to be used
 * @entry: unsigned long int to be used
 * Return: void
 */
void print_entry_point(unsigned char *elf_header, unsigned long int entry)
{
	printf("Entry point address:                ");
	if (elf_header[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}
	if (elf_header[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);
	else
		printf("%#lx\n", entry);
}
/**
 * print_osabi - displays abi
 * @elf_header: the item to be displayed
 * Return: abi
 */
void print_osabi(unsigned char *elf_header)
{
	printf("OS/ABI:                             ");
	switch (elf_header[EI_OSABI])
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
			printf("UNIX - Tru64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_header[EI_OSABI]);
			break;
	}
}
/**
 * print_abi_version - prints version of abi
 * @elf_header: header to be used
 * Return: void
 */
void print_abi_version(unsigned char *elf_header)
{
	printf("ABI Version:                        %d\n",
			elf_header[EI_ABIVERSION]);
}
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: void
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int ink, jum;
	Elf64_Ehdr *head;

	ink = open(argv[1], O_RDONLY);
	if (ink == -1)
		print_error("Failed to open file");
	head = malloc(sizeof(Elf64_Ehdr));
	if (head == NULL)
	{
		print_error("Failed to read ELF header");
		exit(98);
	}
	jum = read(ink, head, sizeof(Elf64_Ehdr));
	if (jum == -1)
	{
		free(head);
		print_error("Not an ELF file");
		exit(98);
	}
	look_elf(head->e_ident);
	printf("ELF Header:\n");
	print_magic((unsigned char *)head);
	print_class((const char *)head);
	print_data((unsigned char *)head);
	print_version((unsigned char *)head);
	print_osabi((unsigned char *)head);
	print_abi_version((unsigned char *)head);
	print_type((unsigned char *)head, head->e_type);
	print_entry_point((unsigned char *)head, head->e_entry);
	
	free(head);
	close(ink);
	return (0);
}
