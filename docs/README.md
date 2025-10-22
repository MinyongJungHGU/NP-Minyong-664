# Numerical Programming API



In `myNP_22000664.h`

## Basic



### printVec()

print vector

```C
void printVec(double* vec, int row);
```



### factorial()

```C
double factorial(int _x);
```



### power()

```C
double power(double _x, int N);
```

__Parameter__

* _x: base
* N: exponent



### sinTaylor()

```C
double sinTaylor(double _x);
```



### cosTaylor()

```C
double sinTaylor(double _x);
```



### sindTaylor()

```C
double sindTaylor(double _x);
```



### cosdTaylor()

```C
double sindTaylor(double _x);
```



### expTaylor()

```C
double expTaylor(double x);
```





## Non-Linear Solver



### bisection()

approximates the solution of nonlinear equation using bisection method

```C
double bisection(double func(const double x),double _a0, double _b0, double _tol);
```

__Parameter__

* func: Nonlinear equation with all the term gone to the left side
* _a0: approximated value  of the solution at left side
* _b0: approximated value  of the solution at right side
* _tol: tolerance
* return: aprroximated solution



### newtonRaphson()

approximates the solution of nonlinear equation using Newton-Raphson method

```C
double newtonRaphson(double func(const double x),double dfunc(const double x), double _x0, double _tol);
```

__Paramater__

* func: Nonlinear equation with all the term gone to the left side
* dfunc: derivate of func
* _x0: starting point of approximation
* _tol: tolerance
* return: approximated solution



### secant()

approximates the solution of nonlinear equation using secant method(without derivative)

```C
double secant(double func(const double x), double _x1, double _x0, double _tol);
```

__Parameter__

* func: Nonlinear eqaution with all the term gone to the left side
* _x1: starting point of approximation
* _x0: extra backward point for secant line
* _tol: tolerance
* return: approximated solution





## Differentiation



### gradient1D()

approximates differentiation for given <u>discrete data set</u> with h^2 error

```C
void gradient1D(double _x[], double _y[], double dydx[], int m);
```

__Parameter__

* _x: x axis data
* _y: y axis data
* dydx: external array that will save the differentiation approximation
* m: size of data set



### gradientFunc()

approximates differentiation for given <u>function</u> with h^2 error

```C
void gradientFunc(double func(const double x), double x[], double dydx[], int m);
```

__Parameter__

* func: given function to differentiate
* x: points set at which differentiation will be approximated
* dydx: external array that will save the differentiation approximation
* m: size of data sets



### acceleration()

approximates  second differentiation for given data sets with h^2 error

```C
void acceleration(double x[], double y[], double dy2dx2[], int m);
```

__Parameter__

* x: x axis data
* y: y axis data
* dy2dx2: external data to save second differentiation values
* m: size of data set



### partDx()

Partial differentiation w.r.t x

```C
void partDx(double func(double x, double y), double _x[], double _y, double rfrx[], int m);
```

__parameter__

* func: a function of x, y
* _x: x data set
* _y: y data set
* rfrx: external array to save partial differentation values
* m: size of data sets





## Integration



### rect()

Integrates using rectangle method

```C
double rect(double func(double x), double a, double b, int n);
```

__Parameter__

* a: starting point of integration
* b: ending point of integration
* n: #of intervals
* return: integration approximation value



### trapz()

Integrates for given discrete data set using trapezoidal method

```C
double trapz(double x[], double y[], int m);
```

__parameter__

* x: x axis data
* y: y axis data
* m: size of data
* return: integration approximation value



### simpson13()

Integrates for given discrete data sets suppossed that m is <u>ENVE NUMBER</u>

```C
double simpson13(double x[], double y[], int m);
```

__Parameter__

* x: x axis data
* y: y axis data
* m: size of data. m should be an even number
* return: integration approximation value



### simpson38()

Integrates for given discrete data set supposed that m is 3-times-number

```C
double simpson38(double x[], double y[], int m);
```

__Parameter__

* x: x axis data
* y: y axis data
* m: size of data. m should be a multiple of three
* return: integration approximation value



### integrate()

Integrates for a given function from a to b with any number n intervals

```C
double integral(double func(const double x), double a, double b, int n);
```

__Parameter__

* func: given function for x
* a: starting point of integration
* b: ending point of integration
* n: # of intervals





## ODE



### odeEU()

approximates the solution of ODE using Euler's method

```C
void odeEU(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y_init);
```

__Parameter__

* y: external array to save yi values
* odeFunc: function for t, y that returns dydt value
* t0: starting point to approximate y
* tf: ending point to aprroximate y
* h: interval b/w each approximation point of y
* y_init: initial value of y



### odeRK2()

approximates the solution of ODE using 2nd Runge-Kutta method

```C
void odeRK2(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y_init);
```

__Parameter__

* y: external array to save yi values

* odeFunc: function for t, y that returns dydt value
* t0: starting point to approximate y
* tf: ending point to aprroximate y
* h: interval b/w each approximation point of y
* y_init: initial value of y



### odeRK3()

approximates the solution of ODE using 3rd Runge-Kutta method

```C
void odeRK3(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y0);
```

__Parameter__

* y: external array to save yi values

