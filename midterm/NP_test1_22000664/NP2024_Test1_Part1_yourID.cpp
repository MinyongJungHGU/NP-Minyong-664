/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [Minyong Jung]  <--- MODIFY!!!!!
Created          : 10-07-2024
Modified         : 10-08-2024
Language/ver     : C++ in MSVS2022

Description      : MidTerm2024 - Part 1 (Q1~Q3)
----------------------------------------------------------------*/

// Include your library "myNP.h"
#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include "../../include/myNP_22000664.h"  // Need to change the path


double func_Q1(double x);
double dfunc_Q1(double x);
double func_Q2(double x);
double func_Q3(double x);

int main(int argc, char* argv[])
{
	
	printf("\n**************************************************");
	printf("\n|                   Question 1.                  |");
	printf("\n**************************************************\n");

	double x0_Q1 = 6.0;
	double tol = 1e-5;
	double x_Q1  = 0.0;

	x_Q1=newtonRaphson(func_Q1, dfunc_Q1, x0_Q1, tol);

	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	// [TO-DO] Add your code here

	printf("\n answer of Q1  x= %f\n\n", x_Q1);


	
	printf("\n**************************************************");
	printf("\n|                   Question 2.                  |");
	printf("\n**************************************************\n");
	
	double x_Q2 = 2.0;
	double h  = 0.01;
	double dydx_Q2 = 0.0;

	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	dydx_Q2 = (func_Q2(x_Q2 + h) - func_Q2(x_Q2)) / h;

	printf("\nanswer of Q2 dydx= %f\n\n", dydx_Q2);
	
	


	
	printf("\n**************************************************");
	printf("\n|                   Question 3.                  |");
	printf("\n**************************************************\n");
	
	double a  = 0.0;
	double b  = 1.2;
	int    N  = 12;
	double I_Q3 = 0.0;

	
	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	I_Q3 =integral(func_Q3, a, b, N);

		
	printf("\nanswer of Q3 I= %f\n\n", I_Q3);


	system("pause");
	return 0;
}



/*==========================================================================*/
/*						Function Definitions								*/
/*==========================================================================*/


double func_Q1(double x)
{
	double out = 0;

	// [TO-DO] Add your code here
	// [TO-DO] Add your code here

	out = PI * 11 * 11 / 2 * x + PI / 6 * x * x * x - 2000;

	
	return out;
}

double dfunc_Q1(double x)
{
	double out = 0;
	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	out = PI * 11 * 11 / 2 + PI / 2 * x * x;


	return out;
}

double func_Q2(double x)
{
	double out = 0;
	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	out = (x * x + sqrt(x)) * cos(x) / sin(x);

	return out;
}


double func_Q3(double x)
{
	double out = 0;
	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	out=1+40*pow(10,-3)*pow(x,0.5);
	return out;
}
