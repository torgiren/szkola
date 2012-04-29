#ifndef __KONTENER_H
#define __KONTENER_H
#include <vector>
#include <iostream>
#include "miasto.h"
#include "droga.h"
#include "exceptions.h"
class Kontener
{
	friend class Engine;
	public:
		Kontener(int cities);
		~Kontener();
		void AddRoad(Droga road);		
		void Print();
		std::vector<Droga*> RetDrogi(int city);
		Droga* RetDroga(unsigned int id);
		int Dump(char* data);
		void Load(char* data,int size);
		int FindRoadId(int miasto0,int miasto1);
	private:
		std::vector<Droga> itsDrogi;
		std::vector<Miasto*> itsMiasta;
};
#endif
