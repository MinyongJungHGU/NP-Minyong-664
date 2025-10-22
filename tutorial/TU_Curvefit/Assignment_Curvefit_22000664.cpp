/*------------------------------------------------------------------------------------------\
@ Numerical Programming  by Young-Keun Kim - Handong Global University

Author          : Young-Keun Kim
Created         : Jan-04-2019
Modified        : Nov-18-2024 v2
Language/ver	: C in MSVS2017
Course			: Numerical Programming

Description     : Assignment 9 Curvefitting
/------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------*/
/*			MODIFY Path and name of Headerfiles										 		*/
/*------------------------------------------------------------------------------------------*/
#include "../../include/myNP_22000664.h"
#include "../../include/myMatrix_22000664.h"





int main(int argc, char* argv[])
{
/*------------------------------------------------------------------------------------------*/
	/*==========================================================================*/
	/*					Part 1-1:  Polyfit(line)								*/
	/*--------------------------------------------------------------------------*/
	/*   - order n=1 linearFit													*/
	/*==========================================================================*/


	/*==========================================================================*/
	/*						Initialization										*/
	/*==========================================================================*/

	// Initial Conditions
	double T[] = { 30, 40, 50, 60, 70, 80};
	double P[] = { 1.05, 1.07, 1.09, 1.14, 1.17, 1.21 };
	double Z_Q1[2] = { 0 };
	int orderN = 1;	// nth order
	int m_Q1 = 6;	// length of dataset
	int mx = 0; int my = 0;


	// Check Is length(X)~= length(Y) ? Exit: Continue 
	mx = sizeof(T) / sizeof(T[0]);
	my = sizeof(P) / sizeof(P[0]);
	if (my != mx) {
		printf("[ERROR] X and Y have different length!! \n\r");
		return 0;
	}



	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/

	orderN = 1;

	// Option 1	 (Recommended)
	Matrix matT = arr2Mat(T, m_Q1, 1);
	Matrix matP = arr2Mat(P, m_Q1, 1);
	Matrix vecZ_Q1 = polyFit_mat(matT, matP, orderN);

	printf("----------------------------------------------------------------\n");
	printf("\t Part 1-1: Line Fitting	(Option 1: polyFit_mat)				\n");
	printf("----------------------------------------------------------------\n");
	printf("Z_Q1= [a0,  a1] \n\r");
	printMat(vecZ_Q1, "Z_Q1");


	// Option 2: Using 1D array
	
	polyFit(Z_Q1, T, P, m_Q1, orderN);
	printf("----------------------------------------------------------------\n");
	printf("\t Part 1-1: Line Fitting	(Option 2: polyFit)					\n");
	printf("----------------------------------------------------------------\n");
	printf("Z_Q1= [a0=%.3f, a1=%.3f] \n\n\r", Z_Q1[0], Z_Q1[1]);
	printf("Predictation of P when T = 120: %f\n", Z_Q1[0] + Z_Q1[1] * 120);


/*------------------------------------------------------------------------------------------*/
	/*==========================================================================*/
	/*					Part 1-2:  Polyfit(nth )								*/
	/*--------------------------------------------------------------------------*/
	/*   - order n=2 or higher, polyfit											*/
	/*==========================================================================*/


	/*==========================================================================*/
	/*						Initialization										*/
	/*==========================================================================*/

	printf("----------------------------------------------------------------\n");
	printf("\t Part 1-2: Polynomial  Fitting (Option 1: polyFit_mat)		\n");
	printf("----------------------------------------------------------------\n");

	// Initial Conditions
	int m_Q2 = 16;				// data length
	double Stress[] = { 0, 3, 4.5, 5.8, 5.9, 5.8, 6.2, 7.4, 9.6, 15.6, 20.7, 26.7,31.1, 35.6, 39.3, 41.5 };
	double Strain[16] = { 0 };
	for (int k = 0; k < m_Q2; k++)
		Strain[k] = 0.4 * k;

	// Is length(X)~= length(Y) ? Exit: Continue 
	// [YOUR CODE GOES HERE]
	mx = sizeof(Strain) / sizeof(Strain[0]);
	my = sizeof(Stress)/sizeof(Stress[0]);
	printf("Q2: mx=%d \t my=%d \n\r", mx, my);
	if (mx != my) {
		printf("[ERROR] X and Y have different length!! \n\r");
		return 0;
	}


	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/

	orderN = 4;	// nth order

	// Option 1	
	Matrix matStrain = arr2Mat(Strain, m_Q2, 1);
	Matrix matStress = arr2Mat(Stress, m_Q2, 1);
	Matrix vecZ_Q2 = polyFit_mat(matStrain, matStress, orderN);
//	Matrix vecZ_Q2 = linearFit_mat(matStrain, matStress);


	printf("Z_Q2= [a0,  a1, .. a4] \n\r");
	printMat(vecZ_Q2, "Z_Q2");

	
	// Option 2: using 1D array
	double Z_Q2[5] = { 0 };		// 4th order - a0 to a4
	polyFit(Z_Q2, Strain, Stress, m_Q2, orderN);

	// Print output
	printf("----------------------------------------------------------------\n");
	printf("\t Part 1-2: Polynomial  Fitting (Option 2: polyFit)			\n");
	printf("----------------------------------------------------------------\n");
	printf("Z_Q2= [a0=%.3f, a1=%.3f, a2=%.3f, a3=%.3f, a4=%.3f] \n\n\r", Z_Q2[0], Z_Q2[1], Z_Q2[2], Z_Q2[3], Z_Q2[4]);






/*------------------------------------------------------------------------------------------*/
	/*==========================================================================*/
	/*					Part 2:  Exponential fit								*/
	/*--------------------------------------------------------------------------*/
	/*   yhat=a0*exp(a1*t)														*/
	/*   																		*/
	/*==========================================================================*/



	//option2

	/*==========================================================================*/
	/*						Initialization										*/
	/*==========================================================================*/
	double Z[2] = { 0 };
	double xdata[15] = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30 };
	double ydata[15] = { 9.7, 8.1, 6.6, 5.1, 4.4, 3.7, 2.8, 2.4, 2.0, 1.6, 1.4, 1.1, 0.85, 0.69, 0.6 };
	int dataL = 15;

	double R = 5 * pow(10, 6);
	double C = 0;
	double tau = 0;
	double V0 = 0;
	double a0, a1 = 0;


	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	expFit(Z, xdata, ydata, dataL);

	a0 = Z[0];
	a1 = Z[1];

	tau = (-1) / a1;
	C = tau / R;
	V0 = exp(a0);




	//option 1
	Matrix X_2 = arr2Mat(xdata, dataL, 1);
	Matrix Y_2 = arr2Mat(ydata, dataL, 1);

	Matrix Z_2= expFit_mat(X_2, Y_2);

	double a0_ = Z_2.at[0][0];
	double a1_ = Z_2.at[1][0];

	double tau_ = (-1) / a1_;
	double C_ = tau_ / R;
	double V0_ = exp(a0_);

	//print
	printf("----------------------------------------------------------------\n");
	printf("\t Part 2: Exponential Fitting (Option 1: expFit_mat)			\n");
	printf("----------------------------------------------------------------\n");
	printf("Capacitance: %.10f\nV0: %f\n", C_, V0_);


	printf("----------------------------------------------------------------\n");
	printf("\t Part 2: Exponential Fitting (Option 2: expFit)			\n");
	printf("----------------------------------------------------------------\n");
	printf("Capacitance: %.10f\nV0: %f\n", C, V0);


	system("pause");
	return 0;
}



