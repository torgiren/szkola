/******************************************************************************/
/* Ten plik, kazdy moze sobie zorganizowac po swojemu                         */
/* Prosze tylko ustawic ponizsze dwie definicje:                              */
/*  - pierwsza defincja to nazwisko osoby lub nazwiska grupy piszacej kod     */
/*  - druga definicja to nazwa cwiczenia i numeracja wersji kodu              */
/******************************************************************************/

#define NAME "Jacek Tarasiuk"
#define VERSION "SGA 0.8"

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include "mysga.h" // Tu trzeba zainkludowac wlasny plik
#include "random.h"
#include <string.h>
using namespace std;

/******************************************************************************/
/*                                                          OPERATORY WYJSCIA */
/* Dla wygody, stworzylem sobie operatory wyjscia dla kazdej klasy.           */
/******************************************************************************/

ostream& operator<<(ostream& out, genotype g)
{
	for (int i=0; i<max_chrom_size; i++)
		if (g.chromosome[i]) out << "1"; else out << "0";
	return out;
}

ostream& operator<<(ostream& out, phenotype p)
{
 out << p.x;
 return out;
}

/******************************************************************************/
/*                                                 IMPLEMENTACJE KLASY FACADE */
/******************************************************************************/

char* My_SGA::Authors_Names() {return NAME;};
char* My_SGA::Version() {return VERSION;};

void My_SGA::Init_Population(int n)
{
	pop.pop_size=n;
	pop.init_generation();
}

float My_SGA::Individual_Fitness(int i)
{
	return pop.main_pop[i].fitness;
}

float My_SGA::Individual_Value(int i, int j)
{
	return pop.main_pop[i].g.RetValue(j);
}

int My_SGA::Next_Generation()
{
	return pop.next_generation();
}

void My_SGA::Any_Rapport(ostream& out)
{
// Tu wpisujemy dowolny kod, ktory bedzie sie wykonywal w kazdym pokoleniu
// Algorytmu Genetycznego. W szczegolnosci mozemy tutaj zapisywac rozne dane
// do pliku z logami, aby latwiej analizowac prace programu.
// Ponizej tylko przykladowy kod, ktory mozna w calosci wykomentowac.
	out << "Pokolenie: " << Gen_Num() << endl;
	for (int i=0; i<10; i++)
	{
		out << i << ". Fenotyp:\t" << pop.main_pop[i].p;
		out << "\tGenotyp:\t" << pop.main_pop[i].g << endl;
	}
}

/******************************************************************************/
/*                                             IMPLEMENTACJE KLASY POPULATION */
/******************************************************************************/

void population::init_generation()
{
	gen_num=0;
	for (int i=0; i<pop_size; i++)
		main_pop[i].init();
}

int population::next_generation()
{
 int i;
 n_cross=0;
 n_mutation=0;
 sum_fitness=0;

 for (i=0; i<pop_size; i++)
	 sum_fitness+=main_pop[i].fitness;

 for (i=0; i<pop_size; i++)
  temp_pop[i]=select();

 for (i=0; i<pop_size; i=i+2)
  n_cross+=temp_pop[i].cross_over(temp_pop[i+1],p_cross);

 for (i=0; i<pop_size; i++)
  n_mutation+=temp_pop[i].mutation(p_mutation);

 for (i=0; i<pop_size; i++)
  main_pop[i]=temp_pop[i];

 for (i=0; i<pop_size; i++)
  main_pop[i].calculate_fitness();
 gen_num++;
 return gen_num;
}

individual population::select()
{
// ????????????????????????????????????????????????????????????????????????? //
// ?? TA METODE NALEZY ZAIMPLEMENTOWAC. Funkcja zwraca pojedynczego       ?? //
// ?? osobnika wylosowanego metoda ruletki, z prawdopodobienstwem         ?? //
// ?? proporcjonalnym do wartosci jego funkcji dostosowania.              ?? //
// ?? W chwili obecnej funkcja zwraca przypadkowego osobnika.             ?? //
// ????????????????????????????????????????????????????????????????????????? //
	int i=rnd_int(max_pop_size);
	float rnd=rnd_float()*sum_fitness;
	int x;
	float sum=0;
	for(x=0;x<pop_size;x++)
	{
		sum+=main_pop[x].fitness;
		if(rnd<sum)
		{
			return main_pop[x];
		};
	};
//	return main_pop[i-1];
}


/******************************************************************************/
/*                                             IMPLEMENTACJE KLASY INDIVIDUAL */
/******************************************************************************/

void individual::init()
{
 g.random_init();
 calculate_fitness();
}

