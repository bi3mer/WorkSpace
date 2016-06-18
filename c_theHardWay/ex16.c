#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person * Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight  = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	free(who->name);
	free (who);
}

void Person_print(struct Person *who)
{
	assert(who != NULL);
	
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	// Make 2 people
	struct Person *joe = Person_create("Joe Alex", 32, 65, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 100);

	// print them out
	printf("Joe Memory: %p\n", joe);
	Person_print(joe);

	printf("Frank Memory: %p\n", frank);
	Person_print(frank);

	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	Person_destroy(joe);
	Person_destroy(frank);

	return 0;



}