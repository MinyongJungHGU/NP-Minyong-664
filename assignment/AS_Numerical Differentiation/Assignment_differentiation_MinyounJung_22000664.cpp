# include<stdio.h>
#include"../../include/myNP_22000664.h"

double myFunc(const double x);

void acceleration(double x[],double y[], double dy2dx2[], int m);


int main() {
	// Problem 1
	printf("Problem 1\n\n");
	double x1[12] = { -1,-0.5,0,0.5,1,1.5,2,2.5,3,3.5,4,4.5 };
	double y1[12] = { -3.632,-0.3935,1,0.6487,-1.282,-4.518,-8.611,-12.82,-15.91,-15.88,-9.402,9.017 };
	double dydx1[12] = { 0 };
	int m1 = 12;

	gradient1D(x1, y1, dydx1, m1);
	printVec(dydx1, m1);
	printf("-----------------------------------------------------------------------------\n");


	//Problem 2
	printf("Problem 2\n\n");
	const int m2 = 21;
	double x2[m2] = { 0 };
	double dydx2[m2] = { 0 };

	for (int i = 0; i < m2; i++) {
		x2[i] = i * 0.2;
	}

	gradientFunc(myFunc, x2, dydx2, m2);
	printVec(dydx2, m2);
	printf("-----------------------------------------------------------------------------\n");

	//Problem 3
	printf("Problem 3\n\n");
	const int m3 = 21;
	double x3[m3] = { 0 };
	double y3[m3] = { 0 };
	double dx2dy2[m2] = { 0 };

	for (int i = 0; i < m3; i++) {
		x3[i] = i * 0.2;
		y3[i] = myFunc(x3[i]);
	}

	acceleration(x3, y3, dx2dy2, m3);
	printVec(dx2dy2, m3);
}

double myFunc(const double x) {
	double y = 0;
	y = x * x * x;
	return y;
}

