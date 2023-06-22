#include "main.h"


/**
 * jack_bauer - function that prints every minute of the day
 * Description: 'program that prints every minute of the day'
 * Return: void.
 * On error, -1 is returned, and errno is set appropriately.
 */
void jack_bauer(void)
{
	int hour, minute;

	for (hour = 0; hour < 24; hour++)
	{
		for (minute = 0; minute < 60; minute++)
		{
			_putchar((hour / 10) + '0');
			_putchar((hour % 10) + '0');
			_putchar(':');
			_putchar((minute / 10) + '0');
			_putchar((minute % 10) + '0');
			_putchar('\n');
		}
	}
}
