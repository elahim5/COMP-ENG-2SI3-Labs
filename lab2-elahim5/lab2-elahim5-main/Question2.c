#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag = 1;
	//write your code below

    for (int i = 0; i < N2; i++){ //iterates through rows
        double sum = 0; //fabs may give double hence why I keep this double instead of int

        for (int j = 0; j < N2; j++){ // iterating through elements in row
            if(i != j){ //avoiding adding diagonal elements
                sum = sum + fabs(mat[i][j]);
            }
        }
        // verify that diagonal element is less than.
        if (fabs(mat[i][i]) < sum){
            isDiag = 0; //if it is then return false
        }
    }

    return isDiag; //returns whether the matrix is diagonally dominant (1) or not (0)
}
