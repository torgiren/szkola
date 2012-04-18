#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
using namespace std;
typedef map<int,map<int,double> > siatka;
void poczatkowy(siatka& tab)
{
	int i;
	int j;
	for(i=-50;i<=50;i++)
		for(j=-50;j<=50;j++)
			tab[i][i]=0.0f;
};
void gestosc(siatka& tab)
{
	int i;
	int j;
	poczatkowy(tab);
	for(i=-10;i<=10;i++)
		for(j=-10;j<=10;j++)
			tab[i][j]=1.0f;
};
void potencjal(siatka& potenc, siatka& pois, double w)
{
	int i;
	int j;
	for(i=-49;i<=49;i++)
		for(j=-49;j<=49;j++)
			potenc[i][j]=(1.0f-w)*potenc[i][j]+w*(potenc[i+1][j]+potenc[i-1][j]+potenc[i][j+1]+potenc[i][j-1]+pois[i][j])/4.0f;
};
void potencjal_zad3(siatka& potenc, siatka& pois, double w)
{
	int i;
	int j;
	siatka tmp=potenc;
	for(i=-49;i<=49;i++)
		for(j=-49;j<=49;j++)
			tmp[i][j]=(1.0f-w)*potenc[i][j]+w*(potenc[i+1][j]+potenc[i-1][j]+potenc[i][j+1]+potenc[i][j-1]+pois[i][j])/4.0f;
	for(i=-50;i<=50;i++)
		for(j=-50;j<=50;j++)
			potenc[i][j]=tmp[i][j];
};
ostream& operator<<(ostream& out,siatka& potenc)
{
	int i;
	int j;
	for(i=-50;i<=50;i++)
		for(j=-50;j<=50;j++)
			out<<i<<" "<<j<<" "<<potenc[i][j]<<endl;	
	return out;
};
double zbiez_funkc(siatka& potenc, siatka& pois)
{
	int i;
	int j;
	double wynik=0;
	for(i=-49;i<=49;i++)
		for(j=-49;j<=49;j++)
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

siatka zad1()
{
	siatka potenc;
	siatka pois;
	gestosc(pois);
	double w;
	ofstream plik("zad1_1.dat");
	for(w=0.05f;w<2.0f;w+=0.05)
	{
		double zbiez=10;
		double zbiez_old;
		poczatkowy(potenc);		
		int iter=0;
		do
		{
			zbiez_old=zbiez;
			potencjal(potenc,pois,w);
			zbiez=zbiez_funkc(potenc,pois);
			++iter;
		}while(fabs((zbiez-zbiez_old)/zbiez_old)>0.0001);
//		}while(fabs(zbiez-zbiez_old)>0.01);
		cout<<w<<" "<<iter<<endl;
		plik<<w<<" "<<iter<<endl;
	};	
	plik.close();
	plik.open("zad1_2.dat");
	plik<<potenc<<endl;
	plik.close();
	return potenc;
};
void zad2()
{
	siatka gestosc;
	poczatkowy(gestosc);
	siatka potenc=zad1();
	double w=1.8;
	int i;
	int j;
	for(i=-49;i<=49;i++)
		for(j=-49;j<=49;j++)
		{
			gestosc[i][j]=4.0f*(potenc[i][j]-(1-w)*potenc[i][j])-potenc[i+1][j]-potenc[i-1][j]-potenc[i][j+1]-potenc[i][j-1];
		};
	ofstream plik;
	plik.open("zad2_1.dat");
	plik<<gestosc<<endl;
	plik.close();
};
void zad3()
{
	siatka potenc;
	siatka pois;
	gestosc(pois);
	double w;
	ofstream plik("zad3_1.dat");
	for(w=0.05f;w<1.0f;w+=0.05)
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
		}while(fabs((zbiez-zbiez_old)/zbiez_old)>0.0001);
		cout<<w<<" "<<iter<<endl;
		plik<<w<<" "<<iter<<endl;
	};	
	plik.close();
	plik.open("zad3_2.dat");
	plik<<potenc<<endl;
	plik.close();
};
int main()
{
//	zad1();
	zad2();
	zad3();
	return 0;
};

