#include <iostream>
#include <ga/ga.h>
const int popsize=200;
const int ngen=300;
const float pmut=0.01;
const float pcross=0.9;
float objective(GAGenome&);
bool play(GAGenome& first, GAGenome& second);
void init(GAGenome& gen);
using namespace std;
int main()
{
	srand(time(NULL));
	GA1DArrayGenome<bool> pop(55,objective);
	pop.initializer(init);
//	pop.crossover(GA1DArrayGenome<bool>::PartialMatchCrossover);
//	pop.crossover(GA1DArrayGenome<bool>::TwoPointCrossover);
	pop.crossover(GA1DArrayGenome<bool>::OnePointCrossover);
	GASimpleGA ga(pop);	
	ga.pMutation(pmut);
	ga.pCrossover(pcross);
	ga.nGenerations(ngen);
	ga.populationSize(popsize);
	ga.selector(GARankSelector());
//	ga.selector(GARouletteWheelSelector());
int iter;
float sredni=0;
for(iter=0;iter<5;iter++)
{
	ga.evolve(rand());
	int i;
	GA1DArrayGenome<bool>& best=(GA1DArrayGenome<bool>&)ga.population().best();
	for(i=49;i>=0;i--)
	{
		printf("%d: %d",i+1,best[i]);
		if(!((i)%3))
			printf("*");
		printf("\n");
	};
	float wynik=0;
	for(i=0;i<50/3;i++)
	{
		if((best[3*i+1]==0)&&(best[3*i+2]==1))
			wynik++;
	};
	wynik*=100;
	wynik/=50/3;
		cout<<ga.population().best()<<"\n"<<ga.population().best().evaluate()<<endl;
	printf("Wynik: %.2f%%\n",wynik);
	sredni+=wynik;
};
	sredni/=5.0;
	printf("Sredni: %.2f\n",sredni);
};
float objective(GAGenome& gen)
{
	GA1DArrayGenome<bool>& genome=(GA1DArrayGenome<bool>&)gen;
	int i;
	int wynik=0;
	for(i=0;i<100;i++)
	{
		wynik+=10*play(genome,genome.geneticAlgorithm()->population().individual(i));
	};
/*
	for(i=0;i<int(50/3);i++)
	{
		if((genome[3*i+1]==0)&&(genome[3*i+2]==1))
		{
			wynik+=1;
		};
	};
*/
	if(genome[0]!=0)
		wynik-=500;
	if(wynik<0) wynik=0;
	return wynik;
};
bool play(GAGenome& first, GAGenome& second)
{
	GA1DArrayGenome<bool>& g1=(GA1DArrayGenome<bool>&)first;
	GA1DArrayGenome<bool>& g2=(GA1DArrayGenome<bool>&)second;
	GA1DArrayGenome<bool>* act[2];
	act[0]=&g2;
	act[1]=&g1;
	int kamienie=55;
	int ruchow=0;
	int i=0;
	while(kamienie>0)
	{
		if((*(act[i%2]))[kamienie-1])
		{
			kamienie-=2;
		}
		else
		{
			kamienie-=1;
		};
		i++;
	};
	ruchow=i;
	return (ruchow%2);
};
void init(GAGenome& gen)
{
	GA1DArrayGenome<bool>& genome=(GA1DArrayGenome<bool>&)gen;
	int i;
	for(i=0;i<genome.size();i++)
	{
		genome[i]=rand()%2;
	};
};
