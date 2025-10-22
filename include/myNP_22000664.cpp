/* myNP_tutorial.cpp 
--------------------------------------------------------------------------
@ C-Tutorial by Min-Yong Jung - Handong Global University

Author			: M.Y.Jung 22000664
Created			: 08-30-2024
Modified		: 09-30-2024
Language/ver	: C++ in MSVS2022

Description: my NP library
------------------------------------------------------------------------*/

#include "myNP_22000664.h"

void printVec(double* vec, int size)
{
	for (int i = 0; i < size; i++)
		printf("Vector[%d] = %.1f \n", i, vec[i]);
	printf("\n");
}


// factorial function
double factorial(int N)
{
	int y = 1;
	for (int k = 2; k <= N; k++)
		y = y * k;

	return y;
}


//  Taylor series approximation for sin(x) (input unit: [rad])
extern double sinTaylor(double _x)
{
	int N_max = 10;
	double S_N = 0;
	double S_K = 0;

	for (int k = 0; k < N_max; k++) {
		S_K = power(-1, k) * power(_x, 2 * k + 1) / factorial(2 * k + 1);
		S_N = S_N + S_K;
	}

	return S_N;
}

extern double cosTaylor(double _x) {
	
	int N_max = 10;
	double S_N = 0;
	double S_K = 0;

	for (int k = 0; k < N_max; k++) {
		S_K = pow(-1, k) * pow(_x, 2 * k) / factorial(2 * k);
		S_N = S_N + S_K;
	}

	return S_N;
};

// Taylor series approximation for sin(x) (input unit: [deg])
extern double sindTaylor(double _x)
{
	double S_N = sinTaylor(_x * PI / 180);
	return S_N;
}

// Taylor series approximation for cos(x) (input unit: [deg])
extern double cosdTaylor(double _x)
{
	double S_N = cosTaylor(_x * PI / 180);
	return S_N;
}


double expTaylor(double x) {
	double S_N = 0;
	double S_K = 0;
	int N_max = 10;

	for (int k = 0; k < N_max;k++) {
		S_K = pow(x, k) / factorial(k);
		S_N = S_N + S_K;
	}
	return S_N;
}

// power fuction
double power(double _x, int N)
{
	double y = 1;

	for (int i = 0; i < N; i++) {
		y = y * _x;
	}

	return y;
}

/* Bisection Method
	_a      : initial value #1
	_b      : initial value #2
	_tol   : tolerance
*/
double bisection(double func(const double x),double _a0, double _b0, double _tol)
{
	// Define Bisection function, assuming (func(a) * func(b) <0 )
	// Initialization
	int k = 0;
	int Nmax = 100;
	double a = _a0;
	double b = _b0;
	double xn = 0;
	double ep = 1000;

	// Bisection 
	if (func(a)*func(b)>0) {
		printf("Unable to calculate.");
	}
	else{
		while (k<Nmax && ep>_tol) {
			// Update xn as midpoint
			xn = (a + b) / 2;

			// Update range a, b
			if (func(a) * func(xn) < 0) {
				b = xn;
			}
			else if(func(a) * func(xn) > 0) {
				a = xn;
			}

			ep = fabs(func(xn));

			if (func(a) * func(b) == 0) {
				if (func(a) == 0) {
					printf("xTrue is %f", a);
				}
				else
					printf("xTrue is %f", b);
			}
		}
			k++;
			printf("k:%d \t", k);
			printf("Xn(k): %f \t", xn);
			printf("Tol: %.8f\n", ep);
		
	}
	if (k == Nmax) {
		printf("the solution did not converge within given iteration");
	}
	return xn;
}



/* Newton-Raphson Method without Passing a Function  */
double newtonRaphson(double func(const double x), double dfunc(const double x),double _x0, double _tol)
{
	double xn = _x0;
	double ep = 1000;
	int Nmax = 1000;
	int k = 0;
	double h = 0;
	while (k<Nmax && ep>_tol) {
		if (dfunc(xn) == 0)
		{
			printf("[ERROR] dF == 0 !!\n");
			break;
		}
		else
		{
			// get h=f/df @ x(k)
			// h=__________;   
			h = -func(xn) / dfunc(xn);

			// update x(k+1)=x(k)+h(k)
			// xk=_____________;  
			xn = xn + h;

			// check tolerance
			ep = fabs(func(xn));

			k++;

			printf("k:%d \t", k);
			printf("X(k): %f \t", xn);
			printf("Tol: %.10f\n", ep);
		}
	}

	return xn;
}

double secant(double func(const double x), double _x1,double _x0,double _tol)
{
	double xn1 = _x1;
	double xn0 = _x0;
	double ep = 1000;
	int Nmax = 1000;
	int k = 0;
	double h = 0;

	while (k<Nmax && ep>_tol) {
		if (func(xn1) == func(xn0))
		{
			printf("[ERROR] dF == 0 !!\n");
			break;
		}
		else
		{
			
			// get h=f/df @ x(k)
			// h=__________;   
			h = -func(xn1) * (xn1 - xn0) / (func(xn1) - func(xn0));
			xn0 = xn1;
			// update x(k+1)=x(k)+h(k)
			// xk=_____________;  
			xn1 = xn1 + h;

			// check tolerance
			ep = fabs(func(xn1));

			k++;

			printf("k:%d \t", k);
			printf("X(k): %f \t", xn1);
			printf("Tol: %.10f\n", ep);
		}
	}

	return xn1;
}

