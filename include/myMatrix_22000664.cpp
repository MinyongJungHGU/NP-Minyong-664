/*----------------------------------------------------------------\
@ Numerical Programming by Young-Keun Kim - Handong Global University

Author           : M.Y. Jung 22000664
Created          : 26-03-2018
Modified         : 14-10-2024
Language/ver     : C++ in MSVS2019

Description      : myMatrix.cpp
----------------------------------------------------------------*/

#include "myMatrix_22000664.h"
#include<math.h>


// Free a memory allocated matrix
void	freeMat(Matrix _A)
{
	// 1. Free allocated column memory
	for (int i = 0; i < _A.rows; i++)
		free(_A.at[i]);
	// 2. Free allocated row memory
	free(_A.at);
}

// Create a matrix from a text file
Matrix	txt2Mat(std::string _filePath, std::string _fileName)
{
	std::ifstream file;
	std::string temp_string, objFile = _filePath + _fileName + ".txt";
	int temp_int = 0, nRows = 0;

	file.open(objFile);
	if (!file.is_open()) {
		printf("\n*********************************************");
		printf("\n  Could not access file: 'txt2Mat' function");
		printf("\n*********************************************\n");
		return createMat(0, 0);
	}
	while (getline(file, temp_string, '\t'))
		temp_int++;
	file.close();

	file.open(objFile);
	while (getline(file, temp_string, '\n'))
		nRows++;
	file.close();

	int nCols = (temp_int - 1) / nRows + 1;
	Matrix Out = createMat(nRows, nCols);

	file.open(objFile);
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++) {
			file >> temp_string;
			Out.at[i][j] = stof(temp_string);
		}
	file.close();

	return Out;
}

// Create Matrix with specified size
Matrix	createMat(int _rows, int _cols)
{
	// check matrix dimension
	if (_rows < 0 || _cols < 0) {
		printf("\n****************************************************");
		printf("\n  ERROR!!: dimension error at 'createMat' function");
		printf("\n****************************************************\n");
		return createMat(0, 0);
	}

	Matrix Out;
	// 1. Allocate row array first
	Out.at = (double**)malloc(sizeof(double*) * _rows);
	// 2. Then, allocate column 
	for (int i = 0; i < _rows; i++)
		Out.at[i] = (double*)malloc(sizeof(double) * _cols);
	// 3. Initialize row & column values of a matrix
	Out.rows = _rows;
	Out.cols = _cols;

	// 4. Initialize with zero (optional)
	initMat(Out, 0);
	return Out;
}


// initialization of Matrix elements
void	initMat(Matrix _A, double _val)
{
	for (int i = 0; i < _A.rows; i++)
		for (int j = 0; j < _A.cols; j++)
			_A.at[i][j] = _val;
}

// Print matrix
void	printMat(Matrix _A, const char* _name)
{
	printf("%s =\n", _name);
	for (int i = 0; i < _A.rows; i++) {
		for (int j = 0; j < _A.cols; j++)
			printf("%15.4f\t", _A.at[i][j]);
		printf("\n");
	}
	printf("\n");
}

// Matrix addition
Matrix	addMat(Matrix _A, Matrix _B)
{
	if (_A.rows != _B.rows || _A.cols != _B.cols) {
		printf("\n*************************************************");
		printf("\n  ERROR!!: dimension error at 'addMat' function");
		printf("\n*************************************************\n");
		return createMat(0, 0);
	}

	Matrix Out = createMat(_A.rows, _B.cols);
	for (int i = 0; i < _A.rows; i++)
		for (int j = 0; j < _B.cols; j++)
			Out.at[i][j] = _A.at[i][j] + _B.at[i][j];

	return Out;
}






//////////////////////////////////////////////////////////////////
/*				Tutorial	&  Assignment						*/
//////////////////////////////////////////////////////////////////

// Create matrix of all zeros
extern Matrix	zeros(int _rows, int _cols)
{
	Matrix Out = createMat(_rows, _cols);

	return Out;
}


// Create matrix of all ones
extern Matrix	ones(int _rows, int _cols)
{
	Matrix Out = createMat(_rows, _cols);
	
	for (int i=0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			Out.at[i][j] = 1;
		}
	}

	return Out;
}


