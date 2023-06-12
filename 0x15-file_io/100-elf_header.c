#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define ELF_MAGIC "\x7f""ELF"

typedef struct
{
	uint8_t e_ident[16];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint32_t e_entry;
	uint32_t e_phoff;
	uint32_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} Elf32_Ehdr;
/**
 * display_elf_header - display elf headers
 * @filename: name of the file
 * Return: void
 */
void display_elf_header(const char *filename)
{
	int ink;
	ssize_t ink_read;
	Elf32_Ehdr header;

	ink = open(filename, O_RDONLY);
	if (ink == -1)
	{
		dprintf(STDERR_FILENO, "Error opening file: %s\n", filename);
		exit(98);
	}
	ink_read = read(ink, &header, sizeof(Elf32_Ehdr));
	if (ink_read == -1)
	{
		dprintf(STDERR_FILENO, "Error reading file: %s\n", filename);
		exit(98);
	}
	if (strncmp((char *)header.e_ident, ELF_MAGIC, 4) != 0)
	{
		dprintf(STDERR_FILENO, "Not an ELF file: %s\n", filename);
		exit(98);
	}
	printf("Magic:   %02x %02x %02x %02x\n",
			header.e_ident[0], header.e_ident[1],
			header.e_ident[2], header.e_ident[3]);
	printf("Class:                             %s\n",
			header.e_ident[4] == 1 ? "ELF32" :
			header.e_ident[4] == 2 ? "ELF64" : "Invalid");
	printf("Data:                              %s\n",
			header.e_ident[5] == 1 ? "2's complement, little endian" :
			header.e_ident[5] == 2 ? "2's complement, big endian" : "Invalid");
	printf("Version:                           %u\n", header.e_ident[6]);
	printf("OS/ABI:                            %u\n", header.e_ident[7]);
	printf("ABI Version:                       %u\n", header.e_ident[8]);
	printf("Type:                              0x%04x\n", header.e_type);
	printf("Entry point address:               0x%08x\n", header.e_entry);
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
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (1);
	}
	display_elf_header(argv[1]);
	return (0);
}
