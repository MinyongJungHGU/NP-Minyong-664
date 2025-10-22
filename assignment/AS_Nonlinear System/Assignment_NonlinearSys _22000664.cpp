/*------------------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author          : Minyong Jung
Created         : 01-04-2019
Modified        : 11-27-2024
Language/ver	: C in MSVS2017
Course			: Numerical Programming 

Description     : Assignment_System of NonLinear
/------------------------------------------------------------------------------------------*/


#include "stdio.h"
#include "stdlib.h"

#include "../../include/myNP_22000664.h"
#include "../../include/myMatrix_22000664.h"


// Goes to myMatrix.h
Matrix nonlinearSys(Matrix Funcs(Matrix _Z), Matrix Jacob(Matrix _Z), Matrix _Z0, double tol);


// Defined in main code
Matrix myFuncEx1(Matrix X);
Matrix myJacobEx1(Matrix X);
Matrix myFuncEx2(Matrix X);
Matrix myJacobEx2(Matrix X);



void main() {

	/*==========================================================================*/
	/*					Variables declaration & initialization					*/
	/*--------------------------------------------------------------------------*/
	/*   - You can change the variable names									*/
	/*   - However, you must use the specified file name						*/
	/*	   : For each assignment, the file name will be notified on HISNET		*/
	/*==========================================================================*/

	/************      Variables declaration & initialization      ************/
	double loss_P1 = 0;
	int n_P1 = 2;
	Matrix J_P1 = zeros(n_P1, n_P1);
	Matrix F_P1 = zeros(n_P1, 1);
	Matrix H_P1 = zeros(n_P1, 1);
	Matrix Z_P1 = zeros(n_P1, 1);

	double loss_P2 = 0.00001;
	int n_P2 = 3;
	Matrix J_P2 = zeros(n_P2, n_P2);
	Matrix F_P2 = zeros(n_P2, 1);
	Matrix H_P2 = zeros(n_P2, 1);
	Matrix Z_P2 = zeros(n_P2, 1);


	// Initial condition
	double z0_P1[2] = { 2.5, 2 };
	Z_P1 = arr2Mat(z0_P1, n_P1, 1);
	
	double z0_P2[3] = { 25.0 / 180 * PI, 90, 90 };
	Z_P2 = arr2Mat(z0_P2, n_P2, 1);


	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	printf("----------------------------------------------------------------------------------------------\n");
	printf("			            System of NonLinear													  \n");
	printf("----------------------------------------------------------------------------------------------\n\r");

	printf("P1\n");

	Z_P1 = nonlinearSys(myFuncEx1, myJacobEx1, Z_P1, 0.001);
	printMat(Z_P1, "Z_P1");

	/*
	printf("P2\n");

	Z_P1 = nonlinearSys(myFuncEx1, myJacobEx1, Z_P1, 0.001);
	printMat(Z_P1, "Z_P1");
	*/

	/*==========================================================================*/
	/*							  Deallocate memory 							*/
	/*==========================================================================*/
	freeMat(J_P1);	freeMat(H_P1);	freeMat(F_P1); 	freeMat(Z_P1);
//	freeMat(J_P2);	freeMat(H_P2);	freeMat(F_P2); 	freeMat(Z_P2);

	system("pause");
}




/*==========================================================================*/
/*						Function Definitions								*/
/*==========================================================================*/

Matrix myFuncEx1(Matrix X)
{
	int n = X.rows;
	Matrix F = zeros(n, 1);
	double x1 = X.at[0][0];
	double x2 = X.at[1][0];

	// [TO-DO] YOUR CODE GOES HERE
	F.at[0][0] = x2 - 1 / 2 * (exp(x1 / 2) + exp(-x1 / 2));
	F.at[1][0] = 9 * (x1) * (x1)+25 * x2 * x2 - 225;

	return F;
}


