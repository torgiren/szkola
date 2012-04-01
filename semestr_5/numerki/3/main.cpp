#include <iostream>
#include <nrutil.h>
#include <nrutil.c>
#include <gaussj.c>
#include <ludcmp.c>
void wypelnij(float** A,float q); //wypelnia TYLKO macierz 5x5
void wypelnij2(float** A,float q); //wypelnia TYLKO macierz 5x5
void rozloz(float** A, float** &L, float **&U); //TYLKO 5x5
void wypisz(float** A); //tYLKO 5x5
float det(float **U); //TYLKO 5x5
using namespace std;
int main()
{
	int rozm_x=6;
	int rozm_y=6;
	float **A;
	float **L;
	float **U;
	int *n;
	n=new int[rozm_x];
	A=new float*[rozm_x];	
	L=new float*[rozm_x];
	U=new float*[rozm_x];
	int x;
	FILE *plik;
	plik=fopen("dane.dat","w");
	for(x=0;x<rozm_x;x++)
	{
		A[x]=new float[rozm_y];
		L[x]=new float[rozm_y];
		U[x]=new float[rozm_y];
	};
	float q;
	for(q=0.2;q<5;q+=0.05)
	{
		wypelnij(A,q);
//	wypisz(A);
//	cout<<endl;
		float tmp;
		ludcmp(A,5,n,&tmp);
		rozloz(A,L,U);
//	wypisz(A);
//	cout<<endl;
//	wypisz(L);
//	cout<<endl;
//	wypisz(U);
		float d=det(U);	
		fprintf(plik,"%f %f\n",q,d);
	};
	fclose(plik);









	for(x=0;x<rozm_x;x++)
	{
		delete [] A[x];
		delete [] L[x];
		delete [] U[x];
	};
	delete [] A;
	delete [] L;
	delete [] U;
	return 0;
};
void wypelnij(float** A,float q)
{
	A[1][1]=2*q*0.001;
	A[2][1]=0.002;
	A[3][1]=1;
	A[4][1]=5;
	A[5][1]=3;

	A[1][2]=1;
	A[2][2]=1;
	A[3][2]=6;
	A[4][2]=9;
	A[5][2]=4;
	
	A[1][3]=6;
	A[2][3]=6;
	A[3][3]=6;
	A[4][3]=10;
	A[5][3]=9;

	A[1][4]=9;
	A[2][4]=9;
	A[3][4]=8;
	A[4][4]=7;
	A[5][4]=7;

	A[1][5]=10;
	A[2][5]=10;
	A[3][5]=6;
	A[4][5]=10;
	A[5][5]=9;
};
void wypelnij2(float **A)
{
	wypelnij(A,0);
	A[1][1]=1;
	A[1][2]=1;
	A[1][3]=1;
	A[1][4]=1;
	A[1][5]=1;
};
void rozloz(float** A, float** &L, float** &U)
{
	int x,y;
	for(x=1;x<6;x++)
	{
		L[x][x]=1;
		for(y=0;y<x;y++)
		{
			L[x][y]=A[x][y];
		};
		for(y=x;y<6;y++)
		{
			U[x][y]=A[x][y];
		};
	};
};
void wypisz(float** A)
{
	int x,y;
	for(x=1;x<6;x++)
	{
		for(y=1;y<6;y++)
		{
			cout<<A[x][y]<<"\t";		
		};
		cout<<endl;
	}
};
float det(float** U)
{
	float tmp=1;
	int x;
	for(x=1;x<6;x++)
	{
		tmp*=U[x][x];
	};
	return tmp;
};
