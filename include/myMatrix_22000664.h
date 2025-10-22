/*----------------------------------------------------------------\
@ Numerical Programming by Young-Keun Kim - Handong Global University

Author           : M.Y, Jung
Created          : 26-03-2018
Modified         : 14-10-2024
Language/ver     : C++ in MSVS2019

Description      : myMatrix.h
----------------------------------------------------------------*/

#ifndef		_MY_MATRIX_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_MATRIX_H

#include <iostream>
#include <string>
#include <fstream>

// double** at is 2-D array itself
typedef struct { 
	double** at;		// 林家蔼 n x n 青纺狼 檬扁 林家
	int rows, cols;
}Matrix;

// Create Matrix with specified size
extern	Matrix	createMat(int _rows, int _cols);

// Free a memory allocated matrix
extern	void	freeMat(Matrix _A);

// Create a matrix from a text file
extern	Matrix	txt2Mat(std::string _filePath, std::string _fileName);

//// Print matrix
extern	void	printMat(Matrix _A, const char* _name);

// Matrix addition
extern	Matrix	addMat(Matrix _A, Matrix _B);


// initialization of Matrix elements
extern	void	initMat(Matrix _A, double _val);



//////////////////////////////////////////////////////////////////
/*							Tutorial							*/
//////////////////////////////////////////////////////////////////


// Create matrix of all zeros
extern	Matrix	zeros(int _rows, int _cols);

// Create matrix of all ones
extern	Matrix	ones(int _rows, int _cols);

// Create identity matrix
extern	Matrix	eye(int _rows, int _cols);


// Matrix subtraction
extern	Matrix	subMat(Matrix _A, Matrix _B);

// Multiply  matrix A and matrix B
extern	Matrix	multMat(Matrix _A, Matrix _B);

// Multiply  matrix A with a scalar k
extern	Matrix	smultMat(Matrix _A, double _k);

// Create Transpose matrix
extern	Matrix	transpose(Matrix _A);

// Copy matrix
extern	Matrix	copyMat(Matrix _A);


extern	void gaussElim(Matrix A, Matrix b, Matrix U, Matrix d);

extern	void LUdecomp(Matrix A, Matrix L, Matrix U);

extern	void solveLU(Matrix L, Matrix U, Matrix b, Matrix x);

extern	void fwdsub(Matrix L, Matrix b, Matrix y);

extern	void backsub(Matrix U, Matrix y, Matrix x);

extern	void invMat(Matrix A, Matrix Ainv);

extern double norm2Vec(Matrix v);

extern Matrix eigval(Matrix A);
extern void QRdecomp(Matrix A, Matrix Q, Matrix R);
extern Matrix eigvec(Matrix A);
extern void eig(Matrix A, Matrix V, Matrix D);



// Calculates coefficients of least squares regression - Line
extern Matrix linearFit_mat(Matrix _vecX, Matrix _vecY);

// Calculates coefficients of least squares regression - Nth order polynomial
extern Matrix polyFit_mat(Matrix _vecX, Matrix _vecY, int orderN);

// [YOUR COMMENT]
//Matrix	expFit_mat(Matrix _X, Matrix _Y);

extern Matrix arr2Mat(double* _1Darray, int _rows, int _cols);


// Calculates coefficients of least squares regression - Line
extern void linearFit(double vecZ[], double vecX[], double vecY[], int dataL);

// Calculates coefficients of least squares regression - Nth order polynomial
extern void polyFit(double vecZ[], double vecX[], double vecY[], int dataL, int orderN);

// [YOUR COMMENT]
extern void expFit(double vecZ[], double vecX[], double vecY[], int dataL);

extern Matrix expFit_mat(Matrix _X, Matrix _Y);


#endif