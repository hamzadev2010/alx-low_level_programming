#include "hash_tables.h"
/**
 * hash_table_get - Retrieves the element from the hash table
 * @ht: The hash table
 * @key: The key
* Return: The element retrieved from the table
*/

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t *temp = NULL;

	if (!key)
		return (NULL);

	if (ht)
	{
		index = key_index((const unsigned char *)key, ht->size);
		temp = ht->array[index];
		while (temp)
		{
			if (strcmp(temp->key, key) == 0)
				return (temp->value);
			temp = temp->next;
		}
	}
	return (NULL);
}
