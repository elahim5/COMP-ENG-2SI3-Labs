#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){

		int i = 0,j = 0,k = 0,index = 0; //declaring index vars

		while(i < k1) { //Loops through val1[]
			while(pos2[j] < pos1[i]){ // If index values in val2 less than in val1, add the val2 values into the list first
				val3[k] = val2[j];
				pos3[k] = pos2[j];
				j++;
				k++;
			}

			if((val1[i] + val2[j]) != 0 && (pos1[i] == pos2[j])){ // if both index values are equal and do not sum to zero
				val3[k] = val1[i] + val2[j]; // Adds the sum of val1 and val2 into val3
				pos3[k] = pos1[i]; // Position of the index is also added to pos3
				i++; //all indexes are incremented by one
				j++;
				k++;

			}else if((val1[i] + val2[j]) == 0){ //if sum equals zero it does not add the values into val3 so index variables are incremented to next element
				i++;
				j++;

			}else{ //other wise adds the element at value 1 into value 3
				val3[k] = val1[i];
				pos3[k] = pos1[i];
				k++;
				i++;
			}
		}

		for(index = j; index < k2; index++){ // loops through other values in val2 (there are more in this than val1)
			val3[k] = val2[j]; // Val2 elements are added to val3
			pos3[k] = pos2[j];
			k++;
			j++;
		}


}
