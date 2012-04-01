#ifndef __KOLO__
#define __KOLO__
#include "figura.h"
class Kolo: public Figura
{
	public:
		friend istream& operator>>(istream& strm,Kolo& element);
		Kolo() {Kolo(0);};
		Kolo(float r): itsR(r) {};
		void SetR(float r) {itsR=r;};
		float RetPole() const {return 3.14*itsR*itsR;};
		float RetObwod() const {return 2*3.14*itsR;};
	protected:
		float itsR;
};
#endif
