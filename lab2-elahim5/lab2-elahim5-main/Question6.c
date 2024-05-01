#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){

	int j=0,i;
	for(i=0;i<size;i++){  //loops through array
	    if (source[i]!=0){  //if current iteration does not equal zero perform below
	        val[j]=source[i]; //source value is put into val[]
	        pos[j]=i;  //pos[] is updated with increment for i loop
	        j++; //increment j only when non zero number is in source[] and added to val and pos
	        }
	    }
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){

	int i,j;
	for(i = 0; i < m; i++){ //array value at element i is 0 for first func
	    source[i] = 0;//loop checks if the index of the array should contain a different value
	    for(j = 0; j < n; j++){ //goes through all element of the position array to change that different value
	        if(i==pos[j]){
	            source[i] = val[j];
	            }
	        }
	    }
	
}
