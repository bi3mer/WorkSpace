#include <stdio.h>

void print_break()
{
	printf("-----\n");
}

int main(int argc, char * argv[])
{
	// create two arrays
	int ages[] = {23, 43, 12, 89, 2, 22};
	char *names[] = {
		"Alan", "Frank", "Mary",
		"John", "Lisa", "Colan"
	};

	// Size of int array
	int count = sizeof(ages) / sizeof(int);
	int i;

	for(i = 0; i < count; ++i)
	{
		printf("%s has %d years alive\n", names[i], ages[i]);
	}

	print_break();

	// set up points to the start of array
	int *cur_age = ages;
	char **cur_name = names;

	for(i = 0; i < count; ++i)
	{
		printf("%s is %d years old\n", *(cur_name + i), *(cur_age + i));
	}

	print_break();

	for(i = 0; i < count; ++i)
	{
		printf("%s is %d years old again\n", cur_name[i], cur_age[i]);
	}

	print_break();

	// *x + 1 -> x[1], so *x -1 will give x[0] now etc.
	for(cur_name = names, cur_age = ages; (cur_age - ages) < count; ++cur_name, ++cur_age)
	{
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}
}