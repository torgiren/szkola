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
		void NewAnt();
	private:
		Drogi RetDrogi();
		int RetDlugosc();
		int PickRoad(Drogi drogi);
		Kontener* itsKontener;
		Mrowka* itsMrowka;
		int itsBest;
};
#endif
