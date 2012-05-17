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
		int Dump(char*& data);
		void Load(char* data);
		int FindRoadId(int miasto0,int miasto1);
		int FindRoadId(Droga* droga);
	private:
		std::vector<Droga> itsDrogi;
		std::vector<Miasto> itsMiasta;
		int itsMaxLen;
};
#endif
