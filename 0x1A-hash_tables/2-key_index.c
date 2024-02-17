#include "hash_tables.h"

/**
 * key_index - A function that gives you the index of a key.
 * @key: The key
 * @size: Size of the key
 * Return: The index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
