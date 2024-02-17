#include "hash_tables.h"

/**
 * hash_table_set - A function that adds an element to the hash table.
 * @ht: The hash table
 * @key: The key
 * @value: The value
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *duplicate_value, *duplicate_key;
	hash_node_t *key_value, *current;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			return (1);
		}
		current = current->next;
	}
	duplicate_value = strdup(value);
	if (duplicate_value == NULL)
		return (0);
	key_value = malloc(sizeof(hash_node_t));
	if (key_value == NULL)
	{
		free(duplicate_value);
		return (0);
	}
	duplicate_key = strdup(key);
	if (duplicate_key == NULL)
	{
		free(duplicate_value);
		free(key_value);
		return (0);
	}
	key_value->key = duplicate_key;
	key_value->value = duplicate_value;
	key_value->next = ht->array[index];
	ht->array[index] = key_value;
	return (1);
}
