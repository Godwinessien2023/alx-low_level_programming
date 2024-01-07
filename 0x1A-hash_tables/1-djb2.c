#include "htable.h"

/**
 * hash_djb2 - To create hash func using djb2 algorithm.
 * @str: The input string
 * Return: Hash function
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	int c;
	unsigned long int hash;

	hash = 5381;

	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c;
	}

	return (hash);
}
