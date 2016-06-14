#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	// 1 to avoid cmd line argument
	for(int i = 1; i < argc; ++i)
	{
		printf("arg %d: %s\n", i, argv[i]);
	}

	// array of c strings
	char *states[] = {
		"C", "O", "W", "T"
	};

	int num_states = 4;

	for(i = 0; i < num_states; ++i)
	{
		printf("state %d: %s\n", i, states[i]);
	}
}