#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )
    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){
	
	rowsNum = row; //set row to variable based on parameter
	colsNum = col; //set cols to variable based on parameter 
	matrixData = NULL;
	
	if(row <= 0) { //if row is less than equal to zero set row to 3
		row = 3;
	};

	if(col <= 0) { //if col is less than equal to zero set col to 3
		col = 3;
	};


	matrixData = (int)malloc(rowsNum*sizeof(int));           //dynamically allocates memory for double pointer 
	for (int i = 0 ; i < rowsNum ; i++) 
		matrixData[i] = (int*) calloc(colsNum,sizeof(int));      //set each row to zero using clear allocation(calloc) and then allocate memory to row



Matrix::Matrix(int row, int col, int** table){
	rowsNum = row; //set row to variable based on parameter
	colsNum = col; //set col to variable based on parameter
	matrixData = new int*[colsNum]; 

	int i = 0;
	while(i < rowsNum) { //loops through rows
		matrixData[i] = new int[colsNum];
		int j = 0;
		for(int j = 0; j < colsNum; j++) {//loops through cols 
					matrixData[i][j] = table[i][j]; //dynamically allocates memory 
			//has same number of rows and cols and same elements in the same position as the matrix pointed to by the table 
				}
		}
		i++;
	}


int Matrix::getElement(int i, int j){
	if(i < 0 || i >= rowsNum || j < 0 || j >= colsNum) { //if idexes i or j are not in required range 
		throw std::out_of_range("Invalid indexes."); //throws an exception stating invalid indexes
		return -1; //ends function 
	}
	else //if condition isnt met following happens
		return matrixData[i][j]; //returns matrix data
}


bool Matrix::setElement(int x, int i, int j){
	if( i < 0 || i >= rowsNum || j < 0 || j >= colsNum) { //if meets these conditions returns false
		return false;
	}
	else {
		matrixData[i][j] = x; //if it doesn meet above conditons returns true and matrix data equals x
		return true;
	}
}


Matrix Matrix::copy(){
    Matrix copy = Matrix(rowsNum,colsNum,matrixData); //gets deep copy, which does not share same memory as original 
    return copy; //returns copy
}


void Matrix::addTo( Matrix m ){ 
    if (m.colsNum == this->colsNum && m.rowsNum == this->rowsNum) {
        for (int i = 0 ; i < this->rowsNum ; i++ ) {

        	for (int j = 0 ; j < this->colsNum ; j++ ) {
                this->matrixData[i][j] += m.matrixData[i][j];
            }
        }//adds matrix m to this matrix 


    } else {
        throw std::invalid_argument( "Invalid operation" ); //throws exception when matrix not defined
    }
}


Matrix Matrix::subMatrix(int i, int j){
	if ((i >= 0 && j >= 0) && (i < this->rowsNum && j < this->colsNum)) { //if meets condition following occurs
	    Matrix subM = Matrix (i + 1, j + 1);

	    for (int k = 0 ; k < i + 1 ; k++ ) { //loops through rows
	        for (int n = 0 ; n < j + 1 ; n++ ) { //loops through cols 
	            subM.matrixData[k][n] = this->matrixData[k][n]; //pointer derefrencing to use same var
	        }
	    }
	    return  subM; //returns new matrix object 
	    } else {
	    	throw std::out_of_range( "Submatrix not defined" ); //throws out exception if not in range
	    }
	}

int Matrix::getsizeofrows(){
	return rowsNum; //returns size of rows
}


int Matrix::getsizeofcols(){
    return colsNum; //returns size of cols
}


bool Matrix::isUpperTr(){
	int i = 0;
    while(i < min(rowsNum, colsNum)){
    	int j = 0;
    	for(int j = 0; j < i; j++){
    	            if(matrixData[i][j] != 0) {
    	                return false; //if upper triangular return false
    	            }
        }
        i++;
    }
    return true; //else return true
}


string Matrix::toString(){
	string out=""; //blank space
	int i =0;
    while (i < rowsNum) {//loops through rows 
    	for(int j = 0; j < colsNum; j++){ //loops through cols 
    	        	out = out + to_string(matrixData[i][j]);
    	        	out = out + " "; //space added for every element in row 
    	        } 
        out = out + "\n";//new line for every row
        i++;
    }
    return out;
}
