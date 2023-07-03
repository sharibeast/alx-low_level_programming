#include <stdio.h>

/**
 * _strspn - function that gets the length of a prefix substring.
 * Description: 'function that gets the length of a prefix substring'
 * @s: Pointer to variable
 * @accept: Pointer variable
 * Return: number of bytes in the initial segment
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int length = 0;
	char *ptr = s;

	while (*ptr != '\0')
	{
		char *ptrAccept = accept;
		int isMatch = 0;

		while (*ptrAccept != '\0')
		{
			if (*ptr == *ptrAccept)
			{
				isMatch = 1;
				break;
			}
			ptrAccept++;
		}

		if (isMatch == 0)
		{
			break;
		}

		length++;
		ptr++;
	}

	return (length);
}
