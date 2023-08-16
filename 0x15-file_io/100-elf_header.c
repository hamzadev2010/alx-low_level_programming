#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void validate_elf_file(unsigned char *elf_magic);
void display_magic_numbers(unsigned char *elf_magic);
void display_class(unsigned char *elf_magic);
void display_data_encoding(unsigned char *elf_magic);
void display_version(unsigned char *elf_magic);
void display_abi(unsigned char *elf_magic);
void display_osabi(unsigned char *elf_magic);
void display_type(unsigned int elf_type, unsigned char *elf_magic);
void display_entry_point(unsigned long int entry_point, unsigned char *elf_magic);
void close_elf_file(int elf_fd);

/**
 * validate_elf_file - Checks if a given file is in ELF format.
 * @elf_magic: Pointer to an array containing ELF magic numbers.
 *
 * Description: If the file is not an ELF file, exit with code 98.
 */
void validate_elf_file(unsigned char *elf_magic)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (elf_magic[index] != 127 &&
		    elf_magic[index] != 'E' &&
		    elf_magic[index] != 'L' &&
		    elf_magic[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * main - Displays information from the ELF header of a given file.
 * @argc: Number of arguments provided to the program.
 * @argv: Array of pointers to the program's arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exit with code 98 if the file is not an ELF file or if an error occurs.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int elf_fd, read_result;

	elf_fd = open(argv[1], O_RDONLY);
	if (elf_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf_file(elf_fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	read_result = read(elf_fd, header, sizeof(Elf64_Ehdr));
	if (read_result == -1)
	{
		free(header);
		close_elf_file(elf_fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	validate_elf_file(header->e_ident);
	printf("ELF Header:\n");
	display_magic_numbers(header->e_ident);
	display_class(header->e_ident);
	display_data_encoding(header->e_ident);
	display_version(header->e_ident);
	display_osabi(header->e_ident);
	display_abi(header->e_ident);
	display_type(header->e_type, header->e_ident);
	display_entry_point(header->e_entry, header->e_ident);

	free(header);
	close_elf_file(elf_fd);
	return (0);
}
