#include "main.h"

/**
 * _strlen - function that returns the length of a string
 * @s: checks address of the string
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; *s != '\0'; s++)
		len++;

	return (len);
}