Matrix myJacobEx1(Matrix X)
{
	int n = X.rows;
	Matrix J = zeros(n, n);
	double x1 = X.at[0][0];
	double x2 = X.at[1][0];

	// [TO-DO] YOUR CODE GOES HERE
	J.at[0][0] = -1 / 4 * (exp(x1 / 2) - exp(-x1 / 2));
	J.at[0][1] = 1;
	J.at[1][0] = 18 * x1;
	J.at[1][1] = 50 * x2;

	return J;
}

Matrix myFuncEx2(Matrix X) {

	Matrix Z = zeros(3, 1);

	Matrix F = zeros(3, 3);

	double th = X.at[0][0];
	double dx = X.at[1][0];
	double dy = X.at[2][0];

	// Initial Position
	double P0x = 0;
	double P0y = 100;
	double P1x = 0;
	double P1y = -100;

	// Final Position
	double P0x_new = 50;
	double P0y_new = 186.6025;
	double P1x_new = 150;
	double P1y_new = 13.3975;

	//Define the Function
	F.at[0][0] = P0x * cos(th) - P0y * sin(th) + dx - P0x_new;
	F.at[1][0] = P0x * sin(th) + P0y * cos(th) + dy - P0y_new;
	F.at[2][0] = P1x * cos(th) - P1y * sin(th) + dx - P1x_new;
}

Matrix myJacobEx2(Matrix X) {
	Matrix J = zeros(3, 3);

	double th = X.at[0][0];
	double P0x = 0;
	double P0y = 100;
	double P1x = 0;
	double P1y = -100;
	
	J.at[0][0] = -P0y * cos(th) - P0x * sin(th);
	J.at[0][1] = 1;
	J.at[0][2] = 0;
	J.at[1][0] = P0x * cos(th) - P0y * sin(th);
	J.at[1][1] = 0;
	J.at[1][2] = 1;
	J.at[2][0] = -P1y * cos(th) - P1x * sin(th);
	J.at[2][1] = 1;
	J.at[2][2] = 0;
}

Matrix nonlinearSys(Matrix Funcs(Matrix _Z), Matrix Jacob(Matrix _Z), Matrix _Z0, double tol) {
	// Initialization
	int n = _Z0.rows;
	double loss = 10;
	Matrix J = zeros(n, n);
	Matrix F = zeros(n, 1);
	Matrix Z = zeros(n, 1);

	// Initial condition
	Z = _Z0;

	for (int k = 0; k < 20; k++) {
		F = Funcs(Z);
	    J = Jacob(Z);
		Matrix U = zeros(n, n);
		Matrix d = zeros(n, 1);

		
		Matrix invJ = zeros(n, n);

		//find inverse matrix


		printMat(Z, "Z1");

		printMat(J, "Jacobian");
		printMat(invJ, "inverse J");

		// [TO-DO]  YOUR CODE GOES HERE
		// F =-1*F;
		// F=____________
		for (int i = 0; i < n; i++) {
			F.at[i][0] = (-1) * F.at[i][0];
		}

		// [TO-DO]  YOUR CODE GOES HERE
		// Solve for H in  JH = (-F)	
		// H = ___________
		
		Matrix H = multMat(invJ, F);

		/*
		gaussElim(J, F, U, d);
		backsub(U, d, H);
		*/


		printMat(F, "F");
		printMat(H, "H");
		
		// [TO-DO]  YOUR CODE GOES HERE
		//	Z = Z + H;
		// Z=______________
		for (int i = 0; i < n; i++) {
			Z.at[i][0] = Z.at[i][0] + H.at[i][0];
		}

		printMat(Z, "Z2");

		// After Z update, print loss
		F = Funcs(Z);

		// [TO-DO]  YOUR CODE GOES HERE
		// loss = norm2(F);   // sqrt((F.at[0][0])^2+(F.at[1][0])^2+...)
		loss = norm2Vec(F);

		printf("iter =%d \t x=%0.3f \t y=%0.3f \t loss=%0.3f\n", k, Z.at[0][0], Z.at[1][0], loss);

		if (loss < tol) {
			printf("Early Termination\n\r");
			return Z;
		}

		freeMat(U);
		freeMat(d);
		freeMat(invJ);
		freeMat(H);

	}

	freeMat(J);
	freeMat(F);

	return Z;
}
