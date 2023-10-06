#include "hash_tables.h"
/**
* key_index - Function to determine the index of the key in a hash table
* @key: The key of the hash table
* @size: The size of the array
* Return: The index of the key
*/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int find_the_index;

	find_the_index = hash_djb2(key);
	return (find_the_index % size);
}
