#ifndef __ODEJMIJ_H
#define __ODEJMIJ_H
#include "dzialanie.h"
class Odejmij: public Dzialanie
{
	public:
		float Oblicz(float x,float y)
		{
			return x-y;
		};
};
#endif