bool individual::cross_over(individual &ind, float p_cross)
{
// ????????????????????????????????????????????????????????????????????????? //
// ?? TA METODE NALEZY ZAIMPLEMENTOWAC. Funkcja zwraca true jesli doszlo  ?? //
// ?? do krzyzowania i false w przypadku przeciwnym.                      ?? //
// ?? Wewnatrz funkcji nalezy dokonac krzyzowania jednopunktowego.        ?? //
// ?? Rodzicami sa osobnik wskazywany przez this oraz osobnik wskazywany  ?? //
// ?? przez ind. Po krzyzowaniu te same wskazniki wskazuja na dzieci.     ?? //
// ????????????????????????????????????????????????????????????????????????? //
	if(rnd_float()<p_cross)
	{
		int x;
		int miejsce=rnd_int(max_chrom_size,1);
/*	
		printf("Przed\n");
		for(x=0;x<miejsce;x++)
		{
			printf("%d",g.chromosome[x]);
		};
		printf("|");
		for(x=miejsce;x<max_chrom_size;x++)
		{
			printf("%d",g.chromosome[x]);
		};
		printf("\n");

		for(x=0;x<miejsce;x++)
		{
			printf("%d",ind.g.chromosome[x]);
		};
		printf("|");
		for(x=miejsce;x<max_chrom_size;x++)
		{
			printf("%d",ind.g.chromosome[x]);
		};
		printf("\n");
*/
		bool new1[max_chrom_size];
		bool new2[max_chrom_size];
		for(x=0;x<miejsce;x++)
		{
			new1[x]=g.chromosome[x];
			new2[x]=ind.g.chromosome[x];
		};
		for(x=miejsce;x<max_chrom_size;x++)
		{
			new1[x]=ind.g.chromosome[x];
			new2[x]=g.chromosome[x];
		};
	/*
		memcpy(g.chromosome,new1,max_chrom_size*sizeof(bool));
		memcpy(ind.g.chromosome,new2,max_chrom_size*sizeof(bool));
	*/

		for(x=0;x<max_chrom_size;x++)
		{
			g.chromosome[x]=new1[x];
			ind.g.chromosome[x]=new2[x];
		};

/*
		printf("Po\n");
		for(x=0;x<miejsce;x++)
		{
			printf("%d",g.chromosome[x]);
		};
		printf("|");
		for(x=miejsce;x<max_chrom_size;x++)
		{
			printf("%d",g.chromosome[x]);
		};
		printf("\n");

		for(x=0;x<miejsce;x++)
		{
			printf("%d",ind.g.chromosome[x]);
		};
		printf("|");
		for(x=miejsce;x<max_chrom_size;x++)
		{
			printf("%d",ind.g.chromosome[x]);
		};
		printf("\n");
*/
		return true;
	};
	return false;
}

void individual::calculate_fitness()
{
 p.decode(g);
 fitness=g.fitness_function();
}

/******************************************************************************/
/*                                               IMPLEMENTACJE KLASY GENOTYPE */
/******************************************************************************/

void genotype::random_init()
{
 int i;
 for (i=0; i<max_chrom_size; i++)
  chromosome[i]=rnd_bool(0.5);
}


int genotype::mutation(float p_mut)
{
// ????????????????????????????????????????????????????????????????????????? //
// ?? TA METODE NALEZY ZAIMPLEMENTOWAC. Funkcja mutuje kazdy z genow      ?? //
// ?? chromosomu z prawdopodobienstwem p_mut. Funkcja zwraca liczbe       ?? //
// ?? mutacji do jakich doszlo w danym chromosomie.                       ?? //
// ????????????????????????????????????????????????????????????????????????? //
	int x;
	for(x=0;x<max_chrom_size;x++)
	{
		if(rnd_float()<p_mut)
		{
			chromosome[x]=!chromosome[x];
		};
	};
	return 0;
}
extern float E1,E2,B,T;

double genotype::fitness_function()
{

	int i;
	float wartosc=0;
	float masa=0;
	float tlusz=0;
	float bialko=0;
	for(i=0;i<6;i++)
	{
		wartosc+=RetValue(i)*products[i].E;
		tlusz+=RetValue(i)*products[i].T;
		bialko+=RetValue(i)*products[i].B;
		masa+=RetValue(i);
	};
//	return func2(pula1,pula2);
	if(wartosc<E1) wartosc*=0.1f;
	if(wartosc>E2) wartosc*=0.1f;
	if(tlusz>T) wartosc*=0.1f;
	if(bialko<B) wartosc*=0.1f;
	return wartosc;

};
float genotype::RetValue(int j)
{
	int x;
	float wartosc=0;
	for(x=0;x<5;x++)
	{
		wartosc+=chromosome[j*5+x]*pow(2,x);
	};
	return wartosc;
};

/******************************************************************************/
/*                                              IMPLEMENTACJE KLASY PHENOTYPE */
/******************************************************************************/

// Funkcja dekoduje liczbe rzeczywista zapisana w kodzie dwojkowym na
// max_chrom_size pozycjach na liczbe zapisana w kodzie dziesietnym i wpisuje
// otrzymana wartosc do zmiennej x.
void phenotype::decode(genotype g)
{
 int i;
 float power_of_2;
 x=0;  power_of_2=1;
 for (i=0; i<max_chrom_size; i++)
 {
  if (g.chromosome[i]) x+=power_of_2;
  power_of_2*=2;
 }
}

// Funkcja dostosowania. UWAGA bedzie zmieniana. Prawdopodobnie zmieni sie
// rowniez dostep do niej.
