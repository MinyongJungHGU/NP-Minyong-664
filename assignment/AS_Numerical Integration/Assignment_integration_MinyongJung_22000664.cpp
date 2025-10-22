#include<stdio.h>
#include"../../include/myNP_22000664.h"

double myFunc(const double x);



int main() {
	//Problem 1
	double x1[] = { 0,5,10,15,20,25,30,35,40,45,50,55,60 };
	double y1[] = { 0,3,8,20,33,42,40,48,60,12,8,4,3 };
	int size1 = sizeof(x1) / sizeof(x1[0]);
	double Tr = trapz(x1, y1, size1);

	printf("\n------------Trapezoidal method-----------\n");
	printf("The numerical integration value is %f\n", Tr);

	//Problem 2
	double x2[] = { -3, -2.25, -1.5, -0.75, 0, 0.75, 1.5, 2.25, 3 };
	double y2[] = { 0,2.1875,3.75,4.6875,5,4.6875,3.75,2.1875,0 };
	int size2 =sizeof(x2)/sizeof(x2[0]);
	double Sim13 = simpson13(x2, y2, size2);

	printf("\n------------simpson 1/3 method-----------\n");
	printf("The numerical integration value is %f\n", Sim13);

	//Problem 3
	
	double x0 = -1;
	double xN = 1;
	int size3 = 13;
	double intgrl = integral(myFunc, x0,xN,size3);

	printf("\n------------Integration from a Function using simpson 1/3 method-----------\n");
	printf("The numerical integration value is %f\n", intgrl);
}	


double myFunc(const double x) {
	double Fx=sqrt(1 - x * x);
	return Fx;
}