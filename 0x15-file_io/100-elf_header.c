/*
 * File: 100-elf_header.c
 * Auth: hamza
 */

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void validate_elf_format(unsigned char *ident);
void display_magic_numbers(unsigned char *ident);
void display_class(unsigned char *ident);
void display_data(unsigned char *ident);
void display_version(unsigned char *ident);
void display_abi(unsigned char *ident);
void display_osabi(unsigned char *ident);
void display_type(unsigned int type, unsigned char *ident);
void display_entry(unsigned long int entry, unsigned char *ident);
void close_elf(int fd);

/**
 * validate_elf_format - Validates if a file is in ELF format.
 * @ident: Pointer to an array containing the ELF magic numbers.
 *
 * Description: Exits with code 98 if the file is not an ELF file.
 */
void validate_elf_format(unsigned char *ident)
{
int index;

for (index = 0; index < 4; index++)
{
if (ident[index] != 127 &&
ident[index] != 'E' &&
ident[index] != 'L' &&
ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

// Rest of the functions remain unchanged.

int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int fd, r;

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close_elf(fd);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
r = read(fd, header, sizeof(Elf64_Ehdr));
if (r == -1)
{
free(header);
close_elf(fd);
dprintf(STDERR_FILENO, argv[1]);
exit(98);
}

validate_elf_format(header->e_ident);
printf("ELF Header:\n");
display_magic_numbers(header->e_ident);
display_class(header->e_ident);
display_data(header->e_ident);
display_version(header->e_ident);
display_osabi(header->e_ident);
display_abi(header->e_ident);
display_type(header->e_type, header->e_ident);
display_entry(header->e_entry, header->e_ident);

free(header);
close_elf(fd);
return (0);
}

