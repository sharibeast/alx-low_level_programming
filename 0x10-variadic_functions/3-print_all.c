#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - print any argument passed to it
 * @format: format of the arguments passed
 * @...: arguments passed
 */
void print_all(const char * const format, ...)
{
	va_list formats;
	char *fomati, *sep = "";
	int i = 0;

	va_start(formats, format);
	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", sep, va_arg(formats, int));
					break;
				case 'i':
					printf("%s%d", sep, va_arg(formats, int));
					break;
				case 'f':
					printf("%s%f", sep, va_arg(formats, double));
					break;
				case 's':
					fomati = va_arg(formats, char *);
					if (!fomati)
						fomati = "(nil)";
					printf("%s%s", sep, fomati);
					break;
				default:
					i++;
					continue;
			}
			sep = ", ";
			i++;
		}
	}
	printf("\n");
	va_end(formats);
}
