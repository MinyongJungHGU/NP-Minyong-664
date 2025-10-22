/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [YOUR NAME]
Created          : 10-07-2024
Modified         : 10-07-2024
Language/ver     : C++ in MSVS2022

Description      : Test2_Part2_yourID_2024.cpp  ver2
----------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

#define EVAL	0		// set 0

// Include your library "myNP.h"
// Need to change the path
#include "../../include/myNP_22000664.h"				
#include "../../include/myMatrix_22000664.h"



void odeFunc_Q3(double dYdt[], const double t, const double Y[]);
double normFrob(Matrix matA);
double traceMat(Matrix matA);
double SVD(Matrix A);
// [Uncomment if you dont have it]
//Matrix	arr2Mat(double* _1Darray, int _rows, int _cols);



int main(int argc, char* argv[])
{
 /*------------------------------------------------------------------------------------------*/
    /*==========================================================================*/
    /*					DO NOT MODIFY HERE
    /*==========================================================================*/

    #if _WIN64 | _WIN32
        /*	 [воик DO NOT EDIT !!!]   Resources file path setting for evaluation	*/
        std::string path = "./";
    #elif __APPLE__    
        std::string path = "./";
    #endif
 /*------------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------------------*/
    /*==========================================================================*/
    /*					Problem 3
    /*==========================================================================*/

    /************      Variables declaration & initialization      ************/
    double theta[100] = { 0 };
    double w[100] = { 0 };

    double t0 = 0.0;
    double tf = 5.0;
    double h = 0.1;

    double theta_init = PI / 2.0;
    double w_init = 0.0;
    int mtest = 50;

    /************      Your Numerical Method						     ************/
    sys2RK2(theta, w, odeFunc_Q3, t0, tf, h, theta_init, w_init);
    


    printf("\n**************************************************");
    printf("\n|                   Question 3.                  |");
    printf("\n**************************************************\n");
    printf("theta[%d] =%0.4f [rad] \n\r", mtest, theta[mtest]);




/*------------------------------------------------------------------------------------------*/
   /*==========================================================================*/
   /*					Problem 4
   /*==========================================================================*/

   /************      Variables declaration & initialization      ************/
    Matrix A = txt2Mat(path, "Test2_matA");  // in the same directory as the source code

    #if EVAL
        Matrix A = txt2Mat(path, "Test2_Eval_matA");
    #endif
  


    double fNorm = normFrob(A);   // Q4 a)
    double trAtA = sqrt(traceMat(multMat(transpose(A),A)));   // Q4 b)
    double trAAt = sqrt(traceMat(multMat(A, transpose(A))));   // Q4 b)
    double fNorm2 = SVD(A);  // Q4 c)
    
    double s2 = 0;

    /************      Your Numerical Method						     ************/
    



    printf("\n**************************************************");
    printf("\n|                   Question 4.                  |");
    printf("\n**************************************************\n");
    printMat(A, " matA Q4");
    printf("4a) Fnorm(A) = %0.4f  \n\r", fNorm);
    printf("4b) Sqrt(Tr(A'A))= %0.4f,  Sqrt(Tr(AA'))= %0.4f  \n\r", trAtA, trAAt);
    printf("4c) Fnorm2(A)= %0.4f  \n\r", fNorm2);

    system("pause");

    return 0;
}



/*==========================================================================*/
/*						Function Definitions								*/
/*==========================================================================*/


void odeFunc_Q3(double dYdt[], const double t, const double Y[])
{
    double m = 0.5;
    double c = 0.16;
    double L = 1.2;
    double g = 9.81;

    dYdt[0] = Y[1];
    dYdt[1] = -c / m * Y[1] - g / L * Y[0];
    
}

double traceMat(Matrix matA)
{
    int n = matA.cols;
    int m = matA.rows;
    double trace = 0;

    int max = (n > m ? m : n);

    for (int k = 0; k < max; k++) {
        trace += matA.at[k][k];
    }

    return trace;
}


double normFrob(Matrix matA)
{
    double fNorm= 0;

    for (int i = 0; i < matA.rows; i++) {
        for (int j = 0; j < matA.cols; j++) {
            fNorm += matA.at[i][j] * matA.at[i][j];
        }
    }

    fNorm = sqrt(fNorm);
    
    return fNorm;
}




/*
// Create a matrix from 1D-array
Matrix	arr2Mat(double* _1Darray, int _rows, int _cols)
{
    Matrix Output = createMat(_rows, _cols);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            Output.at[i][j] = _1Darray[i * _cols + j];

    return Output;
}
*/

double SVD(Matrix A) {

    double fNorm = 0;
    double s2 = 0;

    Matrix S = multMat(A, transpose(A));
    Matrix Eigval = eigval(S);

    for (int k = 0; k < Eigval.rows; k++) {
        s2 += Eigval.at[k][0];
    }

    return fNorm = sqrt(s2);

}