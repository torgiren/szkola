#include <iostream>
#include <cmath>
#include <ga/ga.h>
#include "StaticLib.h"
using namespace std;
  int popsize  = 100;
  int ngen     = 100;
  float pmut   = 0.01;
  float pcross = 0.6;
float objective(GAGenome& gen);
int main(int argc, char* argv[])
{
	GABin2DecPhenotype map;
	map.add(20,GA_Get_Min_x(4),GA_Get_Max_x(4));
	map.add(20,GA_Get_Min_y(4),GA_Get_Max_y(4));

	GABin2DecGenome genome(map,objective);
	GASimpleGA ga(genome);
	ga.minimize();
	ga.populationSize(popsize);
	ga.nGenerations(ngen);
	ga.pMutation(pmut);
	ga.pCrossover(pcross);

//	GANoScaling scaling;
	GASigmaTruncationScaling scaling;
	ga.scaling(scaling);

	ga.scoreFilename("zbieznosc.dat");
	ga.scoreFrequency(1);
	ga.flushFrequency(50);
	ga.selectScores(GAStatistics::AllScores);
//	ga.evolve((unsigned)time(0));

	int i;
	for(i=0;i<100;i++)
{
	ga.step();
	GABin2DecGenome best_genome(map,objective);
	best_genome=ga.statistics().bestIndividual();
	cout<<"Online: "<<ga.statistics().online()<<endl;
	cout<<"Offline: "<<ga.statistics().offlineMax()<<":"<<ga.statistics().offlineMin()<<endl;
	cout<<"Najlepsze rozwiazanie: ("<<best_genome.phenotype(0)<<","<<best_genome.phenotype(1)<<")=>"<<objective(best_genome)<<endl;
	cout<<"Najlepsze rozwiazanie2: "<<ga.population().best()<<":"<<ga.population().best().evaluate()<<":"<<ga.population().best().fitness()<<endl;
};
	return 0;
};
float objective(GAGenome& gen)
{
	float x,y;
	GABin2DecGenome &genome=(GABin2DecGenome&)gen;
	x=genome.phenotype(0);
	y=genome.phenotype(1);
	return GA_TestFunction(4,x,y);
};
