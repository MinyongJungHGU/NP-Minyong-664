/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [YOUR NAME]
Created          : 10-07-2024
Modified         : 10-07-2024
Language/ver     : C++ in MSVS2022

Description      : Test2_Part1_yourID_2024.cpp ver2
----------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>


// [Include your library "myNP.h"]
// [Need to change the path]
#include "../../include/myNP_22000664.h"				
#include "../../include/myMatrix_22000664.h"

// [Uncomment if you dont have it]
//Matrix	arr2Mat(double* _1Darray, int _rows, int _cols);			


int main(int argc, char* argv[])
{
/*------------------------------------------------------------------------------------------*/
    /*==========================================================================*/
    /*					Problem 21 a)
    /*==========================================================================*/

    /************      Variables declaration & initialization      ************/
    double acc1 = 1.5;
    double acc2 = 2.0;
    double acc3 = 0.8;

    double k1 = 180;
    double k2 = 240;
    double k3 = 300;

    double m1 = 8;
    double m2 = 10;
    double m3 = 12;

    // [TO-DO]  Change variable values   
    /* Example: double arrA[] = {-(k1 + k2) / m1, (k2 / m1) , 0,
                                 (k2 / m2), ....  , ... ,
                                  0,  ... ,  ... };*/
    // [TO-DO]  YOUR NP CODE GOES HERE   
    double arrA[] = { -(k1+k2)/m1,k2/m1,0,
                      k2/m2,-(k2+k3)/m2,k3/m2,
                      0,-(k3/m3),k3/m3};


    // [TO-DO]  Change variable values   
    // [TO-DO]  YOUR NP CODE GOES HERE   
    double arrB[] = {acc1,acc2,acc3};



    Matrix matA = arr2Mat(arrA, 3, 3);
    Matrix vecb = arr2Mat(arrB, 3, 1);
    Matrix vecx = zeros(3, 1);

    Matrix matU = zeros(3, 3);
    Matrix vecd = zeros(3, 1);

    /************      Your Numerical Method						     ************/
    // [TO-DO]  YOUR NP CODE GOES HERE   
    // [TO-DO]  YOUR NP CODE GOES HERE   
    gaussElim(matA, vecb, matU, vecd);
    backsub(matU, vecd, vecx);


    printf("\n**************************************************");
    printf("\n|                   Question 1a.                  |");
    printf("\n**************************************************\n");
    printMat(matA, "A");
    printMat(vecb, "b");
    printMat(vecx, "solution x");



/*------------------------------------------------------------------------------------------*/
    /*==========================================================================*/
    /*					Problem 1 b)
    /*==========================================================================*/

    /************      Variables declaration & initialization      ************/
    Matrix matA_Eig = zeros(3, 1);
    Matrix matA_EigVec = zeros(3, 3);


    /************      Your Numerical Method						     ************/
    // [TO-DO]  YOUR NP CODE GOES HERE   
    // [TO-DO]  YOUR NP CODE GOES HERE
    eig(matA, matA_EigVec, matA_Eig);


    printf("\n**************************************************");
    printf("\n|                   Question 1b.                  |");
    printf("\n**************************************************\n");

    printMat(matA, "Matrix A");
    printMat(matA_Eig, "EigenValue");
    printMat(matA_EigVec, "EigenVector");


    /************      Deallocate Memory							     ************/
    freeMat(matA);	freeMat(vecb); freeMat(vecx);
    freeMat(matA_Eig);	freeMat(matA_EigVec);


/*------------------------------------------------------------------------------------------*/
    /*==========================================================================*/
    /*					Problem 2
    /*==========================================================================*/

    /************      Variables declaration & initialization      ************/    
    int m_Q2 = 6;				
//    Matrix vecVel = zeros(6, 1);
//    Matrix vecDis = zeros(6, 1);
//    Matrix vecZ_Q2 = zeros(2, 1);



    // [TO-DO]  Change variable values and convert to Matrix type (vecVel, vecDis)
    // [TO-DO]  YOUR NP CODE GOES HERE   
    double vel[6] = { 20,40,60,80,100,120};
    double dis[6] = { 6.7, 24.2, 56.8, 109.7, 179.5, 290.0};

    Matrix vecVel = arr2Mat(vel, 6, 1);
    Matrix vecDis = arr2Mat(dis, 6, 1);


    /************      Your Numerical Method						     ************/
    // [TO-DO]  YOUR NP CODE GOES HERE   
    // [TO-DO]  YOUR NP CODE GOES HERE   

    Matrix vecZ_Q2 = polyFit_mat(vecVel, vecDis, 2);

    printf("\n**************************************************");
    printf("\n|                   Question 2.                  |");
    printf("\n**************************************************\n");
    printf("Z_Q2= [a0,  a1, a2] \n\r");
    printMat(vecZ_Q2, "Z_Q2");

    printf("Distance on fitted line: \n\r");
    // [TO-DO] Display  distances on the fitted line     
    // [TO-DO]  YOUR NP CODE GOES HERE   
    double a0 = vecZ_Q2.at[0][0];
    double a1 = vecZ_Q2.at[1][0];
    double a2 = vecZ_Q2.at[2][0];

    double dHat = a2 * 100 * 100 + a1 * 100 + a0;
    printf("dHat when v = 100: %f", dHat);

    system("pause");

    return 0;
}


/*------------------------------------------------------------------------------------------*/

/*==========================================================================*/
/*						Function Definitions								*/
/*==========================================================================*/

// [Uncomment if you dont have it]
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