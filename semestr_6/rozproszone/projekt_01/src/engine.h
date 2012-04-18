#ifndef __ENGINE_H
#define __ENGINE_H
#include "mrowka.h"
#include "kontener.h"
class Engine
{
	public:	
		Engine();
		void Step();
	private:
		Kontener* itsKontener;
		Mrowka* itsMrowka;
};
#endif
