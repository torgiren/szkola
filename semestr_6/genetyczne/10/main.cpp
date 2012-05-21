#include <iostream>
#include <fstream>
#include <ga/ga.h>
#include <vector>
using namespace std;
const int popsize=10;
const int ngen=1000;
const float pmut=0.01;
const float pcross=0.6;
int main()
{
	srand(time(NULL));
	ifstream plik;
	plik.open("input.dat");
	int tab[300];
	int i,j;
	for(i=0;i<300;i++)
	{
		plik>>tab[i];
	};
	plik.close();
	vector<GA1DArrayGenome<int>*> pop;
	for(i=0;i<popsize;i++)
	{
		GA1DArrayGenome<int>* tmp=new GA1DArrayGenome<int>(300);
		for(j=0;j<300;j++)
		{
			tmp[j]=j;
		};
		pop.push_back(tmp);
	};
	for(i=0;i<popsize;i++)
	{
		for(j=0;j<50;j++)
		{
			pop[i]->swap(rand()%300,rand()%300);
		};
	};



	for(i=0;i<popsize;i++)
	{
		delete pop[i];
	};
};
