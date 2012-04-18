#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <time.h>
#include <sys/time.h>
using namespace std;
typedef map<int,map<int,double> > siatka;
void poczatkowy(siatka& tab)
{
	int i;
	int j;
	for(i=-50;i<50;i++)
		for(j=-50;j<50;j++)
			tab[i][i]=0;
};
void gestosc(siatka& tab)
{
	int i;
	int j;
	poczatkowy(tab);
	for(i=-10;i<10;i++)
		for(j=-10;j<10;j++)
			tab[i][i]=1;
};
void potencjal(siatka& potenc, siatka& pois, double w)
{
	int i;
	int j;
	for(i=-49;i<49;i++)
		for(j=-49;j<49;j++)
			potenc[i][j]=(1-w)*potenc[i][j]+w*(potenc[i+1][j]+potenc[i-1][j]+potenc[i][j+1]+potenc[i][j-1]+pois[i][j])/4.0f;
};
void potencjal_zad3(siatka& potenc, siatka& pois, double w)
{
	int i;
	int j;
	siatka tmp=potenc;
	for(i=-49;i<49;i++)
		for(j=-49;j<49;j++)
			tmp[i][j]=(1-w)*potenc[i][j]+w*(potenc[i+1][j]+potenc[i-1][j]+potenc[i][j+1]+potenc[i][j-1]+pois[i][j])/4.0f;
	for(i=-50;i<50;i++)
		for(j=-50;j<50;j++)
			potenc[i][j]=tmp[i][j];
};
double zbiez_funkc(siatka& potenc, siatka& pois)
{
	int i;
	int j;
	double wynik=0;
	for(i=-49;i<49;i++)
		for(j=-49;j<49;j++)
		{
			double tmp;
			tmp=pow((potenc[i+1][j]-potenc[i-1][j])/2.0f,2);
			tmp+=pow((potenc[i][j+1]-potenc[i][j-1])/2.0f,2);
			tmp/=2.0f;
			tmp-=pois[i][j]*potenc[i][j];
			wynik+=tmp;
		};
	return wynik;
};

void zad1()
{
	siatka potenc;
	siatka pois;
	gestosc(pois);
	double w;
	for(w=0.01f;w<2.0f;w+=0.01)
	{
		double zbiez=1000;
		double zbiez_old;
		poczatkowy(potenc);		
		int iter=0;
		do
		{
			zbiez_old=zbiez;
			potencjal(potenc,pois,w);
			zbiez=zbiez_funkc(potenc,pois);
			++iter;
		}while(fabs(zbiez-zbiez_old)>0.01);
		cout<<w<<" "<<iter<<endl;
	};
};
void zad2()
{
	siatka gestosc;
	poczatkowy(gestosc);
	siatka potenc;
	double w;
	int i;
	int j;
	for(i=-49;i<49;i++)
		for(j=-49;j<49;j++)
		{
			gestosc[i][j]=4.0f*(potenc[i][j]-(1-w)*potenc[i][j])-potenc[i+1][j]-potenc[i-1][j]-potenc[i][j+1]-potenc[i][j-1];
		};
	
};
void zad3()
{
	siatka potenc;
	siatka pois;
	gestosc(pois);
	double w;
	for(w=0.01f;w<2.0f;w+=0.01)
	{
		double zbiez=1000;
		double zbiez_old;
		poczatkowy(potenc);		
		int iter=0;
		do
		{
			zbiez_old=zbiez;
			potencjal_zad3(potenc,pois,w);
			zbiez=zbiez_funkc(potenc,pois);
			++iter;
		}while(fabs(zbiez-zbiez_old)>0.01);
		cout<<w<<" "<<iter<<endl;
	};
};
int main()
{
//	zad1();
	zad2();
	zad3();
	return 0;
};

