#ifndef __ENGINE_H
#define __ENGINE_H
#include "mrowka.h"
#include "kontener.h"
typedef std::vector<Droga*> Drogi;
class Engine
{
	public:	
		Engine();
		bool Step();
		int RetBest() const;
		void NewAnt(int number);
		void Parowanie();
		void LoadMap(std::string path);
		int Cities();
		void CreateContainer(int cities);
		int DumpContainer(char* data) {return itsKontener->Dump(data);};
		void LoadContainer(char* data) { std::cout<<itsKontener<<std::endl; itsKontener->Load(data);};
		void PrintKontener() {itsKontener->Print();};
	private:
		Drogi RetMozliweDrogi(Mrowka* mrowka);
		Drogi RetTrasa(Mrowka* mrowka);
//		int RetDlugosc();
		int PickRoad(Drogi drogi);
		void ZostawFeromony(Mrowka* mrowka);
		Kontener* itsKontener;
		Mrowka** itsMrowki;
		unsigned int itsAntNumber;
		int itsBest;
};
#endif
