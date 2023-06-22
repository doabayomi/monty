#include "monty.h"

/**
 * *strdup - duplicates a string in memory
 * @str: The string to duplicate
 *
 * Return: The copy of the string.
*/
char *strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *copy = (char *)malloc(len * sizeof(char));

	if (copy != NULL)
		memcpy(copy, str, len);
	return (copy);
}
