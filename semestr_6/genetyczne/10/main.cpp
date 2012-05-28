#include <iostream>
#include <fstream>
#include <ga/ga.h>
#include <vector>
using namespace std;
const int popsize=300;
const int ngen=50;
const float pmut=0.01;
const float pcross=0.80;
float objective(GAGenome &);
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



};
float objective(GAGenome& gen)
{
	int i;
	GA1DArrayGenome<int>& genome=(GA1DArrayGenome<int>&) gen;
	float wynik=0;
	for(i=0;i<100;i++)
	{
		int a=genome[3*i];
		int b=genome[3*i+1];
		int c=genome[3*i+2];
		if(PossibleTriangle(tab[a],tab[b],tab[c]))
		{
//			printf("Mozliwy z bokow: %d %d %d\n",tab[a],tab[b],tab[c]);
			wynik+=100;
		};
	};
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
