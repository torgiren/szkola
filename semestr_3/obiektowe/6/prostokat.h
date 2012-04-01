#ifndef __PROSTOKAT__
#define __PROSTOKAT__
#include "kwadrat.h"
class Prostokat: public Kwadrat
{
	public:
		friend istream& operator>>(istream& strm,Prostokat& element);
		Prostokat() {Prostokat(0,0);};
		Prostokat(float a, float b): Kwadrat(a),itsB(b) {};
		void SetAB(float a,float b) {itsA=a;itsB=b;};
		float RetPole() const {return itsA*itsB;};
		float RetObwod() const {return 2*itsA+2*itsB;};
	protected:
		float itsB;
};
#endif