* odeFunc: function for t, y that returns dydt value
* t0: starting point to approximate y
* tf: ending point to aprroximate y
* h: interval b/w each approximation point of y
* y_0: initial value of y



### sys2RK2()

approximates the solution of 2nd order ODE using 2nd Runge-Kutta method 

```c
void sys2RK2(double y1[], double y2[], void odeFuncSys(double dYdt[], const double t, const double Y[]), const double t0, const double tf, const double h, const double y1_init, const double y2_init);
```

__Parameter__

* y1: external array to save y values
* y2: external array to save dy/dx values
* odeFuncSys: 
  - input: Y=[y v] , t
  - output: dYdt[] = [dydt dvdt]
* t0: starting point to approximate y
* tf: ending point to aprroximate y
* h: interval b/w each approximation point of y
* y1_init: initial value of y1
* y2_init: initial value of y2







in `myMatrix_22000664.h`

## Matrix Basic



### createMat()

create matrix with zero value elements

```C
Matrix createMat(int _rows, int _cols);
```



### freeMat()

free dynamically allocated matrix

```C
void freeMat(Matrix _A);
```



### txt2Mat()

convert .txt file to matrix entity

```C
Matrix	txt2Mat(std::string _filePath, std::string _fileName);
```



### printMat()

print matrix

```C
void printMat(Matrix _A, const char* _name);
```



### addMat()

add two matrices

```C
Matrix	addMat(Matrix _A, Matrix _B);
```



### initMat()

initialize elements of matrix

```C
void initMat(Matrix _A, double _val);
```



### zeros()

create matrix with zero value elements

```C
Matrix	zeros(int _rows, int _cols);
```



### ones()

create matrix with 1 value elements

```C
Matrix	eye(int _rows, int _cols);
```



### eye()

creates identity matrix

```C
Matrix	eye(int _rows, int _cols);
```



### subMat()

subtract two matrices

```C
Matrix subMat(Matrix _A, Matrix _B);
```



### multMat()

multipy two matrices

```C
Matrix multMat(Matrix _A, Matrix _B);
```



### smultMat()

multipy scalar to a matrix

```C
Matrix smultMat(Matrix _A, double _k);
```



### transpose()

transpose matrix

```C
Matrix transpose(Matrix _A);
```



### copyMat()

copy matrix with new address

```C
Matrix copyMat(Matrix _A);
```



### norm2Vec()

calculate 2 norm of vector

```C
double norm2Vec(Matrix v);
```



### arr2Mat()

type conversion of array to matrix

```C
Matrix arr2Mat(double* _1Darray, int _rows, int _cols);
```





## Linear Equation System



### gaussElim()

procede gauss elimination

```c
void gaussElim(Matrix A, Matrix b, Matrix U, Matrix d);
```

__parameter__

* A: system(coefficient) matrix
* b: some input
* U: result of gaussElim for A
* d: result of gaussElim for b



### LUdecomp()

procedes LU decomposition

```C
void LUdecomp(Matrix A, Matrix L, Matrix U);
```

__Parameter__

* A: given matrix
* L: lower triangular matrix
* U: upper triangular matrix



### solveLU()

finds the solution of system of linear equation x with L, U, b

```C
void solveLU(Matrix L, Matrix U, Matrix b, Matrix x);
```

__Parameter__

* L: lower triangular matrix
* U: upper triangular matrix
* b: some input
* x: external array to save the solution



### fwdsub()

forward substitution

```c
void fwdsub(Matrix L, Matrix b, Matrix y);
```

__Parameter__

* L: lower triangular matrix
* b: some input
* y: external array to save Ux values



### backsub()

backward substitution

```C
void backsub(Matrix U, Matrix y, Matrix x);
```

__Parameter__

* U: upper triangular matrix
* y: Ux values
* x: external array to save the solution



### invMat()

calculates inverse matrix

```c
void invMat(Matrix A, Matrix Ainv);
```

__Parameter__

* A: given matrix
* Ainv: matrix to save inverse matrix





## Eigen Value & Eigen Vector



### QRdecomp()

QR decomposition

```C
void QRdecomp(Matrix A, Matrix Q, Matrix R);
```



### eigvec()

find eigenvector as colmumn in matrix

```C
Matrix eigvec(Matrix A);
```



### eigval()

find eigenvalue in a column

```C
Matrix eigval(Matrix A);
```



### eig()

find eigenvalue & eigenvector with sorting

```C
void eig(Matrix A, Matrix V, Matrix D);
```

__Parameter__

* A: given matrix
* V: matrix with eigenvector colmumn
* D: array of eigenvalue





## Curve Fitting



### linearFit_mat()

Calculates coefficients of least squares regression - Line

```C
Matrix linearFit_mat(Matrix _vecX, Matrix _vecY);
```

__Parameter__

* _vecX: x axis data
* _vecY: y axis data

* return: {a0, a1} as matrix form



### polyFit_mat()

Calculates coefficients of least squares regression - Nth order polynomial

```C
Matrix polyFit_mat(Matrix _vecX, Matrix _vecY, int orderN);
```

__Parameter__

* _vecX: x axis data
* _vecY: y axis data
* orderN: order of polynomial



### expFit_mat()

Calculates coefficients of exponential approximation function taken by ln

```C
Matrix expFit_mat(Matrix _X, Matrix _Y);
```

