#include <stdio.h>
/*
Find the min and max of an array of integers.
*/


int min(int array[],int length){
	int min = array[0];
	for(int i = 1; i < 10;i++)
		if(min > array[i])
			min = array[i];
	return min;
}

int max(int array[], int length){
	int max = array[0];
	for(int i = 1; i < 10;i++)
		if(max < array[i])
			max = array[i];
	return max;
}

int main(){
	int array[10] = {10,40,20,10,1000,-20,-40,-60,7,123412};
	int length = sizeof(array) / sizeof(int);
	/*
	I've learned here that in attempting to build a function all that is passed to the funciton is a pointer to the first element.
	Meaning that a sizeof function really isn't in the cards. I tired a macro with similar results.
	*/
	printf("Max of array: %i\n",max(array,length));
	printf("Min of array: %i\n",min(array,length));
}