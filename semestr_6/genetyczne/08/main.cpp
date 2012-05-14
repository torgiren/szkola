#include <iostream>
#include <cmath>
#include <ga/ga.h>
using namespace std;
  int popsize  = 10;
  int ngen     = 1000;
  float pmut   = 0.01;
  float pcross = 0.6;
double funkcja(double x, double y)
{
	const double a=1,b=2;
	return y*b*sin(y*y)+x*sin(a*x);
};
float objective(GAGenome& gen);
int main(int argc, char* argv[])
{
	GABin2DecPhenotype map;
	map.add(30,0,10);
	map.add(30,0,10);
	GABin2DecGenome genome(map,objective);
	GASimpleGA ga(genome);
	ga.population(popsize);
	ga.nGenerations(ngen);
	ga.pMutation(pmut);
	ga.pCrossover(pcross);

	GANoScaling scaling;
	ga.scaling(scaling);

	ga.scoreFilename("zbieznosc.dat");
	ga.scoreFrequency(10);
	ga.flushFrequency(50);
	go.evolve((unsigned)time(0));

	GABin2DecGenome best_genome(map,objective);
	best_benome=ga.statistics().bestIndividual();
	cout<<"Najlepsze rozwiazanie: "<<best_genome.phenotype(0)<<"=>"<<objective(best_genome)<<endl;
	cout<<"Najlepsze rozwiazanie2: "<<ga.population().best()<<":"<<ga.population().best().evaluate()<<":"<<ga.population().best().fitness()<<endl;
	return 0;
};
float objective(GAGenome& gen)
{
	return 1.0f/funkcja(1,2);
};
