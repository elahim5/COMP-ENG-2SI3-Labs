#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;


	/*write your implementation here*/

	FILE *input_file=fopen(filename, "r"); //going into the file and reads file
	fscanf(input_file, "%d", sizePtr); //fscanf reads formatted input from the stream input_file
	class_list = calloc(*sizePtr,sizeof(class_list)); //dynamic memory allocation of class list by getting size of class list

		/*write your implementation here*/
		for (int i=0;i<*sizePtr;i++){ //looping through class list
			class_list[i]=malloc(1*sizeof(student)); //dynamic allocation using calloc(things we need space for , the space required for a student)
			//calloc will also initially set everything to 0, before allocating
			fscanf(input_file,"%d %s %s\n",&(class_list[i]->student_id),class_list[i]->first_name,class_list[i]->last_name);
		} //fscanf reads formatted input from stream, this returns a pointer to the beginning of the array of pointer to student

		fclose(input_file); //closing file

	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	//function finds student ID
	for (int i=0;i<size;i++){ //loops through array of pointers
			if ((list[i]->student_id)==idNo){//if student id is equal to idNo, returns index
				return i; //returns the index
			}
		}
	/*write your implementation here and update the return accordingly*/
	return -1;
}

void input_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/
	int temp1=0;int temp2=0;int id=0; int i=0; //declaring vars
	FILE *input_file=fopen(filename,"r"); //reading file

	while(i<size){ //looping through array
			fscanf(input_file,"%d %d %d\n",&id,&temp1,&temp2); //reads formatted input from file and saves placeholder
			(list[find(id,list,size)]->project1_grade)=temp1; //updating grades for project 1
			(list[find(id,list,size)]->project2_grade)=temp2; //updating grades for project 2
			i++; //indexing by one each time
		}
	fclose(input_file); //closing file


}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/
	for (int i=0;i<size;i++){ //loops through array of points
			(list[i]->final_grade)=(double)((list[i]->project1_grade)+(list[i]->project2_grade))/2;
		} //updates final grade by taking the average of the two projects

}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/

	FILE *output_file=fopen(filename, "w"); //writing on output file, which was passed as parameter
		fprintf(output_file,"%d\n",size); //formatted output to a stream

		for (int i=0;i<size;i++){ //looping through array
			fprintf(output_file,"%d %lf\n",(list[i]->student_id),(list[i]->final_grade));
		} //printing student ids and final grades in output file

		fclose(output_file); //closing output file

}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int j=0;int i=0; //declaring vars
		j = find(idNo,list,*sizePtr); //
		if (j ==-1){ //prints message if student not in the list
			printf("Student not in the list! ");
			return;
		}
		student *temp = calloc(1,sizeof(student)); //clear allocation
		while (i<(*sizePtr)-1){
			temp = list[i]; //swapping like code but it shift to left
			list[i] = list[i+1]; //shifting one position to the left for all students between vacated spot and the array
			list[i+1] = temp;
			if (i == *sizePtr-2){
				free(list[i]); //deallocating memory for var that was withdrawn from list
			}

	    i++; //iterating by one index
		}
		*sizePtr-=1; //one less student in less so updates
}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	for (int i=0;i<*sizePtr;i++){ //loops through class list
			free(list[i]); //Deallocates memory in index of the list
		}
		free(list); //Deallocates the list
		*sizePtr=0; //sets size of ptr to zero
}
