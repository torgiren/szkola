#include <iostream>
#include <fstream>
#include <ga/ga.h>
#include <vector>
#include <math.h>
using namespace std;
const int popsize=1000;
const int ngen=100;
const float pmut=0.01;
const float pcross=0.90;
float objective(GAGenome &);
float pole(float,float,float);
void init(GAGenome& gen);
bool PossibleTriangle(float,float,float);
int tab[300];
int main()
{
	srand(time(NULL));
	ifstream plik;
	plik.open("input.dat");
	int i;
	for(i=0;i<300;i++)
	{
		plik>>tab[i];
	};
	plik.close();
	GA1DArrayGenome<int> pop(300,objective);
	pop.initializer(init);
	pop.mutator(GA1DArrayGenome<int>::SwapMutator);
	pop.crossover(GA1DArrayGenome<int>::PartialMatchCrossover);

	GASimpleGA ga(pop);
	ga.selector(GARankSelector());
	ga.populationSize(popsize);
	ga.nGenerations(ngen);
	ga.pMutation(pmut);
	ga.pCrossover(pcross);

	ga.evolve(time(NULL));


	cout << "Najlepsze rozwiazanie to F(x=";
	cout << ga.population().best() << ")=";
	cout << ga.population().best().evaluate() << " (";
	cout << ga.population().best().fitness() << ")" << endl;


	{
	GA1DArrayGenome<int>& genome=(GA1DArrayGenome<int>&) ga.population().best();
	vector<float> pola;
	float wynik=0;
	for(i=0;i<100;i++)
	{
		int a=genome[3*i];
		int b=genome[3*i+1];
		int c=genome[3*i+2];
		if(PossibleTriangle(tab[a],tab[b],tab[c]))
		{
//			printf("Mozliwy z bokow: %d %d %d\n",tab[a],tab[b],tab[c]);
			
			pola.push_back(pole(tab[a],tab[b],tab[c]));
			wynik++;
		};
	};
	float suma=0;
	for(i=0;i<pola.size();i++)
	{
		suma+=pola[i];
	};
	suma/=(float)pola.size();
	float odchyl=0;
	for(i=0;i<pola.size();i++)
	{
		odchyl+=(suma-pola[i])*(suma-pola[i]);
	};
	odchyl/=pola.size()-1;
	odchyl=sqrt(odchyl);
	cout<<"Trojkatow: "<<wynik<<endl;
	cout<<"Srednie pole: "<<suma<<endl;
	cout<<"Odchylenie: "<<odchyl<<endl;
	};

};
float objective(GAGenome& gen)
{
	int i;
	GA1DArrayGenome<int>& genome=(GA1DArrayGenome<int>&) gen;
	vector<float> pola;
	float wynik=0;
	for(i=0;i<100;i++)
	{
		int a=genome[3*i];
		int b=genome[3*i+1];
		int c=genome[3*i+2];
		if(PossibleTriangle(tab[a],tab[b],tab[c]))
		{
//			printf("Mozliwy z bokow: %d %d %d\n",tab[a],tab[b],tab[c]);
			
			pola.push_back(pole(tab[a],tab[b],tab[c]));
			wynik+=100;
		};
	};
	float suma=0;
	for(i=0;i<pola.size();i++)
	{
		suma+=pola[i];
	};
	float odchyl=0;
	suma/=(float)pola.size();
	for(i=0;i<pola.size();i++)
	{
		odchyl+=(suma-pola[i])*(suma-pola[i]);
	};
	odchyl=sqrt(odchyl);
	wynik-=2.5f*odchyl;
//	cout<<"odchylenie: "<<odchyl<<endl;
//	cout<<"wynik: "<<wynik<<endl;
	if(wynik<0) wynik=0;
	return wynik;
};
void init(GAGenome& gen)
{
	GA1DArrayGenome<int>& genome=(GA1DArrayGenome<int>&) gen;
	int i;
	for(i=0;i<genome.size();i++)
	{
		genome[i]=i;
	};
	for(i=0;i<50;i++)
	{
		genome.swap(rand()%genome.size(),rand()%genome.size());
	};
};
bool PossibleTriangle(float a,float b,float c)
{
	bool possible=false;
	if((a+b>c)&&(a+c>b)&&(b+c>a)) possible=true;
	return possible;
};
float pole(float a,float b,float c)
{
	return sqrt( (a+b+c)*(a+b-c)*(a-b+c)*(-a+b+c) )/4.0;
};
