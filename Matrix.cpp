
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


	         

}


Matrix::Matrix(int row, int col, int** table){

	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/

	

}

int Matrix::getElement(int i, int j){



		return -1;
	}

}

bool Matrix::setElement(int x, int i, int j){


    return false;
}


Matrix Matrix::copy(){

	/* fix the code and write your implementation below */
	Matrix copy = Matrix (0,0);

    Matrix copy=  Matrix(rowsNum,colsNum );


    return  copy;


}


void Matrix::addTo( Matrix m ){

	
}


Matrix Matrix::subMatrix(int i, int j){

	/* The exception detail message should read: "Submatrix not defined"*/

	/* fix the code and write your implementation below */
	Matrix subM = Matrix (0,0);

    


    return  subM;
}


int Matrix::getsizeofrows(){

	
	/* update below return */
	return -1;
}


int Matrix::getsizeofcols(){



	/* update below return */
    return -1;
}


bool Matrix::isUpperTr(){

	/* write your implementation here and update return accordingly */
	
	  return true;
}


string Matrix::toString(){

	string output="FIX";

	//return output;
	 return output;
}
