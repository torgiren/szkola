#ifndef __KWADRAT__
#define __KWADRAT__
#include "figura.h"
/**
Klasa kwadratu
*/
class Kwadrat: public Figura
{
	public:
		friend istream& operator>>(istream& strm,Kwadrat& element);
		Kwadrat();
		Kwadrat(float a);
		void SetA(float a) {itsA=a;};
		///Funkcja zwracajace Pole
		virtual float RetPole() const {return itsA*itsA;};
		///Funkcja zwaracjace Obwod
		virtual float RetObwod() const {return 4*itsA;};
	protected:
		float itsA;
};
#endif
