#include <iostream>
#include <cmath>
#include <vector>
#include <ga/ga.h>
#include <ga/GASelector.h>
#include "StaticLib.h"
using namespace std;
  int popsize  = 100;
  int ngen     = 100;
  float pmut   = 0.01;
  float pcross = 0.6;
float objective(GAGenome& gen);
int main(int argc, char* argv[])
{
	{
		FILE* r=fopen("/dev/urandom","rb");
		int s;
		fread(&s,sizeof(int),1,r);
		fclose(r);
		GARandomSeed(s);
	};
	GABin2DecPhenotype map;
	map.add(20,GA_Get_Min_x(4),GA_Get_Max_x(4));
	map.add(20,GA_Get_Min_y(4),GA_Get_Max_y(4));

	GABin2DecGenome genome(map,objective);
	GASimpleGA ga(genome);



	int c;
	while((c=getopt(argc,argv,"p:g:m:c:s:"))!=-1)
	{
		switch(c)
		{
			//population
			case 'p':
				popsize=atoi(optarg);
				break;
			//generations
			case 'g':
				ngen=atoi(optarg);
				break;
			//mutation
			case 'm':
				pmut=atoi(optarg);
				break;
			//crossover
			case 'c':
				pcross=atoi(optarg);
				break;
			//selector
			case 's':
				if(!strcmp(optarg,"list"))
				{
					fprintf(stderr,"lista selectorów:\n\truletka\n\tturniej\n\trankingowa");
					exit(2);
				}
				else if(!strcmp(optarg,"ruletka"))
				{
					ga.selector(GARouletteWheelSelector());
				}
				else if(!strcmp(optarg,"turniej"))
				{
					ga.selector(GATournamentSelector());
				}
				else if(!strcmp(optarg,"rankingowe"))
				{
					ga.selector(GARankSelector());
				};
				break;
			case '?':
				printf("pomoc...\n");
				break;
		};
	};









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

	vector<float> best,median,online,offlineMax,offlineMin;
	int i;
	for(i=0;i<ngen;i++)
	{
		ga.step();
//		GABin2DecGenome best_genome(map,objective);
//		best_genome=ga.statistics().bestIndividual();
	//	cout<<"Online: "<<ga.statistics().online()<<endl;
	//	cout<<"Offline: "<<ga.statistics().offlineMax()<<":"<<ga.statistics().offlineMin()<<endl;
	//	cout<<"Najlepsze rozwiazanie: ("<<best_genome.phenotype(0)<<","<<best_genome.phenotype(1)<<")=>"<<objective(best_genome)<<endl;
	//	cout<<"Najlepsze rozwiazanie2: "<<ga.population().best()<<":"<<ga.population().best().evaluate()<<":"<<ga.population().best().fitness()<<endl;
		best.push_back(objective(ga.population().individual(0)));
		median.push_back(objective(ga.population().individual(ga.population().size()/2)));
		online.push_back(ga.statistics().online());
		offlineMax.push_back(ga.statistics().offlineMax());
		offlineMin.push_back(ga.statistics().offlineMin());
	};
	FILE* plik;
	for(i=0;i<ngen;i++)
	{
		char path[255];
		sprintf(path,"tmp_%04d.raw",i);
		plik=fopen(path,"a");
		fprintf(plik,"%f %f %f %f %f\n",best[i],median[i],online[i],offlineMax[i],offlineMin[i]);
		fclose(plik);
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
