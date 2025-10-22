// TU_createHeader_example.cpp 

#include "stdio.h"
#include "stdlib.h"

// Change the include path
#include "../../include/myNP_tutorial.h"






int main(int argc, char* argv[])
{
	double x[3] = { 1, 2, 3 };
	int x_size = sizeof(x) / sizeof(double);
	printVec(x, x_size);
}

