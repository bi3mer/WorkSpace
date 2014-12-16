#include <stdio.h>
/*
Replace all spaces, " " with %20 in character array. Assume there is enough space.

Note we assume that the character array will have enough space, else this solution fails.
*/

int length (char *string){
	int count = 0;
	while(*string++)
		count++;
	return count;
}

void moveArray(char *string, int i, int lengthString){
	for(int j = lengthString; j > i; j--){
		string[j+2] = string[j];
	}
}

void manipulateString(char *string){ //0(n^2)
	int lengthString = length(string);
	for(int i = 0; i < lengthString; i++){
		if(string[i] == ' '){
			// place percent sign in place of the space
			string[i] = '%';
			// move array over two spots
			moveArray(string,i,lengthString);
			// place '20' into array
			string[i+1] = '2';
			string[i+2] = '0';
			lengthString = lengthString+2; // moveArray changes length of string by 2
		}
	}
}

int main(){
	char string[40] = "blam blammo dam";
	char stringTwo[40] = "    blammo!  ";
	
	printf("%s becomes: ",string);
	manipulateString(string);
	printf("%s\n",string);

	printf("%s becomes:   ",stringTwo);
	manipulateString(stringTwo);
	printf("%s\n",stringTwo);
}