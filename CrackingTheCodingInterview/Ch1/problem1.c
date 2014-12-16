#include <stdio.h>

typedef int bool;
#define true 1
#define false 0
/*
Ipmlement an algorithm which determines if a string has unique characters. What if you cna't use a data structure.

First method implemented for part 1 will use a dictionary to and check if that character hs been found, or not. 0(n)

Method without data structures will go though each element and then go through the rest of the array to check. 0(n^2)
*/

int length (char *string){
	int count = 0;
	while(*string++)
		count++;
	return count;
}

bool dataStructureMethod(char *string){
	// i'll use an array which makes use of characters represented as an int. I'll also limit the array to the size of 26, for ease.
	if(length(string)>26){
		return false;
	}
	int valid[26];
	for(int i = 0;i<26;i++){
		valid[i] = false;
	}
	for(int i = 0;i<length(string);i++){
		if(valid[string[i]-'a'] == true){
			return false;
		}
		valid[string[i]-'a'] = true;
	}
	return true;
}

bool noDataStructureMethod(char *string){
	if(length(string)>26){
		return false;
	}
	for(int i = 0; i<length(string);i++){
		for(int j = i+1; j<length(string);j++){
			if(string[i] == string[j])
				return false;
		}
	}
	return true;
}

int main(){
	char *goodString = "helowitc";
	char *badString  = "abcdefghijlkmnopqrstuvwxyzabcdefghijlkmnopqrstuvwxyz";
	printf("Data structure method where 1 is true and 0 is false:\n");
	printf("Good string: %i\n", dataStructureMethod(goodString));
	printf("Bad string:  %i\n", dataStructureMethod(badString));
	printf("Without data structure method where 1 is ture and 0 is false:\n");
	printf("Good string: %i\n", noDataStructureMethod(goodString));
	printf("Bad string:  %i\n", noDataStructureMethod(badString));
}