#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	while(i < argc)
	{
		printf("arg %d: %s\n", i, argv[i]);
		++i;
	}

	// array of c strings
	char *states[] = {
		"C", "O", "W", "T"
	};

	i = 0;

	while(i < num_states)
	{
		printf("state %d: %s\n", i, states[i]);
		++i;
	}

	return 0;
}