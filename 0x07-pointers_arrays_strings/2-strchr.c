

/**
 * _strchr - function that locates a character in a string.
 * @s: string
 * @c: character
 *
 * Return: Nothing.
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}
	return (0);
}
