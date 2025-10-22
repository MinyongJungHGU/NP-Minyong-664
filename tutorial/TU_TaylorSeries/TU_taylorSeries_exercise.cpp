/*

*/

#include "../../include/myNP_tutorial.h"



int main(int argc, char* argv[])
{

	double xrad = PI / 3;
	double xdeg = 60;
	//double x = 60;

	double S_Nrad = 0;
	double S_Ndeg = 0;

	/*===== Select the function to call =====*/
	S_Nrad = sinTaylor(xrad);
	S_Ndeg = sindTaylor(xdeg);
	//S_N = sindTaylor(x);


	printf("\n\n");
	printf("=======================================\n");
	printf("    sin( %f[rad] ) Calculation   \n", xrad);
	printf("=======================================\n");
	printf("   -  My     result = %3.12f    \n", S_Nrad);
	printf("   -  Math.h result = %3.12f    \n", sin(xrad));
	printf("   -  absolute err. = %3.12f    \n", S_Nrad - sin(xrad));
	printf("=======================================\n");


	printf("\n\n");
	printf("=======================================\n");
	printf("    sin( %f[deg] ) Calculation   \n", xdeg);
	printf("=======================================\n");
	printf("   -  My     result = %3.12f    \n", S_Ndeg);
	printf("   -  Math.h result = %3.12f    \n", sin(xdeg*PI/180));
	printf("   -  absolute err. = %3.12f    \n", S_Ndeg - sin(xdeg * PI / 180));
	printf("=======================================\n");


	system("pause");
	return 0;
}




