#ifndef DOG_HH
#define DOG_HH

/**
* struct dog - Short description
* @name: name of the dog
* @age: age
* @owner: owner
* Description: Longer description
*/

struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
