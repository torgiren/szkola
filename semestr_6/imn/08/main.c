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
void freetab(double** tab,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		free(tab[i]);
		tab[i]=0;
	};
	free(tab);
};
double ak(double** tab,int size,int k)
{
	int i;
	int j;
	double wynik=0;
	for(i=0;i<size-k;i+=k)
	{
		for(j=0;j<size-k;j+=k)
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
int licz(double** tab, int N, int k,double eps,char* path)
{
	FILE* plik;
	plik=fopen(path,"w");
	int i=0;
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
	}while(fabs(a-a_old)>eps);
	fclose(plik);
	return i;
};
void zapisz_potenc(double **tab,int N,char* path)
{
	int i,j;
	FILE* plik;
	plik=fopen(path,"w");
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
void usrednij(double **tab, int N, int k)
{
	int i,j;
	for(i=0;i<N-k;i+=k)
	{
		for(j=0;j<N-k;j+=k)
		{
			tab[i+k/2][j+k/2]=(tab[i][j]+tab[i+k][j]+tab[i][j+k]+tab[i+k][j+k])/4.0;
		};
	};
	for(i=0;i<N-k;i+=k)
	{
		for(j=0;j<N-k;j+=k)
		{
			if(j!=0)
				tab[i+k/2][j]=(tab[i+k][j]+tab[i][j])/2.0;
			if(i!=0)
				tab[i][j+k/2]=(tab[i][j+k]+tab[i][j])/2.0;
		};
	};
};

void zad1()
{
	int N=129;
	int k=1;
	double **tab=alloc(N);
	poczatkowa(tab,N);
	licz(tab,N,k,0.0000001,"zad1_1.dat");
	zapisz_potenc(tab,N,"zad1_2.dat");
	freetab(tab,N);
};
void zad2()
{
	int N=129;
	double **tab=alloc(N);
	poczatkowa(tab,N);
	int k=16;
	char path[255];
	for(k=16;k>=1;k/=2)
	{
		sprintf(path,"zad2_%d_1.dat",k);
		licz(tab,N,k,0.0000001,path);
		sprintf(path,"zad2_%d_2.dat",k);
		zapisz_potenc(tab,N,path);
		usrednij(tab,N,k);
	};
	freetab(tab,N);
};
int main()
{
	zad1();
	zad2();
	return 0;
};
