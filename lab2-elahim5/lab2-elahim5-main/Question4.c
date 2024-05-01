#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){

	int i=0; //declared i
	while(word[i]!='\0'){      //loops until end of word which would be a null character(spaces are not null)
	    if(word[i]>='a' && word[i]<='z'){ //if statement for lower case letters
	        freq[word[i]-'a']++;  //freq is incremented by one

	    }
	    else if(word[i]>='A' && word[i]<='Z'){ //if statement for upper case letters
	        freq[word[i]-'A']++;  //freq incremented by by one
	    }
	    i++; //increment loop for next character
	        }


   
}
