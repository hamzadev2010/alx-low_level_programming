#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main: checking the code
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *hat;

    hat = hash_table_create(1024);
    printf("%p\n", (void *)hat);
    return (EXIT_SUCCESS);
}

