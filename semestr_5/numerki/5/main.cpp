#include <iostream>
#include <stdio.h>
#include "nrutil.h"
#include <nrutil.c>
#include <gaussj.c>
using namespace std;
float f(float x,float y);
//TYLKO MACIERZ 2x2!!!
float** mul(float** a,float** b);
//TYLKO 2x2 jako 2x1!!!
float dl(float** a);
float** grad(float x,float y);
float** sub(float **a,float **b);
int main()
{
	printf("1)\n");
	FILE *plot;
	plot=fopen("plot.dat","w");
	int i,j;
	for(i=-100;i<100;i++)
	{
		for(j=-100;j<100;j++)
		{
			fprintf(plot,"%f %f %f\n",(float)i/10,(float)j/10,f((float)i/10,(float)j/10));
		};
		fprintf(plot,"\n");
	};
	fclose(plot);
	printf("2)\n");
	float** A=matrix(1,2,1,2);
	float** I=matrix(1,2,1,2);
	float** J=matrix(1,2,1,2);
	A[1][1]=2;
	A[1][2]=1;
	A[2][1]=1;
	A[2][2]=2;
	I[1][1]=1;
	I[1][2]=0;
	I[2][1]=0;
	I[2][2]=1;
	J[1][1]=-1;
	J[2][1]=0;
	J[1][2]=0;
	J[2][2]=01;

	gaussj(A,2,I,2);
	printf("A:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%f ",A[i+1][j+1]);
		};
		printf("\n");
	};
	float **b=matrix(1,2,1,2);
	b[1][1]=-4;
	b[1][2]=-4;
	b[2][1]=0;
	b[2][1]=0;
	float** A2=mul(A,J);
	float **r=mul(A2,b);
	printf("r:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%f ",r[i+1][j+1]);
		};
		printf("\n");
	};
	printf("3)\n");

	float e=10;
	float **r1=matrix(1,2,1,2);
	float **r2=matrix(1,2,1,2);
	r1[1][1]=10;
	r1[1][2]=0;
	r1[2][1]=10;
	r1[2][2]=0;
	
	float w=1;
	int max_iter=100;
	i=0;
	do
	{
		i++;
		r2=sub(r1,mul(A,grad(r1[1][1],r1[1][2])));
		printf("%.2f\t%.2f\n%.2f\t%.2f\n",r2[1][1],r2[2][1],r2[1][2],r2[2][2]);
		float** tmp=sub(r2,r1);
		printf("%.2f\t%.2f\n%.2f\t%.2f\n",tmp[1][1],tmp[2][1],tmp[1][2],tmp[2][2]);
		e=dl(tmp);
		printf("%f\n",e);
		free_matrix(tmp,1,2,1,2);
		printf("*");
		r1=r2;
		if(i>max_iter) break;
	}while(e>0.000006);
	printf("\n");
//	float **



	free_matrix(r,1,2,1,2);
	free_matrix(b,1,2,1,2);
	free_matrix(A,1,2,1,2);
	free_matrix(I,1,2,1,2);
	return 0;
};
float f(float x,float y)
{
	return x*x-4*x+8+y*y-4*y+x*y;
};
float** mul(float** a,float **b)
{
	float** wynik=matrix(1,2,1,2);
	wynik[1][1]=a[1][1]*b[1][1]+a[2][1]*b[1][2];
	wynik[1][2]=a[1][1]*b[2][1]+a[2][1]*b[2][2];
	wynik[2][1]=a[1][2]*b[1][1]+a[2][2]*b[1][2];
	wynik[2][2]=a[1][2]*b[2][1]+a[2][2]*b[2][2];
	return wynik;
};
float dl(float** a)
{
	return sqrt(a[2][1]*a[2][1]+a[2][2]*a[2][2]);
};
float** grad(float x,float y)
{
	float** wynik=matrix(1,2,1,2);	
	wynik[1][1]=2*x-4+y;
	wynik[2][1]=2*y-4+x;
	wynik[1][2]=0;
	wynik[2][2]=0;
	return wynik;
};
float** sub(float **a,float **b)
{
	float **wynik=matrix(1,2,1,2);
	wynik[2][1]=a[2][1]-b[2][1];
	wynik[2][2]=a[2][2]-b[2][2];
	wynik[2][1]=a[2][1]-b[2][1];
	wynik[2][2]=a[2][2]-b[2][2];
	return wynik;
};
