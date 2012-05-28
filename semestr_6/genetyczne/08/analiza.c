#include <stdio.h>
#include <math.h>
#include "StaticLib.h"
int main()
{
	double i,j;
	for(i=GA_Get_Min_x(4);i<GA_Get_Max_x(4);i+=0.01)
	{
		for(j=GA_Get_Min_y(4);j<GA_Get_Max_y(4);j+=0.01)
		{
			printf("%f %f %f\n",i,j,GA_TestFunction(4,i,j));
		};
		printf("\n");
	};
	return 0;
};
