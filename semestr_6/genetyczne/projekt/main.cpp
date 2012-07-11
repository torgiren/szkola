#include<ga/ga.h>
#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
int popsize=1000;
int ngen=500;
float pmut=0.01;
float pcross=0.8;
typedef struct __klocek
{
	float itsW;
	float itsH;
	int itsObrot;
	float itsX;
} klocek;
float GetSzerokosc(klocek* kloc);
klocek *tab;
typedef GA1DArrayGenome<int> GENOME;
float objective(GAGenome&);
void init(GAGenome&);
int size;
int MyMutator(GAGenome& gen, float pmut);
int main(int argc, char* argv[])
{
	srand(time(NULL));
	if(argc<2)
	{
		fprintf(stderr,"Not enough parameters\nUsage: ./%s <filename>\n",argv[0]);
		return 1;
	};
	FILE* plik;
	plik=fopen(argv[1],"r");
	if(!plik)
	{
		fprintf(stderr,"Can't open file %s\n",argv[1]);
		return 2;
	};
	fscanf(plik,"%d",&size);
	if(!(size>0))
	{
		fprintf(stderr,"Data error. Wrong number of blocks\n");
		return 3;
	};
	tab=(klocek*)malloc(size*sizeof(klocek));
	memset(tab,0,sizeof(klocek)*size);
	int i;
	for(i=0;i<size;i++)
	{
		int nr;
		float w,h;
		fscanf(plik,"%d %f %f",&nr,&w,&h);
		tab[nr].itsW=w;
		tab[nr].itsH=h;
//		printf("Mam klocka z parametrow: %f %f %d %f\n",tab[nr].itsW,tab[nr].itsH,tab[nr].itsObrot,tab[nr].itsX);
	};

	GA1DArrayGenome<int> pop(size,objective);
	pop.initializer(init);
//	pop.mutator(GA1DArrayGenome<int>::SwapMutator);
	pop.mutator(MyMutator);
	pop.crossover(GA1DArrayGenome<int>::PartialMatchCrossover);

	GASimpleGA ga(pop);

	ga.selector(GARankSelector());
//	ga.selector(GATournamentSelector());
	ga.populationSize(popsize);
	ga.nGenerations(ngen);
	ga.pMutation(pmut);
	ga.pCrossover(pcross);
	ga.evolve(rand());
	{
		GENOME& genome=(GENOME&)ga.population().best();
		float pos=0;
		for(i=genome.size()-1;i>=0;--i)
		{
			printf("%d:\tnr:%d\tX:%f\tW:%f\n",i,genome[i],tab[genome[i]].itsX,GetSzerokosc(&tab[genome[i]]));
		};
	}
	printf("Najlepsze rozwiazanie to %f\n",objective(ga.population().best()));


	free(tab);
	return 0;
};
void init(GAGenome& gen)
{
	GENOME& genome=(GENOME&)gen;
	int i;
	for(i=0;i<genome.size();i++)
	{
		genome[i]=i;
	};
	for(i=0;i<genome.size()/2;i++)
	{
		genome.swap(rand()%genome.size(),rand()%genome.size());
	};
	for(i=0;i<genome.size()/2;i++)
	{
		tab[genome[i]].itsObrot=rand()%2;
//		tab[genome[i]].itsX=rand()%21-10;
		tab[genome[i]].itsX=(float)rand()/RAND_MAX;
	};
};
float objective(GAGenome& gen)
{
	GENOME& genome=(GENOME&)gen;
	int i=0;
	float wynik=0;
	for(i=1;i<genome.size();i++)
	{
		int j;
//		float szer=tab[genome[i]].itsObrot?tab[genome[i]].itsH:tab[genome[i]].itsW;
		float szer=GetSzerokosc(&tab[genome[i]]);
		float srodek=szer/2.0f;
		float srodek_suma=srodek;
		float pos=0;
		int num=0;
		for(j=i,num=2;j>0;j--,num++)
		{
			float w2=GetSzerokosc(&tab[genome[j]]);
			float w1=GetSzerokosc(&tab[genome[j-1]]);
			pos=pos+w2/2.0f-w1*tab[genome[j-1]].itsX;
//			pos-=tab[genome[j-1]].itsX;
//			float w=GetSzerokosc(&tab[genome[j-1]]);
			if(!((srodek>pos)&&(srodek<pos+w1)))
				goto endfor;

			srodek_suma+=pos+w1/2.0f;
			srodek=srodek_suma/(float)num;
		};
		wynik+=1000;
	};
endfor:
	int max_i=i;
	float min=tab[genome[0]].itsX;
	float max=min+GetSzerokosc(&tab[genome[0]]);
	float pos=min;
//	for(i=1;i<max_i-1;i++)
	for(i=1;i<10;i++)
	{
		float w2=GetSzerokosc(&tab[genome[i+1]]);
		float w1=GetSzerokosc(&tab[genome[i]]);
		pos=pos+tab[genome[i]].itsX*w1-w2/2.0f;
		if(pos<min)
			min=pos;
		if(pos+w2>max)
			max=pos+w2;
	};
	wynik+=max-min;
//	printf("Genome 10=%d, genome[50]=%d\n",genome[10],genome[50]);
	return wynik;
};
float GetSzerokosc(klocek* kloc)
{
	return kloc->itsObrot?kloc->itsH:kloc->itsW;
};
int MyMutator(GAGenome& gen, float pmut)
{
	int nMut=0;
	GENOME& genome=(GENOME&)gen;
	int i;
	for(i=0;i<genome.size();i++)
	{
		if(GAFlipCoin(pmut))
		{
			tab[genome[i]].itsObrot|=1;
			nMut++;
		}
		if(GAFlipCoin(pmut))
		{
//			printf("przed: %f\n",tab[genome[i]].itsX);
//			tab[genome[i]].itsX=(float)rand()/RAND_MAX;
//			printf("po: %f\n",tab[genome[i]].itsX);
			nMut++;
		};
		if(GAFlipCoin(pmut))
		{
			genome.swap(rand()%genome.size(),rand()%genome.size());			
			nMut++;
		};
	};
	return nMut;
};
