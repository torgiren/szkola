#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <cstdlib>
using namespace std;
//typedef double[100][100] siatka;
void poczatkowy(double*** tab)
{
	int i;
	int j;
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			(*tab)[i][j]=0.0f;
};
void gestosc(double*** tab)
{
	int i;
	int j;
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			(*tab)[i][j]=0.0f;
	for(i=40;i<60;i++)
		for(j=40;j<60;j++)
			(*tab)[i][j]=1.0f;
};
void potencjal(double*** potenc, double ***pois, double w)
{
	int i;
	int j;
	for(i=1;i<99;i++)
		for(j=1;j<99;j++)
			(*potenc)[i][j]=(1.0f-w)*(*potenc)[i][j]+w*((*potenc)[i+1][j]+(*potenc)[i-1][j]+(*potenc)[i][j+1]+(*potenc)[i][j-1]+(*pois)[i][j])/4.0f;
};
void potencjal_zad3(double*** potenc, double*** pois, double w)
{
	int i;
	int j;
	double tmp[100][100];
//	memcpy(tmp,potenc,100*100*sizeof(double));
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			tmp[i][j]=0;

	for(i=1;i<99;i++)
		for(j=1;j<99;j++)
///			tmp[i][j]=(1.0f-w)*(*potenc)[i][j];
			tmp[i][j]=(1.0f-w)*(*potenc)[i][j]+w*((*potenc)[i+1][j]+(*potenc)[i-1][j]+(*potenc)[i][j+1]+(*potenc)[i][j-1]+(*pois)[i][j])/4.0f;
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			(*potenc)[i][j]=tmp[i][j];
};
ostream& print_potenc(ostream& out,double*** potenc)
{
	int i;
	int j;
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			out<<i<<" "<<j<<" "<<(*potenc)[i][j]<<endl;	
	return out;
};
double zbiez_funkc(double*** potenc, double*** pois)
{
	int i;
	int j;
	double wynik=0;
	for(i=1;i<99;i++)
		for(j=1;j<99;j++)
		{
			double tmp;
			tmp=pow(((*potenc)[i+1][j]-(*potenc)[i-1][j])/2.0f,2);
			tmp+=pow(((*potenc)[i][j+1]-(*potenc)[i][j-1])/2.0f,2);
			tmp/=2.0f;
			tmp-=(*pois)[i][j]*(*potenc)[i][j];
			wynik+=tmp;
		};
	return wynik;
};

