#include "main.h"
#include <stdio.h>

/**
 * rot13 - function that prints an integer.
 * @s: pointer to string
 *
 * Return: *s
 */

char *rot13(char *s)
{
	int i;
	int j;
	char sample[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rotCharacters[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == sample[j])
			{
				s[i] = rotCharacters[j];
				break;
			}
		}
	}
	return (s);
}
