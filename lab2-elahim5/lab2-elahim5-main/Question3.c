#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){

	int index = 0;  //all elements of matrix are being attached to array together
	    for(int i=0;i<N3;i++){  //iterating from top row to bottom row diagonally
	        int row=i,column=0;    //initializes row at current iteration and column at 0

	        while (row>=0){  //while its not the last row (last diagonal) keep receiving each diagonal
	            arr[index]=mat[row][column];
	            row--;
	            column++; //updating row and column to go diagonally, and index for array
	            index++;
	        }
	    }
	    for(int i=1;i<N3;i++){   //iterating from second col to last col as first loop completes using first half of the rows
	        int row=N3-1,column=i;   //row minus 1 since we need final rows index of matrix and column set to loop iteration
	        while(column<N3){  //while column is less then size of matrix....
	            arr[index]=mat[row][column];
	            row--;
	            column++;  //add matrix element to array, move diagonally and add index to array list
	            index++;
	        }
	    }
	}

