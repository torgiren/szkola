/******************************************************************************/
/* S(imple)G(enetic)A(lghoritm) - wersja 2.0                                  */
/* Algorytmy Genetyczne - wyklad obieralny WFiIS (c)2012 J. Tarasiuk          */
/* ****************************************************************************/
#include <iostream>
#include <fstream>
#include "SGA_Facade.h"
#include "mysga.h" // Tu nalezy dolaczyc plik z wlasnym kodem
                          // zmieniajac nazwe pliku na zawierajaca nazwisko
#include "random.h"

using namespace std;

SGA_Facade *SGA;	// Tworzymy wskaznik na fasade
int GN=0;			// Generation Number - numer pokolenia
int Final_Generation=100;	// Liczba pokolen po ktorej algorytm zatrzyma sie
fstream conv_file,log_file;	// Pliki do zapisu zbieznosci oraz logow

/******************************************************************************/
/*                                                             PROGRAM GLOWNY */
/******************************************************************************/
int main(int argc, char* argv[])
{
	rnd_init(0);
//  Jesli chcemy startowac generator zawsze w ten sam sposob, odkomentowujemy
//  linijke ponizej komentarza, w przeciwnym wypadku generator inicjalizuje sie 
//  wartoscia z pliku "RND_Init.dat" 
//	rnd_init(25828184); 


	conv_file.open("convergence.txt",ios::out);
	log_file.open("log.txt",ios::out);

	// Tworzymy instancje obiektu, bedacego naszym SGA, ktory odziedziczyl
	SGA=new (My_SGA);					          //  wszystko po fasadzie

	cout << "Programmed by: " << SGA->Authors_Names() << endl;
	cout << "Version: " << SGA->Version() << endl << endl;

	// Ponizej inicjalizujemy parametry modelu:
	SGA->Phenotype_Number(1);	// tym sie na razie nie przejmujemy
	SGA->P_Mutation(0.3);		// prawdopodobienstwo mutacji
	SGA->P_Crossover(0.9);		// prawdopodobienstwo krzyzowania
	
	SGA->Init_Population(100);	// Inicjalizujemy populacje bazowa

	// Drukujemy parametry pracy modelu
	SGA->Print_Parameters(cout); 

	// W petli obliczamy i drukujemy statystyki, zapisujemy zbieznosc do
	// pliku, a nastepnie wyznaczamy nowe pokolenie. Na zakonczenie
	// drukujemy ewentualny raport do pliku z logami. Przydatne do 
	// debugowania lub testowania roznych wersji algorytmu.
	for (int i=0; i<Final_Generation; i++)
	{
		cout << GN << " ";
		SGA->Calc_Statistics();
		SGA->Print_Statistics(cout,1);
		conv_file << GN << "\t" << SGA->Average_Fit() << "\t";
		conv_file << SGA->Best_Fit() << endl;
		GN=SGA->Next_Generation();
		SGA->Any_Rapport(log_file);
	}
	
	// Obliczamy statystyki ostatniego pokolenia i drukujemy
	// najlepszego i najgorszego osobnika
	SGA->Calc_Statistics();
	SGA->Print_Statistics(cout,3);

	// Sprzatamy po sobie i konczymy program
	rnd_save();
	delete SGA;
	log_file.close();
	conv_file.close();
//	cout << "\nPress ENTER to finish" << endl;
//	getchar();
	return 0;
}

