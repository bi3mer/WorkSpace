#include <stdio.h>

/*
	Find the lenght of an array in C
*/

int length (char *string){
	int count = 0;
	while(*string++)
		count++;
	return count;
}

int main(){
	char *string = "1234567890";
	printf("Length of array: %i\n",length(string));
}