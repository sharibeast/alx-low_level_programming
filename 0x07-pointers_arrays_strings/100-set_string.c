#include <stdio.h>

/**
 * set_string - function that sets the value of a pointer to a char.
 * Description: 'function that sets the value of a pointer to a char.'
 * @s: Pointer to variable str
 * @to: Pointer variable
 * Return: Character
 */
void set_string(char **s, char *to)
{
	*s = to;
}
