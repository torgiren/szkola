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

	int c;
	GASelectionScheme* sel=NULL;

	while((c=getopt(argc,argv,"p:m:c:S:"))!=-1)
	{
		switch(c)
		{
			//population
			case 'p':
				popsize=atoi(optarg);
				break;
			//generations
//			case 'g':
//				ngen=atoi(optarg);
//				break;
			//mutation
			case 'm':
				pmut=atof(optarg);
				break;
			//crossover
			case 'c':
				pcross=atof(optarg);
				break;
			//selector
			case 'S':
				cout<<"selector"<<endl;
				if(!strcmp(optarg,"list"))
				{
					fprintf(stderr,"lista selectorów:\n\truletka\n\tturniej\n\trankingowa");
					exit(2);
				}
				else if(!strcmp(optarg,"roulette"))
				{
//					ga.selector(GARouletteWheelSelector());
					sel=new GARouletteWheelSelector();
				}
				else if(!strcmp(optarg,"tournament"))
				{
//					ga.selector(GATournamentSelector());
					sel=new GATournamentSelector();
				}
				else if(!strcmp(optarg,"rank"))
				{
//					ga.selector(GARankSelector());
					sel=new GARankSelector();
				};
				break;
			case 'C':
				cout<<"crossover"<<endl;
				if(!strcmp(optarg,"list"))
				{
					fprintf(stderr,"lista crossoverow:\n\tonepoint\n\ttwopoint\n\tevenodd\n\tuniform");
					exit(2);
				}
				else if(!strcmp(optarg,"onepoint"))
				{
					genome.crossover(GA1DBinaryStringGenome::OnePointCrossover);
				}
				else if(!strcmp(optarg,"twopoint"))
				{
					genome.crossover(GA1DBinaryStringGenome::TwoPointCrossover);
				}
				else if(!strcmp(optarg,"evenodd"))
				{
					genome.crossover(GA1DBinaryStringGenome::EvenOddCrossover);
				}
				else if(!strcmp(optarg,"uniform"))
				{
					genome.crossover(GA1DBinaryStringGenome::UniformCrossover);
				};
				break;
			case '?':
				printf("pomoc...\n");
				break;
		};
	};


	GASimpleGA ga(genome);

	if(sel)
		ga.selector(*sel);





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
		fprintf(plik,"%f %f %f %f %f\n",best[i],median[i],offlineMax[i],offlineMin[i],online[i]);
		fclose(plik);
	};
	plik=fopen("wynik.raw","a");
		GABin2DecGenome best_genome(map,objective);
		best_genome=ga.statistics().bestIndividual();
	fprintf(plik,"%f %f\n",best_genome.phenotype(0),best_genome.phenotype(1));
//	fprintf("%f %f\n",ga.statistics().bestIndividual().phenotype(0),ga.statistics().bestIndividual().phenotype(1));
	fclose(plik);

//		cout<<"Najlepsze rozwiazanie: ("<<best_genome.phenotype(0)<<","<<best_genome.phenotype(1)<<")=>"<<objective(best_genome)<<endl;
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
