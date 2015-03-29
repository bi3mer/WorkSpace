#include <stdio.h>

typedef char* bool;
#define true "true"
#define false "false"

/*
Given two strings, find if one is a permutation of the other

First method will use two dictionaries to see if they match, and if they do they must be permutations of eachother.
-Colan
*/
int length (char *string){
	int count = 0;
	while(*string++)
		count++;
	return count;
}

bool checkDictionaries(int dicitonaryA[],int dicitonaryB[]){
	for(int i = 0; i < 256; i++)
		if(dicitonaryA[i] != dicitonaryB[i]){
			return false;
		}
	return true;
}

bool permuationDicitonary(char *a, char*b){
	int lengthA = length(a);
	if(lengthA != length(b)){
		return false;
	}
	int length = 256;
	int dicitonaryA[length];
	int dicitonaryB[length];
	for(int i = 0;i<length;i++){
		dicitonaryA[i] = 0;
		dicitonaryB[i] = 0;
	}
	for(int i = 0;i<lengthA;i++){
		dicitonaryA[a[i]]++;
		dicitonaryB[b[i]]++;
	}
	return checkDictionaries(dicitonaryA,dicitonaryB);
}

int main(){
	char *a = "The eyes";
	char *b = "They see";
	char *c = "dac";
	/* 
	a will match b
	a will not match c
	b will not match c
	*/
	printf("Permutation dictionary method:\n");
	printf("%s matches %s: %s\n",a,b,permuationDicitonary(a,b));
	printf("%s matches %s: %s\n",a,c,permuationDicitonary(a,c));
	printf("%s matches %s: %s\n",b,c,permuationDicitonary(b,c));
}