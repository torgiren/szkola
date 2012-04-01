#ifndef __DODAJ_H
#define __DODAJ_H
#include "dzialanie.h"
class Dodaj: public Dzialanie
{
	public:
		float Oblicz(float x,float y)
		{
			return x+y;
		};
};
#endif
