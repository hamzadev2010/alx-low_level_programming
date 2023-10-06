#include "hash_tables.h"
/**
* hash_table_set - Adds an element to the hash table
* @ht: The hash table
* @key: The key of the element
* @value: The value of the element
* Return: The element added to the table
*/

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	char *temporal_value = NULL;
	hash_node_t *temporal = NULL, *new = NULL;

	if (!ht || !ht->array || !value)
		return (0);

	if (strlen(key) == 0 || !key)
		return (0);
	temporal_value = strdup(value);
	if (!temporal_value)
		return (0);
	index = key_index((unsigned char *)key, ht->size);

	/* checking if athe collision exists */
	temporal = ht->array[index];
	while (temporal)
	{
		if (strcmp(temporal->key, key) == 0)
		{
			free(temporal->value);
			temporal->value = temporal_value;
			temporal->value = strdup(value);
			free(temporal_value);
			return (1);
		}
		temporal = temporal->next;
	}
	/* checking If a collision doesn't exits in insert*/
	new = malloc(sizeof(hash_node_t));
	if (!new)
	{
		free(new);
		return (0);
	}
	new->key = strdup(key);
	new->value = temporal_value;
	new->next = ht->array[index];
	ht->array[index] = new;
	return (1);
}