// Create identity matrix
// Assume square matrix (rows==cols)
extern Matrix eye(int _rows, int _cols)
{
	// Error Handling
	// Check if (rows==cols)
	// Give warning message.
	// Exit
	if (_rows != _cols) {
		printf("\n*************************************************");
		printf("\n  ERROR!!: dimension error at 'eye' function");
		printf("\n*************************************************\n");
		return createMat(0,0);
	}


	Matrix Out = createMat(_rows, _cols);
	
	for (int i = 0; i < _rows; i++) {
		Out.at[i][i]=1;
	}

	return Out;
}


// Matrix subtraction
extern	Matrix	subMat(Matrix _A, Matrix _B) {
	Matrix Out = createMat(_A.rows, _A.cols);
	// add your code here
	// add your code here
	// add your code here
	if (_A.rows != _B.rows || _A.cols != _B.cols) {
		printf("\n*************************************************");
		printf("\n  ERROR!!: dimension error at 'subMat' function");
		printf("\n*************************************************\n");
		return createMat(0, 0);
	}

	for (int i = 0; i < _A.rows;i++) {
		for (int j = 0; j < _A.cols; j++) {
			Out.at[i][j] = _A.at[i][j] - _B.at[i][j];
		}
	}

	return Out;
}


// Multiply  matrix A and matrix B  OUT=AB
extern	Matrix	multMat(Matrix _A, Matrix _B) {
	Matrix Out = createMat(_A.rows, _B.cols);
	// add your code here
	// add your code here
	// add your code here
	if (_A.cols != _B.rows) {
		printf("\n*************************************************");
		printf("\n  ERROR!!: dimension error at 'multMat' function");
		printf("\n*************************************************\n");
		return createMat(0, 0);
	}
	
	initMat(Out,0);

	for (int i = 0; i < _A.rows; i++) {
		for (int j = 0; j < _B.cols; j++) {
			for (int k = 0; k < _A.cols; k++) {
				Out.at[i][j] += _A.at[i][k] * _B.at[k][j];
			}
		}
	}

	return Out;

}


// Multiply  matrix A with a scalar k
extern	Matrix	smultMat(Matrix _A, double _k) {
	Matrix Out = createMat(_A.rows, _A.cols);
	// add your code here
	// add your code here
	// add your code here
	for (int i = 0; i < _A.rows; i++) {
		for (int j = 0; j < _A.cols; j++) {
			Out.at[i][j] = _k * _A.at[i][j];
		}
	}

	return Out;
}


// Create Transpose matrix
extern	Matrix	transpose(Matrix _A) {
	Matrix Out = createMat(_A.cols, _A.rows);
	// add your code here
	// add your code here
	// add your code here
	for (int i = 0; i < _A.rows; i++) {
		for (int j = 0; j < _A.cols; j++) {
			Out.at[j][i] = _A.at[i][j];
		}
	}

	return Out;
}


// Copy independent matrix
extern	Matrix	copyMat(Matrix _A) {
	Matrix Out = createMat(_A.rows, _A.cols);

	for (int i = 0; i < _A.rows; i++) {
		for (int j = 0; j < _A.cols; j++) {
			Out.at[i][j] = _A.at[i][j];
		}
	}

	return Out;
}

void gaussElim(Matrix A, Matrix b, Matrix U, Matrix d) {
	
	int n = 0;
	double mult = 0;

	if (A.rows != A.cols || A.cols != b.rows || b.cols != 1) {
		printf("\n*************************************************");
		printf("\n  ERROR!!: dimension error at 'gaussElim' function");
		printf("\n*************************************************\n");
	}
	else {
		n = A.rows;
	}

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			U.at[i][j] = A.at[i][j];
		}
		d.at[i][0] = b.at[i][0];
	}

	for (int k = 0; k < n - 1;k++) {
		for (int i = k + 1; i < n; i++) {
			mult = U.at[i][k] / U.at[k][k];
			for (int j = k; j < n;j++) {
				U.at[i][j] -= mult * U.at[k][j];
			}
			d.at[i][0] -= mult * d.at[k][0];

		}
	}
}