void gradient1D(double _x[], double _y[], double dydx[], int m) {
	dydx[0] = (-3 * _y[0] + 4 * _y[1] - _y[2]) / (_x[2] - _x[0]);

	for (int i = 1; i < m - 1; i++) {
		dydx[i] = (_y[i + 1] - _y[i - 1]) / (_x[i + 1] - _x[i - 1]);
	}

	dydx[m - 1] = (_y[m - 3] - 4 * _y[m - 2] + 3 * _y[m - 1]) / (_x[m - 1] - _x[m - 3]);

}


void gradientFunc(double func(const double x), double x[], double dydx[], int m) {
	dydx[0] = (-3 * func(x[0]) + 4 * func(x[1]) - func(x[2])) / (x[2] - x[0]);
	for (int i = 1; i < m-1; i++) {
		dydx[i] = (func(x[i + 1]) - func(x[i - 1])) / (x[i + 1] - x[i - 1]);
	}
	dydx[m - 1] = (func(x[m - 3]) - 4 * func(x[m - 2]) + 3 * func(x[m - 1])) / (x[m - 1] - x[m - 3]);
}

void acceleration(double x[], double y[], double dy2dx2[], int m) {
	dy2dx2[0] = (2 * y[0] - 5 * y[1] + 4 * y[2] - y[3]) / (pow(x[1] - x[0], 3));
	for (int i = 0; i < m - 1; i++) {
		dy2dx2[i] = (y[i - 1] - 2 * y[i] + y[i + 1]) / (pow(x[i] - x[i - 1], 2));
	}
	dy2dx2[m - 1] = (-y[m - 4] + 4 * y[m - 3] - 5 * y[m - 2] + 2 * y[m - 1]) / pow(x[m - 1] - x[m - 2], 2);
}

void partDx(double func(double x, double y), double _x[], double _y,double rfrx[],int m) {
	for (int i = 0; i < m - 1; i++) {
		rfrx[i] = (func(_x[i+1],_y) - func(_x[i],_y)) / (_x[i+1]-_x[i]);
	}
	rfrx[m-1]= (func(_x[m - 1], _y) - func(_x[m-2], _y)) / (_x[m - 1] - _x[m-2]);
}

double rect(double func(double x), double a, double b, int n) {
	double I = 0;
	double I_N = 0;
	double h = (b - a) / n;


	for (int i = 0; i < n; i++) {
		I_N = func(a + i * h) * h;
		I = I + I_N;
	}
	return I;
}

//Trapezoidal method for given data set
double trapz(double x[], double y[], int m) {
	double I = 0;
	for (int n = 0; n < m - 1; n++) {
		double I_n = (y[n + 1] + y[n]) * (x[n + 1] - x[n]);
		I += I_n;
	}
	I = I / 2;
	return I;
}

//Simpson 1/3 method for given data set
double simpson13(double x[], double y[], int m) {
	double I = 0;
	double h = x[1] - x[0];
	int N = m - 1;

	I += y[0] + y[N];
	for (int i = 1; i < N; i += 2) {
		I += 4 * y[i];
	}
	for (int k = 2; k < N - 1; k += 2) {
		I += 2 * y[k];
	}
	I = I * h / 3;
	return I;
}

double simpson38(double x[], double y[], int m) {
	double I = 0;
	double h = x[1] - x[0];

	I += y[0] + y[m - 1];
	for (int i = 1; i < m - 2; i += 3) {
		I = I + 3 * (y[i] + y[i + 1]);
	}
	for (int k = 3; k < m - 4; k += 3) {
		I = I + 2 * y[k];
	}
	I = I * 3 * h / 8;

	return I;
}

//Integral for a function using 1/3 Simpson method & 3/8 Simpson method
double integral(double func(const double x), double a, double b, int n) {
	double h = (b - a) / n;
	double I = 0;

	/*
	//Problem 3
	I = I + func(a) + func(b);
	for (int i = 1; i < n; i += 2) {
		I = I + 4 * func(a+i*h);
	}
	for (int k = 2; k < n - 1; k += 2) {
		I = I + 2 * func(a + k * h);
	}
	I = I * h / 3;
	*/
	
	//problem 4
	if (n % 2 == 0) {
		I = I + func(a) + func(b);
		for (int i = 1; i < n; i += 2) {
			I = I + 4 * func(a + i * h);
		}
		for (int k = 2; k < n - 1; k += 2) {
			I = I + 2 * func(a + k * h);
		}
		I = I * h / 3;
	}
	else {
		I = I + func(a) + func(b);
		for (int i = 1; i < n - 3; i += 2) {
			I = I + 4 * func(a + i * h);
		}
		for (int k = 2; k < n - 4; k += 2) {
			I = I + 2 * func(a + k * h);
		}
		I = I * h / 3;
		I = I + (double)3 / 8 * h * (func(a + (n - 3) * h) + 3 * func(a + (n - 2) * h) + 3 * func(a + (n - 1) * h) + func(a + n * h));
		
	}
	
	return I;
}

