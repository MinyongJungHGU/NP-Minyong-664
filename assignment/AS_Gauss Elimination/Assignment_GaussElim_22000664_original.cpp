/*
#include<stdio.h>
#define ASGN		5		// enter your assignment number
#define EVAL		0		// [воик DO NOT EDIT !!!]

#include"../../include/myNP_22000664.h"
#include"../../include/myMatrix_22000664.h"

int main() {
	std::string path = "../../NP_Data/Assignment" + std::to_string(ASGN) + "/";
#if EVAL
	path += "eval/";
#endif

	//Problem 1
	Matrix matA_Q1 = txt2Mat(path, "prob1_matA");
	Matrix vecb_Q1 = txt2Mat(path, "prob1_vecb");
	Matrix matU_Q1 = createMat(matA_Q1.rows,matA_Q1.cols);
	Matrix vecd_Q1 = createMat(vecb_Q1.rows, 1);
	Matrix vecx_Q1 = createMat(vecb_Q1.rows , 1);

	gaussElim(matA_Q1, vecb_Q1, matU_Q1, vecd_Q1);
	backsub(matU_Q1, vecd_Q1, vecx_Q1);


	//Problem 2
	Matrix matK_Q2 = txt2Mat(path, "prob2_matK");
	Matrix vecf_Q2 = txt2Mat(path, "prob2_vecf");
	Matrix matU_Q2 = createMat(matK_Q2.rows, matK_Q2.cols);
	Matrix vecd_Q2 = createMat(vecf_Q2.rows, 1);
	Matrix vecx_Q2 = createMat(vecf_Q2.rows, 1);

	gaussElim(matK_Q2, vecf_Q2, matU_Q2, vecd_Q2);
	backsub(matU_Q2, vecd_Q2, vecx_Q2);


	//display the results
	//Problem 1
	printf("-------------------------------------------------------------\n");
	printf("                   Gausss Elimination Results                \n");
	printf("-------------------------------------------------------------\n");
	printf("Q1.\n\n");
	printMat(matA_Q1, "matA");
	printMat(vecb_Q1, "vecb");
	printMat(matU_Q1, "matU");
	printMat(vecd_Q1, "vecd");
	printMat(vecx_Q1, "vecx");
	printf("\n\n\n");

	//Problem 2
	printf("Q2.\n\n");
	printMat(matK_Q2, "matA");
	printMat(vecf_Q2, "vecb");
	printMat(matU_Q2, "matU");
	printMat(vecd_Q2, "vecd");
	printMat(vecx_Q2, "vecx");

	return 0;
}
*/