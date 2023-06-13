#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>
#include <string.h>

#define BUFF 4096

void look_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_type(unsigned char *e_ident, unsigned int e_type);
void print_entry_point(unsigned char *e_ident, unsigned long int e_entry);
void print_osabi(unsigned char *e_ident);
void print_abi_version(unsigned char *e_ident);
void elf_closer(int elf);

/**
 * look_elf - confirm if a file is elf
 * @e_ident: header of file
 * Return: void
 */
void look_elf(unsigned char *e_ident)
{
	int ink;

	for (ink = 0; ink < 4; ink++)
	{
		if (e_ident[ink] != 127 &&
				e_ident[ink] != 'E' &&
				e_ident[ink] != 'L' &&
				e_ident[ink] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * print_magic - show elf magic
 * @e_ident: header of the file
 * Return: void
 */
void print_magic(unsigned char *e_ident)
{
	int ink;

	printf("  Magic:                              ");
	for (ink = 0; ink < EI_NIDENT; ink++)
	{
		printf("%02X ", e_ident[ink]);
		if (ink == EI_NIDENT -1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * print_class - show class
 * @e_ident: header of the file
 * Return: void
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                              ");
	switch (e_ident[EI_CLASS])
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
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
			break;
	}
}
/**
 * print_data - display data
 * @e_ident: header of the file
 * Return: void
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                               ");
	switch (e_ident[EI_DATA])
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
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
			break;
	}
}
/**
 * print_version - prints version of elf header
 * @e_ident: the printed header
 * Return: void
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                            %d (current)\n",
			e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
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
 * @e_ident: header of the file
 * @e_type: unsigned int to be used
 * Return: void
 */
void print_type(unsigned char *e_ident, unsigned int e_type)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("  Type:                               ");
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
 * @e_ident: header to be used
 * @e_entry: unsigned long int to be used
 * Return: void
 */
void print_entry_point(unsigned char *e_ident, unsigned long int e_entry)
{
	printf("  Entry point address:                ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}
/**
 * print_osabi - displays abi
 * @e_ident: the item to be displayed
 * Return: abi
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                             ");
	switch (e_ident[EI_OSABI])
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
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
			break;
	}
}
/**
 * print_abi_version - prints version of abi
 * @e_ident: header to be used
 * Return: void
 */
void print_abi_version(unsigned char *e_ident)
{
	printf("  ABI Version:                        %d\n",
			e_ident[EI_ABIVERSION]);
}
/**
 * elf_closer - close a elf file
 * @elf: int to be used
 * Return: 98 if error
 */
void elf_closer(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
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
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	head = malloc(sizeof(Elf64_Ehdr));
	if (head == NULL)
	{
		free(head);
		elf_closer(ink);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	jum = read(ink, head, sizeof(Elf64_Ehdr));
	if (jum == -1)
	{
		free(head);
		elf_closer(ink);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	look_elf(head->e_ident);
	printf("ELF Header:\n");
	print_magic(head->e_ident);
	print_class(head->e_ident);
	print_data(head->e_ident);
	print_version(head->e_ident);
	print_osabi(head->e_ident);
	print_abi_version(head->e_ident);
	print_type((unsigned char *)head, head->e_type);
	print_entry_point((unsigned char *)head, head->e_entry);
	
	free(head);
	elf_closer(ink);
	return (0);
}
