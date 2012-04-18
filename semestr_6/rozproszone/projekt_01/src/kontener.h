#ifndef __KONTENER_H
#define __KONTENER_H
#include <vector>
#include <iostream>
#include "miasto.h"
#include "droga.h"
class Kontener
{
	friend class Engine;
	public:
		Kontener(int cities);
		~Kontener();
		void AddRoad(Droga* road);		
		void Print();
		std::vector<Droga*> RetDrogi(int city);
	private:
		std::vector<Droga*> itsDrogi;
		std::vector<Miasto*> itsMiasta;
};
#endif
