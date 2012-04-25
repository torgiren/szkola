#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
int ruletka(int* pop)
{
	int i;
	int sum=0;
	for(i=0;i<500;i++)
	{
		sum+=pop[i];	
	};
	int r=rand()%sum;
	int act=0;
	for(i=0;i<500;i++)
	{
		act+=pop[i];
		if(act>=r)
			return i;
	};
	cerr<<"Jakis blad"<<endl;
	return 0;
};
int turniej(int* pop)
{
	int uczestnicy[8];
	int i;
	for(i=0;i<8;i++)
	{
		uczestnicy[i]=ruletka(pop);
	};
	int j;
	for(j=3;j>0;j--)
	{
		for(i=0;i<j;i++)
		{
			uczestnicy[i]=(rand()%(pop[uczestnicy[2*i+1]]+pop[uczestnicy[2*i]])<pop[uczestnicy[2*i]])?uczestnicy[2*i]:uczestnicy[2*i+1];
		};
	};
	return uczestnicy[0];
};
int main()
{
	srand(time(NULL));
	int* A=new int[500];
	int* B=new int[500];
	int* C=new int[500];
	ifstream plik("dane.txt");
	int a,b;
	plik>>a>>b;
	int i=0;
	while(!plik.eof())
	{
		cout<<a<<" "<<b<<endl;
		plik>>a>>b;
		A[i]=a;
		B[i]=b;
		++i;
	};
	float czest_glob[20][100];
	memset(czest_glob,0,sizeof(float)*20*100);
	int x;
	for(x=0;x<100;x++)
	{
//		int czest[20];
//		memset(czest,0,sizeof(int)*20);
		for(i=0;i<500;i++)
		{
			C[i]=turniej(B);
			czest_glob[B[C[i]]][x]++;
		};
	};
	ofstream wynik("czest.dat");
	float srednia[20];
	memset(srednia,0,sizeof(float)*20);
	for(i=0;i<20;i++)
	{
		int j;
		int tmp=0;
		for(j=0;j<100;j++)
		{
			srednia[i]+=czest_glob[i][j];
		};
		srednia[i]/=100;

	};
	float odchylenie[20];
	memset(odchylenie,0,sizeof(float)*20);
	for(i=0;i<20;i++)
	{
		int j;
		int tmp=0;
		for(j=0;j<100;j++)
		{
			odchylenie[i]+=(srednia[i]-czest_glob[i][j])*(srednia[i]-czest_glob[i][j]);
			odchylenie[i]/=100;
		};
	};
	for(i=0;i<20;i++)
	{
		wynik<<i<<" "<<srednia[i]<<" "<<odchylenie[i]<<endl;
	};
	wynik.close();
	delete A;
	delete B;
	delete C;
	return 0;
};
