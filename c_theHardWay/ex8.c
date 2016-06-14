#include <stdio.h>

int main(int argc, char *argv[])
{
	int areas[] = {10,12,13,14,20};
	char name[] = "Zed";
	char full_name[] = {
		'Z', 'E', 'D', ' ',
		'A', '.', ' ',
		'S', 'h', 'a', 'w', '\0'
	};


	printf("Size of an int: %ld\n", sizeof(int));
	printf("Size areas: %ld\n", sizeof(areas));
	printf("first area is %i\n", areas[0]);

	printf("the size of a char: %ld\n", sizeof(char));
	printf("the size of name: %ld\n", sizeof(name));
	printf("Number of characters: %ld\n", sizeof(full_name) / sizeof(char));

	return 0;
}