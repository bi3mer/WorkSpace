#include <stdio.H>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 1234.1234;
	char initial = 'A';
	char first_name[] = "Zed";
	char last_name[] = "Shaw";

	printf("you are %d milesa way.\n", distance);
	printf("you are %f levels of power.\n", power);
	printf("you have %f awesome super powers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("First name: %s\n", first_name);
	printf("last_name: %s\n", last_name);
	printf("whole name: %s %c %s\n", first_name, initial, last_name);

	return 0;
}