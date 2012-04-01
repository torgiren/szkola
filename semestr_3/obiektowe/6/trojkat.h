#ifndef __TROJKAT__
#define __TROJKAT__
#include "figura.h"
#include <iostream>
using namespace std;
class Trojkat: public Figura
{
	public:
		friend istream& operator>>(istream& strm,Trojkat& element);
		Trojkat(float a=0,float b=0,float c=0):itsA(a),itsB(b),itsC(c) {};
		void SetABC(float a,float b,float c) {itsA=a,itsB=b,itsC=c;};
		float RetPole() const;
		float RetObwod() const {return itsA+itsB+itsC;};
	protected:
		float itsA;
		float itsB;
		float itsC;
};
#endif
