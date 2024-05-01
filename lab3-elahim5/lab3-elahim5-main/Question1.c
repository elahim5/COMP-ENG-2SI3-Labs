#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	/*write your implementation here*/
	//declaring variables
	int strlen1 = 0; int strlen2 = 0; int size = 0;

	//lengths of strings
	strlen1 = strlen(str1); //length of string 1
	strlen2 = strlen(str2); //length of string 2
	size = strlen1 + strlen2; //length of total string

	//dynamic memory allocation for concatenated string
	z = (char*) malloc((size+1));//added 1 for null indication of string

	for (int i=0;i<strlen1;i++){
		z[i] = str1[i]; //iterates string 1 and adds to string total
	}

	for (int j=0;j<strlen2;j++){
		z[j+strlen1] = str2[j]; //iterates through string 2 and adds to string total, which already has string 1
	}

	z[size] = '\0'; //adds null at end of string, size of string is the index of null

	/* finally, return the string*/
	return z;
	
}