void odeEU(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y_init)
{
	// 
	// [BRIEF DESCRIPTION OF THE FUNCTION  GOES HERE]
	// 
		// Variable Initialization
	int N = (tf - t0) / h + 1;

	//Initial Condition
	double ti = t0;
	y[0] = y_init;

	// Euler Explicit ODE Method
	for (int i = 0; i < N - 1; i++) {
		ti += h;
		y[i + 1] = y[i] + odeFunc(ti, y[i]) * h;
	}
}


void odeRK2(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y_init)
{
	// 
	// [BRIEF DESCRIPTION OF THE FUNCTION  GOES HERE]
	// 

		// Variable Initialization
	int N = (tf - t0) / h + 1;
	double y2 = 0;
	double t2 = 0;

	// Initial Condition
	double ti = t0;
	y[0] = y_init;

	// RK Design Parameters
	double C1 = 0.5;
	double C2 = 1 - C1;
	double alpha = 1;
	double beta = alpha;
	double K1 = 0, K2 = 0;

	// RK2 ODE Solver
	for (int i = 0; i < N - 1; i++) {

		// [First-point Gradient]
		K1 = odeFunc(ti, y[i]);

		// [Second-point Gradient]
		// Calculate t2=t(i)+alpha*h
		t2 = ti + alpha * h;

		// Calculate y2 = y(i) + beta * K1 * h
		y2 = y[i] + beta * K1 * h;

		// Calculate: K2   using t2 and y2
		K2 = odeFunc(t2, y2);


		// Estimate: y(i+1) using RK2 	
		y[i + 1] = y[i] + (C1 * K1 + C2 * K2) * h;

		ti += h;
	}
}



void odeRK3(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y0)
{
	// 
	// [BRIEF DESCRIPTION OF THE FUNCTION  GOES HERE]
	// 
		// Variable Initialization
	int N = (tf - t0) / h + 1;
	double y2 = 0;
	double y3 = 0;
	double t2 = 0;
	double t3 = 0;

	// Initial Condition		
	double ti = t0;
	y[0] = y0;

	// RK Design Parameters
	double C1 = 1. / 6, C2 = 4. / 6;
	double C3 = 1. / 6;
	double A2 = 1. / 2;
	double A3 = 1;
	double B21 = 1. / 2;
	double B31 = -1;
	double B32 = 2;
	double K1, K2, K3 = 0;

	// RK3 ODE
	for (int i = 0; i < N - 1; i++) {

		K1 = odeFunc(ti, y[i]);

		t2 = ti + A2 * h;
		y2 = y[i] + B21 * K1 * h;
		K2 = odeFunc(t2, y2);

		t3 = ti + A3 * h;
		y3 = y[i] + B31 * K1 * h + B32 * K2 * h;
		K3 = odeFunc(t3, y3);

		y[i + 1] = y[i] + (C1 * K1 + C2 * K2 + C3 * K3) * h;

		ti += h;
	}
}


// ODE RK2 for 2nd order ODE 
void sys2RK2(double y1[], double y2[], void odeFuncSys(double dYdt[], const double t, const double Y[]), const double t0, const double tf, const double h, const double y1_init, const double y2_init)
{
	// Variable Initialization
	int N = (tf - t0) / h + 1;
	double ti = t0;
	double dYdt[2] = { 0 };
	double dYdt2[2] = { 0 };
	double Yin[2] = { 0 };

	// Initial Condition	
	y1[0] = y1_init;
	y2[0] = y2_init;

	// RK Design Parameters
	double alpha = 1;
	double beta = alpha;
	double C1 = 0.5;
	double C2 = 1 - C1;

	double K1[2] = { 0 };
	double K2[2] = { 0 };

	// RK2 ODE for 2nd ODE
	for (int i = 0; i < N; i++) {
		Yin[0] = y1[i];
		Yin[1] = y2[i];
		odeFuncSys(dYdt, ti, Yin);
		K1[0] = dYdt[0];
		K1[1] = dYdt[1];

		double t2 = ti + alpha * h;
		Yin[0] = y1[i] + beta * K1[0] * h;
		Yin[1] = y2[i] + beta * K1[1] * h;

		odeFuncSys(dYdt2, t2, Yin);
		K2[0] = dYdt2[0];
		K2[1] = dYdt2[1];

		y1[i + 1] = y1[i] + (C1 * K1[0] + C2 * K2[0]) * h;
		y2[i + 1] = y2[i] + (C1 * K1[1] + C2 * K2[1]) * h;

		ti = ti + h;
	}
}