void LUdecomp(Matrix A, Matrix L, Matrix U) {
	int n = 0;
	double mult = 0;

	if (A.rows != A.cols) {
		printf("\n*************************************************");
		printf("\n  ERROR!!: dimension error at 'LUdecomp' function");
		printf("\n*************************************************\n");

		return;
	}
	else {
		n = A.rows;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			U.at[i][j] = A.at[i][j];
		}
	}

	for (int k = 0; k < n - 1; k++) {
		for (int i = k + 1; i < n; i++) {
			mult = U.at[i][k] / U.at[k][k];
			L.at[i][k] = mult;
			for (int j = k; j < n; j++) {
				U.at[i][j] -= mult * U.at[k][j];
			}
		}
	}
}

void solveLU(Matrix L, Matrix U, Matrix b, Matrix x) {
	Matrix y = createMat(b.rows, 1);

	fwdsub(L, b, y);
	backsub(U, y, x);

	freeMat(y);
}

void fwdsub(Matrix L, Matrix b, Matrix y) {
	int n = b.rows;

	//X0
	y.at[0][0] = b.at[0][0] / L.at[0][0];

	//Xi (i: 1 ~ n-1)
	for (int i = 1; i < n; i++) {
		y.at[i][0] = b.at[i][0];
		for (int j = 0; j < i; j++) {
			y.at[i][0] -= L.at[i][j] * y.at[j][0];
		}
		y.at[i][0] = y.at[i][0] / L.at[i][i];
	}
}

void backsub(Matrix U, Matrix y, Matrix x) {
	int n = y.rows;

	//Xn-1
	x.at[n - 1][0] = y.at[n - 1][0] / U.at[n - 1][n - 1];

	//Xi (i: n-2 ~ 0)
	for (int i = n - 2; i >= 0; i--) {
		x.at[i][0] = y.at[i][0];
		for (int j = i + 1; j < n; j++) {
			x.at[i][0] -= U.at[i][j] * x.at[j][0];
		}
		x.at[i][0] = x.at[i][0] / U.at[i][i];
	}
}

void invMat(Matrix A, Matrix Ainv) {
	int n = A.rows;
	Matrix P = eye(A.rows, A.cols);

	if (A.rows != A.cols) {
		printf("not a square matrix\n");
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (A.at[i][i] == 0) {
				Matrix Pi = zeros(A.rows, A.cols);
				Pi.at[i + 1][i + 1] = 1;
				Matrix _P = multMat(Pi, P);

				for (int i = 0; i < A.rows; i++) {
					for (int j = 0; j < A.cols; j++) {
						P.at[i][j] = _P.at[i][j];
					}
				}

				freeMat(Pi);
				freeMat(_P);
			}
		}
	}
	
	Matrix _A = multMat(P, A);
	Matrix x = createMat(n,1);
	Matrix b = createMat(n,1);
	Matrix L = eye(n, n);
	Matrix U = createMat(n, n);

	LUdecomp(_A, L, U);

	for (int i = 0; i < n; i++) {
		if (U.at[i][i] == 0) {
			printf("no inverse matrix exists.\n");
			return;
		}
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			b.at[i][0] = P.at[i][j];
		}

		solveLU(L,U,b,x);

		for (int k = 0; k < n; k++) {
			Ainv.at[k][j] = x.at[k][0];
		}
	}

	freeMat(P);
	freeMat(x);
	freeMat(b);
	freeMat(L);
	freeMat(U);
	freeMat(_A);
}

double norm2Vec (Matrix v) {
	double norm2 = 0;
	if (v.cols != 1) {
		printf("please input column vector\n");
		return 0;
	}
	for (int i = 0; i < v.rows; i++) {
		norm2 += v.at[i][0]* v.at[i][0];
	}
	norm2 = sqrt(norm2);
	return norm2;
}

