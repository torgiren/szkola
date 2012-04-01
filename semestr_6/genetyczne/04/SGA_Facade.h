/*****************************************************************************/
/* TEGO PLIKU, ABSOLUTNIE POD ZADNYM POZOREM NIE MODYFIKUJEMY !!!            */
/*****************************************************************************/

#ifndef SGH_FACADE_H
#define SGH_FACADE_H

#include <iostream>

using namespace std;

// Klasa bedaca fasada dla calego podsystemu SGA tworzonego przez roznne 
// osoby. Fasada ukrywa caly indywidualny podsystem, udostepniajac programowi
// glownemu jedynie niezbedne elementy. 

class SGA_Facade
{
protected:
	// Aktualne wartosci funcji dostosowania dla najlepszego i najgorszego 
	// osobnika w populacji oraz wartosc srednia dla calej populacji
	float	best_fit, worst_fit, average_fit;
	// Aktualny indeks najlepszego i najgorszego osobnika w populacji
	int		best_index, worst_index;
public:
	/*************************************************************************/
	/* Wszystkie funkcje wirtualne musza zostac zdefiniowane w klasie        */
	/* potomnej odwolujac sie do odpowiednich klas naszej implementacji SGA  */
	/*************************************************************************/
	
	// Funckje zwracajace informacje na temat wersji i autorow, drukujace na
	// wybranym urzadzeniu parametry modelu i statystyki populacji oraz
	// raportujace wybrane dane do pliku logow
	virtual char* Authors_Names() {return "no authors yet";};
	virtual char* Version() {return "0.0";};
	void Print_Parameters(ostream& out);
	void Print_Statistics(ostream& out, int mode);
	virtual void  Any_Rapport(ostream& out) {};

	// Funkcje dzialajace na calej populacji
	virtual void  Init_Population(int n) {};
	virtual int   Next_Generation() {return 0;};
	void Calc_Statistics();

	// Funkcje dostepowe do osobnikow
	virtual float Individual_Fitness(int i) {return 0;};
	virtual float Individual_Value(int i, int j) {return 0;};

	// Wszystkie Gettery i Settery maja nazwy takie same jak zmienne, ktorych
	// wartosci ustawiaja lub odczytuja tylko kazdy wyraz nazwy rozpoczyna sie 
	// od duzej litery. W nazwach zmiennych wszystkie litery sa male
	virtual void  Phenotype_Number(int k) {};
	virtual int   Phenotype_Number() {return 0;};
	virtual void  P_Mutation(float p) {}; 
	virtual float P_Mutation() {return 0;};
	virtual void  P_Crossover(float p) {};
	virtual float P_Crossover() {return 0;};
	// pop_size nie ma settera, poniewaz moze byc ustawiany tylko w trakcie
	// inicjalizacji populacji
	virtual	int   Pop_Size() {return 0;};
	// best_fit, worst_fit, average_fit nie maja setterow, poniewaz sa wyliczane
	// podczas liczenia statystyk
	float Best_Fit() {return best_fit;};
	float Worst_Fit() {return worst_fit;};
	float Average_Fit() {return average_fit;};
};

#endif