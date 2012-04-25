#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/**
 * zhardcodowana funkcja. za malo czasu zeby pisac ladna
 */
double index2var(int index)
{
	index-=64;
	double wynik=(double)index;
	wynik*=0.05;
//	printf("%d => %lf\n",index+64,wynik);
	return wynik;
};
double kwadrat(double liczba)
{
	return liczba*liczba;
};
void poczatkowa(double** tab,int size)
{
	int i;
	int j;
	for(i=0;i<size;i++)
	{
		memset(tab[i],0,sizeof(double)*size);
	};
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if((i==0)||(j==0)||(i==(size-1))||(j==(size-1)))
				tab[i][j]=kwadrat(index2var(i))-kwadrat(index2var(j));
		};
	};
};
double **alloc(int size)
{
	double** tab=(double**)malloc(sizeof(double)*size);
	int i;
	for(i=0;i<size;i++)
	{
		tab[i]=(double*)malloc(sizeof(double)*size);
		memset(tab[i],0,sizeof(double)*size);
	};
	return tab;
};
double ak(double** tab,int size,int k)
{
	int i;
	int j;
	double wynik=0;
	for(i=k;i<size-k;i+=k)
	{
		for(j=k;j<size-k;j+=k)
		{
			wynik+=kwadrat(tab[i+k][j]+tab[i+k][j+k]-tab[i][j]-tab[i][j+k]);	
			wynik+=kwadrat(tab[i][j+k]+tab[i+k][j+k]-tab[i][j]-tab[i+k][j]);
		};
	};
	wynik/=8.0f;
	return wynik;
};
void relaksacja(double **tab,int size,int k)
{
	int i,j;
	for(i=k;i<size-k;i+=k)
		for(j=k;j<size-k;j+=k)
		{
			tab[i][j]=(tab[i-k][j]+tab[i][j-k]+tab[i+k][j]+tab[i][j+k])/4.0f;
		};
};
void zad1()
{
	int N=130;
	int k=1;
	double **tab=alloc(N);
	poczatkowa(tab,N);
	int i,j;
	FILE* plik;
	plik=fopen("zad1_0.dat","w");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			fprintf(plik,"%d %d %lf\n",i,j,tab[i][j]);
		};
	};
	fclose(plik);
	plik=fopen("zad1_1.dat","w");
//	printf("%lf %lf %lf\n",tab[0][0],tab[0][1],tab[1][0]);
	double a_old,a;
	a=ak(tab,N,k);
//	int i=0;
	do
	{
		i++;
		relaksacja(tab,N,k);
		a_old=a;
		a=ak(tab,N,k);
		fprintf(plik,"%d %lf\n",i,a);
	}while(fabs(a-a_old)>0.0000001);
//	int j;
	fclose(plik);
	plik=fopen("zad1_2.dat","w");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			fprintf(plik,"%d %d %lf\n",i,j,tab[i][j]);
		};
		fprintf(plik,"\n");
	};
	fclose(plik);
};
void zad2()
{
	int k=16;
	for(k=16;k>=1;k/=2)
	{
	};
};
int main()
{
	zad1();
	return 0;
};
