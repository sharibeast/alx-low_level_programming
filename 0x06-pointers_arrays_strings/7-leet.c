#include "main.h"
/**
 * leet -function that encodes a string into 1337
 * @m: input value
 * Return: m value
 */
char *leet(char *m)
{
	int i, j;
	char numbers[] = "4433007711";
	char letters[] = "aAeEoOtTlL";

	for (i = 0; m[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (m[i] == letters[j])
			{
				m[i] = numbers[j];
			}
		}
	}
	return (m);
}
