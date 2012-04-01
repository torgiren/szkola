#include <stdio.h>
#include <math.h>
int main(void)
{
	printf("Hello world\n");
	printf("char %d bajtow i %d bitow a max wartosc to %.0f\n",sizeof(char),8*sizeof(char),pow(2,sizeof(char)*8));
	printf("int %d bajtow i %d bitow a max wartosc to %.0f\n",sizeof(int),8*sizeof(int),pow(2,sizeof(int)*8));
	printf("float %d bajtow i %d bitow a max wartosc to %.0f\n",sizeof(float),8*sizeof(float),pow(2,sizeof(float)*8));
	printf("double %d bajtow i %d bitow a max wartosc to %.0f\n",sizeof(double),8*sizeof(double),pow(2,sizeof(double)*8));


	char x=255;
//	x=x+1;
	printf("%d\n",x);

	printf("%f\n",2/3);
	
	

	return 0;
};