void zad1()
{
//	double potenc[100][100];
//	double pois[100][100];
	double** pois=(double**)malloc(100*sizeof(double*));
	double** potenc=(double**)malloc(100*sizeof(double*));
	int i;
	for(i=0;i<100;i++)
	{
		potenc[i]=(double*)malloc(100*sizeof(double));
		pois[i]=(double*)malloc(100*sizeof(double));
	};
	cout<<"przed"<<endl;
	gestosc((double***)&pois);
	cout<<"po"<<endl;
	cout<<pois<<endl;
	double w;
	ofstream plik("zad1_1.dat");
	for(w=0.2f;w<2.0f;w+=0.02)
	{
		double zbiez=1;
		double zbiez_old;
		poczatkowy((double***)&potenc);		
		int iter=0;
		do
		{
			zbiez_old=zbiez;
			potencjal(&potenc,&pois,w);
			zbiez=zbiez_funkc(&potenc,&pois);
			++iter;
//			cout<<"delta zbiez: "<<zbiez-zbiez_old<<endl;
		}while(fabs((zbiez-zbiez_old)/zbiez_old)>0.000001);
//		}while(fabs(zbiez-zbiez_old)>0.01);
		cout<<w<<" "<<iter<<endl;
		plik<<w<<" "<<iter<<endl;
	};	
	plik.close();
	plik.open("zad1_2.dat");
	print_potenc(plik,&potenc);
	plik.close();
};
double** specific_zad1(double w)
{
//	double potenc[100][100];
//	double pois[100][100];
	double** pois=(double**)malloc(100*sizeof(double*));
	double** potenc=(double**)malloc(100*sizeof(double*));
	int i;
	for(i=0;i<100;i++)
	{
		potenc[i]=(double*)malloc(100*sizeof(double));
		pois[i]=(double*)malloc(100*sizeof(double));
	};
	cout<<"przed"<<endl;
	gestosc((double***)&pois);
	cout<<"po"<<endl;
	cout<<pois<<endl;
//	for(w=0.2f;w<2.0f;w+=0.02)
	{
		double zbiez=1;
		double zbiez_old;
		poczatkowy((double***)&potenc);		
		int iter=0;
		do
		{
			zbiez_old=zbiez;
			potencjal(&potenc,&pois,w);
			zbiez=zbiez_funkc(&potenc,&pois);
			++iter;
//			cout<<"delta zbiez: "<<zbiez-zbiez_old<<endl;
		}while(fabs((zbiez-zbiez_old)/zbiez_old)>0.000001);
//		}while(fabs(zbiez-zbiez_old)>0.01);
	};	
	return potenc;
};
void zad2()
{
	double** gest=(double**)malloc(100*sizeof(double*));
	double** potenc=specific_zad1(1.8);
	int i;
	for(i=0;i<100;i++)
	{
//		potenc[i]=(double*)malloc(100*sizeof(double));
		gest[i]=(double*)malloc(100*sizeof(double));
	};
//	poczatkowy(gestosc);
//	double potenc[100][100];//TODO Zrobic to
	poczatkowy(&gest);
	int j;
	for(i=1;i<99;i++)
		for(j=1;j<99;j++)
			gest[i][j]=0;
	for(i=1;i<99;i++)
		for(j=1;j<99;j++)
		{
			gest[i][j]=potenc[i+1][j]-2*potenc[i][j]+potenc[i-1][j]+potenc[i][j+1]-2*potenc[i][j]+potenc[i][j-1];
			gest[i][j]*=-1;
//			gestosc[i][j]=4.0f*(potenc[i][j]-(1-w)*potenc[i][j])-potenc[i+1][j]-potenc[i-1][j]-potenc[i][j+1]-potenc[i][j-1];
		};
	ofstream plik;
	plik.open("zad2_1.dat");
	gestosc(&potenc);
	for(i=0;i<100;i++)
	{
		plik<<i<<" "<<gest[50][i]<<" "<<potenc[50][i]<<endl;
	};
	plik.close();
};
void zad3()
{
	double** pois=(double**)malloc(100*sizeof(double*));
	double** potenc=(double**)malloc(100*sizeof(double*));
	int i;
	for(i=0;i<100;i++)
	{
		potenc[i]=(double*)malloc(100*sizeof(double));
		pois[i]=(double*)malloc(100*sizeof(double));
	};
//	double potenc[100][100];
//	double pois[100][100];
	gestosc(&pois);
	double w;
	ofstream plik("zad3_1.dat");
	for(w=0.05f;w<1.2f;w+=0.05)
	{
		double zbiez=10;
		double zbiez_old;
		poczatkowy((double***)&potenc);		
		int iter=0;
		do
		{
			zbiez_old=zbiez;
			potencjal_zad3(&potenc,&pois,w);
			zbiez=zbiez_funkc(&potenc,&pois);
			++iter;
		}while(fabs((zbiez-zbiez_old)/zbiez_old)>0.0000001);
		cout<<w<<" "<<iter<<endl;
		plik<<w<<" "<<iter<<endl;
		if(w==1.0f)
		{
			ofstream plik2;
			plik2.open("zad3_2.dat");
			print_potenc(plik2,&potenc);
			plik2.close();

		};
	};	
	plik.close();
};
int main()
{
//	zad1();
	zad2();
//	zad3();
	return 0;
};

