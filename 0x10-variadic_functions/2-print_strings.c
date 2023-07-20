#include "variadic_functions.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

/**
 * print_strings - function to print the string passed
 * @separator: separating between strings
 * @n: number of arguments passed
 * @...: arguments passed to a function variadicly
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list my_string;
	unsigned int i;
	char *str;

	va_start(my_string, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(my_string, char *);
		if (str == NULL)
			printf("(nil)");
		if (!separator)
			printf("%s", str);
		else if (separator && i == 0)
			printf("%s", str);
		else
			printf("%s%s", separator, str);
	}
	printf("\n");
	va_end(my_string);
}
