/*------------------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author          : Young-Keun Kim
Created         : 07-03-2019
Modified        : 03-01-2021
Language/ver    : C /  MSVS2017
Course          : Numerical method 2021-Spring
Description     : Tutorial of Bisection Method
/------------------------------------------------------------------------------------------*/


#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include "../../include/myNP_22000664.h"


// Move function declaration to  `myNP.h`



void main() {

	/*==========================================================================*/
	/*               Tutorial -     Bisection Method                            */
	/*==========================================================================*/

	/************      Variables declaration & initialization      ************/
	double tol = 0.00001;
	double a0 = 2;			//need to change initial value
	double b0 = 3;			//need to change initial value
	double sol_bm = 0;

	/************      Solve  &		Show Output			           ************/
	printf("------------------------------------------------------------------------------------\n");
	printf("         Bisection Method Results             \n");
	printf("------------------------------------------------------------------------------------\n");

	printf("Bisection Method:\n");
	sol_bm = bisection(func,a0, b0, tol);

	printf("Final Solution: %f \t", sol_bm);
	printf("\n");



	/*==========================================================================*/
	/*               Assignment -     Newton Rhapson                            */
	/*==========================================================================*/

	/************      Variables declaration & initialization      ************/
	double sol_nr = 0;
	double x0 = 3;

	printf("------------------------------------------------------------------------------------\n");
	printf("         Newton-Raphson Method Results             \n");
	printf("------------------------------------------------------------------------------------\n");

	/************      Solve  &		Show Output			           ************/
	printf("Newton-Raphson Method Result:\n");
	sol_nr = newtonRaphson(func,dfunc,x0, tol);

	printf("Final Solution: %f \t", sol_nr);
	printf("\n");


	system("pause");
}




/*==========================================================================*/
/*                    Function Definitions		   		*/
/*==========================================================================*/
//

// Move these function definitions to  `myNP.c`

/* function f(x) of the problem */
double func(double x)
{

	double F = 0;
	F = 8 - 4.5 * (x - sin(x));
	// [TO-DO] YOUR CODE GOES HERE
	return F;
}

/* first derivative of function f(x) of the problem */
double dfunc(double x)
{
	double dF = 0;
	dF =  -4.5 * (1 - cos(x));
	// [TO-DO] YOUR CODE GOES HERE
	return dF;
}





