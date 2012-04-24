#include <iostream>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <fstream>
using namespace std;
double f(int x)
{
	double y=(float)x/1000.0f;
//	cout<<y<<endl;
	double wynik=fabs(sin(M_PI*y)*exp(-y/(6.0f*M_PI)));
//	cout<<wynik<<endl;
	return wynik;
};
int main()
{
	vector<int> wynik;
	wynik.reserve(314);
	int N=pow(10,7);
	srand(time(NULL));
	int i,j;
	for(i=0;i<N;i++)
	{
		int tmp=rand()%(31400);
		double tmp3=f(tmp);
		int tmp2=tmp3*314;
		wynik[tmp2]++;
//		cout<<tmp<<"\t"<<tmp2<<"\t"<<tmp3<<"\t"<<wynik[tmp2]<<endl;
	};
	cout<<"policzone"<<endl;
	ofstream plik("rozklad.dat");
	for(i=1;i<314;i++)
	{
		plik<<(float)i/(3140.0f)<<" "<<(float)wynik[i]/pow(10,7)<<endl;
//		cout<<(float)i/100.0f<<" "<<wynik[i]<<endl;
	};
	plik.close();
	return 0;
};