Matrix eigval(Matrix A) {

	if (A.rows != A.cols) {
		printf("Error in eigval: not a square matrix");
		return createMat(0, 0);
	}

	int N = 200;
	Matrix U = createMat(A.rows, A.cols);
	Matrix _R = createMat(A.rows, A.cols);
	Matrix _Q = createMat(A.rows, A.cols);
	Matrix r = createMat(A.rows, 1);

	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < A.cols; j++) {
			U.at[i][j] = A.at[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		QRdecomp(U,_Q,_R);
		U = multMat(_R, _Q);
	}

	for (int i = 0; i < A.rows; i++) {
		r.at[i][0] = U.at[i][i];
	}

	freeMat(_R);
	freeMat(_Q);
	freeMat(U);

	return r;
}

void QRdecomp(Matrix A, Matrix Q, Matrix R) {

	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < A.cols; j++){
			R.at[i][j] = A.at[i][j];
			if (i == j) {
				Q.at[i][j] = 1;
			}
			else {
				Q.at[i][j] = 0;
			}
		}
	}

	Matrix c = createMat(A.rows, 1);
	Matrix e = createMat(A.rows, 1);

	for (int k = 0; k < A.rows - 1; k++) {

		for (int i = 0; i < A.rows; i++) {

			if (i < k) {
				c.at[i][0] = 0;
			}
			else {
				c.at[i][0] = R.at[i][k];
			}

			if (i == k) {
				if (R.at[k][k] >= 0) {
					e.at[i][0] = 1;
				}
				else {
					e.at[i][0] = -1;
				}
			}
			else {
				e.at[i][0] = 0;
			}
		}


		Matrix v = addMat(c, smultMat(e, norm2Vec(c)));;;
		Matrix I = eye(A.rows, A.cols);
		if (2 / (norm2Vec(v) * norm2Vec(v)) == 0) {
			printf("Error in QR decomp: divded by zero");
		}
		Matrix H = subMat(I, smultMat(multMat(v,transpose(v)), 2 / (norm2Vec(v) * norm2Vec(v))));

		Matrix Q_ = multMat(Q, H);
		Matrix R_ = multMat(H, R);

		for (int i = 0; i < Q.rows; i++) {
			for (int j = 0; j < Q.cols; j++) {
				Q.at[i][j] = Q_.at[i][j];
				R.at[i][j] = R_.at[i][j];
			}
		}

		freeMat(v);
		freeMat(H);
		freeMat(I);
		freeMat(Q_);
		freeMat(R_);
	}

	freeMat(c);
	freeMat(e);
}

Matrix eigvec(Matrix A) {
	Matrix v = ones(A.rows, A.cols);
	Matrix eigVal = eigval(A);


	if (A.rows == 2) {
		for (int k = 0;k < eigVal.rows; k++) {
			Matrix I = eye(A.rows, A.cols);
			for (int i = 0; i < A.rows; i++) {
				I.at[i][i] = eigVal.at[k][0];
			}
			Matrix B = subMat(A, I);

			Matrix vi = ones(2, 1);
			vi.at[1][0] = (-1) * B.at[1][0] / B.at[1][1];
			Matrix viNorm =smultMat(vi, 1 / norm2Vec(vi));
			
			for (int i = 0; i < A.rows; i++) {
				v.at[i][k] = viNorm.at[i][0];
			}

			freeMat(I);
			freeMat(B);
			freeMat(vi);
			freeMat(viNorm);
		}
		return v;
	}
	else if (A.rows == 3) {
		for (int k = 0; k < eigVal.rows; k++) {
			Matrix I = eye(A.rows, A.cols);
			for (int i = 0; i < A.rows; i++) {
				I.at[i][i] = eigVal.at[k][0];
			}
			Matrix B = subMat(A, I);

			Matrix B_ = createMat(2, 2);
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					B_.at[i][j] = B.at[i + 1][j + 1];
				}
			}
			Matrix invB_ = createMat(2, 2);
			invMat(B_,invB_);

			Matrix b = createMat(2, 1);
			b.at[0][0] = (-1) * B.at[1][0];
			b.at[1][0] = (-1) * B.at[2][0];

			Matrix v_ = multMat(invB_, b);

			Matrix v__ = ones(3, 1);

			for (int i = 0; i < 2; i++) {
				v__.at[1 + i][0] = v_.at[i][0];
			}

			Matrix viNorm = smultMat(v__, 1 / norm2Vec(v__));

			for (int i = 0; i < A.rows; i++) {
				v.at[i][k] = viNorm.at[i][0];
			}

			freeMat(I);
			freeMat(B);
			freeMat(viNorm);
			freeMat(B_);
			freeMat(invB_);
			freeMat(b);
			freeMat(v_);
			freeMat(v__);
		}
		return v;
	}

}


