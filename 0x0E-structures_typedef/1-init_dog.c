#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * init_dog - Initializes a dog structure with given values.
 * @d: Pointer to the dog structure to be initialized.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 * Return: None.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = malloc(strlen(name) + 1);
	if (d->name != NULL)
	{
		strcpy(d->name, name);
	}
	d->age = age;
	d->owner = malloc(strlen(owner) + 1);
	if (d->owner != NULL)
	{
		strcpy(d->owner, owner);
	}
}
