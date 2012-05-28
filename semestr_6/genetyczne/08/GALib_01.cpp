#include <cstdlib>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <ga/ga.h>

using namespace std;

// Ustalamy wartosci parametrow algorytmu
  int popsize  = 10;
  int ngen     = 1000;
  float pmut   = 0.01;
  float pcross = 0.6;

// Informujemy kompilator, ze gdzies dalej bedzie funkcja celu
  float objective(GAGenome &);


int main(int argc, char *argv[])
{
// Uzyjemy fenotypu z liczbami rzeczywistymi reprezentowanymu binarnie
  GABin2DecPhenotype map;

// Dodajemy do fenotypu pierwsza zmienna o zakresie zmiennosci od 0 do M_PI,
// ktora bedzie reprezentowana na 30 bitach
  map.add(30, 0, 1*M_PI);

// Tworzymy genom na bazie zdefiniowanego fenotypu i wiazemy z nim funkcje celu
  GABin2DecGenome genome(map, objective);

// Tworzymy algorytm genetyczny na bazie zdefionowanego genomu
  GASimpleGA ga(genome);

// Inicjalizujemy algorytm ustalonymi wczesniej wartosciami
  ga.populationSize(popsize);
  ga.nGenerations(ngen);
  ga.pMutation(pmut);
  ga.pCrossover(pcross);

// Jezeli nie jestesmy pewni, czy funkcja celu przyjmuje wylacznie dodatnie
// wartosci, to musimy zastosowac skalowanie, np. typu SigmaTruncation
  GANoScaling scaling;
  ga.scaling(scaling);
//  GASigmaTruncationScaling scaling;

// Statystyki bedziemy zapisywac do pliku "zbieznosc.dat"
  ga.scoreFilename("zbieznosc.dat");

// Statystyki beda zapisywane co 10 pokolen
  ga.scoreFrequency(10);

// Zapis do pliku bedzie sie odbywal co 50 pokolen
  ga.flushFrequency(50);

// Uruchamiamy ewolucje, inicjalizujac generator losowy przypadkowa wartoscia
  ga.evolve((unsigned)time(0));

// Wypisujemy najlepszy wynik znaleziony kiedykolwiek
  GABin2DecGenome best_genome(map, objective);
  best_genome = ga.statistics().bestIndividual();
  cout << "Najlepsze rozwiazanie znalezione kiedykolwiek to F(x=";
  cout << best_genome.phenotype(0) << ")=";
  cout << objective(best_genome) << endl;

// Wypisujemy najlepszy wynik znaleziony w ostatnim pokoleniu
  cout << "Najlepsze rozwiazanie to F(x=";
  cout << ga.population().best() << ")=";
  cout << ga.population().best().evaluate() << " (";
  cout << ga.population().best().fitness() << ")" << endl;

  getch();
  return EXIT_SUCCESS;
}

float objective(GAGenome & c)
{
  GABin2DecGenome & genome = (GABin2DecGenome &)c;

  float w,x;
  x=genome.phenotype(0);
  w=fabs(sin(M_PI*x)*exp(-x/(6*M_PI)));
  return w;
}

