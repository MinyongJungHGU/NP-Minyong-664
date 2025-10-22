/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : Minyong Jung
Created          : 10-07-2024
Modified         : 10-11-2024
Language/ver     : C++ in MSVS2022

Description      : MidTerm2024 - Part 2 (Q4)
---------------------------------------------------------------*/

// Include your library "myNP.h"
#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include "../../include/myNP_22000664.h"  // Need to change the path


double func_Q4a(double x);
double func_Q4c(double x);

double integralQuad(double func(double _x));
double integralQuad2(double func(double _x), double a, double b);
double integralQuadComp(double func(double _x), double a, double b, int n);

int main(int argc, char* argv[])
{
	
	printf("\n**************************************************");
	printf("\n|                 Question 4-(a).                |");
	printf("\n**************************************************\n");

	double I1 = 0.0;

	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	I1=integralQuad(func_Q4a);

	printf("\nanswer of Q4-(a) = %f\n\n", I1);



	
	printf("\n**************************************************");
	printf("\n|                 Question 4-(b).                |");
	printf("\n**************************************************\n");
	
	double a_b    = 0.0;
	double b_b    = 3.0;
	double I2 = 0.0;

	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	// [TO-DO] Add your code here

	I2 = integralQuad2(func_Q4a,a_b,b_b);

	printf("\nanswer of Q4-(b) = %f\n\n", I2);
	
	


	
	printf("\n**************************************************");
	printf("\n|                 Question 4-(c).                |");
	printf("\n**************************************************\n");
	
	double a_c    = 0.0;
	double b_c    = 1.2;
	int    n    = 12;
	double z_elong = 0.0;

	
	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	z_elong = integralQuadComp(func_Q4c, a_c, b_c, n);
		
	printf("\nanswer of Q4_c = %f\n\n", z_elong);


	system("pause");
	return 0;
}



/*==========================================================================*/
/*						Function Definitions								*/
/*==========================================================================*/


double func_Q4a(double x)
{
	double out = 0.0;

	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	out = exp((-1) * pow(x,2));

	return out;
}

double func_Q4c(double x)
{
	double out = 0.0;

	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	out = 1 + 40 * pow(10, -3) * pow(x, 0.5);

	return out;
}

double integralQuad(double func(double _x))
{
	double weight[3] = {5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0};
	double xn[3]     = {-sqrt(1.0 / 3.0), 0.0, sqrt(1.0 / 3.0)};

	double output = 0.0;

	// [TO-DO] Add your code here
	// [TO-DO] Add your code here

	output = weight[0] * func(xn[0]) + weight[1] * func(xn[1]) + weight[0] * func(xn[2]);

	return output;
}

double integralQuad2(double func(double _x), double a, double b)
{
	double output = 0.0;
	double A = b - a;
	double B = a + b;
	double weight[3] = { 5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0 };
	double xn[3] = { -sqrt(1.0 / 3.0), 0.0, sqrt(1.0 / 3.0) };
	double xn1[3] = { (A * xn[0] + B) / 2.0,(A * xn[1] + B) / 2.0,(A * xn[2] + B) / 2.0 };

	output = weight[0] * func(xn1[0]) + weight[1] * func(xn1[1]) + weight[0] * func(xn1[2]);
	output = A / 2.0 * output;


	// [TO-DO] Add your code here
	// [TO-DO] Add your code here

	return output;
}

double integralQuadComp(double func(double _x), double a, double b, int n)
{
	double output = 0.0;
	double h = (b - a) / n;
	double I_N = 0;


	// [TO-DO] Add your code here
	// [TO-DO] Add your code here
	for (int i = 0; i < n; i++) {
		I_N = integralQuad2(func,a+h*i,a+h*(i+1));
		output = output + I_N;
	}


	return output;

}
