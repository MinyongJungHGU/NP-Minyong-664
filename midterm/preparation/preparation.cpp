#include"../../include/myNP_22000664.h"


double func1(double x);
int main() {

	double x = 0;
	printf("%lf \n", rect(func1,PI,2*PI,500));
	return 0;
}

double func1(double x) {
	double y = 0;

	y = sin(x);
	return y;
}