void eig(Matrix A, Matrix V, Matrix D) {
	Matrix eigVal = eigval(A);
	Matrix eigVec = eigvec(A);
	int idx = 0;
	double temp = 0;
	double tempVec[3]={0};

	//eigvector & eigvalues to V & D
	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < A.rows; j++) {
			V.at[i][j] = eigVec.at[i][j];
		}
		D.at[i][0] = eigVal.at[i][0];
	}

	//sorting
	for (int k = 0; k < A.rows-1; k++) {
		idx = k;

		for (int j = k+1; j < A.rows; j++) {
			if (D.at[idx][0] < D.at[j][0]) {
				idx = j;
			}
		}

		temp=D.at[k][0];
		D.at[k][0] = D.at[idx][0];
		D.at[idx][0] = temp;
		
		for (int i = 0; i < V.rows; i++) {
			tempVec[i] = V.at[i][k];
			V.at[i][k] = V.at[i][idx];
			V.at[i][idx] = tempVec[i];
		}
	}
}

// Returns the parameters of the linear least square function.
Matrix linearFit_mat(Matrix _vecX, Matrix _vecY) {

	// Initialization
	double Sx = 0;
	double Sxx = 0;
	double Sxy = 0;
	double Sy = 0;
	double a1 = 0;
	double a0 = 0;


	// Check m = length(X) and length(Y)
	int mx = _vecX.rows;
	int my = _vecY.rows;

	// Is length(X)~= length(Y) ? Exit: Continue
	if (mx != my) {
		printf("Error: X and Y have different length");
		return zeros(2, 1);
	}

	int dataL = mx;

	// Solve for Sx, Sxx, Sy, Sxy,
	for (int k = 0; k < dataL; k++) {
		Sx += _vecX.at[k][0];
		Sxx += _vecX.at[k][0] * _vecX.at[k][0];
		Sxy += _vecX.at[k][0] * _vecY.at[k][0];
		Sy += _vecY.at[k][0];
	}


	// Solve for a0, a1
	double den = (dataL * Sxx - Sx * Sx);
	a0 = (Sxx * Sy - Sx * Sxy) / den;
	a1 = (dataL * Sxy - Sx * Sy) / den;


	// Return z = [a0, a1]
	double z_array[] = { a0, a1 };
	return arr2Mat(z_array, 2, 1);
}


// [YOUR COMMENT GOES HERE]
Matrix polyFit_mat(Matrix _vecX, Matrix _vecY, int orderN) {

	// Initialization	
	Matrix S = zeros(orderN + 1, orderN + 1);						//((A^T)A)^(-1)
	Matrix Sx = zeros(orderN*2 + 1, 1);
	Matrix b = zeros(orderN + 1, 1);								//b=(A^T)y


	// Check m = length(X) and length(Y)
	int mx = _vecX.rows;
	int my = _vecY.rows;

	// If n=1, use linearFit
	if (orderN == 1) {
		Matrix vecZ = linearFit_mat(_vecX, _vecY);
		return vecZ;
	}


	// Calculate Sx(i)=sum(x[k]^(i)), for i=0 to 2n  #(2n+1) 
	// Note: Sx[0] to Sx[n*2] : (2n+1,1)	
	for (int i = 0; i < 2 * orderN+1; i++) {
		double Sx_temp = 0;
		for (int k = 0; k < mx; k++) {
			Sx_temp += pow(_vecX.at[k][0], i);
		}
		Sx.at[i][0] = Sx_temp;
//		printMat(Sx,"Sx in for loop");
	}

	// Construct matrix S with Sx(i).  
	for (int i = 0; i < orderN+1; i++) {
		for (int j = 0; j < orderN+1; j++) {
			S.at[i][j] = Sx.at[i + j][0];
		}
	}

	// Construct vector b=(A'y) from Sxy(j) = sum(y * (x ^ (j))), for j = 0 to n 
	for (int i = 0; i < orderN+1; i++) {
		double Sxy_temp = 0;
		for (int k = 0; k < mx; k++) {
			Sxy_temp += _vecY.at[k][0] * pow(_vecX.at[k][0], i);
		}
		b.at[i][0] = Sxy_temp;
	}

	// Calculate optimal Z=inv(S)*(b)
	Matrix invS = createMat(orderN + 1, orderN + 1);
	invMat(S, invS);
	Matrix vecZ = multMat(invS, b);
	
	freeMat(invS);
	freeMat(S);
	freeMat(Sx);
	freeMat(b);

	return vecZ;
}

