#include <iostream>
#include <cmath>
#include <nrutil.h>
#include <nrutil.c>
#include <tred2.c>
#include <tqli.c>
#include <pythag.c>
#include <fstream>
void Print(float** A,int n);
void Print(float *A, int n);
void Copy(float* a, float* b, int n);
void Copy(float** A, float** B, int n);
float* Mnoz(float**A, float *v, int n);
float Mnoz(float* v, float *w, int n);
float** Mnoz(float** A, float d, int n);
float* Dziel(float* v,float d, int n);
float** Mnoz2(float* v, float* w, int n);
float** Minus(float** A, float** B, int n);
using namespace std;
int main()
{
	int n=7;
	float **A=matrix(1,n,1,n);
	float **W=matrix(1,n,1,n);
	float *d=vector(1,n);
	float *e=vector(1,n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			A[i][j]=A[j][i]=sqrt(i+j);
			W[i][j]=W[j][i]=A[i][j];
		};
	};

//	cout<<"A: "<<endl;Print(A,n);
	tred2(A,n,d,e);
//	cout<<"A: "<<endl;Print(A,n);
//	cout<<"d: "<<endl;Print(d,n);
//	cout<<"e: "<<endl;Print(e,n);

	float** Z=matrix(1,n,1,n);
	tqli(d,e,n,Z);
//	cout<<"Z: "<<endl;Print(Z,n);

	cout<<"d: "<<endl;Print(d,n);

	cout<<"***********************"<<endl;

	float *x=vector(1,n);
	float l;
	float *x1;
	int k;
	for(k=1;k<=n;k++)
	{
		cout<<"K: "<<k<<endl;
		for(i=1;i<=n;i++)
			x[i]=1;
		for(i=0;i<8;i++)
		{	
//			cout<<"i: "<<i<<endl;
//			cout<<"a"<<endl;
			x1=Mnoz(W,x,n);
//			cout<<"b"<<endl;
			l=Mnoz(x1,x,n)/Mnoz(x,x,n);
//			cout<<"c"<<endl;
			x1=Dziel(x1,sqrt(Mnoz(x1,x1,n)),n);
//			cout<<"d"<<endl;
			Copy(x1,x,n);
//			cout<<"e"<<endl;
			cout<<"iter "<<i<<": l="<<l<<endl;
		};
//		cout<<l<<" ";
//		float** W_tmp=Mnoz2(x,x,n);
//		float** W_tmp2=Mnoz(W_tmp,l,n);
		Copy(Minus(W,Mnoz(Mnoz2(x,x,n),l,n),n),W,n);
	}
	cout<<endl;
};

void Print(float** A, int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<A[i][j]<<" ";
		};
		cout<<endl;
	};

};
void Print(float* A, int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
};
void Copy(float* a, float* b, int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		b[i]=a[i];
	};
};
float* Mnoz(float**A, float *v, int n)
{
	int i,j;
	float *w=vector(1,n);
	for(i=1;i<=n;i++)
	{
		w[i]=0;
		for(j=1;j<=n;j++)
		{
			w[i]+=A[i][j]*v[j];
		};
		
	};
	return w;
};
float Mnoz(float* v, float *w, int n)
{
	float x=0;
	int i;
	for(i=1;i<=n;i++)
	{
		x+=v[i]*w[i];
	};
	return x;
};
float* Dziel(float* v,float d, int n)
{
	float* w=vector(1,n);
	int i;
	for(i=1;i<=n;i++)
	{
		w[i]=v[i]/d;
	};
	return w;
};
float** Mnoz2(float* v, float* w, int n)
{
	float** A=matrix(1,n,1,n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			A[i][j]=v[i]*w[j];
		};
	};
	return A;
};
float** Minus(float** A, float** B, int n)
{
	float **C=matrix(1,n,1,n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			C[i][j]=A[i][j]-B[i][j];
		};
	};
	return C;
};
float** Mnoz(float** A, float d, int n)
{
	float** B=matrix(1,n,1,n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			B[i][j]=A[i][j]*d;
		};
	};
	return B;
};
void Copy(float** A, float** B, int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			B[i][j]=A[i][j];
		};
	};
};
