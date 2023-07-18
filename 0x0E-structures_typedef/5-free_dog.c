#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - function free dog struct from memory
 * @d: pointer to dog struct
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
