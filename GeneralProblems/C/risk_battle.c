//
//  database_battle.c
//  Conquest
//
//  Created by colan biemer on 6/11/14.
//  Copyright (c) 2014 colan. All rights reserved.
//
/*
This will simulate a risk battle.
This will be updated so it takes input for attacker and defender.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> //this is used for a seed to generate a random number

void swap(int *x, int *y){
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int *arr,int size){
	int i,j;
	//0(n^2) sort, I was feeling lazy
	for(i = 0; i<size;++i)
		for(j=0;j<size;++j)
			if(arr[i]>arr[j])
				swap(&arr[i],&arr[j]);
}

int main(){
	int attacker, defender,x;
	attacker = 10;
	defender = 10;
	printf("Attacker army: %i\n", attacker);
	printf("Defender army: %i\n", defender);
	srand(time(NULL));

	while(attacker > 1 && defender >=0){
		// set up rolls
		int attRoll[3]={0,0,0};
		int defRoll[2]={0,0};
		int *ap, *dp;
		x = 0;

		if(attacker >3)
			while(x<3)
				attRoll[x++]=(rand()%6)+1;
		else 
			while(x<2)
				attRoll[x++]=(rand()%6)+1;
		x=0;
		if(defender>1)
			while(x<3)
				defRoll[x++]=(rand()%6)+1;
		else 
			defRoll[x]=(rand()%6)+1;

		// sort rolls
		int defSize, attSize;
		defSize = sizeof(defRoll)/sizeof(*defRoll);	
		attSize = sizeof(attRoll)/sizeof(*attRoll);
		sort(attRoll,attSize);
		sort(defRoll,defSize);

		// simulate battle

		if(defSize<attSize){
			for(x = 0;x<defSize;x++)
				if(attRoll[x]>defRoll[x])
					defender--;
				else
					attacker--;
		} else{
			for(x=0;x<attSize;x++)
				if(attRoll[x]>defRoll[x])
					defender--;
				else
					attacker--;
		}
	}
	if (attacker <= 0) 
		attacker = 1;
	if (defender < 0) 
		defender=0;

	printf("Results:\nattack: %i\n",attacker);
	printf("defend: %i\n",defender);
	return 0;
}