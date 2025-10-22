/* myNP_tutorial.h 
--------------------------------------------------------------------------
@ C-Tutorial by Min-Yong Jung - Handong Global University

Author			: M.Y.Jung 22000664
Created			: 08-30-2024
Modified		: 09-30-2024
Language/ver	: C++ in MSVS2022

Description: my NP header
------------------------------------------------------------------------*/



#ifndef		_MY_NP_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_NP_H
#define		PI		3.14159265358979323846264338327950288419716939937510582

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 * @brief		This function prints values of a vector(1D array)
 * @param vec	: Pointer of double type of vector
 * @param row	: # of row
*/
extern void printVec(double* vec, int row);

/**
 * @brief		This function calculate factorial x!
*/
extern double factorial(int _x);

/**
 * @brief		This function calculates N power of _x
*/
extern double power(double _x, int N);

/**
 * @brief		This function calculates sin(_x) using Taylor for radian _x
 * @param _x	: Input angle in radian
 * @return		: Approximated sine value
*/
extern double sinTaylor(double _x);

extern double cosTaylor(double _x);

/**
 * @brief		This function calculates sin(_x) using sinTaylor function for degree _x
 * @param _x	: Input angle in degree
 * @return		: Approximated sine value
*/
extern double sindTaylor(double _x);

/**
 * @brief		This function calculates cos(_x) using sinTaylor function for degree _x
 * @param _x	: Input angle in degree
 * @return		: Approximated cosine value
 */
extern double cosdTaylor(double _x);

/**
 * @brief		Taylor aprroximation of exponeetial function
 * @param x		radian value
 */
extern double expTaylor(double x);

/**
 * @brief		Approximates the solution of nonlinear equation using bisection method
 * @param func	: Nonlinear equation wiht the right side 0
 * @param _a0	: A left value around the solution
 * @param _b0	: A right value around the solution
 * @param _tol	: The tolerance
 * @return		: Approximation solution
 */
extern double bisection(double func(const double x),double _a0, double _b0, double _tol);

/**
 * @brief		Approximates the solution of nonlinear equation using Newton-Raphson method
 * @param func	: Nonlinear equation wiht the right side 0
 * @param dfunc	: Derivative of func
 * @param _x0	: A value around the solution
 * @param _tol	: The tolerance
 * @return		: Approximation solution
*/
extern double newtonRaphson(double func(const double x),double dfunc(const double x), double _x0, double _tol);

/*
@brief			: Approximates to the solution of nonlinear equation using secant method(without derivative)
@param _x1		: Starting point to approximate
@param _x0		: Extra backowrd point for secant line
*/
extern double secant(double func(const double x), double _x1, double _x0, double _tol);

/**
 * @brief		: Approximation of differentiation for given discrete data set with h^2 error
 * @param _x			: Data 1 (x axis)
 * @param _y			: Data 2 (y axis)
 * @param dydx		: External array that save the differential approximations
 * @param m			: Size of the data sets
*/
extern void gradient1D(double _x[], double _y[], double dydx[], int m);

/**
*@brief		: Approximation of differentiation for given function with h^2 error
* @param func : Given function
* @parma _x : Points at which differentiation will be approximated 
* @param dydx : External array that save the differential approximations
* @param m : Size of the data sets
*/
extern void gradientFunc(double func(const double x), double x[], double dydx[], int m);

/*
@brief		: Approximation fo  second differentiation for given data sets with h^2 error
@param x	: x-axis(1-D array format)
@param y	: y-axis)1-D array format)
*/
extern void acceleration(double x[], double y[], double dy2dx2[], int m);

/*
@brief			: partial differentiation w.r.t x
@param x		: input x (1-D array)
@param y		: input y (a point)
@param rfrx		: external array that stores values of partial differentiation
@param m		: # of x data
*/
extern void partDx(double func(double x, double y), double _x[], double _y, double rfrx[], int m);


/*
@brief			: Integrates using rectangle method
@param a		: Starting point of integration
@param b		: Ending point of integration
@param n		: # of intervals
*/
extern double rect(double func(double x), double a, double b, int n);

/**
@brief		Integrates for given dicrete data set using trazezoidal method
@param x		: Input pointer of x in 1-D array
@param y		: Input pointer of y in 1-D array
*/
extern double trapz(double x[], double y[], int m);

/*
* @brief		Integrate for given discrete data sets suppossed that m is ENVE NUMBER
* @param x		: Input x in 1-D array format
* @param y		: Input y in 1-D array format
* @param m		: EVEN number of intervals
*/
extern double simpson13(double x[], double y[], int m);

/*
@brief			:integrates for given discrete data set supposed that m is 3-times-number
*/
extern double simpson38(double x[], double y[], int m);

/*
* @brief		Integrates for a given function from a to b with any number n intervals
* @param a		: Integration strating point
* @param b		: Integration terminal point
* @param n		: any # of intervals 
*/
extern double integral(double func(const double x), double a, double b, int n);

extern void odeEU(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y_init);

extern void odeRK2(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y_init);

extern void odeRK3(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y0);

// ODE RK2 for 2nd order ODE 
extern void sys2RK2(double y1[], double y2[], void odeFuncSys(double dYdt[], const double t, const double Y[]), const double t0, const double tf, const double h, const double y1_init, const double y2_init);

#endif#pragma once
