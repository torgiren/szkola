/******************************************************************************/
/* Ten plik, kazdy moze sobie zorganizowac po swojemu                         */
/* Prosze tylko zastapic moje nazwisko swoim                                  */
/******************************************************************************/

#ifndef SGA_TARASIUK_H
#define SGA_TARASIUK_H
#include "SGA_Facade.h"

// Maksymalne wartosci potrzebne do zadeklarowania wielkosci tablic
// W przypadku chromosomu jest to  bool chromosome[max_chrom_size];
// a w przypadku populacji dwie tablice: main_pop[max_pop_size],
//                                       temp_pop[max_pop_size];
// Nie jest to rozwiazanie eleganckie i efektywne, ale mam nadzieje
// dydaktyczne. Osobom mniej wprawnym w programowaniu pozwoli skoncentrowac
// sie na Algorytmie Genetycznym a nie na kodowaniu.
// Jesli ktos potrafi moze uzyc tablic dynamicznych, kontenerow itp.

const int max_pop_size=100;
const int max_chrom_size=30;

/******************************************************************************/
/*                                                                   GENOTYPE */
/******************************************************************************/
class genotype
{
 public:
 bool chromosome[max_chrom_size];	// zakodowana postac rozwiazania
 void random_init();
 int  mutation(float p_mut);
 double fitness_function();
 float RetValue(int j);
};

/******************************************************************************/
/*                                                                  PHENOTYPE */
/******************************************************************************/
class phenotype
{
 public:
 float x;							// niezakodowana postac rozwiazania
 void  decode(genotype g);
};

/******************************************************************************/
/*                                                                 INDIVIDUAL */
/******************************************************************************/
class individual
{
 public:
 genotype  g;
 phenotype p;
 double     fitness;
 void init();
 bool cross_over(individual &ind, float p_cross);
 int  mutation(float p_mut) {return g.mutation(p_mut);};
 void calculate_fitness();
};

/******************************************************************************/
/*                                                                 POPULATION */
/******************************************************************************/
class population
{
private:
	// aktualna populacja na ktorej pracujemy, do niej maja sie zawsze odwolywac
	// wszystkie funkcje fasady
	individual main_pop[max_pop_size];
	// populacja pomocnicza, w ktorej chwilowo przechowujemy osobniki przy 
	// tworzeniu nowego pokolenia
	individual temp_pop[max_pop_size];
 int   pop_size,    // aktualna wielkosc populacji
       gen_num;     // numeruje kolejne pokolenia                              
 float p_cross,     // prawdopodobienstwo krzyzowania                          
       p_mutation;  // prawdopodobienstwo mutacji                              
 float sum_fitness; // suma funkcji dostosowania wszystkich osobnikow
					// potrzebna przy selekcji do nowej populacji
 // Dwie zmienne ponizej, nie sa potrzebne do pracy programu. Moga sie jednak
 // przydac podczas debugowania.
 int   n_mutation,  // liczba mutacji w ostatnim pokoleniu                    
       n_cross;     // liczba krzyzowan w ostatnim pokoleniu                  

// Poniewaz nasz algorytm genetyczny SGA intensywnie korzysta ze zmiennych klasy 
// populacja, wiec wygodnie jest go zaprzyjaznic z My_SGA 
friend class My_SGA;

public:
	individual select();	// selekcja
	void init_generation();	// inicjalizacja populacji bazowej
	int  next_generation();	// tworzenie nowego pokolenia
private:
	individual* ruletka();
};


// Klasa, ktora polaczy moj podsystem Algorytmu Genetycznego SGA z programem
// glownym. Klasa dziedziczy po fasadzie SGA_Facade i implementuje wszystkie
// metody wirtualne. Znaczenie wszystkich metod opisane jest w pliku z fasada.
class My_SGA : public SGA_Facade
{
private:
	population pop;
	int		phenotype_number;
	int     Gen_Num() {return pop.gen_num;};
public:
		char* Authors_Names();
		char* Version();
		void  Any_Rapport(ostream& out);

		void Init_Population(int n);
		int  Next_Generation();

		float Individual_Fitness(int i);
		float Individual_Value(int i, int j);

		void  Phenotype_Number(int k) {phenotype_number=k;};
		int   Phenotype_Number() {return phenotype_number;};
		void  P_Mutation(float p) {pop.p_mutation=p;}; 
		float P_Mutation() {return pop.p_mutation;};
		void  P_Crossover(float p) {pop.p_cross=p;};
		float P_Crossover() {return pop.p_cross;};

		int	  Pop_Size() {return pop.pop_size;};
};

#endif
