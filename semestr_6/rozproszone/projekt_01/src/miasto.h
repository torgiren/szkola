#ifndef __MIASTO_H
#define __MIASTO_H
#include<vector>
#include "kierunek.h"
class Miasto
{
	public:
		Kierunek* RetKierunek();
	private:
		std::vector<Kierunek*> itsDrogi;
};
#endif
