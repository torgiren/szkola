#ifndef __KONTENER_H
#define __KONTERNE_H
#include <vector>
#include "miasto.h"
#include "droga.h"
#include "kierunek.h"
class Kontener
{
	public:

	private:
		std::vector<Droga*> itsDrogi;
		std::vector<Miasto*> itsMiasta;
		std::vector<Kierunek*> itsKierunki;
};
#endif
