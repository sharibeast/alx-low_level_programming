#ifndef DOG_HH
#define DOG_HH

/**
* struct dog - Short description
* @name: name of the dog
* @age: age
* @owner: owner
* Description: Longer description
*/

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
