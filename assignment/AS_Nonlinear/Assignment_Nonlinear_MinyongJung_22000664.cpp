#include"include/myNP_22000664.h"

int main() {

	double x0 = 1;
	double xn = 0;

	xn = newtonRaphson(func, dfunc, 1.1,0.0001);
	printf("Final Solution:	%f\n", xn);
	return 0;
}

double func(double x) {
	double y = 0;
	y = 20 * tan(x) - 9.81 * 20 * 20 / (2 * 17 * 17 * cos(x) * cos(x)) - 2;

	return y;
};

double dfunc(double x) {
	double y = 0;
	y = 20 / (cos(x) * cos(x)) - 9.81 * 20 * 20 * 2 * tan(x) / (2 * 17 * 17 * cos(x) * cos(x));
	return y;
}


