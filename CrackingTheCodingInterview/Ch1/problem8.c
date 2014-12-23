#include <stdio.h>
#include <string.h>

/*
check if one string is  a rotation of a nother meaning:

can and nac will match.
can and cna will not match.

using strstr as a way to check for substring
*/

typedef char * bool;
#define true "true";
#define false "false";

int length (char *string){
	int count = 0;
	while(*string++)
		count++;
	return count;
}

bool isRotation(char *stringOne, char *stringTwo){
	int len = length(stringOne);
	if(len != length(stringTwo) || len < 1){
		return false;
	}
	char bigStringOne[len*2-1];
	for(int i = 0;i<len*2-1;i++){
		bigStringOne[i] = stringOne[i%len];
	}
	if(strstr(bigStringOne,stringTwo)!= NULL){
		return true;
	}

	return false;
}

int main(){
	char *x = "milk";
	char *y = "ilkm";
	char *z = "mikl";
	printf("isRotation(%s,%s): %s\n", x,y,isRotation(x,y));
	printf("isRotation(%s,%s): %s\n", x,z,isRotation(x,z));
	printf("isRotation(%s,%s): %s\n", y,z,isRotation(y,z));
}