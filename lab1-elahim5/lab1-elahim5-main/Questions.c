
#include "Questions.h"



int Q1_for()
{
	//initialized variables
	int counter, sum = 0;
	// calculate your sum below..this has to use for loop
	for (counter = 30; counter <= 1000; counter++)
		{
		if (counter%4 == 0) //Only add numbers that are divisible by 4
			{
				sum = sum + counter; //adds sum each time
			}

		}

	// here, we return the calculated sum:
return sum;
}

int Q1_while(){
	int sum = 0, counter = 30; //declaring variables

	// calculate your sum below..this has to use while loop
	while (counter <= 1000)
	{
		if (counter%4 == 0) //Only add numbers that are divisible by 4
					{
						sum = sum + counter; //adds sum each time
					}
		counter++; //adds one to the counter each time to repeat loop with next number until condition is not true
	}

	// here, we return the calculated sum:
	return sum;
}
int Q1_do(){
	int sum = 0, counter = 30;
	// calculate your sum below..this has to use do-while loop
	do //will do first loop no matter what
	{
		if (counter%4 == 0) //Only add numbers that are divisible by 4
					{
						sum = sum + counter; //adds sum each time
					}
		counter++; //adds one to the counter to repeat loop with new number
	} while (counter <= 1000); //condition for loop to repeat until stated condition is not true

	// here, we return the calculated sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit;
	
	// Do your coding below to check
	if (9999 < abs(Q2_input) && abs(Q2_input) <= 99999) //if it is a 5 digit number
	{
		IsFiveDigit = 1; //if five digits returns 1
	}
	
	else
	{
		IsFiveDigit = 0; //otherwise returns 0
	}

	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and returns:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program should return -1
*/	
	// this is the variable that holds the out value to return
	float GPA;
	
	if (90 <= Q3_input && Q3_input <= 100) // if Q3_input is in the range 90-100, GPA = 4
		{
			GPA = 4;
		}
	else if (80 <= Q3_input && Q3_input <= 89) // if Q3_input is in the range 80-89, GPA = 3
		{
			GPA = 3;
		}
	else if (70 <= Q3_input && Q3_input <= 79) // if Q3_input is in the range 70-79, GPA = 2
		{
			GPA = 2;
		}
	else if (60 <= Q3_input && Q3_input <= 69) // if Q3_input is in the range 60-69, GPA = 1
		{
			GPA = 1;
		}
	else if (0 <= Q3_input && Q3_input <= 59) // if Q3_input is in the range 0-59, GPA = 0
		{
			GPA = 0;
		}
	else //if anything else returns 1
		{
		 	GPA = -1;
		}
	
	// Do your coding below to calculate the GPA variable value
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the variable that holds the pi value to return
	double pi=0;
	
	// Do your coding below to calculate the pi value
	for (int i = 0 ; i < Q4_input ; i++ ) //loop iterates through number of numbers you want to add to obtain pi
	{
		double den; //Initializing denominator
		den = i*2+1;
		if (i%2==0) //if even number will add to pi total
		{
			pi = pi + 4.0/den;
		}
		else //if odd number will subtract from pi total
		{
			pi = pi - 4.0/den;
		}

	}

	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the variable that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;
	int side1, side2, hyp; // Initializing variables

	/* Do your coding below
			Use a triple-nested for loop that simply tries all possibilities
			and update the total number of triples if needed
	 */
	for (side1=1;side1<=400;side1++)
	{
		for (side2=1;side2<=400;side2++)
		{
			for (hyp=1;hyp<=400;hyp++) // The triple nested for-loop iterates through all possibilities
			{
					if ((side1*side1 + side2*side2 == hyp*hyp) && (side1<=side2)) // Only adds to count given Conditions are met for pythagorean triples
								      {
								    	  totNumTribles++; // Adds count to the total triples count, each time a triple meets all conditions presented
								      }

			}

		}

	}

	
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
	/*
	*
	*perfect is an array that you need to add into it any perfect number you find
	*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
	*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will
	*automatically reflect in the main calling function.
		*/
	
		int counts=0;
		//counts is the variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int i,factor,sum,x=0; //declared variables
	    for(i=1;i<=Q6_input;i++){ //loops through inputed numbers
	    	sum = 0; //Initialized sum variable
	    	for(factor=1;factor<i;factor++){  //loops through number in the prior loop, to check for factors
	    		if(i%factor==0){ //if its a factor, or divisible by a number smaller than itself, the below condition will run
	    			sum=sum+factor; //adds to sum if number is factor
	    		}
	    	}
	    	if(sum == i){
	    		counts++; //adds to count if factors sum equal to number, which determines if the number is a perfect number
	    		perfect[x]=i; //adds perfect number to array
	    		x=x+1; //adds one to x, so next index space is available to perfect array, if another perfect number can be added after
	    	}
	    }


	   return counts; //finally returns counts

	
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	
	int reversedInt = 0, i, Remainder; // declaring variables

	//Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer

	for (i = 1; i <= 7 ; i++){  //loop iterates through number till no digit is left (7 times)
		Remainder = abs(Q7_input)%10; //finds last number
		reversedInt = reversedInt *10 + Remainder; //digit is added to reverse integer
		Q7_input = Q7_input / 10; //takes off one number from initial input

	}

		return reversedInt; //returns inputed integer reversed
}

int Q7b(int Q7b_input){

	//this is the variable that holds the reversed int.
	//declaring variables
	int reversedInt = 0;
	int x;
	//Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
		while (Q7b_input>0){ //loop iterates through number till no digit is left
			x=abs(Q7b_input)%10; //finds last number
			reversedInt = reversedInt*10+x; //digit is added to reverse integer
			Q7b_input = Q7b_input/10; //takes off one number from initial input
		}



		return reversedInt; //returns inputed integer reversed
}