Matrix	arr2Mat(double* _1Darray, int _rows, int _cols)
{
	Matrix Output = createMat(_rows, _cols);

	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _cols; j++)
			Output.at[i][j] = _1Darray[i * _cols + j];

	return Output;
}

void linearFit(double vecZ[], double vecX[], double vecY[], int dataL) {
	//Initialization
	double Sx = 0;
	double Sxx = 0;
	double Sxy = 0;
	double Sy = 0;
	double a1 = 0;
	double a0 = 0;

	//solve for Sx, Sxx, Sy, Sxy
	for (int k = 0; k < dataL; k++) {
		Sx += vecX[k];
		Sxx += vecX[k] * vecX[k];
		Sxy += vecX[k] * vecY[k];
		Sy += vecY[k];
	}

	//solve for a0, a1
	double den = (dataL * Sxx - Sx * Sx);
	a0 = (Sxx * Sy - Sx * Sxy) / den;
	a1 = (dataL * Sxy - Sx * Sy) / den;

	vecZ[0] = a0;
	vecZ[1] = a1;

}

void polyFit(double vecZ[], double vecX[], double vecY[], int dataL, int orderN) {
	//initialization
	Matrix S = zeros(orderN + 1, orderN + 1);
	Matrix Sx = zeros(orderN * 2 + 1, 1);
	Matrix b = zeros(orderN + 1, 1);

	if (orderN == 1) {
		linearFit(vecZ, vecX, vecY, dataL);
		return;
	}

	//calculate Sx
	for (int i = 0; i < orderN*2 + 1; i++) {
		double Sx_temp = 0;
		for (int k = 0; k < dataL; k++) {
			Sx_temp += pow(vecX[k], i);
		}
		Sx.at[i][0] = Sx_temp;
	}

	//construct S with Sx
	for (int i = 0; i < orderN + 1; i++) {
		for (int j = 0; j < orderN + 1; j++) {
			S.at[i][j] = Sx.at[i + j][0];
		}
	}
	
	//construct vector b
	for (int i = 0; i < orderN + 1; i++) {
		double Sxy_temp = 0;
		for (int k = 0; k < dataL; k++) {
			Sxy_temp += vecY[k] * pow(vecX[k], i);
		}
		b.at[i][0] = Sxy_temp;
	}

	// Calculate optimal Z=inv(S)*(b)
	Matrix invS = createMat(orderN + 1, orderN + 1);
	invMat(S, invS);
	Matrix _vecZ = multMat(invS, b);

	for (int k = 0; k < orderN + 1; k++) {
		vecZ[k] = _vecZ.at[k][0];
	}
}

void expFit(double vecZ[], double vecX[], double vecY[], int dataL) {

	int orderN = 1;
	double lnydata[200] = { 0 };

	for (int i = 0; i < 15; i++) {
		lnydata[i] = log(vecY[i]);
	}

	polyFit(vecZ, vecX, lnydata, dataL, orderN);

}

Matrix expFit_mat(Matrix _X, Matrix _Y) {

	if (_X.rows != _Y.rows) {
		printf("Error in expFit_mat: _X and _Y have different length");
		return zeros(2, 1);
	}

	Matrix lnY = zeros(_Y.rows, _Y.cols);
	int orderN = 1;

	for (int i = 0; i < _Y.rows; i++) {
		lnY.at[i][0] = log(_Y.at[i][0]);
	}

	Matrix Z = polyFit_mat(_X, lnY, orderN);

	return Z;
}