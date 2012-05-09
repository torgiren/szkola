#ifndef __ENGINE_H
#define __ENGINE_H
#include "mrowka.h"
#include "kontener.h"
#include <cstring>
typedef std::vector<Droga*> Drogi;
class Engine
{
	public:	
		Engine(int rank);
		bool Step();
		int RetBest() const;
		Mrowka* RetBestAnt() const;
		void NewAnt(int number);
		void Parowanie();
		void LoadMap(std::string path);
		int Cities();
		void CreateContainer(int cities);
		int DumpContainer(char* data) {return itsKontener->Dump(data);};
		int LoadContainer(char* data) { std::cout<<itsKontener<<std::endl; itsKontener->Load(data);return strlen(data);};
		void PrintKontener() {itsKontener->Print();};
		void ZostawFeromony(Mrowka* mrowka);
		bool IsFinished() {return itsFinished;};
	private:
		Drogi RetMozliweDrogi(Mrowka* mrowka);
		Drogi RetTrasa(Mrowka* mrowka);
//		int RetDlugosc();
		int PickRoad(Drogi drogi);
		Kontener* itsKontener;
		Mrowka** itsMrowki;
		unsigned int itsAntNumber;
		Mrowka* itsBestAnt;
		int itsBest;
		int itsRank;
		bool itsFinished;
};
#endif
