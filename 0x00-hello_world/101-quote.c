#include<unistd.h>
#include<stdio.h>
#include<string.h>
/**
 * main - Entry point
 *
 * Description: 'program that prints exactly giveen sentence'
 *
 * Return: Always 1 (Success)
 */
int main(void)
{
	const char message*  = "and that piece of art is 
		useful\" - Dora Korpar, 2015-10-19\n";
	write(2, message, strlen(message));
	return (1);
}
