#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	if(argc == 1)
	{
		printf("You need more than one argument for this program\n");
	}
	else if(argc > 1 && argc < 4)
	{
		printf("Here are your arguments:\n");

		for(i = 0; i < argc; ++i)
		{
			printf("%s ", argv[i]);
		}
		printf("\n");
	}
	else
	{
		printf("Could you please use less arguments.\n");
	}

	return 0;
}