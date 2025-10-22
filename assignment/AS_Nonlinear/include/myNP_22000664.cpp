#include"myNP_22000664.h"

double newtonRaphson(double fucn(double const x), double dfunc(double const x), double x0, double tol) {

	double xn = x0;
	double e = fabs(func(x0));
	int k = 0;
	int Nmax = 1000;

	printf("---------------------------------------------------------\n");
	printf("              Newton-Raphson Method Results\n");
	printf("---------------------------------------------------------\n");
	printf("Newton-Raphson Method result:\n");

	while (e > tol && Nmax > k) {
		if (dfunc(xn)==0) {
			printf("Reset the initial value");
			break;
		}
		else {
			xn = xn - func(xn) / dfunc(xn);
			e = fabs(func(xn));
			k++;

			printf("Iteration:%d	X(n):%f		Tolerance:%f \n", k, xn, e);
		}
	}
	return xn;
}
