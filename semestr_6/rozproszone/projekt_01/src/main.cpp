#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "mympe.h"
#include "kontener.h"
#include "reader.h"
#include "engine.h"
int main(int argc, char* argv[])
{
//Inicjacja MPI
//Funkcja przeciążona inicjująca również mpe
	MPI_Init(&argc,&argv);
	int rank,size;
//Odczytanie rozmiaru chmury oraz swojego id.
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	srand(time(NULL)*rank);
//Stworzenie klasy silnika.
//Mówimy mu jaki ma id;
	Engine eng(rank);
	char* data=new char[0xfffff];
	memset(data,0,0xfffff);
	int len=0;
	int cities=0;
//Wczytanie mapy na nodzie zerowym.
//oraz zrzucenie go do zmiennej tekstowej;
	if(rank==0)
	{
		eng.LoadMap("map.ini");
		len=eng.DumpContainer(data);
		cities=eng.Cities();
	}
//Przekazanie liczby miast do wszystkich wezłów
	MPI_Bcast(&cities,1,MPI_INT,0,MPI_COMM_WORLD);
	if(size>cities)
	{
		if(rank==0)
			fprintf(stderr,"Liczba procesow wieszka niz liczba miast. nie moge obsluzyc\n");
		MPI_Finalize();
		exit(2);
	};
//Wysłanie mapy do pozostałych węzłów
	MPI_Bcast(&len,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(data,len,MPI_CHAR,0,MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
//Wczytywanie w nodach mapy na podstawie przesłanych danych
	if(rank!=0)
	{
		eng.CreateContainer(cities);
		eng.LoadContainer(data);
	};
	std::cout<<eng.Cities()<<" miast w rank= "<<rank<<std::endl;
	int i;
	delete [] data;
	data=new char[1024];
	int quit=0;
	int glob_best=99999999;
	Mrowka glob_best_ant;
	for(i=0;(i<50)|(!quit);i++)
	{
		int dystans=0;
//Stworzenie odpowiedniej ilości mrówek
		if(rank==0)
			eng.NewAnt(eng.Cities()/size+eng.Cities()%size);
		else
			eng.NewAnt(eng.Cities()/size);
//Stepowanie mrówek aż do obejścia wszystkich miast
		while(eng.Step());
//Parowanie feromonów
		eng.Parowanie();

//Zapisanie wartości najkrótszej ścieżki w każdym węźle
		dystans=eng.RetBestAnt()->itsDlugosc;

//Wysyłanie do węzła głównego swoich najmniejszych długości
		MPI_Send(&dystans,1,MPI_INT,0,0,MPI_COMM_WORLD);
		int bestRank=0;
//Wybranie węzła z najlepszą ścieżką
//znajdź najlepsza mrówkę i uczyń ją pracownicą miesiąca
		if(rank==0)
		{
			int i;
			int best=99999999;
			MPI_Status status;
			int recv;

			for(i=0;i<size;i++)
			{
				MPI_Recv(&recv,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
				if(recv<best)
				{
					best=recv;
					bestRank=status.MPI_SOURCE;	
					if(best<glob_best)
					{
						glob_best=best;
					};
				};
			};
		};
//Rozesłanie informacji o najlepszym węźle do całej chmury
		MPI_Bcast(&bestRank,1,MPI_INT,0,MPI_COMM_WORLD);
		memset(data,0,1024);
//Jeśli to ja jestem najlepszy, zrzucam najlepsza ścieżkę do zmiennej
		if(rank==bestRank)
		{
			eng.RetBestAnt()->PartialDump(data);
			len=strlen(data);
		};
//Wysyłam swoją najlepszą ścieżkę do całej chmury
		MPI_Bcast(&len,1,MPI_INT,bestRank,MPI_COMM_WORLD);
		MPI_Bcast(data,len,MPI_CHAR,bestRank,MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
		Mrowka bestAnt;
		bestAnt.PartialLoad(data);
		if(rank==0)
		{
			printf("dlugosc:  %d -- %d\n",bestAnt.itsDlugosc,glob_best);
			if(bestAnt.itsDlugosc<=glob_best)
			{
				glob_best=bestAnt.itsDlugosc;
				glob_best_ant=bestAnt;
			};
		};
//Zostaw feromony na najlepszej ścieżce w danej iteracji
		eng.ZostawFeromony(&bestAnt);


//Ustalenie warunku znalezienia globalnie najlepszej ścieżki
		int finished=eng.IsFinished();
		MPI_Send(&finished,1,MPI_INT,0,0,MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
		if(rank==0)
		{
			int i;
			int recv;
			int koniec=1;
			for(i=0;i<size;i++)
			{
				MPI_Recv(&recv,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,NULL);
				if(!recv)
				{
					koniec=0;
				};
			};
			quit=koniec;
		};
		MPI_Bcast(&quit,1,MPI_INT,0,MPI_COMM_WORLD);

		std::cout<<"i="<<i<<"\tNajlepsza droga: "<<eng.RetBest()<<std::endl;
	};
	MPI_Barrier(MPI_COMM_WORLD);
//Wypisanie najlepszych ostatecznych dróg dla węzłów
	std::cout<<"rank="<<rank<<"\tNajlepsza droga: "<<eng.RetBest()<<std::endl;
	
//Zapisanie wyników do pliku
	if(rank==0)
	{
		FILE* plik;
		plik=fopen("wynik.txt","w");
		if(!plik)
		{
			fprintf(stderr,"Problem z otwarciem pliku\n");
			return -1;
		};
		fprintf(plik,"Globalnie najlepsza droga to: %d\n",glob_best);
		int i;
		std::vector<Droga*> drogi=eng.RetTrasa(&glob_best_ant);
		int last=glob_best_ant.itsStart;
		printf("Liczba drog: %d\n",drogi.size());
		printf("Dlugosc mrowki: %d\n",glob_best_ant.itsDlugosc);
		for(i=0;i<eng.Cities();i++)
		{
			last=drogi[i]->itsMiasta[0]==last?drogi[i]->itsMiasta[1]:drogi[i]->itsMiasta[0];
			fprintf(plik,"%d ",last);
		};
		fclose(plik);
	}
//Zakończenie pracy z MPI
	MPI_Finalize();
	return 0;
};
