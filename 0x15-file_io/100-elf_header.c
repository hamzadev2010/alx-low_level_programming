#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _strncmp - compare between 2 strings
 * @s1: first string
 * @s2: second string
 * @n: maximum number of bytes to compare
 *
 * Return: 0 if equal, non-zero otherwise
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    for (; n && *s1 && *s2; --n, ++s1, ++s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
    }
    if (n)
    {
        if (*s1)
            return (1);
        if (*s2)
            return (-1);
    }
    return (0);
}

/**
 * _close - close file and display any error
 * @fd: file descriptor to close
 */
void _close(int fd)
{
    if (close(fd) != -1)
        return;
    write(STDERR_FILENO, "Error: Can't close fd\n", 22);
    exit(98);
}

// ... (rest of the functions remain the same)

/**
 * main - copy file
 * @argc: argument count
 * @argv: argument value
 *
 * Return: Always 0
 */
int main(int argc, const char *argv[])
{
    unsigned char buffer[18];
    unsigned int bit_mode;
    int big_endian;
    int fd;

    if (argc != 2)
    {
        write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        write(STDERR_FILENO, "Error: Can't read from file\n", 28);
        exit(98);
    }

    _read(fd, (char *)buffer, 18);

    elf_magic(buffer);
    bit_mode = elf_class(buffer);
    big_endian = elf_data(buffer);
    elf_version(buffer);
    elf_osabi(buffer);
    elf_abivers(buffer);
    elf_type(buffer, big_endian);

    lseek(fd, 24, SEEK_SET);
    _read(fd, (char *)buffer, bit_mode / 8);

    elf_entry(buffer, bit_mode, big_endian);

    _close(fd);

    return (0);
}
