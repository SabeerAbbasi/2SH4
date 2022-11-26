
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

	/*
	* constructs a row-by-col matrix with
	* all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	* 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	*/

	//sets the number of rows and coloumns
	if (row <= 0)
	{
		rowsNum = 3;
	}
	else
	{
		rowsNum = row;
	}

	if (col <= 0)
	{
		colsNum = 3;
	}
	else
	{
		colsNum = col;
	}

	//allocates memory based on coloumns and rows
	matrixData = (int**)malloc(rowsNum*sizeof(int*));

	for (int i = 0 ; i < rowsNum ; ++i)
	{
		matrixData[i] = (int*) malloc(colsNum * sizeof(int));
	}

	for(int i = 0 ; i < rowsNum ; ++i)
		for (int j = 0 ; j < colsNum ; ++j)
			matrixData[i][j] = 0; //constructs matrix with all 0's

}


Matrix::Matrix(int row, int col, int** table){

	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/
	
	rowsNum = row;
	colsNum = col;

	//allocates memory based on columns and rows
	matrixData = (int**)malloc(rowsNum*sizeof(int*));

	for (int i = 0 ; i < rowsNum ; ++i)
	{
		matrixData[i] = (int*) malloc(colsNum*sizeof(int));
	}

	for (int i = 0 ; i < rowsNum ; ++i)
		for (int j = 0 ; j < colsNum ; ++j)
			matrixData[i][j] = table[i][j]; //constructs matrix with table values
}



int Matrix::getElement(int i, int j){
	if(i > colsNum || j > colsNum || i < 0 || j < 0) //verifies range of invalid values
	{
		throw std::out_of_range("Invalid indexes");
			return -1;
	}
		return matrixData[i][j]; //returns specified element
}


bool Matrix::setElement(int x, int i, int j){
	if((i >= 0 && i < rowsNum) && (j>=0 && j < colsNum)){
		matrixData[i][j] = x;
		return true;
	}
	return false;
}


Matrix Matrix::copy(){

    Matrix copy=  Matrix(rowsNum,colsNum, matrixData);
    return  copy;

}


void Matrix::addTo( Matrix m ){
	//comparing row and column dimensions
	if (colsNum != m.colsNum || rowsNum != m.rowsNum)
	       throw invalid_argument("Invalid operation");
	   for (int i = 0; i < rowsNum; i++)
	   {
	       for (int j = 0; j < colsNum; j++)
	       {
	           matrixData[i][j] += m.matrixData[i][j]; //adding the two elements together in the matrix
	       }
	
	   }
}


Matrix Matrix::subMatrix(int i, int j){

	if(i >= rowsNum || i < 0 || j >= colsNum || j < 0)
	{
		throw out_of_range("Submatrix not defined");
	}
	Matrix subM = Matrix (i+1, j+1);
	for (int row = 0; row <= i; row++)
	{
		for (int col = 0; col <= j; col++)
		{
			subM.matrixData[row][col] = matrixData[row][col];
		}
	}
	return subM;
}

int Matrix::getsizeofrows(){

	/* update below return */
	return rowsNum; //returns the rowsNum
}


int Matrix::getsizeofcols(){

	/* update below return */
	return colsNum; //returns the colsNums

}


bool Matrix::isUpperTr(){

	/* write your implementation here and update return accordingly */
	int upper = 0;

		for(int i=1; i<this->rowsNum; i++)
			for(int j=0; j<i; j++) //if j is more than i got through loop and add 1 to j
				upper += this->matrixData[i][j];

		if (upper != 0){
		  return false;
		}

		else{
			return true;
		}
	}

string Matrix::toString(){
	//    Initialized variable
	    string output="";
	    //    Goes through one row for each column & the integer is taken and turns into a string space
	    for (int i = 0; i < rowsNum; i++){
	        for (int j = 0 ; j < colsNum ; j++){
	            output += to_string(matrixData[i][j]) + " ";
	        }
	        //    A new line is added for each new row
	        output += "\n"; //
	    }
	     return output;
	}
