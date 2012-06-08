#include <iostream>
#include <ga/ga.h>
const int popsize=500;
const int ngen=100;
const float pmut=0.01;
const float pcross=0.9;
float objective(GAGenome&);
bool play(GAGenome& first, GAGenome& second);
void init(GAGenome& gen);
using namespace std;
int main()
{
	srand(time(NULL));
	GA1DArrayGenome<bool> pop(50,objective);
	pop.initializer(init);
//	pop.crossover(GA1DArrayGenome<bool>::PartialMatchCrossover);
	pop.crossover(GA1DArrayGenome<bool>::TwoPointCrossover);
	GASimpleGA ga(pop);	
	ga.pMutation(pmut);
	ga.pCrossover(pcross);
	ga.nGenerations(ngen);
	ga.populationSize(popsize);
	ga.selector(GARankSelector());
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
		cout<<ga.population().best()<<"\n"<<ga.population().best().evaluate()<<endl;
};
float objective(GAGenome& gen)
{
	GA1DArrayGenome<bool>& genome=(GA1DArrayGenome<bool>&)gen;
	int i;
	int wynik=0;
	for(i=0;i<100;i++)
	{
		wynik+=2*play(genome,genome.geneticAlgorithm()->population().individual(i));
	};
	for(i=0;i<100;i++)
	{
		wynik+=!play(genome.geneticAlgorithm()->population().individual(i),genome);
	};
//	for(i=0;i<500;i++)
//	{
//		wynik+=!play(genome.geneticAlgorithm()->population().individual(rand()%genome.geneticAlgorithm()->population().size()),genome);
//	};
//	for(i=0;i<genome.size();i++)
//	{
//		printf("%d",genome[i]);
//	};
//	printf("\t%d\n",wynik);
	for(i=0;i<15;i++)
	{
		if((genome[3*i+1]==0)&&(genome[3*i+2]==1))
		{
			wynik+=1;
		};
	};
	return wynik;
};
bool play(GAGenome& first, GAGenome& second)
{
	GA1DArrayGenome<bool>& g1=(GA1DArrayGenome<bool>&)first;
	GA1DArrayGenome<bool>& g2=(GA1DArrayGenome<bool>&)second;
	GA1DArrayGenome<bool>* act[2];
	act[0]=&g2;
	act[1]=&g1;
	int kamienie=50;
	int ruchow=0;
	int i=0;
	while(kamienie>0)
	{
//		printf("Kamieni: %d\n%d: ",kamienie,i);
		if((*(act[i%2]))[kamienie-1])
		{
//			printf("Zdejmuje dwa\n");
			kamienie-=2;
		}
		else
		{
//			printf("Zdejuje jeden\n");
			kamienie-=1;
		};
		i++;
	};
	ruchow=i;
/*
	printf("Walka:\n");
	for(i=0;i<g1.size();i++)
	{
		printf("%d",g1[i]);
	};
	printf("\n");
	for(i=0;i<g2.size();i++)
	{
		printf("%d",g2[i]);
	};
	printf("\n");
	printf("Czy pierwszy wygral: %d\tpo %d ruchach\n",(!(ruchow%2)),ruchow);
*/
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
