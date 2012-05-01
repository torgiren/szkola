#ifndef __MROWKA_H
#define __MROWKA_H
#include <vector>
#include <set>
#include "droga.h"
class Mrowka
{
	public:
		Mrowka();
		void IdzDroga(int roadID, Droga* droga);
//	private:
		std::vector<int> itsDroga;
		std::set<int> itsOdwiedzone;
		int itsMiasto;
		int itsStart;
		int itsDlugosc;
};
#endif
