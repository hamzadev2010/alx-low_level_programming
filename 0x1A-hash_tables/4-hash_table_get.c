#include "hash_tables.h"
/**
  * hash_table_create - creates a new hash table
  * @size: array size
  * Return: pointer for created hash table
  */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned int i;
	hash_table_t *hat = malloc(sizeof(hash_table_t));

	if (size == 0)
		return (NULL);
	if (!new_ht)
		return (NULL);
	hat->array = malloc(sizeof(hash_node_t *) * size);
	if (!hat->array)
	{
		free(new_ht);
		return (NULL);
	}
	hat->size = size;
	for (i = 0; i < size; i++)
	{
		hat->array[i] = NULL;
	}
	return (hat);
}
