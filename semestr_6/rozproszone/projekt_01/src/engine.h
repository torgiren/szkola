#ifndef __ENGINE_H
#define __ENGINE_H
#include "mrowka.h"
#include "kontener.h"
class Engine
{
	public:	
		Engine();
		bool Step();
		int RetBest();
		void NewAnt();
	private:
		Kontener* itsKontener;
		Mrowka* itsMrowka;
		int itsBest;
};
#endif
