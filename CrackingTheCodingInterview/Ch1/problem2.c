#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Reverse a given string.

reverseIterate will iterate through it one step at a time
reverseSwqp will reverse the string via swapping

- Colan
*/
		
int length (char *string){
	int count = 0;
	while(*string++)
		count++;
	return count;
}
// this will be 0(n) and simply iterate, 0(n)
char * reverseIterate(char *string){
	char newString[length(string)];
	int lengthVal = length(string);
	for(int i = lengthVal-1;i >=0;i--){
		newString[lengthVal-i-1] = string[i];
	}
	//convert array to char *
	char *str;
	strncpy(str, newString, lengthVal);
	str[lengthVal] = '\0';
	return str;
}

// this will swap, 0(n/2) = 0(n)
void reverseSwapPointer(char *string){ // when i say pointer i mean that the address is being messed.
	int lengthVal = length(string);
	
	for(int i = 0;i<(lengthVal/2);i++){
		char temp = string[i];
		string[i] = string[lengthVal-i-1];
		string[lengthVal-i-1] = temp;
	}
}

char *reverseSwapReference(char *string){ // when i say reference i mean that a copy is made and returned
	int lengthVal = length(string);
	char *newString = malloc ( sizeof(char) * lengthVal); // this is done so it can be returned 
	strcpy(newString,string);

	for(int i = 0;i<(lengthVal/2);i++){
		char temp = newString[i];
		newString[i] = newString[lengthVal-i-1];
		newString[lengthVal-i-1] = temp;
	}
	return newString;
}

int main(){
	char string[] = "abcdefghijklmnopqrstuvwxyz";
	printf("Regular string:          %s\n",string);
	printf("Regular reversed String: %s\n",reverseIterate(string));
	printf("Swap reversed String:    %s\n",reverseSwapReference(string));
	reverseSwapPointer(string);
	printf("Swap reversed String:    %s\n",string);
}