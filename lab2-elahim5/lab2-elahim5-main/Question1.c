#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below
	for(int i=0;i<size;i++){ //for loop to iterate through array

	    vector3[i] = vector1[i]+vector2[i]; //adding same index's of vectors and storing in vector 3

	    }
	
	
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;

	//write your code below to calculate the prod value
	
    for(int i=0;i<size;i++){ // iterating through array

        prod = prod + vector1[i]*vector2[i]; //taking product of vectors

    }
    

    return prod; //returns product
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;
    
	//write your code here
	// you should call function scalar_prod().

    L2 = pow(scalar_prod(vector1,vector1,size),0.5); //normal of a vector
	
	//finally, return the L2 norm 
    return L2;
}
