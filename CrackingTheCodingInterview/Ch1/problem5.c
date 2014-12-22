#include <stdio.h>
#include <stdlib.h>
/*
given string "aabb" return a2b2
meaning count how many occurrences there are of each and print them out.
*/

int length (char *string){
	int count = 0;
	while(*string++)
		count++;
	return count;
}

char * convertToNumbers(char *string){
	int dictionary['z'-'A']; // yeilds total length for all cap letters
	int lengthVal = length(string);
	char *newString = malloc ( sizeof(char) * ('z'-'A')*2);	
	//this limit assumes the max amount per a character will be under double digits if every character is represented
	//set all values to 0 in dicitonary
	for(int i = 0;i<='z'-'A';i++){
		dictionary[i] = 0;
	}
	//set values in dicitonary
	for(int i = 0; i < lengthVal; i++){
		dictionary[string[i]-'A']+=1;
	}
	int index = 0; //index 
	for(int i = 0; i <= 'z'-'A'; i++){
		if(dictionary[i] > 0){
			newString[index] = i+'A'; // convets the accessor back to its ascII value
			index++;
			newString[index] = dictionary[i] + '0'; // + '0' converts single int back to char value
			index++; 
		}
	}
	return newString;
}

int main(){
	char *a = "aabbccddeeffffffzzz";
	char *b = "zAAAZZZZ";
	printf("%s yields: %s\n",a,convertToNumbers(a));
	printf("%s yields: %s\n",b,convertToNumbers(b));
}