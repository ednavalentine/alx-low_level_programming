#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ELF_M "\x7F\x45\x4C\x46"
#define ELF_MAGIC 4

typedef struct 
{
	uint8_t ident[16];
	uint8_t class;
	uint8_t data;
	uint8_t version;
	uint8_t abi;
	uint8_t abi_version;
	uint8_t pad[7];
	uint16_t type;
	uint32_t entry;
} Elf32_Ehdr;
/**
 * diplay_magic - show elf magic
 * @header: header of the file
 * Return: void
 */
void display_magic(const Elf32_Ehdr *header)
{
	int ink;

	printf("Magic: ");
	for (ink = 0; ink < ELF_MAGIC; ink++)
		printf("%02X ", header->ident[ink]);
	printf("\n");
}
/**
 * display_class - show class
 * @header: header of the file
 * Return: void
 */
void display_class(const Elf32_Ehdr *header)
{
	printf("Class: ");
	switch (header->class)
	{
		case 1:
			printf("ELF32\n");
			break;
		case 2:
			printf("ELF64\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
}
/**
 * display_data - display data
 * @header: header of the file
 * Return: void
 */
void display_data(const Elf32_Ehdr *header)
{
	printf("Data: ");
	switch (header->data)
	{
		case 1U:
			printf("2's complement, little endian\n");
			break;
		case 2:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
}
/**
 * display_type - diplays file types
 * @header: header of the file
 * Return: void
 */
void display_type(const Elf32_Ehdr *header)
{
	printf("Type: ");
	switch (header->type)
	{
		case 0:
			printf("NONE (No file type)\n");
			break;
		case 1:
			printf("REL (Relocatable file)\n");
			break;
		case 2:
			printf("EXEC (Executable file)\n");
			break;
		case 3:
			printf("DYN (Shared object file)\n");
			break;
		case 4:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
}
/**
 * display_elf_header - display elf headers
 * @filename: name of the file
 * Return: void
 */
void display_elf_header(const char *filename)
{
	int ink;
	Elf32_Ehdr header;

	ink = open(filename, O_RDONLY);
	if (ink == -1)
	{
		dprintf(STDERR_FILENO, "Failed to open file: %s\n", filename);
		exit(98);
	}
	if (read(ink, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Failed to read ELF header: %s\n", filename);
		exit(98);
	}
	if (memcmp(header.ident, ELF_M, ELF_MAGIC) != 0U)
	{
		dprintf(STDERR_FILENO, "Invalid ELF file: %s\n", filename);
		exit(98);
	}
	display_magic(&header);
	display_class(&header);
	display_data(&header);
	printf("Version: %d\n", header.version);
	printf("OS/ABI: ");
	switch (header.abi)
	{
		case 0:
			printf("System V\n");
			break;
		case 1:
			printf("HP-UX\n");
			break;
		case 2:
			printf("NetBSD\n");
			break;
		case 3:
			printf("Linux\n");
			break;
		case 4:
			printf("GNU Hurd\n");
			break;
		case 5:
			printf("Solaris\n");
			break;
		case 6:
			printf("AIX\n");
			break;
		case 7:
			printf("IRIX\n");
			break;
		case 8:
			printf("FreeBSD\n");
			break;
		case 9:
			printf("Tru64\n");
			break;
		case 10:
			printf("Novell Modesto\n");
			break;
		case 11:
			printf("OpenBSD\n");
			break;
		case 12:
			printf("OpenVMS\n");
			break;
		case 13:
			printf("NonStop Kernel\n");
			break;
		case 14:
			printf("AROS\n");
			break;
		case 15:
			printf("Fenix OS\n");
			break;
		case 16:
			printf("CloudABI\n");
			break;
		case 17:
			printf("Stratus Technologies OpenVOS\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
	printf("ABI Version: %d\n", header.abi_version);
	display_type(&header);
	printf("Entry point address: 0x%08X\n", header.entry);
	close(ink);
}
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	const char *ink_name;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (1);
	}
	ink_name = argv[1];
	display_elf_header(ink_name);
	return (0);
}
