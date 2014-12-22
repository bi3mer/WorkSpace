#include <stdio.h>
#include <stdlib.h>
/*
Take an nxn matrix and rotate it 90 degrees

1 2 3			  7 4 1
4 5 6 wii become  8 5 2
7 8 9 			  9 6 3

both methods given are 0(n^2) though the void function has to copy all the values over so it is 0(n^2+n^2)=0(n^2)

for the void method i create a temporary matrix and then copy it over, note this can be done in different ways using
temporary variables and such, but I decided not to go that in depth.

-Colan
*/

#define LENGTH 3

void printMatrix(int arr[LENGTH][LENGTH]){
	for(int i = 0; i < LENGTH; i++){
		for(int j = 0; j< LENGTH;j++)
			printf("%i ", arr[i][j]);
		printf("\n");
	}
}


void printMatrixPointer(int **arr){
	for(int i = 0; i < LENGTH; i++){
		for(int j = 0; j< LENGTH;j++)
			printf("%i ", arr[i][j]);
		printf("\n");
	}
}

void rotateMatrix(int arr[LENGTH][LENGTH]){
	/*
	i will represent te column and j will represent the row
	New array delcared to preserve old matrix data, until it is overwritten at the end;
	*/
	int newArr[LENGTH][LENGTH];

	for(int i = 0;i<LENGTH;i++)
		for(int j = 0;j<LENGTH;j++)
			newArr[i][LENGTH-j-1] = arr[j][i];

	for(int i = 0; i<LENGTH;i++)
		for(int j = 0; j<LENGTH;j++)
			arr[i][j] = newArr[i][j];
}

int ** returnRotateMatrix(int arr[LENGTH][LENGTH]){
	int **newArr = (int **)malloc(LENGTH * sizeof(int *));
    for (int i=0; i<LENGTH; i++)
         newArr[i] = (int *)malloc(LENGTH * sizeof(int));

	for(int i = 0;i<LENGTH;i++)
		for(int j = 0;j<LENGTH;j++)
			newArr[i][LENGTH-j-1] = arr[j][i];

	return newArr;
}

int main(){
	int array[LENGTH][LENGTH];

	// generates the 1,2,3,4,5,6,7,8,9
	for(int i = 0; i < LENGTH; i++)
		for(int j = 0; j< LENGTH;j++)
			array[i][j] = (j+1)+3*i; 

	printf("Original matrix:\n");
	printMatrix(array);
	
	printf("\nRotating with return:\n");
	printMatrixPointer(returnRotateMatrix(array));

	printf("\nRotating with void:\n");
	rotateMatrix(array);
	printMatrix(array);
}