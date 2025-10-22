/*-------------------------------------------------------------------------------\
@ Numerical Programming by Young-Keun Kim - Handong Global University

Author           : M.Y. Jung
Created          : 26-03-2018
Modified         : 30-10-2024
Language/ver     : C++ in MSVS2019

Description      : Tutorial code for using matrix structure
-------------------------------------------------------------------------------*/

#define ASGN		6		// enter your assignment number
#define EVAL		0		// [воик DO NOT EDIT !!!]


#include"../../include/myNP_22000664.h"
#include"../../include/myMatrix_22000664.h"


int main(int argc, char* argv[])
{

	/*	 [воик DO NOT EDIT !!!]   Resources file path setting for evaluation	*/
// #if _WIN64 | _WIN32
// 	std::string path = "C:/NP_Data/Assignment" + std::to_string(ASGN) + "/";

// #elif __APPLE__
// 	std::string path = "~/NP_Data/Assignment" + std::to_string(ASGN) + "/";
// #endif

	std::string path = "../../NP_Data/Assignment" + std::to_string(ASGN) + "/";
#if EVAL
	path += "eval/";
#endif

	//Problem 1
	Matrix matA_Q1 = txt2Mat(path, "prob1_matA");
	Matrix vecb_Q1 = txt2Mat(path, "prob1_vecb");
	Matrix matU_Q1 = createMat(matA_Q1.rows, matA_Q1.cols);
	Matrix matL_Q1 = eye(matA_Q1.rows, matA_Q1.cols);
	Matrix vecx_Q1 = createMat(vecb_Q1.rows, 1);

	LUdecomp(matA_Q1, matL_Q1, matU_Q1);
	solveLU(matL_Q1, matU_Q1, vecb_Q1, vecx_Q1);

	
	//Problem 2
	Matrix matK_Q2 = txt2Mat(path, "prob2_matK");
	Matrix vecf_Q2 = txt2Mat(path, "prob2_vecf");
	Matrix matU_Q2 = createMat(matK_Q2.rows, matK_Q2.cols);
	Matrix matL_Q2 = eye(matK_Q2.rows, matK_Q2.cols);
	Matrix vecx_Q2 = createMat(vecf_Q2.rows, 1);

	LUdecomp(matK_Q2, matL_Q2, matU_Q2);
	solveLU(matL_Q2, matU_Q2, vecf_Q2, vecx_Q2);


	//Ainv_Q1
	Matrix Ainv_Q1 = createMat(matA_Q1.rows, matA_Q1.cols);
	invMat(matA_Q1, Ainv_Q1);


	//display the results
	//Problem 1
	printf("-------------------------------------------------------------\n");
	printf("                   LU decomposition Results                \n");
	printf("-------------------------------------------------------------\n");
	printf("Q1.\n\n");
	printMat(matA_Q1, "matA");
	printMat(vecb_Q1, "vecb");
	printMat(matL_Q1, "matL");
	printMat(matU_Q1, "matU");
	printMat(vecx_Q1, "vecx");
	printf("\n\n\n");

	
	//Problem 2
	printf("Q2.\n\n");
	printMat(matK_Q2, "matK");
	printMat(vecf_Q2, "vecf");
	printMat(matL_Q2, "matL");
	printMat(matU_Q2, "matU");
	printMat(vecx_Q2, "vecx");
	printf("\n\n\n");


	//Ainv_Q1
	printf("-------------------------------------------------------------\n");
	printf("                   Inverse Matrix of matA_Q1                \n");
	printf("-------------------------------------------------------------\n");
	printMat(Ainv_Q1, "Ainv");


	/*==========================================================================*/
	/*							  Deallocate memory 							*/
	/*==========================================================================*/
	freeMat(matA_Q1);		freeMat(vecb_Q1);
	freeMat(matU_Q1);		freeMat(matL_Q1);		freeMat(vecx_Q1);

	freeMat(matK_Q2);		freeMat(vecf_Q2);
	freeMat(matU_Q2);		freeMat(matL_Q2);		freeMat(vecx_Q2);

	freeMat(Ainv_Q1);

	system("pause");
	return 0;
}
