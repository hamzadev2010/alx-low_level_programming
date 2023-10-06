#include "hash_tables.h"
/**
* hash_table_create : creation of new table
* @size: array size
* Return: pointer of new table
*/

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int index = 0;
	hash_table_t *tab = malloc(sizeof(hash_table_t));

	if (!tab)
		return (NULL);
	tab->array = malloc(sizeof(hash_node_t **) * size);
	if (!tab->array)
	{
		free(tab);
		return (NULL);
	}
	while (index < size)
	{
		tab->array[index] = NULL;
		index++;
	}
	tab->size = size;
	return (tab);
}
