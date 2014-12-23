#include <stdio.h>
#include <stdlib.h>

/*
if you find a 0 in the matrix, set the entire row and column of it to 0 as well.

meaning:
0 1 1              0 0 0
1 1 1 will become  0 1 1
1 1 1              0 1 1

the challenge behind this is to ensure that it doens't all go to 0's and only the proper rowss and columns.

Initial thought is to grab all the row and column values 
then take the values and place in all the 0's, 0(n^2)

- Colan
*/

#define ROW_LENGTH 5
#define COL_LENGTH 5

void printMatrix(int arr[COL_LENGTH][ROW_LENGTH]){
	for(int i = 0; i < COL_LENGTH; i++){
		for(int j = 0; j< ROW_LENGTH;j++)
			printf("%i ", arr[i][j]);
		printf("\n");
	}
}

void modify(int arr[COL_LENGTH][ROW_LENGTH]){
	// A better coding style would be to split this up into more than one function, but feeling lazy.
	int index = 0;
	int rows[ROW_LENGTH];
	int cols[COL_LENGTH];
	//Note: a dynamic array, such as ArrayList in java, would probably be better than this
	for(int i = 0;i< ROW_LENGTH;i++)
		rows[i] = -1;
	for(int i = 0;i< COL_LENGTH;i++)
		cols[i] = -1;
	
	for(int i = 0; i<COL_LENGTH;i++){
		for(int j = 0; j<ROW_LENGTH;j++){
			if(arr[i][j] == 0){
				rows[index] = j;
				cols[index] = i;
				index++;
			}
		}
	}

	for(int i = 0; i < ROW_LENGTH;i++){
		if(rows[i] != -1){
			for(int j = 0;j<COL_LENGTH;j++)
				arr[rows[i]][j] = 0;
		}
		else
			break;
	}

	for(int i = 0; i < COL_LENGTH;i++){
		if(cols[i] != -1){
			for(int j = 0;j<ROW_LENGTH;j++)
				arr[j][cols[i]] = 0;
		}
		else
			break;
	}
}

int main(){
	int arr[COL_LENGTH][ROW_LENGTH];
	for(int i = 0; i <COL_LENGTH;i++)
		for(int j = 0; j< ROW_LENGTH; j++)
			arr[i][j] = 1;
	arr[0][0] = 0;
	// arr[0][1] = 0;
	// arr[0][2] = 0;
	// arr[0][3] = 0;
	// arr[0][4] = 0;
	arr[COL_LENGTH-1][ROW_LENGTH-1] = 0;
	printf("\nOriginal:\n");
	printMatrix(arr);
	printf("\nNew: \n");
	modify(arr);
	printMatrix(arr);
}