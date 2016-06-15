#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Error: You need one argument\n");
		return 1;
	}

	int i = 0;
	for(; argv[1][i] != '\0'; ++i)
	{
		char letter = argv[1][i];

		switch(letter)
		{
			case 'a':
			case 'A':
				printf("%d: A\n", i);
				break;
			case 'd':
			case 'D':
				printf("%d: D\n", i);
				break;
			case 'i':
			case 'I':
				printf("%d: I\n", i);
				break;
			case 'o':
			case 'O':
				printf("%d: O\n", i);
				break;
			case 'u':
			case 'U':
				printf("%d: U\n", i);
				break;
			case 'y':
			case 'Y':
				if(i > 2)
				{
					// It's only someitmes y
					printf("%d: Y\n", i);
				}
				break;
			default:
				printf("%d: %c is not a vowel\n", i, letter);
		}
	}
}