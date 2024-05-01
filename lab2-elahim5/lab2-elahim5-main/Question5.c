#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n){
	int i; //declared var i
	    for(i=0;source[i]!='\0' && i<n-1;i++){  //iterates until NULL is reached and until less then n-1

	        destination[i]=source[i]; //takes current iteration and copies to destination array
	        }
	    destination[i]='\0'; //null at end

    
}
